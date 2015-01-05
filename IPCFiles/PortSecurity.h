//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 PortSecurity.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:48 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_PORTSECURITY_H
#define IPC_FW_PORTSECURITY_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;

class PortSecurityEvents
{
public:
	virtual void getLastSourceMacVlan()=0;
};



class PortSecurity : public IpcBase
{
private:
	PortSecurityEvents *m_eventsFunctor;
public :
	PortSecurity()
	{	
	}	
	PortSecurity(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="PortSecurity";
		m_eventsFunctor=NULL;
	}
	~PortSecurity()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:48 pm";
	}

	bool isEnabled();
	void setEnabled(bool bEnable);
	bool setMaxMacNumber(int max);
	int getMaxMacNumber();
	int getTotalMac();
	int getViolationCount();
	void setViolationMode(int type);
	bool addSecureMacEntry(CMacAddress  macAddress,bool isSticky);
	bool removeSecureMacEntry(CMacAddress  macAddress);
	int getSecureMacCount();
	bool secureMacExist(CMacAddress  macAddress);
	std::string getPort();
	bool isStickyOn();
	void setStickyflag(bool isSticky);

	//Event Related functions 

	virtual void event(Ipc::CIpcEventMsg eventMsg);

	bool  PortSecurity::subscribeEvent(std::string eventName);
	bool  PortSecurity::unSubscribeEvent(std::string eventName);
	void  PortSecurity::setEventCallBack(PortSecurityEvents* eventFunctor);
};
#endif

//-----------PortSecurity.hEnds -------------//