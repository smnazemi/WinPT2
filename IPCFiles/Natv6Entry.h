//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 Natv6Entry.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:46 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_NATV6ENTRY_H
#define IPC_FW_NATV6ENTRY_H

#include "../framework/IPCFrameWork.h"

using namespace std;



class Natv6Entry : public IpcBase
{
private:
	CIpAddress  m_v6SrcIp;
	CIpAddress  m_v6DstIp;
	CIpAddress  m_v4SrcIp;
	CIpAddress  m_v4DstIp;
public:
	//Constructors and Distructor
	Natv6Entry()
	{	
	}	
	Natv6Entry(CPtmpBuffer  *buf)
	{	
		m_className="Natv6Entry";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_v6SrcIp=buf->readIpv6Address();

		buf->readInt();//skip the type of data
		m_v6DstIp=buf->readIpv6Address();

		buf->readInt();//skip the type of data
		m_v4SrcIp=buf->readIpv6Address();

		buf->readInt();//skip the type of data
		m_v4DstIp=buf->readIpv6Address();
	}
	~Natv6Entry()
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

	virtual void event(Ipc::CIpcEventMsg eventMsg){}

	//get and set functions

	inline CIpAddress  getv6SrcIp()
	{
		return m_v6SrcIp;
	}
	inline void setv6SrcIp(CIpAddress  valueToSet)
	{
		m_v6SrcIp= valueToSet;
		return;
	}


	inline CIpAddress  getv6DstIp()
	{
		return m_v6DstIp;
	}
	inline void setv6DstIp(CIpAddress  valueToSet)
	{
		m_v6DstIp= valueToSet;
		return;
	}


	inline CIpAddress  getv4SrcIp()
	{
		return m_v4SrcIp;
	}
	inline void setv4SrcIp(CIpAddress  valueToSet)
	{
		m_v4SrcIp= valueToSet;
		return;
	}


	inline CIpAddress  getv4DstIp()
	{
		return m_v4DstIp;
	}
	inline void setv4DstIp(CIpAddress  valueToSet)
	{
		m_v4DstIp= valueToSet;
		return;
	}


};
#endif
//-----data class file : Natv6Entry.h --end----
