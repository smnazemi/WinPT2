//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 Cloud.cpp 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:44 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#include "Cloud.h"

bool Cloud::addPhoneConnection(std::string number,std::string portName)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="addPhoneConnection";
	newBuf->write(callName);
	newBuf->write(eString);

	newBuf->write(number);

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
void Cloud::removePhoneConnection(std::string number)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="removePhoneConnection";
	newBuf->write(callName);
	newBuf->write(eString);

	newBuf->write(number);

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
bool Cloud::addActivePhoneConnection(std::string portName1,std::string portName2)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="addActivePhoneConnection";
	newBuf->write(callName);
	newBuf->write(eString);

	newBuf->write(portName1);

	newBuf->write(eString);

	newBuf->write(portName2);

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
bool Cloud::removeActivePhoneConnection(std::string portName1,std::string portName2)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="removeActivePhoneConnection";
	newBuf->write(callName);
	newBuf->write(eString);

	newBuf->write(portName1);

	newBuf->write(eString);

	newBuf->write(portName2);

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
bool Cloud::addSubLinkConnection(std::string portName1,std::string portName2)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="addSubLinkConnection";
	newBuf->write(callName);
	newBuf->write(eString);

	newBuf->write(portName1);

	newBuf->write(eString);

	newBuf->write(portName2);

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
bool Cloud::removeSubLinkConnection(std::string subLink)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="removeSubLinkConnection";
	newBuf->write(callName);
	newBuf->write(eString);

	newBuf->write(subLink);

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
bool Cloud::addSignaling(std::string portName,bool bDSL)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="addSignaling";
	newBuf->write(callName);
	newBuf->write(eString);

	newBuf->write(portName);

	newBuf->write(eBool);

	newBuf->write(bDSL);

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
bool Cloud::removeSignaling(std::string portName)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="removeSignaling";
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
bool Cloud::setDslSignaling(std::string portName,bool bDSL)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="setDslSignaling";
	newBuf->write(callName);
	newBuf->write(eString);

	newBuf->write(portName);

	newBuf->write(eBool);

	newBuf->write(bDSL);

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
bool Cloud::addPortConnection(std::string portName1,std::string portName2)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="addPortConnection";
	newBuf->write(callName);
	newBuf->write(eString);

	newBuf->write(portName1);

	newBuf->write(eString);

	newBuf->write(portName2);

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
bool Cloud::removePortConnection(std::string portName)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="removePortConnection";
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
bool Cloud::removeAllPortConnection(std::string portName)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="removeAllPortConnection";
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
bool Cloud::addHostMacMapping(CMacAddress  macAddress,std::string portName)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="addHostMacMapping";
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
void Cloud::removeHostMacMapping(CMacAddress  macAddress)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="removeHostMacMapping";
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
		return ;
	}
}
bool Cloud::setDslConnection(std::string portName,bool bDSL)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="setDslConnection";
	newBuf->write(callName);
	newBuf->write(eString);

	newBuf->write(portName);

	newBuf->write(eBool);

	newBuf->write(bDSL);

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
