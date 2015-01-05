//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 VtpProcess.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:49 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_VTPPROCESS_H
#define IPC_FW_VTPPROCESS_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "Process.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class VtpProcess : public Process
{
public :
	VtpProcess()
	{	
	}	
	VtpProcess(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="VtpProcess";
	}
	~VtpProcess()
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

	void setDomainName(std::string domainName);
	std::string getDomainName();
	void setMode(int type);
	int getMode();
	void setVersion(char version);
	char getVersion();
	void setPassword(std::string password);
	std::string getPassword();
	int getConfigRevision();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------VtpProcess.hEnds -------------//