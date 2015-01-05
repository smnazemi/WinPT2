//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 FrameRelayProcess.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:45 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_FRAMERELAYPROCESS_H
#define IPC_FW_FRAMERELAYPROCESS_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "PortKeepAliveProcess.h"
#include "FrameRelayMapEntry.h"
#include "Port.h"
#include "DlciTable.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class FrameRelayProcess : public PortKeepAliveProcess
{
public :
	FrameRelayProcess()
	{	
	}	
	FrameRelayProcess(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="FrameRelayProcess";
	}
	~FrameRelayProcess()
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

	void setLmiType(int lmiType);
	void setEncapType(int encapType);
	int getEncapType();
	int getLmiType();
	bool addMapEntry(CIpAddress ipAddress,int dlci,bool bBroadcast,int encapType,std::string portName);
	bool addIntDlciEntry(std::string portName,int dlci);
	bool deleteMapEntry(std::string portName,CIpAddress ipAddress);
	bool deleteIntDlciEntry(std::string portName,int dlci);
	FrameRelayMapEntry getMapEntryAt(int index,std::string portName);
	int getIntDlciEntryAt(int index,std::string portName);
	int getLmiDlciEntryAt(int index);
	bool getLmiDlciStatusEntryAt(int index);
	int getMapEntryCount(std::string portName);
	int getIntDlciEntryCount(std::string portName);
	int getLmiDlciEntryCount();
	Port getIntDlciToPort(int dlci);
	void clearInvArpEntries();
	DlciTable getDlciTable();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------FrameRelayProcess.hEnds -------------//