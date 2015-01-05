//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 PLSwitch.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:50 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_PLSWITCH_H
#define IPC_FW_PLSWITCH_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;

class PLSwitchEvents
{
public:
	virtual void modeSwitched(bool isLogical)=0;
};



class PLSwitch : public IpcBase
{
private:
	PLSwitchEvents *m_eventsFunctor;
public :
	PLSwitch()
	{	
	}	
	PLSwitch(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="PLSwitch";
		m_eventsFunctor=NULL;
	}
	~PLSwitch()
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
	void setDisabled(bool bDisabled);
	void setWidgetDisable(std::string widgetName,bool bDisabled);
	void showLogicalMode();
	void showPhysicalMode();

	//Event Related functions 

	virtual void event(Ipc::CIpcEventMsg eventMsg);

	bool  PLSwitch::subscribeEvent(std::string eventName);
	bool  PLSwitch::unSubscribeEvent(std::string eventName);
	void  PLSwitch::setEventCallBack(PLSwitchEvents* eventFunctor);
};
#endif

//-----------PLSwitch.hEnds -------------//