//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 DhcpServerProcess.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:44 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_DHCPSERVERPROCESS_H
#define IPC_FW_DHCPSERVERPROCESS_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "Process.h"
#include "DhcpPool.h"
#include "DhcpPool.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class DhcpServerProcess : public Process
{
public :
	DhcpServerProcess()
	{	
	}	
	DhcpServerProcess(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="DhcpServerProcess";
	}
	~DhcpServerProcess()
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

	void addExcludedAddress(CIpAddress startIp,CIpAddress endIp);
	void removeExcludedAddress(CIpAddress startIp,CIpAddress endIp);
	int getExcludedAddressCount();
	std::pair<CIpAddress,CIpAddress>  getExcludedAddressAt(int index);
	void addPool(std::string poolName);
	DhcpPool getPool(std::string poolName);
	void removePool(std::string poolName);
	int getPoolCount();
	DhcpPool getPoolAt(int index);
	bool isEnable();
	void setEnable(bool bEnable);
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------DhcpServerProcess.hEnds -------------//