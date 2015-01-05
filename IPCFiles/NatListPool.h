//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 NatListPool.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:46 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_NATLISTPOOL_H
#define IPC_FW_NATLISTPOOL_H

#include "../framework/IPCFrameWork.h"

#include "NatList.h"

using namespace std;



class NatListPool : public NatList
{
private:
	std::string m_pool;
public:
	//Constructors and Distructor
	NatListPool()
	{	
	}	
	NatListPool(CPtmpBuffer  *buf)
	{	
		m_className="NatListPool";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_pool=buf->readString();
	}
	~NatListPool()
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

	inline std::string getpool()
	{
		return m_pool;
	}
	inline void setpool(std::string valueToSet)
	{
		m_pool= valueToSet;
		return;
	}


};
#endif
//-----data class file : NatListPool.h --end----
