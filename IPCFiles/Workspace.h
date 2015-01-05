//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 Workspace.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:50 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_WORKSPACE_H
#define IPC_FW_WORKSPACE_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"
#include "LogicalWorkspace.h"
#include "GeoView.h"
#include "RackView.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class Workspace : public IpcBase
{
public :
	Workspace()
	{	
	}	
	Workspace(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="Workspace";
	}
	~Workspace()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:50 pm";
	}

	bool isLogicalView();
	bool isGeoView();
	bool isRackView();
	LogicalWorkspace getLogicalWorkspace();
	GeoView getGeoView();
	RackView getRackView();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------Workspace.hEnds -------------//