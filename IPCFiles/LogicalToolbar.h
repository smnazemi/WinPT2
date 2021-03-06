//************************************************************************
//
// � Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 LogicalToolbar.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:49 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_LOGICALTOOLBAR_H
#define IPC_FW_LOGICALTOOLBAR_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class LogicalToolbar : public IpcBase
{
public :
	LogicalToolbar()
	{	
	}	
	LogicalToolbar(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="LogicalToolbar";
	}
	~LogicalToolbar()
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

	void setVisible(bool bVisible);
	void setWidgetVisible(std::string widgetName,bool bVisible);
	void setDisabled(bool bDisabled);
	void setWidgetDisable(std::string widgetName,bool bVisible);
	void createCluster();
	void showLevel1Cluster();
	void showLevel2Cluster();
	void showLevel3Cluster();
	void showLevel4Cluster();
	void showViewPort();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------LogicalToolbar.hEnds -------------//