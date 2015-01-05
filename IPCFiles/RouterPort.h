//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 RouterPort.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:48 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_ROUTERPORT_H
#define IPC_FW_ROUTERPORT_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "HostPort.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class RouterPort : public HostPort
{
public :
	RouterPort()
	{	
	}	
	RouterPort(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="RouterPort";
	}
	~RouterPort()
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

	void setAclInID(std::string aclId);
	void setAclOutID(std::string aclId);
	std::string getAclInID();
	std::string getAclOutID();
	void setNatMode(int type);
	int getNatMode();
	void setCdpEnable(bool bEnable);
	bool isCdpEnable();
	void setRipPassive(bool bRipPassive);
	bool isRipPassive();
	void setRipSplitHorizon(bool bEnable);
	bool isRipSplitHorizon();
	void setRipV2Broadcast(bool bEnable);
	bool isRipV2Broadcast();
	void setDefEigrpInt(short interval);
	short getDefEigrpInt();
	void setDefEigrpHoldTime(short holdtime);
	short getDefEigrpHoldTime();
	void addEntryEigrpPassive(int as,bool bPassive);
	void removeEntryEigrpPassive(int as);
	void addEntryOspfPassive(int id,bool bPassive);
	void removeEntryOspfPassive(int id);
	int getOspfAuthType();
	void setOspfAuthKey(std::string key);
	std::string getOspfAuthKey();
	bool addOspfMd5Key(short keyId,std::string key);
	void removeOspfMd5Key(short keyId);
	void setOspfCost(short cost);
	short getOspfCost();
	void setOspfDeadInterval(short interval);
	short getOspfDeadInterval();
	void setOspfHelloInterval(short interval);
	short getOspfHelloInterval();
	void setOspfPriority(short usPriority);
	short getOspfPriority();
	void setDelay(int delay);
	int getDelay();
	void setBandwidthInfo(int bandwidth);
	int getBandwidthInfo();
	void setMtu(int mtu);
	int getMtu();
	void setReliability(char reliability);
	char getReliability();
	void setLoad(char load);
	char getLoad();
	void resetBandwidth();
	void resetDelay();
	void setIntForAs(short as,short interval);
	short getIntOfAs(short as);
	void setHoldTimeForAs(short as,short holdtime);
	short getHoldTimeOfAs(short as);
	bool addSummaryAddress(short as,CIpAddress networkAddress,CIpAddress mask,int adminDistance);
	bool removeSummaryAddress(short as,CIpAddress networkAddress,CIpAddress mask,int adminDistance);
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------RouterPort.hEnds -------------//