//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is
//  prohibited unless authorized in writing.
//
//************************************************************************
/*! /file
	File Name:	 MultiUserManager.h
	Author:		 Ajan U. Nair, Tony Deng
	Date:		 Thu August 21 2008  	Time: 13:14:46 pm
	Revision:	 1.2
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_MULTIUSERMANAGER_H
#define IPC_FW_MULTIUSERMANAGER_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"
#include "RemoteNetwork.h"
using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class MultiUserManager : public IpcBase
{
public :
	enum EAcceptMode
	{
		eAlwaysAccept,
		eAlwaysDeny,
		ePrompt
	};
	MultiUserManager()
	{
	}
	MultiUserManager(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="MultiUserManager";
	}
	~MultiUserManager()
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

	bool isServerStarted();
	int getPortNumber();

	bool startServer(int portNumber, QString password);
	bool stopServer();
	void setPassword(QString password) ;
	QString getPassword();
	void setAcceptMode(EAcceptMode acceptMode);
	EAcceptMode getAcceptMode();

	int getRemoteNetworkCount();

	RemoteNetwork getRemoteNetworkAt(int index);
	RemoteNetwork getRemoteNetworkByName(QString name);
};
#endif


//-----------MultiUserManager.hEnds -------------//