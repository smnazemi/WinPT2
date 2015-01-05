//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 IPC.cpp 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:46 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#include "IPC.h"

Network IPC::network()
{
	std::string callName= "network";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	Network networkObj(m_ipcFramework,*buf);

	return networkObj;
}
AppWindow IPC::appWindow()
{
	std::string callName= "appWindow";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	AppWindow appwindowObj(m_ipcFramework,*buf);

	return appwindowObj;
}
MultiUserManager IPC::multiUserManager()
{
	std::string callName= "multiUserManager";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	MultiUserManager multiusermanagerObj(m_ipcFramework,*buf);

	return multiusermanagerObj;
}
IpcManager IPC::ipcManager()
{
	std::string callName= "ipcManager";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	IpcManager ipcmanagerObj(m_ipcFramework,*buf);

	return ipcmanagerObj;
}
