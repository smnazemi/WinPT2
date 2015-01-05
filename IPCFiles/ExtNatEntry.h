//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 ExtNatEntry.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:45 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_EXTNATENTRY_H
#define IPC_FW_EXTNATENTRY_H

#include "../framework/IPCFrameWork.h"

#include "NatEntry.h"

using namespace std;



class ExtNatEntry : public NatEntry
{
private:
	int m_protocol;
	int m_insideLocalPort;
	int m_insideGlobalPort;
	int m_outsideLocalPort;
	int m_outsideGlobalPort;
public:
	//Constructors and Distructor
	ExtNatEntry()
	{	
	}	
	ExtNatEntry(CPtmpBuffer  *buf)
	{	
		m_className="ExtNatEntry";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_protocol=buf->readInt();

		buf->readInt();//skip the type of data
		m_insideLocalPort=buf->readInt();

		buf->readInt();//skip the type of data
		m_insideGlobalPort=buf->readInt();

		buf->readInt();//skip the type of data
		m_outsideLocalPort=buf->readInt();

		buf->readInt();//skip the type of data
		m_outsideGlobalPort=buf->readInt();
	}
	~ExtNatEntry()
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

	inline int getprotocol()
	{
		return m_protocol;
	}
	inline void setprotocol(int valueToSet)
	{
		m_protocol= valueToSet;
		return;
	}


	inline int getinsideLocalPort()
	{
		return m_insideLocalPort;
	}
	inline void setinsideLocalPort(int valueToSet)
	{
		m_insideLocalPort= valueToSet;
		return;
	}


	inline int getinsideGlobalPort()
	{
		return m_insideGlobalPort;
	}
	inline void setinsideGlobalPort(int valueToSet)
	{
		m_insideGlobalPort= valueToSet;
		return;
	}


	inline int getoutsideLocalPort()
	{
		return m_outsideLocalPort;
	}
	inline void setoutsideLocalPort(int valueToSet)
	{
		m_outsideLocalPort= valueToSet;
		return;
	}


	inline int getoutsideGlobalPort()
	{
		return m_outsideGlobalPort;
	}
	inline void setoutsideGlobalPort(int valueToSet)
	{
		m_outsideGlobalPort= valueToSet;
		return;
	}


};
#endif
//-----data class file : ExtNatEntry.h --end----
