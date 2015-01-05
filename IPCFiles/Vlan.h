//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 Vlan.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:49 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_VLAN_H
#define IPC_FW_VLAN_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"
#include "MacTable.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class Vlan : public IpcBase
{
public :
	Vlan()
	{	
	}	
	Vlan(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="Vlan";
	}
	~Vlan()
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

	std::string getName();
	MacTable getMacTable();
	bool isDefault();
	int getVlanNumber();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------Vlan.hEnds -------------//