//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 SwitchPort.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:48 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_SWITCHPORT_H
#define IPC_FW_SWITCHPORT_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "Port.h"
#include "PortSecurity.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class SwitchPort : public Port
{
public :
	SwitchPort()
	{	
	}	
	SwitchPort(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="SwitchPort";
	}
	~SwitchPort()
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

	void setAccessPort(bool bAccessPort);
	bool isAccessPort();
	void setAccessVlan(int vlan);
	int getAccessVlan();
	void addTrunkVlans(int start,int end);
	void removeTrunkVlans(int start,int end);
	void setCdpEnable(bool bCDPEnable);
	bool isCdpEnable();
	void setNativeVlanId(int vlanID);
	int getNativeVlanId();
	void setVoipVlanId(int vlanID);
	int getVoipVlanId();
	void setNonegotiateFlag(bool bFlag);
	bool isNonegotiate();
	void setAdminOpMode(int type);
	int getAdminOpMode();
	void setAdminModeToNoneDefault(bool bNoneDefault);
	bool isAdminModeSet();
	PortSecurity getPortSecurity();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------SwitchPort.hEnds -------------//