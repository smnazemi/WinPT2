//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 EigrpSummaryAddress.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:45 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_EIGRPSUMMARYADDRESS_H
#define IPC_FW_EIGRPSUMMARYADDRESS_H

#include "../framework/IPCFrameWork.h"

using namespace std;



class EigrpSummaryAddress : public IpcBase
{
private:
	CIpAddress m_network;
	CIpAddress m_subnetMask;
	int m_adminDistance;
public:
	//Constructors and Distructor
	EigrpSummaryAddress()
	{	
	}	
	EigrpSummaryAddress(CPtmpBuffer  *buf)
	{	
		m_className="EigrpSummaryAddress";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_network=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_subnetMask=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_adminDistance=buf->readInt();
	}
	~EigrpSummaryAddress()
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

	virtual void event(Ipc::CIpcEventMsg eventMsg){}

	//get and set functions

	inline CIpAddress getnetwork()
	{
		return m_network;
	}
	inline void setnetwork(CIpAddress valueToSet)
	{
		m_network= valueToSet;
		return;
	}


	inline CIpAddress getsubnetMask()
	{
		return m_subnetMask;
	}
	inline void setsubnetMask(CIpAddress valueToSet)
	{
		m_subnetMask= valueToSet;
		return;
	}


	inline int getadminDistance()
	{
		return m_adminDistance;
	}
	inline void setadminDistance(int valueToSet)
	{
		m_adminDistance= valueToSet;
		return;
	}


};
#endif
//-----data class file : EigrpSummaryAddress.h --end----
