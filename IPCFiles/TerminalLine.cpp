//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 TerminalLine.cpp 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:48 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#include "TerminalLine.h"

std::string TerminalLine::getName()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getName";
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
		std::string returnInfo=callResult.returnDataBuffer.readString();
		return returnInfo;
	}
}
std::string TerminalLine::getMode()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getMode";
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
		std::string returnInfo=callResult.returnDataBuffer.readString();
		return returnInfo;
	}
}
std::string TerminalLine::getPrompt()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getPrompt";
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
		std::string returnInfo=callResult.returnDataBuffer.readString();
		return returnInfo;
	}
}
CommandHistory TerminalLine::getUserHistory()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getUserHistory";
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
		callResult.returnDataBuffer.flushRead();
		CommandHistory returnInfo(&(callResult.returnDataBuffer));
		return returnInfo;
	}
}
CommandHistory TerminalLine::getConfigHistory()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getConfigHistory";
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
		callResult.returnDataBuffer.flushRead();
		CommandHistory returnInfo(&(callResult.returnDataBuffer));
		return returnInfo;
	}
}
CommandHistory TerminalLine::getCurrentHistory()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getCurrentHistory";
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
		callResult.returnDataBuffer.flushRead();
		CommandHistory returnInfo(&(callResult.returnDataBuffer));
		return returnInfo;
	}
}
int TerminalLine::getHistorySize()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getHistorySize";
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
		int returnInfo=callResult.returnDataBuffer.readInt();
		return returnInfo;
	}
}
std::string TerminalLine::getCommandInput()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getCommandInput";
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
		std::string returnInfo=callResult.returnDataBuffer.readString();
		return returnInfo;
	}
}
int TerminalLine::getTelnetClientCount()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getTelnetClientCount";
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
		int returnInfo=callResult.returnDataBuffer.readInt();
		return returnInfo;
	}
}
TelnetClientProcess TerminalLine::getTelnetClientAt(int index)
{
	std::string callName= "getTelnetClientAt";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eInt);
	buf->write(index);

	buf->write(eVoid);

	TelnetClientProcess telnetclientprocessObj(m_ipcFramework,*buf);

	return telnetclientprocessObj;
}
