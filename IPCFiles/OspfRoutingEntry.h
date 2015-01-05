//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 OspfRoutingEntry.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:47 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_OSPFROUTINGENTRY_H
#define IPC_FW_OSPFROUTINGENTRY_H

#include "../framework/IPCFrameWork.h"

#include "RoutingEntry.h"

using namespace std;



class OspfRoutingEntry : public RoutingEntry
{
private:
	int m_realCost;
	CIpAddress m_advRoute;
public:
	//Constructors and Distructor
	OspfRoutingEntry()
	{	
	}	
	OspfRoutingEntry(CPtmpBuffer  *buf)
	{	
		m_className="OspfRoutingEntry";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_realCost=buf->readInt();

		buf->readInt();//skip the type of data
		m_advRoute=buf->readIpAddress();
	}
	~OspfRoutingEntry()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:47 pm";
	}

	virtual void event(Ipc::CIpcEventMsg eventMsg){}

	//get and set functions

	inline int getrealCost()
	{
		return m_realCost;
	}
	inline void setrealCost(int valueToSet)
	{
		m_realCost= valueToSet;
		return;
	}


	inline CIpAddress getadvRoute()
	{
		return m_advRoute;
	}
	inline void setadvRoute(CIpAddress valueToSet)
	{
		m_advRoute= valueToSet;
		return;
	}


};
#endif
//-----data class file : OspfRoutingEntry.h --end----
