//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 LoopbackManager.cpp 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:46 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#include "LoopbackManager.h"

RouterPort LoopbackManager::getLoopback(int loopbackNumber)
{
	std::string callName= "getLoopback";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eInt);
	buf->write(loopbackNumber);

	buf->write(eVoid);

	RouterPort routerportObj(m_ipcFramework,*buf);

	return routerportObj;
}
RouterPort LoopbackManager::getLoopbackAt(int index)
{
	std::string callName= "getLoopbackAt";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eInt);
	buf->write(index);

	buf->write(eVoid);

	RouterPort routerportObj(m_ipcFramework,*buf);

	return routerportObj;
}
bool LoopbackManager::addLoopback(int loopbackNumber)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="addLoopback";
	newBuf->write(callName);
	newBuf->write(eInt);

	newBuf->write(loopbackNumber);

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
bool LoopbackManager::removeLoopback(int loopbackNumber)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="removeLoopback";
	newBuf->write(callName);
	newBuf->write(eInt);

	newBuf->write(loopbackNumber);

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
int LoopbackManager::getLoopbackCount()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getLoopbackCount";
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
		int returnInfo=callResult.returnDataBuffer.readInt();
		return returnInfo;
	}
}
