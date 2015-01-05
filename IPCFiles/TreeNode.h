//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 TreeNode.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:49 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_TREENODE_H
#define IPC_FW_TREENODE_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"
#include "TreeNode.h"
#include "TreeNode.h"
#include "TreeNode.h"
#include "TreeNode.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class TreeNode : public IpcBase
{
public :
	TreeNode()
	{	
	}	
	TreeNode(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="TreeNode";
	}
	~TreeNode()
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

	QString getNodeName();
	QString getNodeValue();
	TreeNode getParentNode();
	int getChildCount();
	int getCheckType();
	TreeNode getChildNodeAt(int index);
	TreeNode getChildNodeBy(QString name);
	TreeNode getCheckOnlyTree();
	QString getIncorrectFeedback();
	void setIncorrectFeedback(QString feedbackStr);
	int getLeafCount();
	int getCheckLeafCount();
	bool isVariableEnabled();
	void setCheck(bool bCheck);
	int getComparatorClass();
	void setNodeName(QString name);
	void setNodeValue(QString value);
	int getLeafCountByComponent(QString component);
	int getCheckLeafCountByComponent(QString component);
	int getCheckLeafPoints();
	std::pair<QString,QString> getCompPointPair();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------TreeNode.hEnds -------------//