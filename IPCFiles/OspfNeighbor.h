//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 OspfNeighbor.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:47 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_OSPFNEIGHBOR_H
#define IPC_FW_OSPFNEIGHBOR_H

#include "../framework/IPCFrameWork.h"

using namespace std;



class OspfNeighbor : public IpcBase
{
private:
	CIpAddress m_routerId;
	CIpAddress m_address;
	std::string m_port;
	short m_priority;
	int m_state;
	short m_option;
	CIpAddress m_dr;
	CIpAddress m_backupDr;
	short m_deadInterval;
	CIpAddress m_areaId;
	bool m_isMaster;
	int m_seqNumber;
	bool m_isVirtual;
public:
	//Constructors and Distructor
	OspfNeighbor()
	{	
	}	
	OspfNeighbor(CPtmpBuffer  *buf)
	{	
		m_className="OspfNeighbor";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_routerId=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_address=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_port=buf->readString();

		buf->readInt();//skip the type of data
		m_priority=buf->readShort();

		buf->readInt();//skip the type of data
		m_state=buf->readInt();

		buf->readInt();//skip the type of data
		m_option=buf->readShort();

		buf->readInt();//skip the type of data
		m_dr=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_backupDr=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_deadInterval=buf->readShort();

		buf->readInt();//skip the type of data
		m_areaId=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_isMaster=buf->readBool();

		buf->readInt();//skip the type of data
		m_seqNumber=buf->readInt();

		buf->readInt();//skip the type of data
		m_isVirtual=buf->readBool();
	}
	~OspfNeighbor()
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

	inline CIpAddress getrouterId()
	{
		return m_routerId;
	}
	inline void setrouterId(CIpAddress valueToSet)
	{
		m_routerId= valueToSet;
		return;
	}


	inline CIpAddress getaddress()
	{
		return m_address;
	}
	inline void setaddress(CIpAddress valueToSet)
	{
		m_address= valueToSet;
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


	inline short getpriority()
	{
		return m_priority;
	}
	inline void setpriority(short valueToSet)
	{
		m_priority= valueToSet;
		return;
	}


	inline int getstate()
	{
		return m_state;
	}
	inline void setstate(int valueToSet)
	{
		m_state= valueToSet;
		return;
	}


	inline short getoption()
	{
		return m_option;
	}
	inline void setoption(short valueToSet)
	{
		m_option= valueToSet;
		return;
	}


	inline CIpAddress getdr()
	{
		return m_dr;
	}
	inline void setdr(CIpAddress valueToSet)
	{
		m_dr= valueToSet;
		return;
	}


	inline CIpAddress getbackupDr()
	{
		return m_backupDr;
	}
	inline void setbackupDr(CIpAddress valueToSet)
	{
		m_backupDr= valueToSet;
		return;
	}


	inline short getdeadInterval()
	{
		return m_deadInterval;
	}
	inline void setdeadInterval(short valueToSet)
	{
		m_deadInterval= valueToSet;
		return;
	}


	inline CIpAddress getareaId()
	{
		return m_areaId;
	}
	inline void setareaId(CIpAddress valueToSet)
	{
		m_areaId= valueToSet;
		return;
	}


	inline bool getisMaster()
	{
		return m_isMaster;
	}
	inline void setisMaster(bool valueToSet)
	{
		m_isMaster= valueToSet;
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


	inline bool getisVirtual()
	{
		return m_isVirtual;
	}
	inline void setisVirtual(bool valueToSet)
	{
		m_isVirtual= valueToSet;
		return;
	}


};
#endif
//-----data class file : OspfNeighbor.h --end----
