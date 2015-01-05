//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 OspfProcess.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:47 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_OSPFPROCESS_H
#define IPC_FW_OSPFPROCESS_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "RoutingProtocol.h"
#include "OspfArea.h"
#include "OspfArea.h"
#include "OspfAreaNetwork.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class OspfProcess : public RoutingProtocol
{
public :
	OspfProcess()
	{	
	}	
	OspfProcess(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="OspfProcess";
	}
	~OspfProcess()
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

	int getProcessId();
	CIpAddress getRouterId();
	int getAreaCount();
	OspfArea getAreaAt(int index);
	OspfArea getArea(CIpAddress ipAddressArea);
	void removeArea(CIpAddress ipAddressArea);
	bool setAreaAuthentication(CIpAddress ipAddressArea,int type);
	int getAreaAuthenticationCount();
	std::pair<int,CIpAddress> getAreaAuthenticationAt(int index);
	int getAreaAuthentication(CIpAddress ipAddressArea);
	void setDefaultInfoOrig(int type);
	int getDefaultInfoOrig();
	void setLogAdjacencyChanges(int type);
	int getLogAdjacencyChanges();
	void addConfiguredNetwork(CIpAddress ipAddressArea,CIpAddress ipAddress,CIpAddress mask);
	void removeConfigureNetwork(CIpAddress ipAddressArea,CIpAddress ipAddress,CIpAddress mask);
	int getConfNetworkCount();
	OspfAreaNetwork getConfNetworkAt(int index);
	CIpAddress getAreaId(CIpAddress ipAddress,CIpAddress mask);
	void setDefaultPassiveInt(bool b);
	bool getDefaultPassiveInt();
	void setPassiveInt(std::string portname,bool bPassive);
	void clearAllRoutes();
	void clearRoute(CIpAddress networkId,CIpAddress mask);
	void generateOspfRoutes(CIpAddress ipAddressAreaID);
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------OspfProcess.hEnds -------------//