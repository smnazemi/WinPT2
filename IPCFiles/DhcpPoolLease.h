//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 DhcpPoolLease.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:44 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_DHCPPOOLLEASE_H
#define IPC_FW_DHCPPOOLLEASE_H

#include "../framework/IPCFrameWork.h"

using namespace std;



class DhcpPoolLease : public IpcBase
{
private:
	CIpAddress m_ipAddress;
	CMacAddress  m_macAddress;
	long m_leaseTime;
	std::string m_port;
public:
	//Constructors and Distructor
	DhcpPoolLease()
	{	
	}	
	DhcpPoolLease(CPtmpBuffer  *buf)
	{	
		m_className="DhcpPoolLease";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_ipAddress=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_macAddress=buf->readMacAddress();

		buf->readInt();//skip the type of data
		m_leaseTime=buf->readLong();

		buf->readInt();//skip the type of data
		m_port=buf->readString();
	}
	~DhcpPoolLease()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:44 pm";
	}

	virtual void event(Ipc::CIpcEventMsg eventMsg){}

	//get and set functions

	inline CIpAddress getipAddress()
	{
		return m_ipAddress;
	}
	inline void setipAddress(CIpAddress valueToSet)
	{
		m_ipAddress= valueToSet;
		return;
	}


	inline CMacAddress  getmacAddress()
	{
		return m_macAddress;
	}
	inline void setmacAddress(CMacAddress  valueToSet)
	{
		m_macAddress= valueToSet;
		return;
	}


	inline long getleaseTime()
	{
		return m_leaseTime;
	}
	inline void setleaseTime(long valueToSet)
	{
		m_leaseTime= valueToSet;
		return;
	}


	inline std::string getport()
	{
		return m_port;
	}
	inline void setport(std::string valueToSet)
	{
		m_port= valueToSet;
		return;
	}


};
#endif
//-----data class file : DhcpPoolLease.h --end----
