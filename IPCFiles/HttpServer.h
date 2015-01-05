//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 HttpServer.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:46 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_HTTPSERVER_H
#define IPC_FW_HTTPSERVER_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "Process.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class HttpServer : public Process
{
public :
	HttpServer()
	{	
	}	
	HttpServer(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="HttpServer";
	}
	~HttpServer()
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

	void setEnable(bool bEnable);
	bool isEnabled();
	void setPortNumber(short portNum);
	short getPortNumber();
	std::string getPage(std::string url);
	std::string getUsername();
	std::string getPassword();
	void setUsername(std::string username);
	void setPassword(std::string password);
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------HttpServer.hEnds -------------//