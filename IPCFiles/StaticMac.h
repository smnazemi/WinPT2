//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 StaticMac.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:50 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_STATICMAC_H
#define IPC_FW_STATICMAC_H

#include "../framework/IPCFrameWork.h"

using namespace std;



class StaticMac : public IpcBase
{
private:
	CMacAddress  m_macAddress;
	int m_vlanId;
	std::string m_port;
public:
	//Constructors and Distructor
	StaticMac()
	{	
	}	
	StaticMac(CPtmpBuffer  *buf)
	{	
		m_className="StaticMac";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_macAddress=buf->readMacAddress();

		buf->readInt();//skip the type of data
		m_vlanId=buf->readInt();

		buf->readInt();//skip the type of data
		m_port=buf->readString();
	}
	~StaticMac()
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

	inline CMacAddress  getmacAddress()
	{
		return m_macAddress;
	}
	inline void setmacAddress(CMacAddress  valueToSet)
	{
		m_macAddress= valueToSet;
		return;
	}


	inline int getvlanId()
	{
		return m_vlanId;
	}
	inline void setvlanId(int valueToSet)
	{
		m_vlanId= valueToSet;
		return;
	}


	inline std::string getport()
	{
		return m_port;
	}
	inline void setport(std::string valueToSet)
	{
		m_port= valueToSet;
		return;
	}


};
#endif
//-----data class file : StaticMac.h --end----
