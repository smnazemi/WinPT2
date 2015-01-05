//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 Cable.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:44 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_CABLE_H
#define IPC_FW_CABLE_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"
#include "Link.h"
#include "Port.h"
#include "Device.h"//mine


using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class Cable : public Link
{
public :
	Cable()
	{	
	}	
	Cable(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="Cable";
	}
	~Cable()
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

	Port getPort1();
	Port getPort2();
	Device getDevice2();//mine
	Port getOtherPort(std::string deviceName,std::string portName);
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------Cable.hEnds -------------//