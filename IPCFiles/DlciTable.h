//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 DlciTable.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:45 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_DLCITABLE_H
#define IPC_FW_DLCITABLE_H

#include "../framework/IPCFrameWork.h"
#include "FrameRelayMapEntry.h"

using namespace std;



class DlciTable : public IpcBase
{
private:
	std::vector<FrameRelayMapEntry> m_dlciEntries;
public:
	//Constructors and Distructor
	DlciTable()
	{	
	}	
	DlciTable(CPtmpBuffer  *buf)
	{	
		m_className="DlciTable";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		{
			buf->readInt();//skip data type of vect contents
			int sizeOfVect=buf->readInt();
			for(int index_dlciEntries=0;index_dlciEntries<sizeOfVect;index_dlciEntries++)
			{
				buf->flushRead();
				FrameRelayMapEntry vectMem0(buf);
				m_dlciEntries.push_back(vectMem0);
			}
		}
	}
	~DlciTable()
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

	inline std::vector<FrameRelayMapEntry> getdlciEntries()
	{
		return m_dlciEntries;
	}
	inline void setdlciEntries(std::vector<FrameRelayMapEntry> valueToSet)
	{
		m_dlciEntries= valueToSet;
		return;
	}


};
#endif
//-----data class file : DlciTable.h --end----
