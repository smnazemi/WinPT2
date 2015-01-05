//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 WirelessCommon.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:49 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_WIRELESSCOMMON_H
#define IPC_FW_WIRELESSCOMMON_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "Process.h"
#include "Port.h"
#include "WEPProcess.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class WirelessCommon : public Process
{
public :
	WirelessCommon()
	{	
	}	
	WirelessCommon(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="WirelessCommon";
	}
	~WirelessCommon()
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

	void setAuthenType(int authType);
	int getAuthenType();
	void setSsid(std::string ssid);
	std::string getSsid();
	void setNetworkType(int netType);
	int getNetworkType();
	bool setPort(std::string portName);
	Port getPort();
	WEPProcess* getCurrentNetworkAt();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------WirelessCommon.hEnds -------------//