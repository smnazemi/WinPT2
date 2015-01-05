//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 EigrpNeighbor.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:45 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_EIGRPNEIGHBOR_H
#define IPC_FW_EIGRPNEIGHBOR_H

#include "../framework/IPCFrameWork.h"

using namespace std;



class EigrpNeighbor : public IpcBase
{
private:
	CIpAddress m_neighborAddress;
	std::string m_portName;
	int m_holdTime;
	long m_upTime;
	int m_seqNumber;
	int m_srtt;
	int m_rto;
	long m_lastHeardTime;
	long m_lastUpdateTime;
public:
	//Constructors and Distructor
	EigrpNeighbor()
	{	
	}	
	EigrpNeighbor(CPtmpBuffer  *buf)
	{	
		m_className="EigrpNeighbor";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_neighborAddress=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_portName=buf->readString();

		buf->readInt();//skip the type of data
		m_holdTime=buf->readInt();

		buf->readInt();//skip the type of data
		m_upTime=buf->readLong();

		buf->readInt();//skip the type of data
		m_seqNumber=buf->readInt();

		buf->readInt();//skip the type of data
		m_srtt=buf->readInt();

		buf->readInt();//skip the type of data
		m_rto=buf->readInt();

		buf->readInt();//skip the type of data
		m_lastHeardTime=buf->readLong();

		buf->readInt();//skip the type of data
		m_lastUpdateTime=buf->readLong();
	}
	~EigrpNeighbor()
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

	inline CIpAddress getneighborAddress()
	{
		return m_neighborAddress;
	}
	inline void setneighborAddress(CIpAddress valueToSet)
	{
		m_neighborAddress= valueToSet;
		return;
	}


	inline std::string getportName()
	{
		return m_portName;
	}
	inline void setportName(std::string valueToSet)
	{
		m_portName= valueToSet;
		return;
	}


	inline int getholdTime()
	{
		return m_holdTime;
	}
	inline void setholdTime(int valueToSet)
	{
		m_holdTime= valueToSet;
		return;
	}


	inline long getupTime()
	{
		return m_upTime;
	}
	inline void setupTime(long valueToSet)
	{
		m_upTime= valueToSet;
		return;
	}


	inline int getseqNumber()
	{
		return m_seqNumber;
	}
	inline void setseqNumber(int valueToSet)
	{
		m_seqNumber= valueToSet;
		return;
	}


	inline int getsrtt()
	{
		return m_srtt;
	}
	inline void setsrtt(int valueToSet)
	{
		m_srtt= valueToSet;
		return;
	}


	inline int getrto()
	{
		return m_rto;
	}
	inline void setrto(int valueToSet)
	{
		m_rto= valueToSet;
		return;
	}


	inline long getlastHeardTime()
	{
		return m_lastHeardTime;
	}
	inline void setlastHeardTime(long valueToSet)
	{
		m_lastHeardTime= valueToSet;
		return;
	}


	inline long getlastUpdateTime()
	{
		return m_lastUpdateTime;
	}
	inline void setlastUpdateTime(long valueToSet)
	{
		m_lastUpdateTime= valueToSet;
		return;
	}


};
#endif
//-----data class file : EigrpNeighbor.h --end----
