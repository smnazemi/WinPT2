//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 FrameRelayMapEntry.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:45 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_FRAMERELAYMAPENTRY_H
#define IPC_FW_FRAMERELAYMAPENTRY_H

#include "../framework/IPCFrameWork.h"

using namespace std;



class FrameRelayMapEntry : public IpcBase
{
private:
	std::string m_port;
	CIpAddress m_ipAddress;
	short m_dlci;
	bool m_isBroadcast;
	int m_encapType;
public:
	//Constructors and Distructor
	FrameRelayMapEntry()
	{	
	}	
	FrameRelayMapEntry(CPtmpBuffer  *buf)
	{	
		m_className="FrameRelayMapEntry";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_port=buf->readString();

		buf->readInt();//skip the type of data
		m_ipAddress=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_dlci=buf->readShort();

		buf->readInt();//skip the type of data
		m_isBroadcast=buf->readBool();

		buf->readInt();//skip the type of data
		m_encapType=buf->readInt();
	}
	~FrameRelayMapEntry()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:45 pm";
	}

	virtual void event(Ipc::CIpcEventMsg eventMsg){}

	//get and set functions

	inline std::string getport()
	{
		return m_port;
	}
	inline void setport(std::string valueToSet)
	{
		m_port= valueToSet;
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


	inline short getdlci()
	{
		return m_dlci;
	}
	inline void setdlci(short valueToSet)
	{
		m_dlci= valueToSet;
		return;
	}


	inline bool getisBroadcast()
	{
		return m_isBroadcast;
	}
	inline void setisBroadcast(bool valueToSet)
	{
		m_isBroadcast= valueToSet;
		return;
	}


	inline int getencapType()
	{
		return m_encapType;
	}
	inline void setencapType(int valueToSet)
	{
		m_encapType= valueToSet;
		return;
	}


};
#endif
//-----data class file : FrameRelayMapEntry.h --end----
