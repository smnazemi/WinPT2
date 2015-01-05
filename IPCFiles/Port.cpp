//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 Port.cpp 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:47 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#include "Port.h"

std::string Port::getName()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getName";
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
		std::string returnInfo=callResult.returnDataBuffer.readString();
		return returnInfo;
	}
}
int Port::getType()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getType";
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
void Port::setDescription(std::string description)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="setDescription";
	newBuf->write(callName);
	newBuf->write(eString);

	newBuf->write(description);

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
std::string Port::getDescription()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getDescription";
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
		std::string returnInfo=callResult.returnDataBuffer.readString();
		return returnInfo;
	}
}
void Port::setPower(bool bOn)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="setPower";
	newBuf->write(callName);
	newBuf->write(eBool);

	newBuf->write(bOn);

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
bool Port::getPower()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getPower";
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
void Port::setBandwidth(int bandwidth)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="setBandwidth";
	newBuf->write(callName);
	newBuf->write(eInt);

	newBuf->write(bandwidth);

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
int Port::getBandwidth()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getBandwidth";
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
void Port::setDuplex(bool bAuto)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="setDuplex";
	newBuf->write(callName);
	newBuf->write(eBool);

	newBuf->write(bAuto);

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
bool Port::getDuplex()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getDuplex";
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
void Port::setMacAddress(CMacAddress  macAddress)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="setMacAddress";
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
CMacAddress  Port::getMacAddress()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getMacAddress";
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
CMacAddress  Port::getBia()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getBia";
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
void Port::setClockRate(int clockrate)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="setClockRate";
	newBuf->write(callName);
	newBuf->write(eInt);

	newBuf->write(clockrate);

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
int Port::getClockRate()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getClockRate";
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
Link Port::getLink()
{
	std::string callName= "getLink";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	Link linkObj(m_ipcFramework,*buf);

	return linkObj;
}

int Port::getConnectionType()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getConnectionType";
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
Process* Port::getAreaId()
{
	std::string callName= "getAreaId";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	Process* processObj = new Process(m_ipcFramework,*buf);

	return processObj;
}
Process* Port::setDefaultPassiveInt()
{
	std::string callName= "setDefaultPassiveInt";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	Process* processObj = new Process(m_ipcFramework,*buf);

	return processObj;
}

//Event Related functions 
void Port::event(Ipc::CIpcEventMsg eventMsg)
{
	if(eventMsg.getEventName()=="powerChanged")
	{
		//Need to check the encoding the CEP has chosen and read the text/binary params buffer.
		CPtmpBuffer *buf=&eventMsg.textParams();
		buf->readInt();//skip the type of value
		bool on=buf->readBool();
		m_eventsFunctor->powerChanged(on);
	}
	if(eventMsg.getEventName()=="macChanged")
	{
		//Need to check the encoding the CEP has chosen and read the text/binary params buffer.
		CPtmpBuffer *buf=&eventMsg.textParams();
		buf->readInt();//skip the type of value
		CMacAddress  newMac=buf->readMacAddress();
		buf->readInt();//skip the type of value
		CMacAddress  oldMac=buf->readMacAddress();
		m_eventsFunctor->macChanged(newMac,oldMac);
	}
}

void  Port::setEventCallBack(PortEvents* eventFunctor)
{
	m_eventsFunctor=eventFunctor;
}

bool  Port::subscribeEvent(std::string eventName)
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
bool  Port::unSubscribeEvent(std::string eventName)
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

