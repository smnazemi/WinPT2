//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 MacTable.cpp 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:46 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#include "MacTable.h"

bool MacTable::addMacEntry(CMacAddress  macAddress,std::string portName)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="addMacEntry";
	newBuf->write(callName);
	newBuf->write(eMacAddress);

	newBuf->write(macAddress);

	newBuf->write(eString);

	newBuf->write(portName);

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
bool MacTable::removeMacEntry(CMacAddress  macAddress,std::string portName)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="removeMacEntry";
	newBuf->write(callName);
	newBuf->write(eMacAddress);

	newBuf->write(macAddress);

	newBuf->write(eString);

	newBuf->write(portName);

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
MacEntry MacTable::getEntryAt(int index)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getEntryAt";
	newBuf->write(callName);
	newBuf->write(eInt);

	newBuf->write(index);

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
		callResult.returnDataBuffer.flushRead();
		MacEntry returnInfo(&(callResult.returnDataBuffer));
		return returnInfo;
	}
}
void MacTable::removeEntryAt(int index)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="removeEntryAt";
	newBuf->write(callName);
	newBuf->write(eInt);

	newBuf->write(index);

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
int MacTable::getEntryCount()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getEntryCount";
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
MacEntry MacTable::getEntryOfMac(CMacAddress  macAddress)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getEntryOfMac";
	newBuf->write(callName);
	newBuf->write(eMacAddress);

	newBuf->write(macAddress);

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
		callResult.returnDataBuffer.flushRead();
		MacEntry returnInfo(&(callResult.returnDataBuffer));
		return returnInfo;
	}
}
void MacTable::clearMacTable()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="clearMacTable";
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
