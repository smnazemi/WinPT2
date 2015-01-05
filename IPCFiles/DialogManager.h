//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 DialogManager.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:49 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_DIALOGMANAGER_H
#define IPC_FW_DIALOGMANAGER_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"
#include "DeviceDialog.h"
#include "DeviceDialog.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class DialogManager : public IpcBase
{
public :
	DialogManager()
	{	
	}	
	DialogManager(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="DialogManager";
	}
	~DialogManager()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:49 pm";
	}

	void closeAll();
	DeviceDialog getCurrentDialog();
	DeviceDialog getDialog(std::string deviceName);
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------DialogManager.hEnds -------------//