//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 InstructionDlg.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:49 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_INSTRUCTIONDLG_H
#define IPC_FW_INSTRUCTIONDLG_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class InstructionDlg : public IpcBase
{
public :
	InstructionDlg()
	{	
	}	
	InstructionDlg(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="InstructionDlg";
	}
	~InstructionDlg()
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

	void resetActivity();
	void showAnswerPage(bool bResetOnClose);
	void prev();
	void next();
	void alwaysOnTop(bool bOn);
	void setVisible(bool bVisible);
	void setWidgetVisible(std::string widgetName,bool bVisible);
	void setDisabled(bool bDisabled);
	void setWidgetDisable(std::string widgetName,bool bVisible);
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------InstructionDlg.hEnds -------------//