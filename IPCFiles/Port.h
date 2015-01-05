//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 Port.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:47 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_PORT_H
#define IPC_FW_PORT_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"
#include "Link.h"
#include "Process.h"
// Don't include cable.h

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;

class PortEvents
{
public:
	virtual void powerChanged(bool on)=0;
	virtual void macChanged(CMacAddress  newMac,CMacAddress  oldMac)=0;
};



class Port : public IpcBase
{
private:
	PortEvents *m_eventsFunctor;
public :
	Port()
	{	
	}	
	Port(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="Port";
		m_eventsFunctor=NULL;
	}
	~Port()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:47 pm";
	}

	std::string getName();
	int getType();
	void setDescription(std::string description);
	std::string getDescription();
	void setPower(bool bOn);
	bool getPower();
	void setBandwidth(int bandwidth);
	int getBandwidth();
	void setDuplex(bool bAuto);
	bool getDuplex();
	void setMacAddress(CMacAddress  macAddress);
	CMacAddress  getMacAddress();
	CMacAddress  getBia();
	void setClockRate(int clockrate);
	int getClockRate();
	Link getLink();
	//Cable getCableType();
	int getConnectionType();
	Process* getAreaId();
	Process* setDefaultPassiveInt();

	//Event Related functions 

	virtual void event(Ipc::CIpcEventMsg eventMsg);

	bool  Port::subscribeEvent(std::string eventName);
	bool  Port::unSubscribeEvent(std::string eventName);
	void  Port::setEventCallBack(PortEvents* eventFunctor);
};
#endif

//-----------Port.hEnds -------------//