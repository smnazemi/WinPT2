//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 Device.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:44 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_DEVICE_H
#define IPC_FW_DEVICE_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"
#include "Port.h"
#include "Port.h"
#include "Process.h"
#include "IcmpProcess.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;

class DeviceEvents
{
public:
	virtual void nameChanged(QString newName,QString oldName)=0;
	virtual void powerChanged(bool on)=0;
	virtual void portAdded(std::string portName)=0;
	virtual void portRemoved(std::string portName)=0;
};



class Device : public IpcBase
{
private:
	DeviceEvents *m_eventsFunctor;
public :
	Device()
	{	
	}	
	Device(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="Device";
		m_eventsFunctor=NULL;
	}
	~Device()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:44 pm";
	}

	void setName(QString name);
	QString getName();
	void setPower(bool bOn);
	bool getPower();
	int getType();
	Port getPort(std::string portName);
	int getPortCount();
	Port getPortAt(int index);
	Process getProcess(std::string process);
	IcmpProcess getIcmpProcess(std::string process);
	bool addModule(std::string slot,int type,std::string model);
	bool removeModule(std::string slot);

	//Event Related functions 

	virtual void event(Ipc::CIpcEventMsg eventMsg);

	bool  Device::subscribeEvent(std::string eventName);
	bool  Device::unSubscribeEvent(std::string eventName);
	void  Device::setEventCallBack(DeviceEvents* eventFunctor);
};
#endif

//-----------Device.hEnds -------------//