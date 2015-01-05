//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 TerminalLine.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:48 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_TERMINALLINE_H
#define IPC_FW_TERMINALLINE_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"
#include "CommandHistory.h"
#include "CommandHistory.h"
#include "CommandHistory.h"
#include "TelnetClientProcess.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class TerminalLine : public IpcBase
{
public :
	TerminalLine()
	{	
	}	
	TerminalLine(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="TerminalLine";
	}
	~TerminalLine()
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

	std::string getName();
	std::string getMode();
	std::string getPrompt();
	CommandHistory getUserHistory();
	CommandHistory getConfigHistory();
	CommandHistory getCurrentHistory();
	int getHistorySize();
	std::string getCommandInput();
	int getTelnetClientCount();
	TelnetClientProcess getTelnetClientAt(int index);
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------TerminalLine.hEnds -------------//