//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 OspfArea.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:47 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_OSPFAREA_H
#define IPC_FW_OSPFAREA_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"
#include "OspfNeighborTable.h"
#include "OspfDatabase.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class OspfArea : public IpcBase
{
public :
	OspfArea()
	{	
	}	
	OspfArea(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="OspfArea";
	}
	~OspfArea()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:47 pm";
	}

	CIpAddress getAreaId();
	void setAuthentication(int type);
	int getAuthentication();
	int getConfiguredPortCount();
	int getConfiguredNetworkCount();
	std::pair<CIpAddress,CIpAddress> getConfiguredNetworkAt(int index);
	OspfNeighborTable getNeighborTable(std::string portName);
	OspfDatabase getDatabase();
	int getFloodLength(std::string portName);
	int getLastFloodLength(std::string portName);
	int getLastFloodTime(std::string portName);
	int getMaxFloodLength(std::string portName);
	int getMaxFloodTime(std::string portName);
	int getSpfCount();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------OspfArea.hEnds -------------//