//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 DnsServerProcess.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:45 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_DNSSERVERPROCESS_H
#define IPC_FW_DNSSERVERPROCESS_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "Process.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class DnsServerProcess : public Process
{
public :
	DnsServerProcess()
	{	
	}	
	DnsServerProcess(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="DnsServerProcess";
	}
	~DnsServerProcess()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:45 pm";
	}

	bool addIpAddress(std::string hostname,CIpAddress ipAddress);
	void removeIpAddress(std::string hostname);
	std::pair<std::string,CIpAddress> getEntryAt(int index);
	int getEntryCount();
	bool isValidName(std::string hostname);
	void setEnable(bool bEnable);
	bool isEnabled();
	void setPortNumber(int num);
	int getPortNumber();
	bool isDomainNameExisted(std::string domainName);
	CIpAddress getIpAddOfDomain(std::string domainName);
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------DnsServerProcess.hEnds -------------//