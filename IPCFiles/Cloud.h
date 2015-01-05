//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 Cloud.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:44 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_CLOUD_H
#define IPC_FW_CLOUD_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "Device.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class Cloud : public Device
{
public :
	Cloud()
	{	
	}	
	Cloud(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="Cloud";
	}
	~Cloud()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:44 pm";
	}

	bool addPhoneConnection(std::string number,std::string portName);
	void removePhoneConnection(std::string number);
	bool addActivePhoneConnection(std::string portName1,std::string portName2);
	bool removeActivePhoneConnection(std::string portName1,std::string portName2);
	bool addSubLinkConnection(std::string portName1,std::string portName2);
	bool removeSubLinkConnection(std::string subLink);
	bool addSignaling(std::string portName,bool bDSL);
	bool removeSignaling(std::string portName);
	bool setDslSignaling(std::string portName,bool bDSL);
	bool addPortConnection(std::string portName1,std::string portName2);
	bool removePortConnection(std::string portName);
	bool removeAllPortConnection(std::string portName);
	bool addHostMacMapping(CMacAddress  macAddress,std::string portName);
	void removeHostMacMapping(CMacAddress  macAddress);
	bool setDslConnection(std::string portName,bool bDSL);
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------Cloud.hEnds -------------//