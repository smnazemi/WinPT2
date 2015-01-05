//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 LogicalWorkspace.cpp 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:49 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#include "LogicalWorkspace.h"

int LogicalWorkspace::getState()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getState";
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
int LogicalWorkspace::getComponentItemsCount()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getComponentItemsCount";
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
ComponentItem LogicalWorkspace::getComponentItem(QString deviceName)
{
	std::string callName= "getComponentItem";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eQString);
	buf->write(deviceName);

	buf->write(eVoid);

	ComponentItem componentitemObj(m_ipcFramework,*buf);

	return componentitemObj;
}
QString LogicalWorkspace::addDevice(int type,std::string model)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="addDevice";
	newBuf->write(callName);
	newBuf->write(eInt);
	newBuf->write(type);

	newBuf->write(eString);

	newBuf->write(model);

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
		QString returnInfo=callResult.returnDataBuffer.readQString();
		return returnInfo;
	}
}
bool LogicalWorkspace::removeDevice(QString deviceName)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="removeDevice";
	newBuf->write(callName);
	newBuf->write(eQString);

	newBuf->write(deviceName);

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
QString LogicalWorkspace::addRemoteNetwork()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="addRemoteNetwork";
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
		callResult.returnDataBuffer.readQString();
		QString returnInfo=callResult.returnDataBuffer.readQString();
		return returnInfo;
	}
	
}
int LogicalWorkspace::getConnection(QString deviceName, std::string portName)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName= "getConnType";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eQString);
	buf->write(deviceName);
	newBuf->write(eString);
	newBuf->write(portName);
	buf->write(eVoid);

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
		
bool LogicalWorkspace::createLink(QString deviceName1,std::string portName1,QString deviceName2,std::string portName2,int connType)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="createLink";
	newBuf->write(callName);
	newBuf->write(eQString);

	newBuf->write(deviceName1);

	newBuf->write(eString);

	newBuf->write(portName1);

	newBuf->write(eQString);

	newBuf->write(deviceName2);

	newBuf->write(eString);

	newBuf->write(portName2);

	newBuf->write(eInt);
	newBuf->write(connType);

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

//Event Related functions 
void LogicalWorkspace::event(Ipc::CIpcEventMsg eventMsg)
{
	if(eventMsg.getEventName()=="deviceAdded")
	{
		//Need to check the encoding the CEP has chosen and read the text/binary params buffer.
		CPtmpBuffer *buf=&eventMsg.textParams();
		buf->readInt();//skip the type of value
		QString name=buf->readQString();
		m_eventsFunctor->deviceAdded(name);
	}
	if(eventMsg.getEventName()=="deviceRemoved")
	{
		//Need to check the encoding the CEP has chosen and read the text/binary params buffer.
		CPtmpBuffer *buf=&eventMsg.textParams();
		buf->readInt();//skip the type of value
		QString name=buf->readQString();
		m_eventsFunctor->deviceRemoved(name);
	}
	if(eventMsg.getEventName()=="linkCreated")
	{
		//Need to check the encoding the CEP has chosen and read the text/binary params buffer.
		CPtmpBuffer *buf=&eventMsg.textParams();
		buf->readInt();//skip the type of value
		QString deviceName1=buf->readQString();
		buf->readInt();//skip the type of value
		std::string portName1=buf->readString();
		buf->readInt();//skip the type of value
		QString deviceName2=buf->readQString();
		buf->readInt();//skip the type of value
		std::string portName2=buf->readString();
		buf->readInt();//skip the type of value
		int connType=buf->readInt();
		m_eventsFunctor->linkCreated(deviceName1,portName1,deviceName2,portName2,connType);
	}
}

void  LogicalWorkspace::setEventCallBack(LogicalWorkspaceEvents* eventFunctor)
{
	m_eventsFunctor=eventFunctor;
}

bool  LogicalWorkspace::subscribeEvent(std::string eventName)
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
bool  LogicalWorkspace::unSubscribeEvent(std::string eventName)
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

