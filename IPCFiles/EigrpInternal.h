//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 EigrpInternal.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:45 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_EIGRPINTERNAL_H
#define IPC_FW_EIGRPINTERNAL_H

#include "../framework/IPCFrameWork.h"

using namespace std;



class EigrpInternal : public IpcBase
{
private:
	CIpAddress m_network;
	char m_prefixLength;
	CIpAddress m_nextHop;
	int m_delay;
	int m_bandwidth;
	int m_mtu;
	char m_hopCount;
	char m_reliability;
	char m_load;
public:
	//Constructors and Distructor
	EigrpInternal()
	{	
	}	
	EigrpInternal(CPtmpBuffer  *buf)
	{	
		m_className="EigrpInternal";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_network=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_prefixLength=buf->readByte();

		buf->readInt();//skip the type of data
		m_nextHop=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_delay=buf->readInt();

		buf->readInt();//skip the type of data
		m_bandwidth=buf->readInt();

		buf->readInt();//skip the type of data
		m_mtu=buf->readInt();

		buf->readInt();//skip the type of data
		m_hopCount=buf->readByte();

		buf->readInt();//skip the type of data
		m_reliability=buf->readByte();

		buf->readInt();//skip the type of data
		m_load=buf->readByte();
	}
	~EigrpInternal()
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


	inline char getprefixLength()
	{
		return m_prefixLength;
	}
	inline void setprefixLength(char valueToSet)
	{
		m_prefixLength= valueToSet;
		return;
	}


	inline CIpAddress getnextHop()
	{
		return m_nextHop;
	}
	inline void setnextHop(CIpAddress valueToSet)
	{
		m_nextHop= valueToSet;
		return;
	}


	inline int getdelay()
	{
		return m_delay;
	}
	inline void setdelay(int valueToSet)
	{
		m_delay= valueToSet;
		return;
	}


	inline int getbandwidth()
	{
		return m_bandwidth;
	}
	inline void setbandwidth(int valueToSet)
	{
		m_bandwidth= valueToSet;
		return;
	}


	inline int getmtu()
	{
		return m_mtu;
	}
	inline void setmtu(int valueToSet)
	{
		m_mtu= valueToSet;
		return;
	}


	inline char gethopCount()
	{
		return m_hopCount;
	}
	inline void sethopCount(char valueToSet)
	{
		m_hopCount= valueToSet;
		return;
	}


	inline char getreliability()
	{
		return m_reliability;
	}
	inline void setreliability(char valueToSet)
	{
		m_reliability= valueToSet;
		return;
	}


	inline char getload()
	{
		return m_load;
	}
	inline void setload(char valueToSet)
	{
		m_load= valueToSet;
		return;
	}


};
#endif
//-----data class file : EigrpInternal.h --end----
