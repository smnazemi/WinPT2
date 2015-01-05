//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 EigrpProcess.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:45 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_EIGRPPROCESS_H
#define IPC_FW_EIGRPPROCESS_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "RoutingProtocol.h"
#include "EigrpSummaryAddress.h"
#include "EigrpTopologyTable.h"
#include "EigrpNeighborTable.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class EigrpProcess : public RoutingProtocol
{
public :
	EigrpProcess()
	{	
	}	
	EigrpProcess(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="EigrpProcess";
	}
	~EigrpProcess()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:45 pm";
	}

	int getASNumber();
	void setKs(int k1,int k2,int k3,int k4,int k5);
	void setVariance(int variance);
	int getVariance();
	void setAutoSummary(bool bAutoSum);
	bool getAutoSummary();
	void setDefaultPassiveInt(bool bEnable);
	bool getDefaultPassiveInt();
	void setPassiveInt(std::string portName,bool bPassive);
	bool isPassiveInt(std::string portName);
	void setIntAdminDistance(int adminDistance);
	void setExtAdminDistance(int adminDistance);
	void addConfiguredNetwork(CIpAddress ipAddress,CIpAddress mask);
	void removeConfiguredNetwork(CIpAddress ipAddress,CIpAddress mask);
	int getConfiguredNetworkCount();
	bool addSummaryAddress(std::string portName,CIpAddress ipAddress,CIpAddress subnet,int adminDistance);
	bool removeSummaryAddress(std::string portName,CIpAddress ipAddress,CIpAddress subnet,int adminDistance);
	int getSummaryAddressCount(std::string portName);
	EigrpSummaryAddress getSummaryAddressAt(std::string portName,int as,int index);
	EigrpTopologyTable getTopologyTable();
	EigrpNeighborTable getNeighborTable();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------EigrpProcess.hEnds -------------//