//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 OspfLSA.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:47 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_OSPFLSA_H
#define IPC_FW_OSPFLSA_H

#include "../framework/IPCFrameWork.h"
#include "OspfLSAHeader.h"

using namespace std;



class OspfLSA : public IpcBase
{
private:
	OspfLSAHeader m_header;
public:
	//Constructors and Distructor
	OspfLSA()
	{	
	}	
	OspfLSA(CPtmpBuffer  *buf)
	{	
		m_className="OspfLSA";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		buf->flushRead();
		OspfLSAHeader header(buf);
		m_header= header;
	}
	~OspfLSA()
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

	inline OspfLSAHeader getheader()
	{
		return m_header;
	}
	inline void setheader(OspfLSAHeader valueToSet)
	{
		m_header= valueToSet;
		return;
	}


};
#endif
//-----data class file : OspfLSA.h --end----
