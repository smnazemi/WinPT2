//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 OspfMainProcess.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:47 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_OSPFMAINPROCESS_H
#define IPC_FW_OSPFMAINPROCESS_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "Process.h"
#include "Process.h"
#include "Process.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class OspfMainProcess : public Process
{
public :
	OspfMainProcess()
	{	
	}	
	OspfMainProcess(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="OspfMainProcess";
	}
	~OspfMainProcess()
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

	bool addOspfProcess(int id);
	bool removeOspfProcess(int id);
	Process getOspfProcessAt(int index);
	Process getOspfProcess(int id);
	int getOspfProcessCount();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------OspfMainProcess.hEnds -------------//