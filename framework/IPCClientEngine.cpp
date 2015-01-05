//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	IPCClientEngine.cpp  
	Author:		Ajan U. Nair 
	Date:		09-Jul-2008   
	Revision:	1.0           
	Description:
		Implementation of IPCClientEngine class.
		This class has got a separate thread and an event loop, which 
		enables the framework to listen for communication from PT without
		blocking the user thread.
		
*/
#include "IPCClientEngine.h"



#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

using namespace Ptmp;
using namespace Ipc;
using namespace std;


IPCClientEngine::IPCClientEngine(IPCFrameWork* fwInstance)
{
	m_ipcFwInstance=fwInstance;
}

IPCClientEngine::~IPCClientEngine()
{
}

void IPCClientEngine::run()
{

	fwDebug("Thread run");
	startEngine();
	m_PtmpConnection->setDefaultUserName(QString::fromStdString(m_userName));
	bool bConnectSent=m_PtmpConnection->connect(QString::fromStdString(this->m_serverAddress), this->m_serverPort);

	if(bConnectSent)
		fwDebug("CONNECT SENT");
	else
		fwDebug("CONNECT Failed");

	this->exec();

	fwDebug("run:-exit Event Loop");
	return;
}



void  IPCClientEngine::setNegoParams(Ptmp::EPtmpBufferEncoding encoding,
		Ptmp::EPtmpEncryption encryption,
		Ptmp::EPtmpCompression compression,
		Ptmp::EPtmpAuthentication authen )
{
	m_NegotiationParams.m_encoding=encoding;
	m_NegotiationParams.m_encryption=encryption;
	m_NegotiationParams.m_compression=compression;
	m_NegotiationParams.m_authentication=authen;
}

void IPCClientEngine::startEngine()
{
	m_PtmpConnection = new CPtmpConnection(&m_NegotiationParams);

	m_frameWorkCallManager  =new callManager(this);

	TPtmpConnectionCallBack<callManager>* callback = new TPtmpConnectionCallBack<callManager>(
		m_PtmpConnection,
		m_frameWorkCallManager,
		NULL,
		&callManager::getPassword,
		NULL,
		&callManager::onEstablished,
		&callManager::onDisconnect,
		&callManager::onError,
		&callManager::onData);

	m_PtmpConnection->registerCallBack(callback);

}
void IPCClientEngine::setServerInfo(std::string serverAddress, int portNumber)
{
	m_serverAddress=serverAddress;
	m_serverPort=portNumber;
}

std::string IPCClientEngine::getPassword()
{
	
	return m_password ;
}


void IPCClientEngine::setUserInfo(std::string userName, std::string password)
{
	m_password=password;
	m_userName=userName;
}
bool  IPCClientEngine::sendMsg(Ipc::CIpcEvntSubsMsg msg)
{
	return m_PtmpConnection->send(&msg);
}
/**
 * the call id is returned. 
 */
int IPCClientEngine::makeIPCCall(int callId,CPtmpBuffer * ptmpBuffer)
{
	CIpcCallMsg msg;
	msg.setCallId(callId);
	CPtmpBuffer& buffer = msg.getBuffer();
	buffer=*ptmpBuffer;

	if (m_PtmpConnection!=NULL)
	{
		m_PtmpConnection->send(&msg);
	}
	else
	{
		fwDebug("IPCCall not dispatched- connection failure!!");
		return -1;
	}

	CPtmpBuffer tempBuf ;
	msg.serialize(tempBuf);
	QByteArray array= tempBuf.getRawBuffer();
	array.replace('\0', ",");
	fwDebug("\nSent:-"+array);
	
	return msg.getCallId();
}
