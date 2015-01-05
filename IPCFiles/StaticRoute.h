//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 StaticRoute.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:48 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_STATICROUTE_H
#define IPC_FW_STATICROUTE_H

#include "../framework/IPCFrameWork.h"

#include "RoutingEntry.h"

using namespace std;



class StaticRoute : public RoutingEntry
{
private:
public:
	//Constructors and Distructor
	StaticRoute()
	{	
	}	
	StaticRoute(CPtmpBuffer  *buf)
	{	
		m_className="StaticRoute";
		buf->readString();//skip the name of data obj
	}
	~StaticRoute()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:48 pm";
	}

	virtual void event(Ipc::CIpcEventMsg eventMsg){}

	//get and set functions

};
#endif
//-----data class file : StaticRoute.h --end----
