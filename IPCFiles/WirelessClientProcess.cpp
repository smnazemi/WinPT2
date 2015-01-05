//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 WirelessClientProcess.cpp 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:49 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#include "WirelessClientProcess.h"

bool WirelessClientProcess::addProfile(std::string name,std::string ssid,int netType,CMacAddress  macAddress,int authType,std::string wepKey,bool bDHCPOn,CIpAddress ipAddress,CIpAddress subnet,CIpAddress gateway,CIpAddress DNS)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="addProfile";
	newBuf->write(callName);
	newBuf->write(eString);

	newBuf->write(name);

	newBuf->write(eString);

	newBuf->write(ssid);

	newBuf->write(eInt);
	newBuf->write(netType);

	newBuf->write(eMacAddress);

	newBuf->write(macAddress);

	newBuf->write(eInt);
	newBuf->write(authType);

	newBuf->write(eString);

	newBuf->write(wepKey);

	newBuf->write(eBool);

	newBuf->write(bDHCPOn);

	newBuf->write(eIpAddress);

	newBuf->write(ipAddress);

	newBuf->write(eIpAddress);

	newBuf->write(subnet);

	newBuf->write(eIpAddress);

	newBuf->write(gateway);

	newBuf->write(eIpAddress);

	newBuf->write(DNS);

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
bool WirelessClientProcess::deleteProfile(std::string name)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="deleteProfile";
	newBuf->write(callName);
	newBuf->write(eString);

	newBuf->write(name);

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
WirelessProfile WirelessClientProcess::getProfile(std::string name)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getProfile";
	newBuf->write(callName);
	newBuf->write(eString);

	newBuf->write(name);

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
		WirelessProfile returnInfo(&(callResult.returnDataBuffer));
		return returnInfo;
	}
}
int WirelessClientProcess::getProfileCount()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getProfileCount";
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
WirelessProfile WirelessClientProcess::getProfileAt(int index)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getProfileAt";
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
		WirelessProfile returnInfo(&(callResult.returnDataBuffer));
		return returnInfo;
	}
}
WirelessProfile WirelessClientProcess::getCurrentProfile()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getCurrentProfile";
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
		callResult.returnDataBuffer.flushRead();
		WirelessProfile returnInfo(&(callResult.returnDataBuffer));
		return returnInfo;
	}
}
bool WirelessClientProcess::setCurrentProfile(std::string name,std::string ssid,int netType,CMacAddress  macAddress,int authType,std::string wepKey,bool bDHCPOn,CIpAddress ipAddress,CIpAddress subnet,CIpAddress gateway,CIpAddress DNS)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="setCurrentProfile";
	newBuf->write(callName);
	newBuf->write(eString);

	newBuf->write(name);

	newBuf->write(eString);

	newBuf->write(ssid);

	newBuf->write(eInt);
	newBuf->write(netType);

	newBuf->write(eMacAddress);

	newBuf->write(macAddress);

	newBuf->write(eInt);
	newBuf->write(authType);

	newBuf->write(eString);

	newBuf->write(wepKey);

	newBuf->write(eBool);

	newBuf->write(bDHCPOn);

	newBuf->write(eIpAddress);

	newBuf->write(ipAddress);

	newBuf->write(eIpAddress);

	newBuf->write(subnet);

	newBuf->write(eIpAddress);

	newBuf->write(gateway);

	newBuf->write(eIpAddress);

	newBuf->write(DNS);

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
int WirelessClientProcess::getCurrentNetworkCount()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getCurrentNetworkCount";
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
WirelessProfile WirelessClientProcess::getCurrentNetworkAt(int index)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getCurrentNetworkAt";
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
		WirelessProfile returnInfo(&(callResult.returnDataBuffer));
		return returnInfo;
	}
}
CMacAddress  WirelessClientProcess::getCurrentApMac()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getCurrentApMac";
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
		CMacAddress  returnInfo=callResult.returnDataBuffer.readMacAddress();
		return returnInfo;
	}
}
