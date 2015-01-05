//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 HostPort.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:46 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_HOSTPORT_H
#define IPC_FW_HOSTPORT_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "Port.h"
#include "Ipv6AddressConfig.h"
#include "Ipv6AddressConfig.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;

class HostPortEvents
{
public:
	virtual void ipChanged(CIpAddress newIp,CIpAddress newMask,CIpAddress oldIp,CIpAddress oldMask)=0;
	virtual void ipv6LinkLocalChanged(CIpAddress  newIp,CIpAddress  oldIp)=0;
	virtual void ipv6AddressAdded(CIpAddress  ipAddress,int prefix,int type)=0;
	virtual void ipv6AddressRemoved(CIpAddress  ipAddress,int prefix,int type)=0;
};



class HostPort : public Port
{
private:
	HostPortEvents *m_eventsFunctor;
public :
	HostPort()
	{	
	}	
	HostPort(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="HostPort";
		m_eventsFunctor=NULL;
	}
	~HostPort()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:46 pm";
	}

	void setIpSubnetMask(CIpAddress newIpAddress,CIpAddress newMask);
	void setDefaultArpTimeout();
	void setDhcpClientFlag(bool bFlag);
	bool isDhcpClientOn();
	CIpAddress getIpAddress();
	CIpAddress getSubnetMask();
	void setIpv6Enabled(bool bEnable);
	bool isIpv6Enabled();
	void setIpv6AddressAutoConfig(bool bAutoConfig);
	bool isIpv6AddressAutoConfig();
	void setIpv6LinkLocal(CIpAddress  ipAddress);
	CIpAddress  getIpv6LinkLocal();
	bool addIpv6Address(CIpAddress  ipAddress,int prefix,int type,bool bAllowDup);
	bool removeIpv6Address(CIpAddress  ipAddress,int prefix,int type);
	void removeAllIpv6Addresses();
	bool hasIpv6Address(CIpAddress  ipAddress);
	Ipv6AddressConfig getIpv6Address(CIpAddress  ipAddress);
	std::vector<Ipv6AddressConfig> getIpv6Addresses();
	bool isInIpv6Multicast(CIpAddress  ipAddress);
	std::vector<CIpAddress > getIpv6Multicast();

	//Event Related functions 

	virtual void event(Ipc::CIpcEventMsg eventMsg);

	bool  HostPort::subscribeEvent(std::string eventName);
	bool  HostPort::unSubscribeEvent(std::string eventName);
	void  HostPort::setEventCallBack(HostPortEvents* eventFunctor);
};
#endif

//-----------HostPort.hEnds -------------//