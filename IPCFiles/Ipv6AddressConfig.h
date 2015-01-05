//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 Ipv6AddressConfig.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:50 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_IPV6ADDRESSCONFIG_H
#define IPC_FW_IPV6ADDRESSCONFIG_H

#include "../framework/IPCFrameWork.h"

using namespace std;



class Ipv6AddressConfig : public IpcBase
{
private:
	CIpAddress  m_address;
	int m_prefix;
	int m_type;
public:
	//Constructors and Distructor
	Ipv6AddressConfig()
	{	
	}	
	Ipv6AddressConfig(CPtmpBuffer  *buf)
	{	
		m_className="Ipv6AddressConfig";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_address=buf->readIpv6Address();

		buf->readInt();//skip the type of data
		m_prefix=buf->readInt();

		buf->readInt();//skip the type of data
		m_type=buf->readInt();
	}
	~Ipv6AddressConfig()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:50 pm";
	}

	virtual void event(Ipc::CIpcEventMsg eventMsg){}

	//get and set functions

	inline CIpAddress  getaddress()
	{
		return m_address;
	}
	inline void setaddress(CIpAddress  valueToSet)
	{
		m_address= valueToSet;
		return;
	}


	inline int getprefix()
	{
		return m_prefix;
	}
	inline void setprefix(int valueToSet)
	{
		m_prefix= valueToSet;
		return;
	}


	inline int gettype()
	{
		return m_type;
	}
	inline void settype(int valueToSet)
	{
		m_type= valueToSet;
		return;
	}


};
#endif
//-----data class file : Ipv6AddressConfig.h --end----
