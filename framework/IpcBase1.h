//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	IpcBase.h  
	Author:		Ajan U. Nair 
	Date:		16-Jul-2008   
	Revision:	1.0           
	Description:
		Implementation of IpcBase class which is derived by all the 
		IPC classes. This file holds the implementation of common functions 
		for all IPC classes.

		The exceptin class IpcFwException is also implemented in this file.
		
*/

#ifndef IPC_BASE_H
#define IPC_BASE_H


#include <iostream>


#include "../IPC/CIpcEventMsg.h"
#include "IPCFrameWork.h"
#include "EventHandler.h"

class IPCFrameWork;

using namespace std;
class IpcBase
{
public:
	IpcBase():m_ipcFramework(0)
	{
	}
	virtual ~IpcBase();

	std::string IpcBase::getIpcCallStr();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}
	
	QUuid IpcBase::getObjectUuid();
	std::string IpcBase::getClassName();
	bool IpcBase::registerObjectEvent(std::string evnt);
	void IpcBase::unregisterObjectEvent(std::string event);

protected:
	Ptmp::CPtmpBuffer m_ptmpBuffer;
	IPCFrameWork *m_ipcFramework;
	std::string m_className;
};

class IpcFwException
{
	std::string m_errMsg;
public:
	IpcFwException(std::string errMsg)
	{
		m_errMsg=errMsg;
	}
	void print()
	{
		cerr << m_errMsg << endl;
	}
	std::string getErrMsg()
	{
		return m_errMsg;
	}
};
#endif