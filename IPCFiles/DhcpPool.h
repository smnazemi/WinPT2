//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 DhcpPool.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:44 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_DHCPPOOL_H
#define IPC_FW_DHCPPOOL_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"
#include "DhcpPoolLease.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class DhcpPool : public IpcBase
{
public :
	DhcpPool()
	{	
	}	
	DhcpPool(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="DhcpPool";
	}
	~DhcpPool()
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

	std::string getDhcpPoolName();
	void setNetworkAddress(CIpAddress ipAddress);
	CIpAddress getNetworkAddress();
	void setSubnetMask(CIpAddress ipAddress);
	CIpAddress getSubnetMask();
	void setDefaultRouter(CIpAddress ipAddress);
	CIpAddress getDefaultRouter();
	DhcpPoolLease* getPort(int index);
	void setStartIp(CIpAddress ipAddress);
	void setEndIp(CIpAddress ipAddress);
	CIpAddress getStartIp();
	CIpAddress getEndIp();
	void setDnsServerIp(CIpAddress ipAddress);
	CIpAddress getDnsServerIp();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------DhcpPool.hEnds -------------//