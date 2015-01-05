//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 MenuBar.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:49 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_MENUBAR_H
#define IPC_FW_MENUBAR_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"
#include "Menu.h"
#include "Menu.h"
#include "Menu.h"
#include "Menu.h"
#include "Menu.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class MenuBar : public IpcBase
{
public :
	MenuBar()
	{	
	}	
	MenuBar(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="MenuBar";
	}
	~MenuBar()
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

	Menu getFilePopupMenu();
	Menu getEditPopupMenu();
	Menu getOptionsPopupMenu();
	Menu getExtensionsPopupMenu();
	Menu getHelpPopupMenu();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------MenuBar.hEnds -------------//