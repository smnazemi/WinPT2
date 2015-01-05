//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 CdpNeighbor.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:44 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_CDPNEIGHBOR_H
#define IPC_FW_CDPNEIGHBOR_H

#include "../framework/IPCFrameWork.h"

using namespace std;



class CdpNeighbor : public IpcBase
{
private:
	std::string m_deviceId;
	std::string m_localPort;
	std::string m_remotePort;
	std::string m_platform;
	char m_capability;
	char m_cdpVersion;
	char m_holdTime;
	std::string m_softwareVersion;
	short m_nativeVlan;
public:
	//Constructors and Distructor
	CdpNeighbor()
	{	
	}	
	CdpNeighbor(CPtmpBuffer  *buf)
	{	
		m_className="CdpNeighbor";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_deviceId=buf->readString();

		buf->readInt();//skip the type of data
		m_localPort=buf->readString();

		buf->readInt();//skip the type of data
		m_remotePort=buf->readString();

		buf->readInt();//skip the type of data
		m_platform=buf->readString();

		buf->readInt();//skip the type of data
		m_capability=buf->readByte();

		buf->readInt();//skip the type of data
		m_cdpVersion=buf->readByte();

		buf->readInt();//skip the type of data
		m_holdTime=buf->readByte();

		buf->readInt();//skip the type of data
		m_softwareVersion=buf->readString();

		buf->readInt();//skip the type of data
		m_nativeVlan=buf->readShort();
	}
	~CdpNeighbor()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:44 pm";
	}

	virtual void event(Ipc::CIpcEventMsg eventMsg){}

	//get and set functions

	inline std::string getdeviceId()
	{
		return m_deviceId;
	}
	inline void setdeviceId(std::string valueToSet)
	{
		m_deviceId= valueToSet;
		return;
	}


	inline std::string getlocalPort()
	{
		return m_localPort;
	}
	inline void setlocalPort(std::string valueToSet)
	{
		m_localPort= valueToSet;
		return;
	}


	inline std::string getremotePort()
	{
		return m_remotePort;
	}
	inline void setremotePort(std::string valueToSet)
	{
		m_remotePort= valueToSet;
		return;
	}


	inline std::string getplatform()
	{
		return m_platform;
	}
	inline void setplatform(std::string valueToSet)
	{
		m_platform= valueToSet;
		return;
	}


	inline char getcapability()
	{
		return m_capability;
	}
	inline void setcapability(char valueToSet)
	{
		m_capability= valueToSet;
		return;
	}


	inline char getcdpVersion()
	{
		return m_cdpVersion;
	}
	inline void setcdpVersion(char valueToSet)
	{
		m_cdpVersion= valueToSet;
		return;
	}


	inline char getholdTime()
	{
		return m_holdTime;
	}
	inline void setholdTime(char valueToSet)
	{
		m_holdTime= valueToSet;
		return;
	}


	inline std::string getsoftwareVersion()
	{
		return m_softwareVersion;
	}
	inline void setsoftwareVersion(std::string valueToSet)
	{
		m_softwareVersion= valueToSet;
		return;
	}


	inline short getnativeVlan()
	{
		return m_nativeVlan;
	}
	inline void setnativeVlan(short valueToSet)
	{
		m_nativeVlan= valueToSet;
		return;
	}


};
#endif
//-----data class file : CdpNeighbor.h --end----
