//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 HostPort.cpp 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:45 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#include "HostPort.h"

void HostPort::setIpSubnetMask(CIpAddress newIpAddress,CIpAddress newMask)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="setIpSubnetMask";
	newBuf->write(callName);
	newBuf->write(eIpAddress);

	newBuf->write(newIpAddress);

	newBuf->write(eIpAddress);

	newBuf->write(newMask);

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
void HostPort::setDefaultArpTimeout()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="setDefaultArpTimeout";
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
void HostPort::setDhcpClientFlag(bool bFlag)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="setDhcpClientFlag";
	newBuf->write(callName);
	newBuf->write(eBool);

	newBuf->write(bFlag);

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
bool HostPort::isDhcpClientOn()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="isDhcpClientOn";
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
CIpAddress HostPort::getIpAddress()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getIpAddress";
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
CIpAddress HostPort::getSubnetMask()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getSubnetMask";
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
void HostPort::setIpv6Enabled(bool bEnable)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="setIpv6Enabled";
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
bool HostPort::isIpv6Enabled()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="isIpv6Enabled";
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
void HostPort::setIpv6AddressAutoConfig(bool bAutoConfig)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="setIpv6AddressAutoConfig";
	newBuf->write(callName);
	newBuf->write(eBool);

	newBuf->write(bAutoConfig);

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
bool HostPort::isIpv6AddressAutoConfig()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="isIpv6AddressAutoConfig";
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
void HostPort::setIpv6LinkLocal(CIpAddress  ipAddress)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="setIpv6LinkLocal";
	newBuf->write(callName);
	newBuf->write(eIpv6Address);

	newBuf->write(ipAddress);

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
CIpAddress  HostPort::getIpv6LinkLocal()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getIpv6LinkLocal";
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
		CIpAddress  returnInfo=callResult.returnDataBuffer.readIpv6Address();
		return returnInfo;
	}
}
bool HostPort::addIpv6Address(CIpAddress  ipAddress,int prefix,int type,bool bAllowDup)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="addIpv6Address";
	newBuf->write(callName);
	newBuf->write(eIpv6Address);

	newBuf->write(ipAddress);

	newBuf->write(eInt);

	newBuf->write(prefix);

	newBuf->write(eInt);
	newBuf->write(type);

	newBuf->write(eBool);

	newBuf->write(bAllowDup);

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
bool HostPort::removeIpv6Address(CIpAddress  ipAddress,int prefix,int type)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="removeIpv6Address";
	newBuf->write(callName);
	newBuf->write(eIpv6Address);

	newBuf->write(ipAddress);

	newBuf->write(eInt);

	newBuf->write(prefix);

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
		callResult.returnDataBuffer.readInt();
		bool returnInfo=callResult.returnDataBuffer.readBool();
		return returnInfo;
	}
}
void HostPort::removeAllIpv6Addresses()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="removeAllIpv6Addresses";
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
bool HostPort::hasIpv6Address(CIpAddress  ipAddress)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="hasIpv6Address";
	newBuf->write(callName);
	newBuf->write(eIpv6Address);

	newBuf->write(ipAddress);

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
Ipv6AddressConfig HostPort::getIpv6Address(CIpAddress  ipAddress)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getIpv6Address";
	newBuf->write(callName);
	newBuf->write(eIpv6Address);

	newBuf->write(ipAddress);

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
		Ipv6AddressConfig returnInfo(&(callResult.returnDataBuffer));
		return returnInfo;
	}
}
std::vector<Ipv6AddressConfig> HostPort::getIpv6Addresses()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getIpv6Addresses";
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
		std::vector<Ipv6AddressConfig> returnInfo;
		{
			callResult.returnDataBuffer.readInt();//skip the type of vect members.
			int sizeOfVect=callResult.returnDataBuffer.readInt();
			for(int index_returnInfo=0;index_returnInfo<sizeOfVect;index_returnInfo++)
			{

				callResult.returnDataBuffer.flushRead();
				Ipv6AddressConfig vectMem0(&(callResult.returnDataBuffer));
				returnInfo.push_back(vectMem0);
			}
		}
		return returnInfo;
	}
}
bool HostPort::isInIpv6Multicast(CIpAddress  ipAddress)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="isInIpv6Multicast";
	newBuf->write(callName);
	newBuf->write(eIpv6Address);

	newBuf->write(ipAddress);

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
std::vector<CIpAddress > HostPort::getIpv6Multicast()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getIpv6Multicast";
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
		std::vector<CIpAddress > returnInfo;
		{
			callResult.returnDataBuffer.readInt();//skip the type of vect members.
			int sizeOfVect=callResult.returnDataBuffer.readInt();
			for(int index_returnInfo=0;index_returnInfo<sizeOfVect;index_returnInfo++)
			{

				CIpAddress  vectMem0=callResult.returnDataBuffer.readIpv6Address();
				returnInfo.push_back(vectMem0);
			}
		}
		return returnInfo;
	}
}

