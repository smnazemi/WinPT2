//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 AclStatement.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:44 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_ACLSTATEMENT_H
#define IPC_FW_ACLSTATEMENT_H

#include "../framework/IPCFrameWork.h"

using namespace std;



class AclStatement : public IpcBase
{
private:
	std::string m_statement;
public:
	//Constructors and Distructor
	AclStatement()
	{	
	}	
	AclStatement(CPtmpBuffer  *buf)
	{	
		m_className="AclStatement";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_statement=buf->readString();
	}
	~AclStatement()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:43 pm";
	}

	virtual void event(Ipc::CIpcEventMsg eventMsg){}

	//get and set functions

	inline std::string getstatement()
	{
		return m_statement;
	}
	inline void setstatement(std::string valueToSet)
	{
		m_statement= valueToSet;
		return;
	}


};
#endif
//-----data class file : AclStatement.h --end----
