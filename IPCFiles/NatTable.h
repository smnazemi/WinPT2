//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 NatTable.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:46 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_NATTABLE_H
#define IPC_FW_NATTABLE_H

#include "../framework/IPCFrameWork.h"
#include "NatEntry.h"

using namespace std;



class NatTable : public IpcBase
{
private:
	std::vector<NatEntry> m_entries;
public:
	//Constructors and Distructor
	NatTable()
	{	
	}	
	NatTable(CPtmpBuffer  *buf)
	{	
		m_className="NatTable";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		{
			buf->readInt();//skip data type of vect contents
			int sizeOfVect=buf->readInt();
			for(int index_entries=0;index_entries<sizeOfVect;index_entries++)
			{
				buf->flushRead();
				NatEntry vectMem0(buf);
				m_entries.push_back(vectMem0);
			}
		}
	}
	~NatTable()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:46 pm";
	}

	virtual void event(Ipc::CIpcEventMsg eventMsg){}

	//get and set functions

	inline std::vector<NatEntry> getentries()
	{
		return m_entries;
	}
	inline void setentries(std::vector<NatEntry> valueToSet)
	{
		m_entries= valueToSet;
		return;
	}


};
#endif
//-----data class file : NatTable.h --end----
