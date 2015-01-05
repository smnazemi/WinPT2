//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 TimedSummaryLSA.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:50 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_TIMEDSUMMARYLSA_H
#define IPC_FW_TIMEDSUMMARYLSA_H

#include "../framework/IPCFrameWork.h"
#include "OspfSummaryLSA.h"

using namespace std;



class TimedSummaryLSA : public IpcBase
{
private:
	OspfSummaryLSA m_lsa;
public:
	//Constructors and Distructor
	TimedSummaryLSA()
	{	
	}	
	TimedSummaryLSA(CPtmpBuffer  *buf)
	{	
		m_className="TimedSummaryLSA";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		buf->flushRead();
		OspfSummaryLSA lsa(buf);
		m_lsa= lsa;
	}
	~TimedSummaryLSA()
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

	inline OspfSummaryLSA getlsa()
	{
		return m_lsa;
	}
	inline void setlsa(OspfSummaryLSA valueToSet)
	{
		m_lsa= valueToSet;
		return;
	}


};
#endif
//-----data class file : TimedSummaryLSA.h --end----
