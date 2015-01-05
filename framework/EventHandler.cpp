//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	EventHandler.cpp   
	Author:		Ajan U. Nair 
	Date:		28-Jul-2008   
	Revision:	1.0           
	Description:
		This file holds the EventHandler class implementation
		Event managerment functions are implemented here. 
*/
#include "EventHandler.h"
#include "IpcBase.h"


using namespace std;
using namespace Ptmp;
using namespace Ipc;


class IpcBase;

void EventHandler::run()
{
	fwDebug("\nEventThread Run!");
	m_state=1;
	//m_ipcEventSyncSema.acquire(1);
	while(true)
	{
		m_ipcEventSyncSema.acquire(1);
		processQandSendEvents();
	}
	return;
}
void EventHandler::processQandSendEvents()
{
	while(!m_eventQueue.empty())
	{
		std::string eventName=m_eventQueue.front().getEventName();
		std::pair<std::multimap<std::string ,IpcBase*>::iterator, std::multimap<std::string ,IpcBase*>::iterator> itPair;
		itPair =m_subscriptionMap.equal_range(eventName);
		for (std::multimap<std::string ,IpcBase*>::iterator it = itPair.first; it != itPair.second; ++it) 
		{
			if((*it).second!=NULL)
			{
				((*it).second)->event(m_eventQueue.front());
			}
		}
		m_eventQueue.pop_front();
	}
	return;
}
int EventHandler::subscribe(std::string className,std::string objectUuid,std::string eventName,IpcBase * subscriberObj)
{
	if(m_state==0)
	{
		this->start();
	}
	QUuid objUuid(QString::fromStdString(objectUuid));

	if((m_ipcFwInstance->sendSubscribeForEvents(className,objUuid,eventName)))
	{
		m_subscriptionMap.insert(std::make_pair(eventName,subscriberObj));
	}else
	{
		return 0;
	}
	return 1;
}
int EventHandler::unSubscribe(std::string className,std::string objectUuid,std::string eventName,IpcBase * subscriberObj)
{
	QUuid objUuid(QString::fromStdString(objectUuid));
	if((m_ipcFwInstance->sendUnSubscribeForEvents(className,objUuid,eventName)))
	{
		std::pair<std::multimap<std::string ,IpcBase*>::iterator, std::multimap<std::string ,IpcBase*>::iterator> itPair;
		itPair =m_subscriptionMap.equal_range(eventName);

		std::multimap<std::string ,IpcBase*>::iterator it = itPair.first; 
		while(it != itPair.second)
		{
			if((*it).second ==subscriberObj)
			{
				m_subscriptionMap.erase(it++);//it is incremented first, then old value is passed to erase()
			}else
			{
				it++;
			}
		}
	}else
	{
		return 0;
	}
	return 1;
}	

int EventHandler::removeFromSubscriptionMap(IpcBase * subscriberObj)
{
	if(m_subscriptionMap.size()==0)
		return 0;

	std::multimap<std::string ,IpcBase*>::iterator it;
	it= m_subscriptionMap.begin();

	while(it!=m_subscriptionMap.end())
	{
		if((*it).second==subscriberObj)
		{
			m_subscriptionMap.erase(it++);//it is incremented first, then old value is passed to erase()
		}else
		{
			it++;
		}
	}
	return 1;
}

void EventHandler::fireEvent(Ipc::CIpcEventMsg eventMsg)
{
	m_eventQueue.push_back(eventMsg);
	m_ipcEventSyncSema.release(1);
}

