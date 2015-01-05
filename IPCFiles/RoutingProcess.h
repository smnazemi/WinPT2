//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 RoutingProcess.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:48 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_ROUTINGPROCESS_H
#define IPC_FW_ROUTINGPROCESS_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "Process.h"
#include "StaticRoute.h"
#include "RoutingTable.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class RoutingProcess : public Process
{
public :
	RoutingProcess()
	{	
	}	
	RoutingProcess(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="RoutingProcess";
	}
	~RoutingProcess()
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

	void clearAllRoutes();
	void clearRoute(CIpAddress networkId,CIpAddress mask);
	bool addStaticRoute(CIpAddress ipAddress,CIpAddress subnetMask,CIpAddress nextHop,std::string portName,int adminDistance);
	bool removeStaticRoute(CIpAddress ipAddress,CIpAddress subnetMask,CIpAddress nextHop,std::string portName,int adminDistance);
	int getStaticRouteCount();
	StaticRoute getStaticRouteAt(int index);
	RoutingTable getRoutingTable();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------RoutingProcess.hEnds -------------//