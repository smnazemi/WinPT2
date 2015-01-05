//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 EigrpRoutingEntry.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:45 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_EIGRPROUTINGENTRY_H
#define IPC_FW_EIGRPROUTINGENTRY_H

#include "../framework/IPCFrameWork.h"

#include "RoutingEntry.h"
#include "EigrpInternal.h"

using namespace std;



class EigrpRoutingEntry : public RoutingEntry
{
private:
	int m_reportedDistance;
	EigrpInternal m_internal;
public:
	//Constructors and Distructor
	EigrpRoutingEntry()
	{	
	}	
	EigrpRoutingEntry(CPtmpBuffer  *buf)
	{	
		m_className="EigrpRoutingEntry";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_reportedDistance=buf->readInt();

		buf->readInt();//skip the type of data
		buf->flushRead();
		EigrpInternal internal(buf);
		m_internal= internal;
	}
	~EigrpRoutingEntry()
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

	inline int getreportedDistance()
	{
		return m_reportedDistance;
	}
	inline void setreportedDistance(int valueToSet)
	{
		m_reportedDistance= valueToSet;
		return;
	}


	inline EigrpInternal getinternal()
	{
		return m_internal;
	}
	inline void setinternal(EigrpInternal valueToSet)
	{
		m_internal= valueToSet;
		return;
	}


};
#endif
//-----data class file : EigrpRoutingEntry.h --end----
