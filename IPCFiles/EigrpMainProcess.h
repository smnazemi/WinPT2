//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 EigrpMainProcess.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:45 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_EIGRPMAINPROCESS_H
#define IPC_FW_EIGRPMAINPROCESS_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "Process.h"
#include "EigrpProcess.h"
#include "EigrpProcess.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class EigrpMainProcess : public Process
{
public :
	EigrpMainProcess()
	{	
	}	
	EigrpMainProcess(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="EigrpMainProcess";
	}
	~EigrpMainProcess()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:45 pm";
	}

	void addEigrpProcess(int as);
	void removeEigrpProcess(int as);
	EigrpProcess getEigrpProcessAt(int index);
	EigrpProcess getEigrpProcess(int as);
	int getEigrpProcessCount();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------EigrpMainProcess.hEnds -------------//