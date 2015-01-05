//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 IcmpProcess.cpp 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:46 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#include "IcmpProcess.h"

short IcmpProcess::startPing(CIpAddress dstIpAddress,int repeatTime,int timeout,int waitTime,std::string portName)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="startPing";
	newBuf->write(callName);
	newBuf->write(eIpAddress);

	newBuf->write(dstIpAddress);

	newBuf->write(eInt);

	newBuf->write(repeatTime);

	newBuf->write(eInt);

	newBuf->write(timeout);

	newBuf->write(eInt);

	newBuf->write(waitTime);

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
		short returnInfo=callResult.returnDataBuffer.readShort();
		return returnInfo;
	}
}
PingProcess IcmpProcess::getPingProcess(short id)
{
	std::string callName= "getPingProcess";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eShort);
	buf->write(id);

	buf->write(eVoid);

	PingProcess pingprocessObj(m_ipcFramework,*buf);

	return pingprocessObj;
}
short IcmpProcess::startTraceRoute(CIpAddress dstIpAddress,int probeCount,int minTTL,int maxTTL,int timeout,int waitTime,std::string portName)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="startTraceRoute";
	newBuf->write(callName);
	newBuf->write(eIpAddress);

	newBuf->write(dstIpAddress);

	newBuf->write(eInt);

	newBuf->write(probeCount);

	newBuf->write(eInt);

	newBuf->write(minTTL);

	newBuf->write(eInt);

	newBuf->write(maxTTL);

	newBuf->write(eInt);

	newBuf->write(timeout);

	newBuf->write(eInt);

	newBuf->write(waitTime);

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
		short returnInfo=callResult.returnDataBuffer.readShort();
		return returnInfo;
	}
}
TraceRouteProcess IcmpProcess::getTraceRouteProcess(short id)
{
	std::string callName= "getTraceRouteProcess";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eShort);
	buf->write(id);

	buf->write(eVoid);

	TraceRouteProcess tracerouteprocessObj(m_ipcFramework,*buf);

	return tracerouteprocessObj;
}
