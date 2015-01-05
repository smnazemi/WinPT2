//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is
//  prohibited unless authorized in writing.
//
//************************************************************************
/*! /file
	File Name:	 MuRemoteNetworkEvents.h
	Author:		 Tony Deng
	Date:		 April 29 2009  	Time: 10:30:00 am
	Revision:	 1.0
	Description: Hand written, may have errors :-)
*/
#ifndef IPC_FW_MUREMOTENETWORK_H
#define IPC_FW_MUREMOTENETWORK_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "Device.h"
#include "Port.h"
#include "TerminalLine.h"
#include "TerminalLine.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;

class MuRemoteNetworkEvents
{
public:
	virtual void peerConnected()=0;
	virtual void peerDisconnected()=0;
};


class MuRemoteNetwork : public Device
{
private:
	MuRemoteNetworkEvents *m_eventsFunctor;
public :
	MuRemoteNetwork()
	{
	}
	MuRemoteNetwork(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="MuRemoteNetwork";
		m_eventsFunctor=NULL;
	}
	~MuRemoteNetwork()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu April 29 2009  	Time: 10:30:00 am";
	}

	bool connect(QString peerAddress, int peerPort, QString userName, QString password);
	void disconnect();
	bool isConnected();

	//Event Related functions

	virtual void event(Ipc::CIpcEventMsg eventMsg);

	bool  MuRemoteNetwork::subscribeEvent(std::string eventName);
	bool  MuRemoteNetwork::unSubscribeEvent(std::string eventName);
	void  MuRemoteNetwork::setEventCallBack(MuRemoteNetworkEvents* eventFunctor);
};
#endif

//-----------MuRemoteNetwork.hEnds -------------//