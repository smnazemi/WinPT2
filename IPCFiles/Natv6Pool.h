//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 Natv6Pool.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:46 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_NATV6POOL_H
#define IPC_FW_NATV6POOL_H

#include "../framework/IPCFrameWork.h"

using namespace std;



class Natv6Pool : public IpcBase
{
private:
	std::string m_poolName;
	CIpAddress m_startIp;
	CIpAddress m_endIp;
	CIpAddress m_mask;
public:
	//Constructors and Distructor
	Natv6Pool()
	{	
	}	
	Natv6Pool(CPtmpBuffer  *buf)
	{	
		m_className="Natv6Pool";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_poolName=buf->readString();

		buf->readInt();//skip the type of data
		m_startIp=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_endIp=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_mask=buf->readIpAddress();
	}
	~Natv6Pool()
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

	inline std::string getpoolName()
	{
		return m_poolName;
	}
	inline void setpoolName(std::string valueToSet)
	{
		m_poolName= valueToSet;
		return;
	}


	inline CIpAddress getstartIp()
	{
		return m_startIp;
	}
	inline void setstartIp(CIpAddress valueToSet)
	{
		m_startIp= valueToSet;
		return;
	}


	inline CIpAddress getendIp()
	{
		return m_endIp;
	}
	inline void setendIp(CIpAddress valueToSet)
	{
		m_endIp= valueToSet;
		return;
	}


	inline CIpAddress getmask()
	{
		return m_mask;
	}
	inline void setmask(CIpAddress valueToSet)
	{
		m_mask= valueToSet;
		return;
	}


};
#endif
//-----data class file : Natv6Pool.h --end----
