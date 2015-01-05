//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 NatEntry.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:46 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_NATENTRY_H
#define IPC_FW_NATENTRY_H

#include "../framework/IPCFrameWork.h"

using namespace std;



class NatEntry : public IpcBase
{
private:
	CIpAddress m_insideLocalIp;
	CIpAddress m_insideGlobalIp;
	CIpAddress m_outsideLocalIp;
	CIpAddress m_outsideGlobalIp;
public:
	//Constructors and Distructor
	NatEntry()
	{	
	}	
	NatEntry(CPtmpBuffer  *buf)
	{	
		m_className="NatEntry";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_insideLocalIp=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_insideGlobalIp=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_outsideLocalIp=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_outsideGlobalIp=buf->readIpAddress();
	}
	~NatEntry()
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

	inline CIpAddress getinsideLocalIp()
	{
		return m_insideLocalIp;
	}
	inline void setinsideLocalIp(CIpAddress valueToSet)
	{
		m_insideLocalIp= valueToSet;
		return;
	}


	inline CIpAddress getinsideGlobalIp()
	{
		return m_insideGlobalIp;
	}
	inline void setinsideGlobalIp(CIpAddress valueToSet)
	{
		m_insideGlobalIp= valueToSet;
		return;
	}


	inline CIpAddress getoutsideLocalIp()
	{
		return m_outsideLocalIp;
	}
	inline void setoutsideLocalIp(CIpAddress valueToSet)
	{
		m_outsideLocalIp= valueToSet;
		return;
	}


	inline CIpAddress getoutsideGlobalIp()
	{
		return m_outsideGlobalIp;
	}
	inline void setoutsideGlobalIp(CIpAddress valueToSet)
	{
		m_outsideGlobalIp= valueToSet;
		return;
	}


};
#endif
//-----data class file : NatEntry.h --end----
