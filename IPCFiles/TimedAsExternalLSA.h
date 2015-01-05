//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 TimedAsExternalLSA.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:50 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_TIMEDASEXTERNALLSA_H
#define IPC_FW_TIMEDASEXTERNALLSA_H

#include "../framework/IPCFrameWork.h"
#include "OspfAsExternalLSA.h"

using namespace std;



class TimedAsExternalLSA : public IpcBase
{
private:
	OspfAsExternalLSA m_lsa;
public:
	//Constructors and Distructor
	TimedAsExternalLSA()
	{	
	}	
	TimedAsExternalLSA(CPtmpBuffer  *buf)
	{	
		m_className="TimedAsExternalLSA";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		buf->flushRead();
		OspfAsExternalLSA lsa(buf);
		m_lsa= lsa;
	}
	~TimedAsExternalLSA()
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

	inline OspfAsExternalLSA getlsa()
	{
		return m_lsa;
	}
	inline void setlsa(OspfAsExternalLSA valueToSet)
	{
		m_lsa= valueToSet;
		return;
	}


};
#endif
//-----data class file : TimedAsExternalLSA.h --end----
