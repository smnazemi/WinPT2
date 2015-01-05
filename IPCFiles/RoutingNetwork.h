//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 RoutingNetwork.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:48 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_ROUTINGNETWORK_H
#define IPC_FW_ROUTINGNETWORK_H

#include "../framework/IPCFrameWork.h"
#include "RoutingEntry.h"

using namespace std;



class RoutingNetwork : public IpcBase
{
private:
	CIpAddress m_network;
	CIpAddress m_subnetMask;
	std::vector<RoutingEntry> m_routingEntries;
public:
	//Constructors and Distructor
	RoutingNetwork()
	{	
	}	
	RoutingNetwork(CPtmpBuffer  *buf)
	{	
		m_className="RoutingNetwork";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_network=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_subnetMask=buf->readIpAddress();

		buf->readInt();//skip the type of data
		{
			buf->readInt();//skip data type of vect contents
			int sizeOfVect=buf->readInt();
			for(int index_routingEntries=0;index_routingEntries<sizeOfVect;index_routingEntries++)
			{
				buf->flushRead();
				RoutingEntry vectMem0(buf);
				m_routingEntries.push_back(vectMem0);
			}
		}
	}
	~RoutingNetwork()
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

	inline CIpAddress getnetwork()
	{
		return m_network;
	}
	inline void setnetwork(CIpAddress valueToSet)
	{
		m_network= valueToSet;
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


	inline std::vector<RoutingEntry> getroutingEntries()
	{
		return m_routingEntries;
	}
	inline void setroutingEntries(std::vector<RoutingEntry> valueToSet)
	{
		m_routingEntries= valueToSet;
		return;
	}


};
#endif
//-----data class file : RoutingNetwork.h --end----
