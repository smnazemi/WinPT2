//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 EigrpTopologyEntry.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:45 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_EIGRPTOPOLOGYENTRY_H
#define IPC_FW_EIGRPTOPOLOGYENTRY_H

#include "../framework/IPCFrameWork.h"
#include "EigrpRoutingEntry.h"

using namespace std;



class EigrpTopologyEntry : public IpcBase
{
private:
	CIpAddress m_network;
	CIpAddress m_subnetMask;
	int m_state;
	int m_feasibleDistance;
	int m_reportedDistance;
	int m_successorCount;
	std::vector<EigrpRoutingEntry> m_routingEntries;
public:
	//Constructors and Distructor
	EigrpTopologyEntry()
	{	
	}	
	EigrpTopologyEntry(CPtmpBuffer  *buf)
	{	
		m_className="EigrpTopologyEntry";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_network=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_subnetMask=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_state=buf->readInt();

		buf->readInt();//skip the type of data
		m_feasibleDistance=buf->readInt();

		buf->readInt();//skip the type of data
		m_reportedDistance=buf->readInt();

		buf->readInt();//skip the type of data
		m_successorCount=buf->readInt();

		buf->readInt();//skip the type of data
		{
			buf->readInt();//skip data type of vect contents
			int sizeOfVect=buf->readInt();
			for(int index_routingEntries=0;index_routingEntries<sizeOfVect;index_routingEntries++)
			{
				buf->flushRead();
				EigrpRoutingEntry vectMem0(buf);
				m_routingEntries.push_back(vectMem0);
			}
		}
	}
	~EigrpTopologyEntry()
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


	inline int getstate()
	{
		return m_state;
	}
	inline void setstate(int valueToSet)
	{
		m_state= valueToSet;
		return;
	}


	inline int getfeasibleDistance()
	{
		return m_feasibleDistance;
	}
	inline void setfeasibleDistance(int valueToSet)
	{
		m_feasibleDistance= valueToSet;
		return;
	}


	inline int getreportedDistance()
	{
		return m_reportedDistance;
	}
	inline void setreportedDistance(int valueToSet)
	{
		m_reportedDistance= valueToSet;
		return;
	}


	inline int getsuccessorCount()
	{
		return m_successorCount;
	}
	inline void setsuccessorCount(int valueToSet)
	{
		m_successorCount= valueToSet;
		return;
	}


	inline std::vector<EigrpRoutingEntry> getroutingEntries()
	{
		return m_routingEntries;
	}
	inline void setroutingEntries(std::vector<EigrpRoutingEntry> valueToSet)
	{
		m_routingEntries= valueToSet;
		return;
	}


};
#endif
//-----data class file : EigrpTopologyEntry.h --end----
