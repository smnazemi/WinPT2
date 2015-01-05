//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 VlanManager.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:49 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_VLANMANAGER_H
#define IPC_FW_VLANMANAGER_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "Process.h"
#include "Vlan.h"
#include "Vlan.h"
#include "Vlan.h"
#include "RouterPort.h"
#include "RouterPort.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class VlanManager : public Process
{
public :
	VlanManager()
	{	
	}	
	VlanManager(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="VlanManager";
	}
	~VlanManager()
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

	Vlan getVlan(int vlanID);
	Vlan getVlanAt(int index);
	bool addVlan(int vlandID,std::string vlanName);
	bool removeVlan(int vlandID);
	int getVlanCount();
	int getMaxVlans();
	Vlan getVlanByName(std::string name);
	bool changeVlanName(int vlanID,std::string name);
	bool addVlanInt(int vlanID);
	bool removeVlanInt(int vlanID);
	RouterPort getVlanInt(int vlanID);
	RouterPort getVlanIntAt(int index);
	int getVlanIntCount( );
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------VlanManager.hEnds -------------//