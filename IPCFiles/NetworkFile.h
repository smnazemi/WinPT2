//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 NetworkFile.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:49 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_NETWORKFILE_H
#define IPC_FW_NETWORKFILE_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"
#include "Options.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;

class NetworkFileEvents
{
public:
	virtual void fileNewed()=0;
	virtual void fileOpened()=0;
	virtual void fileSaved()=0;
};



class NetworkFile : public IpcBase
{
private:
	NetworkFileEvents *m_eventsFunctor;
public :
	NetworkFile()
	{	
	}	
	NetworkFile(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="NetworkFile";
		m_eventsFunctor=NULL;
	}
	~NetworkFile()
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

	QString getSavedFilename();
	QString getVersion();
	QString getNetworkDescription();
	void setNetworkDescription(QString description);
	Options getOptions();

	//Event Related functions 

	virtual void event(Ipc::CIpcEventMsg eventMsg);

	bool  NetworkFile::subscribeEvent(std::string eventName);
	bool  NetworkFile::unSubscribeEvent(std::string eventName);
	void  NetworkFile::setEventCallBack(NetworkFileEvents* eventFunctor);
};
#endif

//-----------NetworkFile.hEnds -------------//