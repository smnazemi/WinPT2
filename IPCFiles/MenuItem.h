//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 MenuItem.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:49 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_MENUITEM_H
#define IPC_FW_MENUITEM_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;

class MenuItemEvents
{
public:
	virtual void onClicked()=0;
};



class MenuItem : public IpcBase
{
private:
	MenuItemEvents *m_eventsFunctor;
public :
	MenuItem()
	{	
	}	
	MenuItem(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="MenuItem";
		m_eventsFunctor=NULL;
	}
	~MenuItem()
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


	//Event Related functions 

	virtual void event(Ipc::CIpcEventMsg eventMsg);

	bool  MenuItem::subscribeEvent(std::string eventName);
	bool  MenuItem::unSubscribeEvent(std::string eventName);
	void  MenuItem::setEventCallBack(MenuItemEvents* eventFunctor);
};
#endif

//-----------MenuItem.hEnds -------------//