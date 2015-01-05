//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 LoopbackManager.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:46 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_LOOPBACKMANAGER_H
#define IPC_FW_LOOPBACKMANAGER_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "Process.h"
#include "RouterPort.h"
#include "RouterPort.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class LoopbackManager : public Process
{
public :
	LoopbackManager()
	{	
	}	
	LoopbackManager(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="LoopbackManager";
	}
	~LoopbackManager()
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

	RouterPort getLoopback(int loopbackNumber);
	RouterPort getLoopbackAt(int index);
	bool addLoopback(int loopbackNumber);
	bool removeLoopback(int loopbackNumber);
	int getLoopbackCount();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------LoopbackManager.hEnds -------------//