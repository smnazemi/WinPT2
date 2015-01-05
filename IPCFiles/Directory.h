//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 Directory.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:45 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_DIRECTORY_H
#define IPC_FW_DIRECTORY_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"
#include "File.h"
#include "File.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class Directory : public IpcBase
{
public :
	Directory()
	{	
	}	
	Directory(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="Directory";
	}
	~Directory()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:45 pm";
	}

	int getFileCount();
	File getFileAt(int index);
	File getFile(std::string filename);
	int getSpaceUsed();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------Directory.hEnds -------------//