//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 Network.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:47 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_NETWORK_H
#define IPC_FW_NETWORK_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"
#include "Device.h"
#include "CiscoDevice.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class Network : public IpcBase
{
public :
	Network()
	{	
	}	
	Network(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="Network";
	}
	~Network()
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

	Device getDevice(QString deviceName);
	CiscoDevice getCiscoDevice(QString deviceName);
	Device getDeviceAt(int index);
	int getDeviceCount();
	
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------Network.hEnds -------------//