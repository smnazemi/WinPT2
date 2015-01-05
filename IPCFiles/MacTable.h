//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 MacTable.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:46 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_MACTABLE_H
#define IPC_FW_MACTABLE_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"
#include "MacEntry.h"
#include "MacEntry.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class MacTable : public IpcBase
{
public :
	MacTable()
	{	
	}	
	MacTable(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="MacTable";
	}
	~MacTable()
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

	bool addMacEntry(CMacAddress  macAddress,std::string portName);
	bool removeMacEntry(CMacAddress  macAddress,std::string portName);
	MacEntry getEntryAt(int index);
	void removeEntryAt(int index);
	int getEntryCount();
	MacEntry getEntryOfMac(CMacAddress  macAddress);
	void clearMacTable();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------MacTable.hEnds -------------//