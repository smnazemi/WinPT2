//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 LogicalWorkspace.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:49 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_LOGICALWORKSPACE_H
#define IPC_FW_LOGICALWORKSPACE_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"
#include "ComponentItem.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;

class LogicalWorkspaceEvents
{
public:
	virtual void deviceAdded(QString name)=0;
	virtual void deviceRemoved(QString name)=0;
	virtual void linkCreated(QString deviceName1,std::string portName1,QString deviceName2,std::string portName2,int connType)=0;
};



class LogicalWorkspace : public IpcBase
{
private:
	LogicalWorkspaceEvents *m_eventsFunctor;
public :
	LogicalWorkspace()
	{	
	}	
	LogicalWorkspace(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="LogicalWorkspace";
		m_eventsFunctor=NULL;
	}
	~LogicalWorkspace()
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

	int getState();
	int getComponentItemsCount();
	ComponentItem getComponentItem(QString deviceName);
	QString addDevice(int type,std::string model);
	QString addRemoteNetwork();
	bool removeDevice(QString deviceName);
	int getConnection(QString deviceName, std::string portName);
	bool createLink(QString deviceName1,std::string portName1,QString deviceName2,std::string portName2,int connType);

	//Event Related functions 

	virtual void event(Ipc::CIpcEventMsg eventMsg);

	bool  LogicalWorkspace::subscribeEvent(std::string eventName);
	bool  LogicalWorkspace::unSubscribeEvent(std::string eventName);
	void  LogicalWorkspace::setEventCallBack(LogicalWorkspaceEvents* eventFunctor);
};
#endif

//-----------LogicalWorkspace.hEnds -------------//