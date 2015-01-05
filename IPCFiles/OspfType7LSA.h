//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 OspfType7LSA.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:47 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_OSPFTYPE7LSA_H
#define IPC_FW_OSPFTYPE7LSA_H

#include "../framework/IPCFrameWork.h"

#include "OspfLSA.h"

using namespace std;



class OspfType7LSA : public OspfLSA
{
private:
	CIpAddress m_networkMask;
	bool m_eBit;
	int m_metric;
	CIpAddress m_forwardingAddress;
	int m_externalRouteTag;
public:
	//Constructors and Distructor
	OspfType7LSA()
	{	
	}	
	OspfType7LSA(CPtmpBuffer  *buf)
	{	
		m_className="OspfType7LSA";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_networkMask=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_eBit=buf->readBool();

		buf->readInt();//skip the type of data
		m_metric=buf->readInt();

		buf->readInt();//skip the type of data
		m_forwardingAddress=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_externalRouteTag=buf->readInt();
	}
	~OspfType7LSA()
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


	inline bool geteBit()
	{
		return m_eBit;
	}
	inline void seteBit(bool valueToSet)
	{
		m_eBit= valueToSet;
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


	inline CIpAddress getforwardingAddress()
	{
		return m_forwardingAddress;
	}
	inline void setforwardingAddress(CIpAddress valueToSet)
	{
		m_forwardingAddress= valueToSet;
		return;
	}


	inline int getexternalRouteTag()
	{
		return m_externalRouteTag;
	}
	inline void setexternalRouteTag(int valueToSet)
	{
		m_externalRouteTag= valueToSet;
		return;
	}


};
#endif
//-----data class file : OspfType7LSA.h --end----
