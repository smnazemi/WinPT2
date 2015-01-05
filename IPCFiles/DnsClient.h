//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 DnsClient.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:45 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_DNSCLIENT_H
#define IPC_FW_DNSCLIENT_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "Process.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class DnsClient : public Process
{
public :
	DnsClient()
	{	
	}	
	DnsClient(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="DnsClient";
	}
	~DnsClient()
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
	void removeIp(std::string hostname,CIpAddress ipAddress);
	bool isValidName(std::string hostname);
	void setServerIp(CIpAddress ipAddress);
	CIpAddress getServerIp();
	void setEnabled(bool bEnable);
	bool isEnabled();
	int getStrToIpCount();
	std::string getHostAt(int index);
	bool isHostNameExisted(std::string hostname);
	bool isIpExisted(std::string hostname,CIpAddress ipAddress);
	std::vector<CIpAddress> getIpOfHost(std::string hostname);
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------DnsClient.hEnds -------------//