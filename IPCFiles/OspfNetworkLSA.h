//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 OspfNetworkLSA.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:47 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_OSPFNETWORKLSA_H
#define IPC_FW_OSPFNETWORKLSA_H

#include "../framework/IPCFrameWork.h"

#include "OspfLSA.h"

using namespace std;



class OspfNetworkLSA : public OspfLSA
{
private:
	CIpAddress m_mask;
	std::vector<CIpAddress> m_routers;
public:
	//Constructors and Distructor
	OspfNetworkLSA()
	{	
	}	
	OspfNetworkLSA(CPtmpBuffer  *buf)
	{	
		m_className="OspfNetworkLSA";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_mask=buf->readIpAddress();

		buf->readInt();//skip the type of data
		{
			buf->readInt();//skip data type of vect contents
			int sizeOfVect=buf->readInt();
			for(int index_routers=0;index_routers<sizeOfVect;index_routers++)
			{
				CIpAddress vectMem0=buf->readIpAddress();
				m_routers.push_back(vectMem0);
			}
		}
	}
	~OspfNetworkLSA()
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

	inline CIpAddress getmask()
	{
		return m_mask;
	}
	inline void setmask(CIpAddress valueToSet)
	{
		m_mask= valueToSet;
		return;
	}


	inline std::vector<CIpAddress> getrouters()
	{
		return m_routers;
	}
	inline void setrouters(std::vector<CIpAddress> valueToSet)
	{
		m_routers= valueToSet;
		return;
	}


};
#endif
//-----data class file : OspfNetworkLSA.h --end----
