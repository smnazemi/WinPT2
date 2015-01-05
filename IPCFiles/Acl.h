//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 Acl.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:43 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_ACL_H
#define IPC_FW_ACL_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"
#include "AclStatement.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class Acl : public IpcBase
{
public :
	Acl()
	{	
	}	
	Acl(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="Acl";
	}
	~Acl()
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

	bool addStatement(std::string statement);
	bool removeStatement(std::string statement);
	AclStatement getStatementAt(int index);
	int getStatementCount();
	void addRemark(std::string remark);
	std::string getRemark(int index);
	int getRemarkCount();
	int getCommandCount();
	std::string getCommandAt(int index);
	bool isExtended();
	std::string getAclId();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------Acl.hEnds -------------//