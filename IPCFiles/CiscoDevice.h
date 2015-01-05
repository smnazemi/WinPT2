//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 CiscoDevice.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:44 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_CISCODEVICE_H
#define IPC_FW_CISCODEVICE_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "Device.h"
#include "Port.h"
#include "TerminalLine.h"
#include "TerminalLine.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class CiscoDevice : public Device
{
public :
	CiscoDevice()
	{	
	}	
	CiscoDevice(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="CiscoDevice";
	}
	~CiscoDevice()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:44 pm";
	}

	void setHostName(std::string hostname);
	std::string getHostName();
	void setEnableSecret(std::string password);
	std::string getEnableSecret();
	void setEnablePassword(std::string password,int level);
	std::string getEnablePassword();
	void setStartupFile(std::string str);
	std::vector<std::string> getStartupFile();
	bool addBootSystem(std::string name);
	bool removeBootSystem(std::string name);
	void removeAllBootSystem();
	std::vector<std::string> getBootSystems();
	int  getConfigRegister();
	void setNextConfigRegister(int m_register);
	int  getNextConfigRegister();
	void setBannerMotd(std::string banner);
	std::string getBannerMotd();
	void  setTimeZone(std::string timeZone,short hourOffset,short minOffset);
	std::string getTimeZone();
	CMacAddress  getBia();
	void  setServicePasswordEncryption(bool bEnable);
	bool getServicePasswordEncryption();
	Port getConsole();
	TerminalLine getConsoleLine();
	TerminalLine getVtyLine(int num);
	std::pair<int,std::string> enterCommand(std::string commandStr,std::string modeStr);
	void skipBoot();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------CiscoDevice.hEnds -------------//