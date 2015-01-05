//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 EigrpTopologyTable.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:45 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_EIGRPTOPOLOGYTABLE_H
#define IPC_FW_EIGRPTOPOLOGYTABLE_H

#include "../framework/IPCFrameWork.h"
#include "EigrpTopologyEntry.h"

using namespace std;



class EigrpTopologyTable : public IpcBase
{
private:
	std::vector<EigrpTopologyEntry> m_topologyEntries;
public:
	//Constructors and Distructor
	EigrpTopologyTable()
	{	
	}	
	EigrpTopologyTable(CPtmpBuffer  *buf)
	{	
		m_className="EigrpTopologyTable";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		{
			buf->readInt();//skip data type of vect contents
			int sizeOfVect=buf->readInt();
			for(int index_topologyEntries=0;index_topologyEntries<sizeOfVect;index_topologyEntries++)
			{
				buf->flushRead();
				EigrpTopologyEntry vectMem0(buf);
				m_topologyEntries.push_back(vectMem0);
			}
		}
	}
	~EigrpTopologyTable()
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

	inline std::vector<EigrpTopologyEntry> gettopologyEntries()
	{
		return m_topologyEntries;
	}
	inline void settopologyEntries(std::vector<EigrpTopologyEntry> valueToSet)
	{
		m_topologyEntries= valueToSet;
		return;
	}


};
#endif
//-----data class file : EigrpTopologyTable.h --end----
