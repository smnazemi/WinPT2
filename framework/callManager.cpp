//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	callManager.cpp   
	Author:		Ajan U. Nair 
	Date:		09-Jul-2008   
	Revision:	1.0           
	Description:
		This file holds the callManager class implementation
		This class holds all the PTMP connection related call backs 
		implementations

*/

#include "callManager.h"


#include "../IPC/CIpcCallMsg.h"
#include "../IPC/CIpcRetValMsg.h"

#include "../PTMP/CDataMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

using namespace Ptmp;
using namespace Ipc;
using namespace std;

callManager::callManager(){

}

callManager::~callManager(){

}

callManager::callManager(IPCClientEngine * ipcClientEngInstance)
{
	m_ipcClientEngObj=ipcClientEngInstance;
}

QString callManager::getPassword(CPtmpConnection * ptmpConnection,const QString &userName)
{
	fwDebug("callManager : getPassword");
	return QString::fromStdString(m_ipcClientEngObj->m_password);
}

void callManager::onData(CPtmpConnection * ptmpConnection, CPtmpMsg * ptmpMsg)
{
	fwDebug("\ncallManager : onData");
	CDataMsg* dataMsg = dynamic_cast<CDataMsg*>(ptmpMsg);
	
	if (dataMsg != NULL)
	{
		QByteArray array = dataMsg->getBuffer().getRawBuffer();
		array.replace('\0', ",");
		fwDebug("Data Received: "+ QString(array));
	}

	EPtmpMsgType msgType= ptmpMsg->getType();

	if((msgType==CIpcMsg::eIpcReturnValueMsg)||(msgType==CIpcMsg::eIpcReturnErrMsg))
	{
		m_ipcClientEngObj->m_ipcFwInstance->setCallResult(ptmpMsg);
	}else
	if(msgType==CIpcMsg::eIpcEventMsg)
	{
		fwDebug("---eIpcEventMsg---");
		Ipc::CIpcEventMsg * eventMsg=dynamic_cast<Ipc::CIpcEventMsg*>(ptmpMsg);

		//CPtmpBuffer buf=eventMsg->textParams();
		//QByteArray array = buf.getRawBuffer();
		//array.replace('\0', ",");
		//qDebug("\nReceived:-");
		//qDebug(array);

		m_ipcClientEngObj->m_ipcFwInstance->m_eventHandler->fireEvent(*eventMsg);
	}else
	{
		fwDebug("UN IDENTIFIED MSG");
	}
}

void callManager::onDisconnect(CPtmpConnection * ptmpConnection)
{
	fwDebug("callManager : onDisconnect");
}

void callManager::onError(CPtmpConnection * ptmpConnection, EPtmpConnectionErrorType errorType)
{
	fwDebug("callManager : onError");
	m_ipcClientEngObj->m_ipcFwInstance->setIpcFwState(0);// state 0 = error.
	m_ipcClientEngObj->m_ipcFwInstance->m_ipcCallSyncSema.release(1);
}


void callManager::onEstablished(CPtmpConnection * ptmpConnection)
{
	fwDebug("callManager : onEstablished");
	m_ipcClientEngObj->m_ipcFwInstance->setIpcFwState(1);// state 1 = connected
	m_ipcClientEngObj->m_ipcFwInstance->m_ipcCallSyncSema.release(1);
}