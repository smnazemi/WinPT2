//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 Cable.cpp 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:44 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#include "Cable.h"

Port Cable:: getPort1()
{
	std::string callName= "getPort1";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	Port portObj(m_ipcFramework,*buf);

	return portObj;
}
Port Cable:: getPort2()
{
	std::string callName= "getPort2";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	Port portObj(m_ipcFramework,*buf);

	return portObj;
}
Device Cable:: getDevice2()//mine
{
	std::string callName= "getDevice2";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	Device portObj(m_ipcFramework,*buf);

	return portObj;
}
Port Cable:: getOtherPort(std::string deviceName,std::string portName)
{
	std::string callName= "getOtherPort";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eString);
	buf->write(deviceName);

	buf->write(eString);
	buf->write(portName);

	buf->write(eVoid);

	Port portObj(m_ipcFramework,*buf);

	return portObj;
}
