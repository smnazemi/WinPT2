//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 FileManager.cpp 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:45 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#include "FileManager.h"

FileSystem* FileManager::getName(std::string name)
{
	std::string callName= "getName";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eString);
	buf->write(name);

	buf->write(eVoid);

	FileSystem* filesystemObj = new FileSystem(m_ipcFramework,*buf);

	return filesystemObj;
}
