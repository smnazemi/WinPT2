//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 DhcpClientProcess.cpp 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:44 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#include "DhcpClientProcess.h"

bool DhcpClientProcess::dhcpRelease(std::string portName)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="dhcpRelease";
	newBuf->write(callName);
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
bool DhcpClientProcess::resetDhcpConfOn(std::string portName)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="resetDhcpConfOn";
	newBuf->write(callName);
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
