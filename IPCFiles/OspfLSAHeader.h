//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 OspfLSAHeader.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:47 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_OSPFLSAHEADER_H
#define IPC_FW_OSPFLSAHEADER_H

#include "../framework/IPCFrameWork.h"

using namespace std;



class OspfLSAHeader : public IpcBase
{
private:
	CIpAddress m_lsId;
	CIpAddress m_advRouter;
	char m_type;
	short m_age;
	char m_option;
	int m_seqNumber;
	short m_checksum;
	short m_length;
public:
	//Constructors and Distructor
	OspfLSAHeader()
	{	
	}	
	OspfLSAHeader(CPtmpBuffer  *buf)
	{	
		m_className="OspfLSAHeader";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_lsId=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_advRouter=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_type=buf->readByte();

		buf->readInt();//skip the type of data
		m_age=buf->readShort();

		buf->readInt();//skip the type of data
		m_option=buf->readByte();

		buf->readInt();//skip the type of data
		m_seqNumber=buf->readInt();

		buf->readInt();//skip the type of data
		m_checksum=buf->readShort();

		buf->readInt();//skip the type of data
		m_length=buf->readShort();
	}
	~OspfLSAHeader()
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

	inline CIpAddress getlsId()
	{
		return m_lsId;
	}
	inline void setlsId(CIpAddress valueToSet)
	{
		m_lsId= valueToSet;
		return;
	}


	inline CIpAddress getadvRouter()
	{
		return m_advRouter;
	}
	inline void setadvRouter(CIpAddress valueToSet)
	{
		m_advRouter= valueToSet;
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


	inline short getage()
	{
		return m_age;
	}
	inline void setage(short valueToSet)
	{
		m_age= valueToSet;
		return;
	}


	inline char getoption()
	{
		return m_option;
	}
	inline void setoption(char valueToSet)
	{
		m_option= valueToSet;
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


	inline short getchecksum()
	{
		return m_checksum;
	}
	inline void setchecksum(short valueToSet)
	{
		m_checksum= valueToSet;
		return;
	}


	inline short getlength()
	{
		return m_length;
	}
	inline void setlength(short valueToSet)
	{
		m_length= valueToSet;
		return;
	}


};
#endif
//-----data class file : OspfLSAHeader.h --end----
