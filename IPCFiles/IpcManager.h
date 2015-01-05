//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 IpcManager.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:46 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_IPCMANAGER_H
#define IPC_FW_IPCMANAGER_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;

class IpcManagerEvents
{
public:
	virtual void onSave(QUuid  saveId)=0;
	virtual void onOpen(QUuid  openId,QString openData)=0;
};



class IpcManager : public IpcBase
{
private:
	IpcManagerEvents *m_eventsFunctor;
public :
	IpcManager()
	{	
	}	
	IpcManager(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="IpcManager";
		m_eventsFunctor=NULL;
	}
	~IpcManager()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:46 pm";
	}

	int getListeningPort();
	bool launchCep(std::string cepId);
	bool putSaveData(QUuid  saveId,QString saveData);
	QString getOpenData(QUuid  openId);

	//Event Related functions 

	virtual void event(Ipc::CIpcEventMsg eventMsg);

	bool  IpcManager::subscribeEvent(std::string eventName);
	bool  IpcManager::unSubscribeEvent(std::string eventName);
	void  IpcManager::setEventCallBack(IpcManagerEvents* eventFunctor);
};
#endif

//-----------IpcManager.hEnds -------------//