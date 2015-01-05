//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 Router.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:48 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_ROUTER_H
#define IPC_FW_ROUTER_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "CiscoDevice.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class Router : public CiscoDevice
{
public :
	Router()
	{	
	}	
	Router(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="Router";
	}
	~Router()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:48 pm";
	}

	bool addSubInt(std::string portName,int subIntNum);
	bool removeSubInt(std::string portName);
	bool changePortEncapsulation(std::string portname,std::string encapsulationType);
	void addUserPass(std::string username,std::string password,int type);
	void removeUserPass(std::string username);
	std::string getUserPass(std::string username);
	int getUserPassCount();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------Router.hEnds -------------//