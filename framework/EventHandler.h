//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	EventHandler.h   
	Author:		Ajan U. Nair 
	Date:		28-Jul-2008   
	Revision:	1.0           
	Description:
		This file holds the EventHandler class implementation
		Event managerment functions are implemented here. 
*/

#if !defined(EVENT_HANDLER__INCLUDED_)
#define EVENT_HANDLER__INCLUDED_

#include <QString>
#include <QThread>
#include "IPCFrameWork.h"


#include "../PTMP/CPtmpMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../IPC/CIpcEvntSubsMsg.h"
#include "../IPC/CIpcEventMsg.h"

#include "IpcBase.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFrameWork;
class Network;
class IpcBase;

class EventHandler: public QThread
{
Q_OBJECT
	IPCFrameWork* m_ipcFwInstance;
	std::list<Ipc::CIpcEventMsg> m_eventQueue;
	std::multimap<std::string , IpcBase* > m_subscriptionMap;
	int m_state;//state=0 : not started,   =1 :started
public:
	QSemaphore m_ipcEventSyncSema;
	
	EventHandler(IPCFrameWork* fwInst)
	{
		m_ipcFwInstance=fwInst;
		m_state=0;
	}
	void processQandSendEvents();
	int subscribe(std::string className,std::string objectUuid,std::string eventName,IpcBase * subscriberObj);
	int unSubscribe(std::string className,std::string objectUuid,std::string eventName,IpcBase * subscriberObj);
	int EventHandler::removeFromSubscriptionMap(IpcBase * subscriberObj);
	void fireEvent(Ipc::CIpcEventMsg eventMsg);
protected:
	void run();
};
#endif