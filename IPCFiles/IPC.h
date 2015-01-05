//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 IPC.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:46 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_IPC_H
#define IPC_FW_IPC_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"
#include "Network.h"
#include "AppWindow.h"
#include "MultiUserManager.h"
#include "IpcManager.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class IPC : public IpcBase
{
public :
	IPC()
	{	
	}	
	IPC(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="IPC";
	}
	~IPC()
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

	Network network();
	AppWindow appWindow();
	MultiUserManager multiUserManager();
	IpcManager ipcManager();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------IPC.hEnds -------------//