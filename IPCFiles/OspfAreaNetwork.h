//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 OspfAreaNetwork.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:50 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_OSPFAREANETWORK_H
#define IPC_FW_OSPFAREANETWORK_H

#include "../framework/IPCFrameWork.h"

using namespace std;



class OspfAreaNetwork : public IpcBase
{
private:
	CIpAddress m_areaId;
	std::pair<CIpAddress,CIpAddress> m_ipAndMask;
public:
	//Constructors and Distructor
	OspfAreaNetwork()
	{	
	}	
	OspfAreaNetwork(CPtmpBuffer  *buf)
	{	
		m_className="OspfAreaNetwork";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_areaId=buf->readIpAddress();

		buf->readInt();//skip the type of data
		buf->readInt();

			CIpAddress pairMemType1_0=buf->readIpAddress();

		m_ipAndMask.first=pairMemType1_0;
		buf->readInt();

			CIpAddress pairMemType2_0=buf->readIpAddress();

		m_ipAndMask.first=pairMemType2_0;
	}
	~OspfAreaNetwork()
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

	inline CIpAddress getareaId()
	{
		return m_areaId;
	}
	inline void setareaId(CIpAddress valueToSet)
	{
		m_areaId= valueToSet;
		return;
	}


	inline std::pair<CIpAddress,CIpAddress> getipAndMask()
	{
		return m_ipAndMask;
	}
	inline void setipAndMask(std::pair<CIpAddress,CIpAddress> valueToSet)
	{
		m_ipAndMask= valueToSet;
		return;
	}


};
#endif
//-----data class file : OspfAreaNetwork.h --end----
