//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 WirelessClientProcess.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:49 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_WIRELESSCLIENTPROCESS_H
#define IPC_FW_WIRELESSCLIENTPROCESS_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "WirelessCommon.h"
#include "WirelessProfile.h"
#include "WirelessProfile.h"
#include "WirelessProfile.h"
#include "WirelessProfile.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class WirelessClientProcess : public WirelessCommon
{
public :
	WirelessClientProcess()
	{	
	}	
	WirelessClientProcess(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="WirelessClientProcess";
	}
	~WirelessClientProcess()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:49 pm";
	}

	bool addProfile(std::string name,std::string ssid,int netType,CMacAddress  macAddress,int authType,std::string wepKey,bool bDHCPOn,CIpAddress ipAddress,CIpAddress subnet,CIpAddress gateway,CIpAddress DNS);
	bool deleteProfile(std::string name);
	WirelessProfile getProfile(std::string name);
	int getProfileCount();
	WirelessProfile getProfileAt(int index);
	WirelessProfile getCurrentProfile();
	bool setCurrentProfile(std::string name,std::string ssid,int netType,CMacAddress  macAddress,int authType,std::string wepKey,bool bDHCPOn,CIpAddress ipAddress,CIpAddress subnet,CIpAddress gateway,CIpAddress DNS);
	int getCurrentNetworkCount();
	WirelessProfile getCurrentNetworkAt(int index);
	CMacAddress  getCurrentApMac();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------WirelessClientProcess.hEnds -------------//