//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 WirelessRouter.cpp 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:49 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#include "WirelessRouter.h"

void WirelessRouter::setDefaultGateway(CIpAddress gateway)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="setDefaultGateway";
	newBuf->write(callName);
	newBuf->write(eIpAddress);

	newBuf->write(gateway);

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
void WirelessRouter::setInternetConnectionType(int type)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="setInternetConnectionType";
	newBuf->write(callName);
	newBuf->write(eInt);
	newBuf->write(type);

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
int WirelessRouter::getInternetConnectionType()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getInternetConnectionType";
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
CIpAddress WirelessRouter::getDefaultGateway()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getDefaultGateway";
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
		CIpAddress returnInfo=callResult.returnDataBuffer.readIpAddress();
		return returnInfo;
	}
}
void WirelessRouter::setRemoteManagementEnable(bool bEnable)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="setRemoteManagementEnable";
	newBuf->write(callName);
	newBuf->write(eBool);

	newBuf->write(bEnable);

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
bool WirelessRouter::isRemoteManagementEnable()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="isRemoteManagementEnable";
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
void WirelessRouter::addNatEntry(std::string name,int extPort,int intPort,int protoType,CIpAddress ipAddress,bool bEnable)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="addNatEntry";
	newBuf->write(callName);
	newBuf->write(eString);

	newBuf->write(name);

	newBuf->write(eInt);

	newBuf->write(extPort);

	newBuf->write(eInt);

	newBuf->write(intPort);

	newBuf->write(eInt);
	newBuf->write(protoType);

	newBuf->write(eIpAddress);

	newBuf->write(ipAddress);

	newBuf->write(eBool);

	newBuf->write(bEnable);

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
void WirelessRouter::removeNatEntry(std::string name,int extPort,int intPort,int protoType,CIpAddress ipAddress,bool bEnable)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="removeNatEntry";
	newBuf->write(callName);
	newBuf->write(eString);

	newBuf->write(name);

	newBuf->write(eInt);

	newBuf->write(extPort);

	newBuf->write(eInt);

	newBuf->write(intPort);

	newBuf->write(eInt);
	newBuf->write(protoType);

	newBuf->write(eIpAddress);

	newBuf->write(ipAddress);

	newBuf->write(eBool);

	newBuf->write(bEnable);

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
void WirelessRouter::removeAllNatEntries()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="removeAllNatEntries";
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
int WirelessRouter:: getNatEntryCount()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName=" getNatEntryCount";
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
NatConfigEntry WirelessRouter::getNatEntryAt(int index)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getNatEntryAt";
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
		NatConfigEntry returnInfo(&(callResult.returnDataBuffer));
		return returnInfo;
	}
}
std::vector<NatConfigEntry> WirelessRouter::getNatEntries()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getNatEntries";
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
		std::vector<NatConfigEntry> returnInfo;
		{
			callResult.returnDataBuffer.readInt();//skip the type of vect members.
			int sizeOfVect=callResult.returnDataBuffer.readInt();
			for(int index_returnInfo=0;index_returnInfo<sizeOfVect;index_returnInfo++)
			{

				callResult.returnDataBuffer.flushRead();
				NatConfigEntry vectMem0(&(callResult.returnDataBuffer));
				returnInfo.push_back(vectMem0);
			}
		}
		return returnInfo;
	}
}
