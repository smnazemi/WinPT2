//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 RSSwitch.cpp 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:50 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#include "RSSwitch.h"

void RSSwitch::setVisible(bool bVisible)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="setVisible";
	newBuf->write(callName);
	newBuf->write(eBool);

	newBuf->write(bVisible);

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
void RSSwitch::setWidgetVisible(std::string widgetName,bool bVisible)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="setWidgetVisible";
	newBuf->write(callName);
	newBuf->write(eString);

	newBuf->write(widgetName);

	newBuf->write(eBool);

	newBuf->write(bVisible);

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
void RSSwitch::setDisabled(bool bDisable)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="setDisabled";
	newBuf->write(callName);
	newBuf->write(eBool);

	newBuf->write(bDisable);

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
void RSSwitch::setWidgetDisable(std::string widgetName,bool bDisable)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="setWidgetDisable";
	newBuf->write(callName);
	newBuf->write(eString);

	newBuf->write(widgetName);

	newBuf->write(eBool);

	newBuf->write(bDisable);

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
void RSSwitch::showRealtimeMode()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="showRealtimeMode";
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
void RSSwitch::showSimulationMode()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="showSimulationMode";
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

//Event Related functions 
void RSSwitch::event(Ipc::CIpcEventMsg eventMsg)
{
	if(eventMsg.getEventName()=="modeSwitched")
	{
		//Need to check the encoding the CEP has chosen and read the text/binary params buffer.
		CPtmpBuffer *buf=&eventMsg.textParams();
		buf->readInt();//skip the type of value
		bool isRealtime=buf->readBool();
		m_eventsFunctor->modeSwitched(isRealtime);
	}
}

void  RSSwitch::setEventCallBack(RSSwitchEvents* eventFunctor)
{
	m_eventsFunctor=eventFunctor;
}

bool  RSSwitch::subscribeEvent(std::string eventName)
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
bool  RSSwitch::unSubscribeEvent(std::string eventName)
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

