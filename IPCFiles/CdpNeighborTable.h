//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 CdpNeighborTable.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:44 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_CDPNEIGHBORTABLE_H
#define IPC_FW_CDPNEIGHBORTABLE_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"
#include "CdpNeighbor.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class CdpNeighborTable : public IpcBase
{
public :
	CdpNeighborTable()
	{	
	}	
	CdpNeighborTable(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="CdpNeighborTable";
	}
	~CdpNeighborTable()
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

	int getNeighborTableCount();
	CdpNeighbor getCdpNeighborAt(int index);
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------CdpNeighborTable.hEnds -------------//