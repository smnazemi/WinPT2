//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 Network.cpp 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:47 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#include "Network.h"

Device Network::getDevice(QString deviceName)
{
	std::string callName= "getDevice";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eQString);
	buf->write(deviceName);

	buf->write(eVoid);

	Device deviceObj(m_ipcFramework,*buf);

	return deviceObj;
}

CiscoDevice Network::getCiscoDevice(QString deviceName)
{
	std::string callName= "getDevice";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eQString);
	buf->write(deviceName);

	buf->write(eVoid);

	CiscoDevice deviceObj(m_ipcFramework,*buf);

	return deviceObj;
}

Device Network::getDeviceAt(int index)
{
	std::string callName= "getDeviceAt";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eInt);
	buf->write(index);

	buf->write(eVoid);

	Device deviceObj(m_ipcFramework,*buf);

	return deviceObj;
}
int Network::getDeviceCount()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getDeviceCount";
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
