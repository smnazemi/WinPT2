//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 Natv6Table.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:47 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_NATV6TABLE_H
#define IPC_FW_NATV6TABLE_H

#include "../framework/IPCFrameWork.h"
#include "Natv6Entry.h"

using namespace std;



class Natv6Table : public IpcBase
{
private:
	std::vector<Natv6Entry> m_entries;
public:
	//Constructors and Distructor
	Natv6Table()
	{	
	}	
	Natv6Table(CPtmpBuffer  *buf)
	{	
		m_className="Natv6Table";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		{
			buf->readInt();//skip data type of vect contents
			int sizeOfVect=buf->readInt();
			for(int index_entries=0;index_entries<sizeOfVect;index_entries++)
			{
				buf->flushRead();
				Natv6Entry vectMem0(buf);
				m_entries.push_back(vectMem0);
			}
		}
	}
	~Natv6Table()
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

	inline std::vector<Natv6Entry> getentries()
	{
		return m_entries;
	}
	inline void setentries(std::vector<Natv6Entry> valueToSet)
	{
		m_entries= valueToSet;
		return;
	}


};
#endif
//-----data class file : Natv6Table.h --end----
