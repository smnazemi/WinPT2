//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 Natv6List.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:46 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_NATV6LIST_H
#define IPC_FW_NATV6LIST_H

#include "../framework/IPCFrameWork.h"

using namespace std;



class Natv6List : public IpcBase
{
private:
	std::string m_aclId;
	bool m_isOverload;
public:
	//Constructors and Distructor
	Natv6List()
	{	
	}	
	Natv6List(CPtmpBuffer  *buf)
	{	
		m_className="Natv6List";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_aclId=buf->readString();

		buf->readInt();//skip the type of data
		m_isOverload=buf->readBool();
	}
	~Natv6List()
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

	inline std::string getaclId()
	{
		return m_aclId;
	}
	inline void setaclId(std::string valueToSet)
	{
		m_aclId= valueToSet;
		return;
	}


	inline bool getisOverload()
	{
		return m_isOverload;
	}
	inline void setisOverload(bool valueToSet)
	{
		m_isOverload= valueToSet;
		return;
	}


};
#endif
//-----data class file : Natv6List.h --end----
