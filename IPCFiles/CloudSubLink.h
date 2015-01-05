//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 CloudSubLink.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:44 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_CLOUDSUBLINK_H
#define IPC_FW_CLOUDSUBLINK_H

#include "../framework/IPCFrameWork.h"

using namespace std;



class CloudSubLink : public IpcBase
{
private:
	std::string m_name;
	int m_dlci;
public:
	//Constructors and Distructor
	CloudSubLink()
	{	
	}	
	CloudSubLink(CPtmpBuffer  *buf)
	{	
		m_className="CloudSubLink";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_name=buf->readString();

		buf->readInt();//skip the type of data
		m_dlci=buf->readInt();
	}
	~CloudSubLink()
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

	inline std::string getname()
	{
		return m_name;
	}
	inline void setname(std::string valueToSet)
	{
		m_name= valueToSet;
		return;
	}


	inline int getdlci()
	{
		return m_dlci;
	}
	inline void setdlci(int valueToSet)
	{
		m_dlci= valueToSet;
		return;
	}


};
#endif
//-----data class file : CloudSubLink.h --end----
