//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 UserCreatedPDU.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:50 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_USERCREATEDPDU_H
#define IPC_FW_USERCREATEDPDU_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class UserCreatedPDU : public IpcBase
{
public :
	UserCreatedPDU()
	{	
	}	
	UserCreatedPDU(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="UserCreatedPDU";
	}
	~UserCreatedPDU()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:50 pm";
	}

	void setVisible(bool bVisible);
	void setWidgetVisible(std::string widgetName,bool bVisible);
	void setDisabled(bool bDisable);
	void setWidgetDisable(std::string widgetName,bool bDisable);
	void activateScenario(int index);
	void deleteScenarioBtn_clicked();
	void newScenarioBtn_clicked();
	void scenarioInfoBtn_clicked();
	void removePDUBtn_clicked();
	void toggleOpenListWindowBtn(bool bEnable);
	void setScenarioDescription(std::string description);
	void firePDU(int index);
	void colorPDU(int index);
	void editPDU(int index);
	void deletePDU(int index);
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------UserCreatedPDU.hEnds -------------//