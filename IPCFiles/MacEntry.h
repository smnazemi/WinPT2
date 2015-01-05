//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 MacEntry.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:46 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_MACENTRY_H
#define IPC_FW_MACENTRY_H

#include "../framework/IPCFrameWork.h"

using namespace std;



class MacEntry : public IpcBase
{
private:
	CMacAddress  m_macAddress;
	std::string m_port;
	bool m_isDynamic;
public:
	//Constructors and Distructor
	MacEntry()
	{	
	}	
	MacEntry(CPtmpBuffer  *buf)
	{	
		m_className="MacEntry";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_macAddress=buf->readMacAddress();

		buf->readInt();//skip the type of data
		m_port=buf->readString();

		buf->readInt();//skip the type of data
		m_isDynamic=buf->readBool();
	}
	~MacEntry()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:46 pm";
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


	inline std::string getport()
	{
		return m_port;
	}
	inline void setport(std::string valueToSet)
	{
		m_port= valueToSet;
		return;
	}


	inline bool getisDynamic()
	{
		return m_isDynamic;
	}
	inline void setisDynamic(bool valueToSet)
	{
		m_isDynamic= valueToSet;
		return;
	}


};
#endif
//-----data class file : MacEntry.h --end----
