//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 MenuBar.cpp 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:49 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#include "MenuBar.h"

Menu MenuBar::getFilePopupMenu()
{
	std::string callName= "getFilePopupMenu";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	Menu menuObj(m_ipcFramework,*buf);

	return menuObj;
}
Menu MenuBar::getEditPopupMenu()
{
	std::string callName= "getEditPopupMenu";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	Menu menuObj(m_ipcFramework,*buf);

	return menuObj;
}
Menu MenuBar::getOptionsPopupMenu()
{
	std::string callName= "getOptionsPopupMenu";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	Menu menuObj(m_ipcFramework,*buf);

	return menuObj;
}
Menu MenuBar::getExtensionsPopupMenu()
{
	std::string callName= "getExtensionsPopupMenu";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	Menu menuObj(m_ipcFramework,*buf);

	return menuObj;
}
Menu MenuBar::getHelpPopupMenu()
{
	std::string callName= "getHelpPopupMenu";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	Menu menuObj(m_ipcFramework,*buf);

	return menuObj;
}
