//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 WirelessRouter.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:49 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_WIRELESSROUTER_H
#define IPC_FW_WIRELESSROUTER_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "Router.h"
#include "NatConfigEntry.h"
#include "NatConfigEntry.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class WirelessRouter : public Router
{
public :
	WirelessRouter()
	{	
	}	
	WirelessRouter(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="WirelessRouter";
	}
	~WirelessRouter()
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

	void setDefaultGateway(CIpAddress gateway);
	void setInternetConnectionType(int type);
	int getInternetConnectionType();
	CIpAddress getDefaultGateway();
	void setRemoteManagementEnable(bool bEnable);
	bool isRemoteManagementEnable();
	void addNatEntry(std::string name,int extPort,int intPort,int protoType,CIpAddress ipAddress,bool bEnable);
	void removeNatEntry(std::string name,int extPort,int intPort,int protoType,CIpAddress ipAddress,bool bEnable);
	void removeAllNatEntries();
	int  getNatEntryCount();
	NatConfigEntry getNatEntryAt(int index);
	std::vector<NatConfigEntry> getNatEntries();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------WirelessRouter.hEnds -------------//