//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	IPCFrameWork.cpp  
	Author:		Ajan U. Nair 
	Date:		09-Jul-2008   
	Revision:	1.0           
	Description:
		IPCFrameWork class, provides methods to access the IPC client implementation
		from the IPC files. 

		Objects of basic classes like AppWindow,Network etc. are provided by IPCFramework
		directly.
		
*/


#if !defined IPC_FRAME_WORK_CPP_INCLUDED
#define IPC_FRAME_WORK_CPP_INCLUDED


#define IPC_FW_VERSION		"1.1"
#define IPC_FW_BUILD_STR	"Thu August 21 2008  13:14:43 pm"

#include "IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../IPC/CIpcRetValMsg.h"
#include "../IPC/CIpcRetErrMsg.h"
#include "../IPC/CIpcEvntSubsMsg.h"

#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "../IPCFiles/Network.h"
#include "../IPCFiles/AppWindow.h"
#include "../IPCFiles/CommandLog.h"
#include "../IPCFiles/IpcManager.h"
#include "../IPCFiles/MultiUserManager.h"
#include "../IPCFiles/AclStatement.h"

using namespace Ptmp;
using namespace Ipc;
using namespace std;

class CallResult;

void fwDebug(QString outStr)
{
	if(ENABLE_DBG_MSG_FW_ENGINE)
	{
		qDebug(outStr);
	}else
	{
		return;
	}
}


IPCFrameWork::~IPCFrameWork(){

}

IPCFrameWork::IPCFrameWork(Ptmp::EPtmpBufferEncoding encoding,
		Ptmp::EPtmpEncryption encryption,
		Ptmp::EPtmpCompression compression,
		Ptmp::EPtmpAuthentication authen ):m_callResult(),m_ipcFwState(0)
{
	m_ipcClientEng= new IPCClientEngine(this);
	m_eventHandler= new EventHandler(this);

	m_ipcClientEng->setNegoParams(encoding,encryption,compression,authen);
}


std::string IPCFrameWork::getVersion()
{
	if(Network::getFwVersion()==IPC_FW_VERSION)
		if(AppWindow::getFwVersion()==IPC_FW_VERSION)
			if(AclStatement::getFwVersion()==IPC_FW_VERSION)
				return IPC_FW_VERSION ;

	std::string errMsg="getVersion call failed :";
	errMsg.append("IPCFramwWork");
	errMsg.append(":");
	errMsg.append("Version Mismatch. Check versions of Network,AppWindow and AclStatement");
	throw IpcFwException(errMsg);
}
std::string IPCFrameWork::getBuildInfo()
{
	if(Network::getFwBuildInfo()==IPC_FW_BUILD_STR)
		if(AppWindow::getFwBuildInfo()==IPC_FW_BUILD_STR)
			if(AclStatement::getFwBuildInfo()==IPC_FW_BUILD_STR)
				return IPC_FW_BUILD_STR ;
	
	std::string errMsg="getBuildInfo call failed :";
	errMsg.append("IPCFramwWork");
	errMsg.append(":");
	errMsg.append("BuildInfo Mismatch. Check BuildInfo of Network,AppWindow and AclStatement");
	throw IpcFwException(errMsg);
}


int IPCFrameWork::startFrameWork(std::string serverAddress , int portNumber )
{
	fwDebug("Version:"+QString::fromStdString(IPCFrameWork::getVersion()));
	fwDebug("BuildInfo:"+QString::fromStdString(IPCFrameWork::getBuildInfo()));

	IPCFrameWork::getVersion();//for validating the version are correct 
	IPCFrameWork::getBuildInfo();//for validating the build info are correct.

	m_ipcClientEng->setServerInfo(serverAddress,portNumber);
	m_ipcClientEng->start();

	this->m_ipcCallSyncSema.acquire(1);
	if(m_ipcFwState==1)// if fw is connected
		return 0;
	else
		return -1;
	
}




void IPCFrameWork::setUserInfo(std::string userName, std::string password)
{
	m_ipcClientEng->setUserInfo(userName,password);
}

bool IPCFrameWork::sendSubscribeForEvents(std::string className,QUuid objectUuid,std::string eventName)
{
	Ipc::CIpcEvntSubsMsg subMsg(className, objectUuid, eventName, true);
	return this->m_ipcClientEng->sendMsg(subMsg);
}
bool  IPCFrameWork::sendUnSubscribeForEvents(std::string className,QUuid objectUuid,std::string eventName)
{
	Ipc::CIpcEvntSubsMsg subMsg(className, objectUuid, eventName, false);
	return this->m_ipcClientEng->sendMsg(subMsg);
}

