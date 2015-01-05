//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 RoutingEntry.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:48 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_ROUTINGENTRY_H
#define IPC_FW_ROUTINGENTRY_H

#include "../framework/IPCFrameWork.h"

using namespace std;



class RoutingEntry : public IpcBase
{
private:
	char m_typeOfProtocol;
	CIpAddress m_networkId;
	CIpAddress m_subnetMask;
	std::string m_portName;
	CIpAddress m_nextHop;
	int m_adminDistance;
	int m_metric;
public:
	//Constructors and Distructor
	RoutingEntry()
	{	
	}	
	RoutingEntry(CPtmpBuffer  *buf)
	{	
		m_className="RoutingEntry";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_typeOfProtocol=buf->readByte();

		buf->readInt();//skip the type of data
		m_networkId=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_subnetMask=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_portName=buf->readString();

		buf->readInt();//skip the type of data
		m_nextHop=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_adminDistance=buf->readInt();

		buf->readInt();//skip the type of data
		m_metric=buf->readInt();
	}
	~RoutingEntry()
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

	inline char gettypeOfProtocol()
	{
		return m_typeOfProtocol;
	}
	inline void settypeOfProtocol(char valueToSet)
	{
		m_typeOfProtocol= valueToSet;
		return;
	}


	inline CIpAddress getnetworkId()
	{
		return m_networkId;
	}
	inline void setnetworkId(CIpAddress valueToSet)
	{
		m_networkId= valueToSet;
		return;
	}


	inline CIpAddress getsubnetMask()
	{
		return m_subnetMask;
	}
	inline void setsubnetMask(CIpAddress valueToSet)
	{
		m_subnetMask= valueToSet;
		return;
	}


	inline std::string getportName()
	{
		return m_portName;
	}
	inline void setportName(std::string valueToSet)
	{
		m_portName= valueToSet;
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


	inline int getadminDistance()
	{
		return m_adminDistance;
	}
	inline void setadminDistance(int valueToSet)
	{
		m_adminDistance= valueToSet;
		return;
	}


	inline int getmetric()
	{
		return m_metric;
	}
	inline void setmetric(int valueToSet)
	{
		m_metric= valueToSet;
		return;
	}


};
#endif
//-----data class file : RoutingEntry.h --end----
