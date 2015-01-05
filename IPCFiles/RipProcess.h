//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 RipProcess.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:48 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_RIPPROCESS_H
#define IPC_FW_RIPPROCESS_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "RoutingProtocol.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class RipProcess : public RoutingProtocol
{
public :
	RipProcess()
	{	
	}	
	RipProcess(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="RipProcess";
	}
	~RipProcess()
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

	void setUpdateTimerInterval(long updateTimerInterval);
	void setAllRipTimerIntervals(long updateTimerInterval,long invalidTimerInterval,long holddownInterval,long flushInterval);
	void setTimersBasicFlag(bool isEnabled);
	void setAutoSummaryFlag(bool bAutoSummary);
	void setDefaultPassiveInterface(bool bDefaultPassiveInterface);
	void setAdminDistance(int adminDistance);
	void addRipConfigNetwork(CIpAddress networkAddress);
	void removeRipConfigNetwork(CIpAddress networkAddress);
	void addRipConfigNeighbor(CIpAddress neighborAddress);
	void removeRipConfigNeighbor(CIpAddress neighborAddress);
	void setDebugRipDatabaseFlag(bool bDebugRipDatabase);
	void setDebugRipFlag(bool bFlag);
	void setDebugRipEventFlag(bool bDebugRipEventFlag);
	void setDebugRipTriggerFlag(bool bDebugRipTriggerFlag);
	void setDefaultInformationOriginate(bool bOriginate);
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------RipProcess.hEnds -------------//