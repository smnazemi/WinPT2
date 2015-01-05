//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 PingProcess.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:47 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_PINGPROCESS_H
#define IPC_FW_PINGPROCESS_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "Process.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class PingProcess : public Process
{
public :
	PingProcess()
	{	
	}	
	PingProcess(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="PingProcess";
	}
	~PingProcess()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:47 pm";
	}

	CIpAddress getDestinationIP();
	CIpAddress getLastIP( );
	bool isBroadcast();
	int getSentCount();
	int getMinDelay();
	int getMaxDelay();
	int getReceivedCount();
	int getLastDelay();
	int getTotalDelay();
	int getLastTtl();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------PingProcess.hEnds -------------//