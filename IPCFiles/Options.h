//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 Options.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:50 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_OPTIONS_H
#define IPC_FW_OPTIONS_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class Options : public IpcBase
{
public :
	Options()
	{	
	}	
	Options(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="Options";
	}
	~Options()
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

	bool isAnimation();
	bool isSound();
	bool isDockFirst();
	bool isLoggingEnabled();
	bool isPortShown();
	bool isChallenge_PDUInfo();
	bool isDeviceModelShown();
	bool isLinkLightsShown();
	bool isAccessible();
	bool isPhysicalTabShown();
	bool isConfigTabShown();
	bool isCLITabShown();
	bool isDesktopTabShown();
	bool isGUITabShown();
	bool isHideDevLabel();
	QString getConfigFilePath();
	void setAnimation(bool bEnable);
	void setSound(bool bEnable);
	void setIsDockFirst(bool bEnable);
	void setIsLoggingEnabled(bool bEnable);
	void setIsPortShown(bool bEnable);
	void setIsChallenge_PDUInfo(bool bEnable);
	void setAccessible(bool bEnable);
	void setIsDeviceModelShown(bool bEnable);
	void setIsLinkLightShown(bool bEnable);
	void addBackgroundImage(QString location,QString filePath);
	void removeBackgroundImage(QString filePath);
	void setPhysicalTabShown(bool bEnable);
	void setConfigTabShown(bool bEnable);
	void setCLITabShown(bool bEnable);
	void setDesktopTabShown(bool bEnable);
	void setGUITabShown(bool bEnable);
	void setHideDevLabel(bool bEnable,bool isWorkspaceActive);
	void saveFile(QString filename);
	void openFile(QString filename);
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------Options.hEnds -------------//