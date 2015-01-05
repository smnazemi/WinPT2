//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 NatConfigEntry.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:46 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_NATCONFIGENTRY_H
#define IPC_FW_NATCONFIGENTRY_H

#include "../framework/IPCFrameWork.h"

using namespace std;



class NatConfigEntry : public IpcBase
{
private:
	std::string m_name;
	int m_externalPort;
	int m_internalPort;
	int m_protocol;
	CIpAddress m_ipAddress;
	bool m_isEnable;
public:
	//Constructors and Distructor
	NatConfigEntry()
	{	
	}	
	NatConfigEntry(CPtmpBuffer  *buf)
	{	
		m_className="NatConfigEntry";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_name=buf->readString();

		buf->readInt();//skip the type of data
		m_externalPort=buf->readInt();

		buf->readInt();//skip the type of data
		m_internalPort=buf->readInt();

		buf->readInt();//skip the type of data
		m_protocol=buf->readInt();

		buf->readInt();//skip the type of data
		m_ipAddress=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_isEnable=buf->readBool();
	}
	~NatConfigEntry()
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

	inline std::string getname()
	{
		return m_name;
	}
	inline void setname(std::string valueToSet)
	{
		m_name= valueToSet;
		return;
	}


	inline int getexternalPort()
	{
		return m_externalPort;
	}
	inline void setexternalPort(int valueToSet)
	{
		m_externalPort= valueToSet;
		return;
	}


	inline int getinternalPort()
	{
		return m_internalPort;
	}
	inline void setinternalPort(int valueToSet)
	{
		m_internalPort= valueToSet;
		return;
	}


	inline int getprotocol()
	{
		return m_protocol;
	}
	inline void setprotocol(int valueToSet)
	{
		m_protocol= valueToSet;
		return;
	}


	inline CIpAddress getipAddress()
	{
		return m_ipAddress;
	}
	inline void setipAddress(CIpAddress valueToSet)
	{
		m_ipAddress= valueToSet;
		return;
	}


	inline bool getisEnable()
	{
		return m_isEnable;
	}
	inline void setisEnable(bool valueToSet)
	{
		m_isEnable= valueToSet;
		return;
	}


};
#endif
//-----data class file : NatConfigEntry.h --end----
