//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 ComponentItem.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:47 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_COMPONENTITEM_H
#define IPC_FW_COMPONENTITEM_H

#include "../framework/IPCFrameWork.h"

#include "../PTMP/CDataMsg.h"
#include "../IPC/CIpcCallMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsgParameter.h"
#include "Device.h"

using namespace Ptmp;
using namespace Ipc;

class IPCFramework;




class ComponentItem : public IpcBase
{
public :
	ComponentItem()
	{	
	}	
	ComponentItem(IPCFrameWork* ipcFw,CPtmpBuffer ptmpBuf)
	{
		m_ipcFramework=ipcFw;
		m_ptmpBuffer=ptmpBuf;
		m_className="ComponentItem";
	}
	~ComponentItem()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:47 pm";
	}

	void setVisible(bool bVisible);
	int rtti();
	void moveBy(double x,double y);
	Device device();
	int getXCoordinate();
	int getYCoordinate();
	void setSelected(bool bSelected);
	std::string getClusterID();
	void setX(double x);
	void setY(double y);
	void setXVelocity(double xv);
	void setYVelocity(double yv);
	double xVelocity();
	double yVelocity();
	virtual void event(Ipc::CIpcEventMsg eventMsg){}

};
#endif

//-----------ComponentItem.hEnds -------------//