CallResult & IPCFrameWork::makeIPCCall(CPtmpBuffer * ptmpBuffer)
{
	this->m_currentCallId=rand();
	this->m_ipcClientEng->makeIPCCall(m_currentCallId,ptmpBuffer);

	//qDebug("\n=================\n");
	//QByteArray array = ptmpBuffer->getRawBuffer();
	//array.replace('\0', ",");
	//qDebug("Sent: "+array);
	//qDebug("\n=================\n");
	
	this->m_ipcCallSyncSema.acquire(1);
	return m_callResult;
}

int IPCFrameWork::setCallResult(CPtmpMsg * ptmpMsg)
{
	if(ptmpMsg->getType() ==CIpcMsg::eIpcReturnValueMsg)
	{
		fwDebug("eIpcReturnValueMsg");
		CIpcRetValMsg * retValMsg=dynamic_cast<CIpcRetValMsg*>(ptmpMsg);

		//qDebug("\n=============\n");
		QByteArray array = retValMsg->getBuffer().getRawBuffer();
		array.replace('\0', ",");
		fwDebug("\nReceived: "+array);
		//qDebug("\n=============\n");

		if(m_currentCallId!=retValMsg->getCallId())
		{
			fwDebug("CallId does not match. current Id:"+QString::number(m_currentCallId)+" received Id:"+QString::number(retValMsg->getCallId()));
			m_callResult.errClassName="";
			m_callResult.callStatus=false;
			m_callResult.errInfo="CallId does not match";
			this->m_ipcCallSyncSema.release(1);
			return -1;
		}else
		{
			m_callResult.callStatus=true;
			
			m_callResult.callId=retValMsg->getCallId();
			CPtmpBuffer  retBuf=retValMsg->getBuffer();
			m_callResult.returnDataBuffer=retBuf;
			this->m_ipcCallSyncSema.release(1);
			return 1;
		}
	}else
	if(ptmpMsg->getType()==CIpcMsg::eIpcReturnErrMsg)
	{
		fwDebug("eIpcReturnErrMsg");
		CIpcRetErrMsg * retErrMsg=dynamic_cast<CIpcRetErrMsg*>(ptmpMsg);
		if(m_currentCallId!=retErrMsg->getCallId())
		{
			fwDebug("CallId does not matchcurrent:"+QString::number(m_currentCallId)+" received:"+QString::number(retErrMsg->getCallId()));
			m_callResult.errClassName="";
			m_callResult.callStatus=false;
			m_callResult.errInfo="CallId does not match";

			this->m_ipcCallSyncSema.release(1);
			return -1;
		}else
		{
			
			m_callResult.callStatus=false;
			m_callResult.errClassName=retErrMsg->getClassName();
			m_callResult.errInfo=retErrMsg->getErrorInfo();

			this->m_ipcCallSyncSema.release(1);
			return 1;
		}

	}
	return 0;
}
CallResult IPCFrameWork::getLastCallResult()
{
	return m_callResult;
}

Network* IPCFrameWork::network()
{
	CPtmpBuffer localBuf;
	std::string callName= "network";
	localBuf.write(callName);
	localBuf.writeTypeValue(eVoid);
	Network *networkObj=new Network(this,localBuf);
    return networkObj;
}
AppWindow* IPCFrameWork::appWindow()
{
	CPtmpBuffer localBuf;
	std::string callName= "appWindow";
	localBuf.write(callName);
	localBuf.writeTypeValue(eVoid);
	AppWindow *appWindowObj=new AppWindow(this,localBuf);
    return appWindowObj;
}

MultiUserManager* IPCFrameWork::multiUserManager()
{
	CPtmpBuffer localBuf;
	std::string callName= "multiUserManager";
	localBuf.write(callName);
	localBuf.writeTypeValue(eVoid);
	MultiUserManager *multiUserManagerObj=new MultiUserManager(this,localBuf);
    return multiUserManagerObj;
}

IpcManager* IPCFrameWork::ipcManager()
{
	CPtmpBuffer localBuf;
	std::string callName= "ipcManager";
	localBuf.write(callName);
	localBuf.writeTypeValue(eVoid);
	IpcManager *ipcManagerObj=new IpcManager(this,localBuf);
    return ipcManagerObj;
}
CommandLog* IPCFrameWork::commandLog()
{
	CPtmpBuffer localBuf;
	std::string callName= "commandLog";
	localBuf.write(callName);
	localBuf.writeTypeValue(eVoid);
	CommandLog *commandLogObj=new CommandLog(this,localBuf);
    return commandLogObj;
}


#endif