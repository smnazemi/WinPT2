//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 Natv6ListInterface.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:46 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_NATV6LISTINTERFACE_H
#define IPC_FW_NATV6LISTINTERFACE_H

#include "../framework/IPCFrameWork.h"

#include "Natv6List.h"

using namespace std;



class Natv6ListInterface : public Natv6List
{
private:
	std::string m_port;
public:
	//Constructors and Distructor
	Natv6ListInterface()
	{	
	}	
	Natv6ListInterface(CPtmpBuffer  *buf)
	{	
		m_className="Natv6ListInterface";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_port=buf->readString();
	}
	~Natv6ListInterface()
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
//-----data class file : Natv6ListInterface.h --end----
