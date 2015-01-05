//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 AppWindow.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:43 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_APPWINDOW_H
#define IPC_FW_APPWINDOW_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"
#include "MenuBar.h"
#include "RSSwitch.h"
#include "PLSwitch.h"
#include "LogicalToolbar.h"
#include "PhysicalToolbar.h"
#include "SimulationToolbar.h"
#include "RealtimeToolbar.h"
#include "PhysicalLocationDialog.h"
#include "SimulationPanel.h"
#include "UserCreatedPDU.h"
#include "NetworkComponentBox.h"
#include "PDUListWindow.h"
#include "ActivityWizard.h"
#include "InfoDialog.h"
#include "CommonToolbar.h"
#include "Workspace.h"
#include "ActiveDialog.h"
#include "AdministrativeDialog.h"
#include "PaletteDialog.h"
#include "InstructionDlg.h"
#include "NetworkFile.h"
#include "DialogManager.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class AppWindow : public IpcBase
{
public :
	AppWindow()
	{	
	}	
	AppWindow(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="AppWindow";
	}
	~AppWindow()
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

	MenuBar getMenuBar();
	RSSwitch getRSSwitch();
	PLSwitch getPLSwitch();
	LogicalToolbar getLogicalToolbar();
	PhysicalToolbar getPhysicalToolbar();
	SimulationToolbar getSimulationToolbar();
	RealtimeToolbar getRealtimeToolbar();
	PhysicalLocationDialog getPhysicalLocationDialog();
	SimulationPanel getSimulationPanel();
	UserCreatedPDU getUserCreatedPDU();
	NetworkComponentBox getNetworkComponentBox();
	PDUListWindow getPDUListWindow();
	ActivityWizard getActivityWizard();
	InfoDialog getInfoDialog();
	CommonToolbar getCommonToolbar();
	bool isSimulationMode();
	bool isRealtimeMode();
	bool isLogicalMode();
	bool isPhysicalMode();
	Workspace getActiveWorkspace();
	ActiveDialog getActiveDialog();
	AdministrativeDialog getAdminDialog();
	PaletteDialog getPaletteDialog();
	InstructionDlg getInstructionDlg();
	NetworkFile getActiveFile();
	void exit();
	DialogManager getDialogManager();
	void writeToPT(QString msg);
	bool fileOpen(QString filename);
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------AppWindow.hEnds -------------//