//Event Related functions 
void HostPort::event(Ipc::CIpcEventMsg eventMsg)
{
	if(eventMsg.getEventName()=="ipChanged")
	{
		//Need to check the encoding the CEP has chosen and read the text/binary params buffer.
		CPtmpBuffer *buf=&eventMsg.textParams();
		buf->readInt();//skip the type of value
		CIpAddress newIp=buf->readIpAddress();
		buf->readInt();//skip the type of value
		CIpAddress newMask=buf->readIpAddress();
		buf->readInt();//skip the type of value
		CIpAddress oldIp=buf->readIpAddress();
		buf->readInt();//skip the type of value
		CIpAddress oldMask=buf->readIpAddress();
		m_eventsFunctor->ipChanged(newIp,newMask,oldIp,oldMask);
	}
	if(eventMsg.getEventName()=="ipv6LinkLocalChanged")
	{
		//Need to check the encoding the CEP has chosen and read the text/binary params buffer.
		CPtmpBuffer *buf=&eventMsg.textParams();
		buf->readInt();//skip the type of value
		CIpAddress  newIp=buf->readIpv6Address();
		buf->readInt();//skip the type of value
		CIpAddress  oldIp=buf->readIpv6Address();
		m_eventsFunctor->ipv6LinkLocalChanged(newIp,oldIp);
	}
	if(eventMsg.getEventName()=="ipv6AddressAdded")
	{
		//Need to check the encoding the CEP has chosen and read the text/binary params buffer.
		CPtmpBuffer *buf=&eventMsg.textParams();
		buf->readInt();//skip the type of value
		CIpAddress  ipAddress=buf->readIpv6Address();
		buf->readInt();//skip the type of value
		int prefix=buf->readInt();
		buf->readInt();//skip the type of value
		int type=buf->readInt();
		m_eventsFunctor->ipv6AddressAdded(ipAddress,prefix,type);
	}
	if(eventMsg.getEventName()=="ipv6AddressRemoved")
	{
		//Need to check the encoding the CEP has chosen and read the text/binary params buffer.
		CPtmpBuffer *buf=&eventMsg.textParams();
		buf->readInt();//skip the type of value
		CIpAddress  ipAddress=buf->readIpv6Address();
		buf->readInt();//skip the type of value
		int prefix=buf->readInt();
		buf->readInt();//skip the type of value
		int type=buf->readInt();
		m_eventsFunctor->ipv6AddressRemoved(ipAddress,prefix,type);
	}
}

void  HostPort::setEventCallBack(HostPortEvents* eventFunctor)
{
	m_eventsFunctor=eventFunctor;
}

bool  HostPort::subscribeEvent(std::string eventName)
{
	if(m_eventsFunctor==NULL)
	{
		std::string errString ="eventsFunctor=NULL. Have you called setEventCallBack ?";
		throw  IpcFwException(errString);
	}
	QUuid uuidOfObj;
	try
	{
		uuidOfObj=this->getObjectUuid();
	}catch(IpcFwException e)
	{
		std::string errString ="subscribeEvent(std::string eventName)failed\nreason: getObjectUuid() failed";
		errString.append( e.getErrMsg());
		throw IpcFwException (errString);
	}
	if(m_ipcFramework->m_eventHandler->subscribe(m_className,uuidOfObj.toString().toStdString(),eventName,this))
		return true;
	return false;
}
bool  HostPort::unSubscribeEvent(std::string eventName)
{
	if(m_eventsFunctor==NULL)
	{
		std::string errString ="eventsFunctor=NULL. Have you called setEventCallBack ?";
		throw  IpcFwException(errString);
	}
	QUuid uuidOfObj;
	try
	{
		uuidOfObj=this->getObjectUuid();
	}catch(IpcFwException e)
	{
		std::string errString ="subscribeEvent(std::string eventName)failed\nreason: getObjectUuid() failed";
		errString.append( e.getErrMsg());
		throw IpcFwException (errString);
	}
	if(m_ipcFramework->m_eventHandler->unSubscribe(m_className,uuidOfObj.toString().toStdString(),eventName,this))
		return true;
	return false;
}

