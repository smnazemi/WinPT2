//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 CommandHistory.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:44 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_COMMANDHISTORY_H
#define IPC_FW_COMMANDHISTORY_H

#include "../framework/IPCFrameWork.h"

using namespace std;



class CommandHistory : public IpcBase
{
private:
	std::vector<std::string> m_history;
	int m_maxCount;
public:
	//Constructors and Distructor
	CommandHistory()
	{	
	}	
	CommandHistory(CPtmpBuffer  *buf)
	{	
		m_className="CommandHistory";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		{
			buf->readInt();//skip data type of vect contents
			int sizeOfVect=buf->readInt();
			for(int index_history=0;index_history<sizeOfVect;index_history++)
			{
				std::string vectMem0=buf->readString();
				m_history.push_back(vectMem0);
			}
		}

		buf->readInt();//skip the type of data
		m_maxCount=buf->readInt();
	}
	~CommandHistory()
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

	inline std::vector<std::string> gethistory()
	{
		return m_history;
	}
	inline void sethistory(std::vector<std::string> valueToSet)
	{
		m_history= valueToSet;
		return;
	}


	inline int getmaxCount()
	{
		return m_maxCount;
	}
	inline void setmaxCount(int valueToSet)
	{
		m_maxCount= valueToSet;
		return;
	}


};
#endif
//-----data class file : CommandHistory.h --end----
