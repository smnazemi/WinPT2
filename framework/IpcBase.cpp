//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	IpcBase.cpp  
	Author:		Ajan U. Nair 
	Date:		16-Jul-2008   
	Revision:	1.0           
	Description:
		Implementation of IpcBase class which is derived by all the 
		IPC classes. This file holds the implementation of common functions 
		for all IPC classes.
		
*/

#include "IpcBase.h"

std::string IpcBase::getIpcCallStr()
{
	if(m_ptmpBuffer.size()==0)
	{
		std::string nullStr;
		return nullStr;
	}
	QByteArray qbA=m_ptmpBuffer.getRawBuffer();
	QString retStr(qbA.replace('\0',','));
	return retStr.toStdString();
}
IpcBase::~IpcBase()
{
	if(m_ipcFramework!=NULL)
		m_ipcFramework->m_eventHandler->removeFromSubscriptionMap(this);
}

QUuid IpcBase::getObjectUuid()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);

	std::string callName="getObjectUuid";
	newBuf->write(callName);
	newBuf->writeTypeValue(eVoid);

	CallResult callResult=m_ipcFramework->makeIPCCall(newBuf);
	
	if(!callResult.callStatus)
	{
		// error on call
		std::string errMsg="IPC call failed :";
		errMsg.append(callResult.errClassName);
		errMsg.append(":");
		errMsg.append(callResult.errInfo);
		throw IpcFwException(errMsg);
	}else
	{
		callResult.returnDataBuffer.readInt();
		return callResult.returnDataBuffer.readUuid();
	}
	return NULL;
}
std::string IpcBase::getClassName()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);

	std::string callName="getClassName";
	newBuf->write(callName);
	newBuf->writeTypeValue(eVoid);

	CallResult callResult=m_ipcFramework->makeIPCCall(newBuf);
	
	if(!callResult.callStatus)
	{
		// error on call
		std::string errMsg="IPC call failed :";
		errMsg.append(callResult.errClassName);
		errMsg.append(":");
		errMsg.append(callResult.errInfo);
		throw IpcFwException(errMsg);
	}else
	{
		callResult.returnDataBuffer.readInt();
		return callResult.returnDataBuffer.readString();
	}
	return NULL;
}
bool IpcBase::registerObjectEvent(std::string evnt)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);

	std::string callName="registerObjectEvent";
	newBuf->write(callName);
	newBuf->write(eString);
	newBuf->write(evnt);
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
		return callResult.returnDataBuffer.readBool();
	}
	return NULL;

}
void IpcBase::unregisterObjectEvent(std::string event)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);

	std::string callName="unregisterObjectEvent";
	newBuf->write(callName);
	newBuf->write(eString);
	newBuf->write(event);
	newBuf->writeTypeValue(eVoid);

	CallResult callResult=m_ipcFramework->makeIPCCall(newBuf);
	
	if(!callResult.callStatus)
	{
		// error on call
		std::string errMsg="IPC call failed :";
		errMsg.append(callResult.errClassName);
		errMsg.append(":");
		errMsg.append(callResult.errInfo);
		throw IpcFwException(errMsg);
	}else
	{
		callResult.returnDataBuffer.readInt();
		return;
	}
	return ;
}