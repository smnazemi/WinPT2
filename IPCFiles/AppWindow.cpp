//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 AppWindow.cpp 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:43 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#include "AppWindow.h"

MenuBar AppWindow::getMenuBar()
{
	std::string callName= "getMenuBar";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	MenuBar menubarObj(m_ipcFramework,*buf);

	return menubarObj;
}
RSSwitch AppWindow::getRSSwitch()
{
	std::string callName= "getRSSwitch";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	RSSwitch rsswitchObj(m_ipcFramework,*buf);

	return rsswitchObj;
}
PLSwitch AppWindow::getPLSwitch()
{
	std::string callName= "getPLSwitch";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	PLSwitch plswitchObj(m_ipcFramework,*buf);

	return plswitchObj;
}
LogicalToolbar AppWindow::getLogicalToolbar()
{
	std::string callName= "getLogicalToolbar";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	LogicalToolbar logicaltoolbarObj(m_ipcFramework,*buf);

	return logicaltoolbarObj;
}
PhysicalToolbar AppWindow::getPhysicalToolbar()
{
	std::string callName= "getPhysicalToolbar";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	PhysicalToolbar physicaltoolbarObj(m_ipcFramework,*buf);

	return physicaltoolbarObj;
}
SimulationToolbar AppWindow::getSimulationToolbar()
{
	std::string callName= "getSimulationToolbar";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	SimulationToolbar simulationtoolbarObj(m_ipcFramework,*buf);

	return simulationtoolbarObj;
}
RealtimeToolbar AppWindow::getRealtimeToolbar()
{
	std::string callName= "getRealtimeToolbar";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	RealtimeToolbar realtimetoolbarObj(m_ipcFramework,*buf);

	return realtimetoolbarObj;
}
PhysicalLocationDialog AppWindow::getPhysicalLocationDialog()
{
	std::string callName= "getPhysicalLocationDialog";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	PhysicalLocationDialog physicallocationdialogObj(m_ipcFramework,*buf);

	return physicallocationdialogObj;
}
SimulationPanel AppWindow::getSimulationPanel()
{
	std::string callName= "getSimulationPanel";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	SimulationPanel simulationpanelObj(m_ipcFramework,*buf);

	return simulationpanelObj;
}
UserCreatedPDU AppWindow::getUserCreatedPDU()
{
	std::string callName= "getUserCreatedPDU";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	UserCreatedPDU usercreatedpduObj(m_ipcFramework,*buf);

	return usercreatedpduObj;
}
NetworkComponentBox AppWindow::getNetworkComponentBox()
{
	std::string callName= "getNetworkComponentBox";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	NetworkComponentBox networkcomponentboxObj(m_ipcFramework,*buf);

	return networkcomponentboxObj;
}
PDUListWindow AppWindow::getPDUListWindow()
{
	std::string callName= "getPDUListWindow";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	PDUListWindow pdulistwindowObj(m_ipcFramework,*buf);

	return pdulistwindowObj;
}
ActivityWizard AppWindow::getActivityWizard()
{
	std::string callName= "getActivityWizard";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	ActivityWizard activitywizardObj(m_ipcFramework,*buf);

	return activitywizardObj;
}
InfoDialog AppWindow::getInfoDialog()
{
	std::string callName= "getInfoDialog";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	InfoDialog infodialogObj(m_ipcFramework,*buf);

	return infodialogObj;
}
CommonToolbar AppWindow::getCommonToolbar()
{
	std::string callName= "getCommonToolbar";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	CommonToolbar commontoolbarObj(m_ipcFramework,*buf);

	return commontoolbarObj;
}
bool AppWindow::isSimulationMode()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="isSimulationMode";
	newBuf->write(callName);
	newBuf->writeTypeValue(eVoid);
	CallResult callResult=m_ipcFramework->makeIPCCall(newBuf);
	if(!callResult.callStatus)
	{
		std::string errMsg="IPC call failed :";
		errMsg.append(callResult.errClassName);
		errMsg.append(":");
		errMsg.append(callResult.errInfo);
		throw IpcFwException(errMsg);
	}else
	{
		callResult.returnDataBuffer.readInt();
		bool returnInfo=callResult.returnDataBuffer.readBool();
		return returnInfo;
	}
}
bool AppWindow::isRealtimeMode()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="isRealtimeMode";
	newBuf->write(callName);
	newBuf->writeTypeValue(eVoid);
	CallResult callResult=m_ipcFramework->makeIPCCall(newBuf);
	if(!callResult.callStatus)
	{
		std::string errMsg="IPC call failed :";
		errMsg.append(callResult.errClassName);
		errMsg.append(":");
		errMsg.append(callResult.errInfo);
		throw IpcFwException(errMsg);
	}else
	{
		callResult.returnDataBuffer.readInt();
		bool returnInfo=callResult.returnDataBuffer.readBool();
		return returnInfo;
	}
}
bool AppWindow::isLogicalMode()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="isLogicalMode";
	newBuf->write(callName);
	newBuf->writeTypeValue(eVoid);
	CallResult callResult=m_ipcFramework->makeIPCCall(newBuf);
	if(!callResult.callStatus)
	{
		std::string errMsg="IPC call failed :";
		errMsg.append(callResult.errClassName);
		errMsg.append(":");
		errMsg.append(callResult.errInfo);
		throw IpcFwException(errMsg);
	}else
	{
		callResult.returnDataBuffer.readInt();
		bool returnInfo=callResult.returnDataBuffer.readBool();
		return returnInfo;
	}
}
bool AppWindow::isPhysicalMode()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="isPhysicalMode";
	newBuf->write(callName);
	newBuf->writeTypeValue(eVoid);
	CallResult callResult=m_ipcFramework->makeIPCCall(newBuf);
	if(!callResult.callStatus)
	{
		std::string errMsg="IPC call failed :";
		errMsg.append(callResult.errClassName);
		errMsg.append(":");
		errMsg.append(callResult.errInfo);
		throw IpcFwException(errMsg);
	}else
	{
		callResult.returnDataBuffer.readInt();
		bool returnInfo=callResult.returnDataBuffer.readBool();
		return returnInfo;
	}
}
Workspace AppWindow::getActiveWorkspace()
{
	std::string callName= "getActiveWorkspace";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	Workspace workspaceObj(m_ipcFramework,*buf);

	return workspaceObj;
}
ActiveDialog AppWindow::getActiveDialog()
{
	std::string callName= "getActiveDialog";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	ActiveDialog activedialogObj(m_ipcFramework,*buf);

	return activedialogObj;
}
AdministrativeDialog AppWindow::getAdminDialog()
{
	std::string callName= "getAdminDialog";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	AdministrativeDialog administrativedialogObj(m_ipcFramework,*buf);

	return administrativedialogObj;
}
PaletteDialog AppWindow::getPaletteDialog()
{
	std::string callName= "getPaletteDialog";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	PaletteDialog palettedialogObj(m_ipcFramework,*buf);

	return palettedialogObj;
}
InstructionDlg AppWindow::getInstructionDlg()
{
	std::string callName= "getInstructionDlg";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	InstructionDlg instructiondlgObj(m_ipcFramework,*buf);

	return instructiondlgObj;
}
NetworkFile AppWindow::getActiveFile()
{
	std::string callName= "getActiveFile";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	NetworkFile networkfileObj(m_ipcFramework,*buf);

	return networkfileObj;
}
void AppWindow::exit()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="exit";
	newBuf->write(callName);
	newBuf->writeTypeValue(eVoid);
	CallResult callResult=m_ipcFramework->makeIPCCall(newBuf);
	if(!callResult.callStatus)
	{
		std::string errMsg="IPC call failed :";
		errMsg.append(callResult.errClassName);
		errMsg.append(":");
		errMsg.append(callResult.errInfo);
		throw IpcFwException(errMsg);
	}else
	{
		return ;
	}
}
DialogManager AppWindow::getDialogManager()
{
	std::string callName= "getDialogManager";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	DialogManager dialogmanagerObj(m_ipcFramework,*buf);

	return dialogmanagerObj;
}
void AppWindow::writeToPT(QString msg)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="writeToPT";
	newBuf->write(callName);
	newBuf->write(eQString);

	newBuf->write(msg);

	newBuf->writeTypeValue(eVoid);
	CallResult callResult=m_ipcFramework->makeIPCCall(newBuf);
	if(!callResult.callStatus)
	{
		std::string errMsg="IPC call failed :";
		errMsg.append(callResult.errClassName);
		errMsg.append(":");
		errMsg.append(callResult.errInfo);
		throw IpcFwException(errMsg);
	}else
	{
		return ;
	}
}
bool AppWindow::fileOpen(QString filename)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="fileOpen";
	newBuf->write(callName);
	newBuf->write(eQString);

	newBuf->write(filename);

	newBuf->writeTypeValue(eVoid);
	CallResult callResult=m_ipcFramework->makeIPCCall(newBuf);
	if(!callResult.callStatus)
	{
		std::string errMsg="IPC call failed :";
		errMsg.append(callResult.errClassName);
		errMsg.append(":");
		errMsg.append(callResult.errInfo);
		throw IpcFwException(errMsg);
	}else
	{
		callResult.returnDataBuffer.readInt();
		bool returnInfo=callResult.returnDataBuffer.readBool();
		return returnInfo;
	}
}
