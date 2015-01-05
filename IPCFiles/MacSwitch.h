//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 MacSwitch.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:46 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_MACSWITCH_H
#define IPC_FW_MACSWITCH_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"
#include "StaticMac.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class MacSwitch : public IpcBase
{
public :
	MacSwitch()
	{	
	}	
	MacSwitch(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="MacSwitch";
	}
	~MacSwitch()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:46 pm";
	}

	bool addStaticMac(CMacAddress  macAddress,int vlanNumber,std::string portName);
	bool removeStaticMac(CMacAddress  macAddress,int vlanNumber,std::string portName);
	int getStaticMacCount();
	StaticMac getGlobalMacAt(int index);
	bool portExistedInStatic(std::string portName);
	bool isEntryExisted(CMacAddress  macAddress,int vlanNumber,std::string portName);
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------MacSwitch.hEnds -------------//