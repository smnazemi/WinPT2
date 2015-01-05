//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 RSSwitch.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:50 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_RSSWITCH_H
#define IPC_FW_RSSWITCH_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;

class RSSwitchEvents
{
public:
	virtual void modeSwitched(bool isRealtime)=0;
};



class RSSwitch : public IpcBase
{
private:
	RSSwitchEvents *m_eventsFunctor;
public :
	RSSwitch()
	{	
	}	
	RSSwitch(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="RSSwitch";
		m_eventsFunctor=NULL;
	}
	~RSSwitch()
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

	void setVisible(bool bVisible);
	void setWidgetVisible(std::string widgetName,bool bVisible);
	void setDisabled(bool bDisable);
	void setWidgetDisable(std::string widgetName,bool bDisable);
	void showRealtimeMode();
	void showSimulationMode();

	//Event Related functions 

	virtual void event(Ipc::CIpcEventMsg eventMsg);

	bool  RSSwitch::subscribeEvent(std::string eventName);
	bool  RSSwitch::unSubscribeEvent(std::string eventName);
	void  RSSwitch::setEventCallBack(RSSwitchEvents* eventFunctor);
};
#endif

//-----------RSSwitch.hEnds -------------//