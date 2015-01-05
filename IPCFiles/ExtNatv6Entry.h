//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 ExtNatv6Entry.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:45 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_EXTNATV6ENTRY_H
#define IPC_FW_EXTNATV6ENTRY_H

#include "../framework/IPCFrameWork.h"

#include "Natv6Entry.h"

using namespace std;



class ExtNatv6Entry : public Natv6Entry
{
private:
	int m_protocol;
	int m_v6SrcPort;
	int m_v6DstPort;
	int m_v4SrcPort;
	int m_v4DstPort;
public:
	//Constructors and Distructor
	ExtNatv6Entry()
	{	
	}	
	ExtNatv6Entry(CPtmpBuffer  *buf)
	{	
		m_className="ExtNatv6Entry";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_protocol=buf->readInt();

		buf->readInt();//skip the type of data
		m_v6SrcPort=buf->readInt();

		buf->readInt();//skip the type of data
		m_v6DstPort=buf->readInt();

		buf->readInt();//skip the type of data
		m_v4SrcPort=buf->readInt();

		buf->readInt();//skip the type of data
		m_v4DstPort=buf->readInt();
	}
	~ExtNatv6Entry()
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


	inline int getv6SrcPort()
	{
		return m_v6SrcPort;
	}
	inline void setv6SrcPort(int valueToSet)
	{
		m_v6SrcPort= valueToSet;
		return;
	}


	inline int getv6DstPort()
	{
		return m_v6DstPort;
	}
	inline void setv6DstPort(int valueToSet)
	{
		m_v6DstPort= valueToSet;
		return;
	}


	inline int getv4SrcPort()
	{
		return m_v4SrcPort;
	}
	inline void setv4SrcPort(int valueToSet)
	{
		m_v4SrcPort= valueToSet;
		return;
	}


	inline int getv4DstPort()
	{
		return m_v4DstPort;
	}
	inline void setv4DstPort(int valueToSet)
	{
		m_v4DstPort= valueToSet;
		return;
	}


};
#endif
//-----data class file : ExtNatv6Entry.h --end----
