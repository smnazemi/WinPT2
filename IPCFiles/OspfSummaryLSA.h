//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 OspfSummaryLSA.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:47 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_OSPFSUMMARYLSA_H
#define IPC_FW_OSPFSUMMARYLSA_H

#include "../framework/IPCFrameWork.h"

#include "OspfLSA.h"

using namespace std;



class OspfSummaryLSA : public OspfLSA
{
private:
	CIpAddress m_networkMask;
	int m_metric;
public:
	//Constructors and Distructor
	OspfSummaryLSA()
	{	
	}	
	OspfSummaryLSA(CPtmpBuffer  *buf)
	{	
		m_className="OspfSummaryLSA";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_networkMask=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_metric=buf->readInt();
	}
	~OspfSummaryLSA()
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

	inline CIpAddress getnetworkMask()
	{
		return m_networkMask;
	}
	inline void setnetworkMask(CIpAddress valueToSet)
	{
		m_networkMask= valueToSet;
		return;
	}


	inline int getmetric()
	{
		return m_metric;
	}
	inline void setmetric(int valueToSet)
	{
		m_metric= valueToSet;
		return;
	}


};
#endif
//-----data class file : OspfSummaryLSA.h --end----
