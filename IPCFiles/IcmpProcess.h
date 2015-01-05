//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 IcmpProcess.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:46 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_ICMPPROCESS_H
#define IPC_FW_ICMPPROCESS_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "Process.h"
#include "PingProcess.h"
#include "TraceRouteProcess.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class IcmpProcess : public Process
{
public :
	IcmpProcess()
	{	
	}	
	IcmpProcess(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="IcmpProcess";
	}
	~IcmpProcess()
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

	short startPing(CIpAddress dstIpAddress,int repeatTime,int timeout,int waitTime,std::string portName);
	PingProcess getPingProcess(short id);
	short startTraceRoute(CIpAddress dstIpAddress,int probeCount,int minTTL,int maxTTL,int timeout,int waitTime,std::string portName);
	TraceRouteProcess getTraceRouteProcess(short id);
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------IcmpProcess.hEnds -------------//