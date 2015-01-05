//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is
//  prohibited unless authorized in writing.
//
//************************************************************************
/*! /file
	File Name:	 RemoteNetwork.cpp
	Author:		 Tony Deng
	Date:		 May 4, 2009  	Time: 10:30:00 am
	Revision:	 1.1
	Description: Hand written, may have errors :-)
*/
#include "RemoteNetwork.h"

bool RemoteNetwork::connect(QString peerAddress, int peerPort, QString userName, QString password)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="connect";
	newBuf->write(callName);
	newBuf->write(eQString);
	newBuf->write(peerAddress);
	newBuf->write(eInt);
	newBuf->write(peerPort);
	newBuf->write(eQString);
	newBuf->write(userName);
	newBuf->write(eQString);
	newBuf->write(password);
	newBuf->writeTypeValue(eVoid);

	CallResult callResult=m_ipcFramework->makeIPCCall(newBuf);
	if(!callResult.callStatus)
	{
		std::string errMsg="IPC call failed :";
		errMsg.append(callResult.errClassName);
		errMsg.append(":");
		errMsg.append(callResult.errInfo);
		throw IpcFwException(errMsg);
	}else
	{
		callResult.returnDataBuffer.readInt();
		bool returnInfo=callResult.returnDataBuffer.readBool();
		return returnInfo;
	}
}
void RemoteNetwork::disconnect()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="disconnect";
	newBuf->write(callName);
	newBuf->writeTypeValue(eVoid);
	CallResult callResult=m_ipcFramework->makeIPCCall(newBuf);
	if(!callResult.callStatus)
	{
		std::string errMsg="IPC call failed :";
		errMsg.append(callResult.errClassName);
		errMsg.append(":");
		errMsg.append(callResult.errInfo);
		throw IpcFwException(errMsg);
	}else
	{
		return ;
	}
}
bool RemoteNetwork::isConnected()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="isConnected";
	newBuf->write(callName);
	newBuf->writeTypeValue(eVoid);
	CallResult callResult=m_ipcFramework->makeIPCCall(newBuf);
	if(!callResult.callStatus)
	{
		std::string errMsg="IPC call failed :";
		errMsg.append(callResult.errClassName);
		errMsg.append(":");
		errMsg.append(callResult.errInfo);
		throw IpcFwException(errMsg);
	}else
	{
		callResult.returnDataBuffer.readInt();
		bool returnInfo=callResult.returnDataBuffer.readBool();
		return returnInfo;
	}
}


//Event Related functions
void RemoteNetwork::event(Ipc::CIpcEventMsg eventMsg)
{
	if(eventMsg.getEventName()=="peerConnected")
	{
		//Need to check the encoding the CEP has chosen and read the text/binary params buffer.
		CPtmpBuffer *buf=&eventMsg.textParams();
		m_eventsFunctor->peerConnected();
	}
	if(eventMsg.getEventName()=="peerDisconnected")
	{
		//Need to check the encoding the CEP has chosen and read the text/binary params buffer.
		CPtmpBuffer *buf=&eventMsg.textParams();
		m_eventsFunctor->peerDisconnected();
	}
}

void  RemoteNetwork::setEventCallBack(RemoteNetworkEvents* eventFunctor)
{
	m_eventsFunctor=eventFunctor;
}

bool  RemoteNetwork::subscribeEvent(std::string eventName)
{
	if(m_eventsFunctor==NULL)
	{
		std::string errString ="eventsFunctor=NULL. Have you called setEventCallBack ?";
		throw  IpcFwException(errString);
	}
	QUuid uuidOfObj;
	try
	{
		uuidOfObj=this->getObjectUuid();
	}catch(IpcFwException e)
	{
		std::string errString ="subscribeEvent(std::string eventName)failed\nreason: getObjectUuid() failed";
		errString.append( e.getErrMsg());
		throw IpcFwException (errString);
	}
	if(m_ipcFramework->m_eventHandler->subscribe(m_className,uuidOfObj.toString().toStdString(),eventName,this))
		return true;
	return false;
}
bool  RemoteNetwork::unSubscribeEvent(std::string eventName)
{
	if(m_eventsFunctor==NULL)
	{
		std::string errString ="eventsFunctor=NULL. Have you called setEventCallBack ?";
		throw  IpcFwException(errString);
	}
	QUuid uuidOfObj;
	try
	{
		uuidOfObj=this->getObjectUuid();
	}catch(IpcFwException e)
	{
		std::string errString ="subscribeEvent(std::string eventName)failed\nreason: getObjectUuid() failed";
		errString.append( e.getErrMsg());
		throw IpcFwException (errString);
	}
	if(m_ipcFramework->m_eventHandler->unSubscribe(m_className,uuidOfObj.toString().toStdString(),eventName,this))
		return true;
	return false;
}

