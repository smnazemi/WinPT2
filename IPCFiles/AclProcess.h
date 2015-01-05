//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 AclProcess.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:43 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_ACLPROCESS_H
#define IPC_FW_ACLPROCESS_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "Process.h"
#include "Acl.h"
#include "Acl.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class AclProcess : public Process
{
public :
	AclProcess()
	{	
	}	
	AclProcess(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="AclProcess";
	}
	~AclProcess()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:43 pm";
	}

	void addAcl(std::string aclID);
	void removeAcl(std::string aclID);
	Acl getAcl(std::string aclID);
	Acl getAclAt(int index);
	int getAclCount();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------AclProcess.hEnds -------------//