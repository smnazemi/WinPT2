//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 Antenna.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:44 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_ANTENNA_H
#define IPC_FW_ANTENNA_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "Link.h"
#include "Port.h"
#include "Antenna.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class Antenna : public Link
{
public :
	Antenna()
	{	
	}	
	Antenna(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="Antenna";
	}
	~Antenna()
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

	Port  getPort();
	int getReceiverCount();
	Antenna getReceiverAt(int index);
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------Antenna.hEnds -------------//