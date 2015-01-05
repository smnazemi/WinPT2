//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 TimedNetworkLSA.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:50 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_TIMEDNETWORKLSA_H
#define IPC_FW_TIMEDNETWORKLSA_H

#include "../framework/IPCFrameWork.h"
#include "OspfNetworkLSA.h"

using namespace std;



class TimedNetworkLSA : public IpcBase
{
private:
	OspfNetworkLSA m_lsa;
public:
	//Constructors and Distructor
	TimedNetworkLSA()
	{	
	}	
	TimedNetworkLSA(CPtmpBuffer  *buf)
	{	
		m_className="TimedNetworkLSA";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		buf->flushRead();
		OspfNetworkLSA lsa(buf);
		m_lsa= lsa;
	}
	~TimedNetworkLSA()
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

	inline OspfNetworkLSA getlsa()
	{
		return m_lsa;
	}
	inline void setlsa(OspfNetworkLSA valueToSet)
	{
		m_lsa= valueToSet;
		return;
	}


};
#endif
//-----data class file : TimedNetworkLSA.h --end----
