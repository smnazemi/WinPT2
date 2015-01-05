//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 TimedType7LSA.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:50 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_TIMEDTYPE7LSA_H
#define IPC_FW_TIMEDTYPE7LSA_H

#include "../framework/IPCFrameWork.h"
#include "OspfType7LSA.h"

using namespace std;



class TimedType7LSA : public IpcBase
{
private:
	OspfType7LSA m_lsa;
public:
	//Constructors and Distructor
	TimedType7LSA()
	{	
	}	
	TimedType7LSA(CPtmpBuffer  *buf)
	{	
		m_className="TimedType7LSA";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		buf->flushRead();
		OspfType7LSA lsa(buf);
		m_lsa= lsa;
	}
	~TimedType7LSA()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:50 pm";
	}

	virtual void event(Ipc::CIpcEventMsg eventMsg){}

	//get and set functions

	inline OspfType7LSA getlsa()
	{
		return m_lsa;
	}
	inline void setlsa(OspfType7LSA valueToSet)
	{
		m_lsa= valueToSet;
		return;
	}


};
#endif
//-----data class file : TimedType7LSA.h --end----
