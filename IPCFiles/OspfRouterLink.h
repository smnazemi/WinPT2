//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 OspfRouterLink.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:47 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_OSPFROUTERLINK_H
#define IPC_FW_OSPFROUTERLINK_H

#include "../framework/IPCFrameWork.h"

using namespace std;



class OspfRouterLink : public IpcBase
{
private:
	CIpAddress m_linkId;
	CIpAddress m_linkData;
	char m_type;
	short m_metric;
public:
	//Constructors and Distructor
	OspfRouterLink()
	{	
	}	
	OspfRouterLink(CPtmpBuffer  *buf)
	{	
		m_className="OspfRouterLink";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_linkId=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_linkData=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_type=buf->readByte();

		buf->readInt();//skip the type of data
		m_metric=buf->readShort();
	}
	~OspfRouterLink()
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

	inline CIpAddress getlinkId()
	{
		return m_linkId;
	}
	inline void setlinkId(CIpAddress valueToSet)
	{
		m_linkId= valueToSet;
		return;
	}


	inline CIpAddress getlinkData()
	{
		return m_linkData;
	}
	inline void setlinkData(CIpAddress valueToSet)
	{
		m_linkData= valueToSet;
		return;
	}


	inline char gettype()
	{
		return m_type;
	}
	inline void settype(char valueToSet)
	{
		m_type= valueToSet;
		return;
	}


	inline short getmetric()
	{
		return m_metric;
	}
	inline void setmetric(short valueToSet)
	{
		m_metric= valueToSet;
		return;
	}


};
#endif
//-----data class file : OspfRouterLink.h --end----
