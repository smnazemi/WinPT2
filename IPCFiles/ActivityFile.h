//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 ActivityFile.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:43 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_ACTIVITYFILE_H
#define IPC_FW_ACTIVITYFILE_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"

#include "NetworkFile.h"
#include "TreeNode.h"
#include "TreeNode.h"
#include "NetworkFile.h"
#include "NetworkFile.h"
#include "NetworkFile.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class ActivityFile : public NetworkFile
{
public :
	ActivityFile()
	{	
	}	
	ActivityFile(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="ActivityFile";
	}
	~ActivityFile()
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

	QString getInstruction(int index);
	QString getInstructionSource(int index);
	QString getCurrentInstructionSource();
	QString getCurrentInstruction();
	int getInstructionCount();
	void resetActivity();
	double getPercentageComplete();
	double getAssessmentItemsCount();
	double getCorrectAssessmentItemsCount();
	double getConnectivityCount();
	TreeNode getComparatorTree();
	TreeNode getAssessedComparatorTree();
	void nextInstructionPage();
	void prevInstructionPage();
	void removeInstructionPage();
	void insertInstructionPage();
	NetworkFile getInitNetworkFile();
	NetworkFile getAnsNetworkFile();
	NetworkFile getUserNetworkFile();
	std::vector<QString> getComponentList();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------ActivityFile.hEnds -------------//