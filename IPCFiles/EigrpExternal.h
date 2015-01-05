//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 EigrpExternal.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:45 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_EIGRPEXTERNAL_H
#define IPC_FW_EIGRPEXTERNAL_H

#include "../framework/IPCFrameWork.h"

#include "EigrpInternal.h"

using namespace std;



class EigrpExternal : public EigrpInternal
{
private:
	CIpAddress m_originalRouter;
	int m_routeAS;
	int m_externalMetric;
	char m_externalProtocolType;
	int m_adminTag;
public:
	//Constructors and Distructor
	EigrpExternal()
	{	
	}	
	EigrpExternal(CPtmpBuffer  *buf)
	{	
		m_className="EigrpExternal";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_originalRouter=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_routeAS=buf->readInt();

		buf->readInt();//skip the type of data
		m_externalMetric=buf->readInt();

		buf->readInt();//skip the type of data
		m_externalProtocolType=buf->readByte();

		buf->readInt();//skip the type of data
		m_adminTag=buf->readInt();
	}
	~EigrpExternal()
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

	inline CIpAddress getoriginalRouter()
	{
		return m_originalRouter;
	}
	inline void setoriginalRouter(CIpAddress valueToSet)
	{
		m_originalRouter= valueToSet;
		return;
	}


	inline int getrouteAS()
	{
		return m_routeAS;
	}
	inline void setrouteAS(int valueToSet)
	{
		m_routeAS= valueToSet;
		return;
	}


	inline int getexternalMetric()
	{
		return m_externalMetric;
	}
	inline void setexternalMetric(int valueToSet)
	{
		m_externalMetric= valueToSet;
		return;
	}


	inline char getexternalProtocolType()
	{
		return m_externalProtocolType;
	}
	inline void setexternalProtocolType(char valueToSet)
	{
		m_externalProtocolType= valueToSet;
		return;
	}


	inline int getadminTag()
	{
		return m_adminTag;
	}
	inline void setadminTag(int valueToSet)
	{
		m_adminTag= valueToSet;
		return;
	}


};
#endif
//-----data class file : EigrpExternal.h --end----
