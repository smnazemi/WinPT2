//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 RoutingTable.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:48 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_ROUTINGTABLE_H
#define IPC_FW_ROUTINGTABLE_H

#include "../framework/IPCFrameWork.h"
#include "RoutingNetwork.h"

using namespace std;



class RoutingTable : public IpcBase
{
private:
	std::vector<RoutingNetwork> m_routingNetworks;
public:
	//Constructors and Distructor
	RoutingTable()
	{	
	}	
	RoutingTable(CPtmpBuffer  *buf)
	{	
		m_className="RoutingTable";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		{
			buf->readInt();//skip data type of vect contents
			int sizeOfVect=buf->readInt();
			for(int index_routingNetworks=0;index_routingNetworks<sizeOfVect;index_routingNetworks++)
			{
				buf->flushRead();
				RoutingNetwork vectMem0(buf);
				m_routingNetworks.push_back(vectMem0);
			}
		}
	}
	~RoutingTable()
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

	inline std::vector<RoutingNetwork> getroutingNetworks()
	{
		return m_routingNetworks;
	}
	inline void setroutingNetworks(std::vector<RoutingNetwork> valueToSet)
	{
		m_routingNetworks= valueToSet;
		return;
	}


};
#endif
//-----data class file : RoutingTable.h --end----
