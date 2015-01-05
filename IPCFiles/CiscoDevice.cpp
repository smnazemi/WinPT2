//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 CiscoDevice.cpp 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:44 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#include "CiscoDevice.h"

void CiscoDevice::setHostName(std::string hostname)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="setHostName";
	newBuf->write(callName);
	newBuf->write(eString);

	newBuf->write(hostname);

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
		return ;
	}
}
std::string CiscoDevice::getHostName()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getHostName";
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
void CiscoDevice::setEnableSecret(std::string password)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="setEnableSecret";
	newBuf->write(callName);
	newBuf->write(eString);

	newBuf->write(password);

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
		return ;
	}
}
std::string CiscoDevice::getEnableSecret()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getEnableSecret";
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
void CiscoDevice::setEnablePassword(std::string password,int level)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="setEnablePassword";
	newBuf->write(callName);
	newBuf->write(eString);

	newBuf->write(password);

	newBuf->write(eInt);

	newBuf->write(level);

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
		return ;
	}
}
std::string CiscoDevice::getEnablePassword()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getEnablePassword";
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
void CiscoDevice::setStartupFile(std::string str)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="setStartupFile";
	newBuf->write(callName);
	newBuf->write(eString);

	newBuf->write(str);

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
		return ;
	}
}
std::vector<std::string> CiscoDevice::getStartupFile()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getStartupFile";
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
		std::vector<std::string> returnInfo;
		{
			callResult.returnDataBuffer.readInt();//skip the type of vect members.
			int sizeOfVect=callResult.returnDataBuffer.readInt();
			for(int index_returnInfo=0;index_returnInfo<sizeOfVect;index_returnInfo++)
			{

				std::string vectMem0=callResult.returnDataBuffer.readString();
				returnInfo.push_back(vectMem0);
			}
		}
		return returnInfo;
	}
}
bool CiscoDevice::addBootSystem(std::string name)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="addBootSystem";
	newBuf->write(callName);
	newBuf->write(eString);

	newBuf->write(name);

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
		bool returnInfo=callResult.returnDataBuffer.readBool();
		return returnInfo;
	}
}
bool CiscoDevice::removeBootSystem(std::string name)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="removeBootSystem";
	newBuf->write(callName);
	newBuf->write(eString);

	newBuf->write(name);

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
		bool returnInfo=callResult.returnDataBuffer.readBool();
		return returnInfo;
	}
}
void CiscoDevice::removeAllBootSystem()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="removeAllBootSystem";
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
		return ;
	}
}
std::vector<std::string> CiscoDevice::getBootSystems()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getBootSystems";
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
		std::vector<std::string> returnInfo;
		{
			callResult.returnDataBuffer.readInt();//skip the type of vect members.
			int sizeOfVect=callResult.returnDataBuffer.readInt();
			for(int index_returnInfo=0;index_returnInfo<sizeOfVect;index_returnInfo++)
			{

				std::string vectMem0=callResult.returnDataBuffer.readString();
				returnInfo.push_back(vectMem0);
			}
		}
		return returnInfo;
	}
}
int CiscoDevice:: getConfigRegister()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName=" getConfigRegister";
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
void CiscoDevice::setNextConfigRegister(int m_register)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="setNextConfigRegister";
	newBuf->write(callName);
	newBuf->write(eInt);

	newBuf->write(m_register);

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
		return ;
	}
}
int CiscoDevice:: getNextConfigRegister()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName=" getNextConfigRegister";
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
void CiscoDevice::setBannerMotd(std::string banner)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="setBannerMotd";
	newBuf->write(callName);
	newBuf->write(eString);

	newBuf->write(banner);

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
		return ;
	}
}
std::string CiscoDevice::getBannerMotd()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getBannerMotd";
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
void CiscoDevice:: setTimeZone(std::string timeZone,short hourOffset,short minOffset)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName=" setTimeZone";
	newBuf->write(callName);
	newBuf->write(eString);

	newBuf->write(timeZone);

	newBuf->write(eShort);

	newBuf->write(hourOffset);

	newBuf->write(eShort);

	newBuf->write(minOffset);

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
		return ;
	}
}
std::string CiscoDevice::getTimeZone()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getTimeZone";
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
CMacAddress  CiscoDevice::getBia()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getBia";
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
		CMacAddress  returnInfo=callResult.returnDataBuffer.readMacAddress();
		return returnInfo;
	}
}
void CiscoDevice:: setServicePasswordEncryption(bool bEnable)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName=" setServicePasswordEncryption";
	newBuf->write(callName);
	newBuf->write(eBool);

	newBuf->write(bEnable);

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
		return ;
	}
}
bool CiscoDevice::getServicePasswordEncryption()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="getServicePasswordEncryption";
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
		bool returnInfo=callResult.returnDataBuffer.readBool();
		return returnInfo;
	}
}
Port CiscoDevice::getConsole()
{
	std::string callName= "getConsole";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	Port portObj(m_ipcFramework,*buf);

	return portObj;
}
TerminalLine CiscoDevice::getConsoleLine()
{
	std::string callName= "getConsoleLine";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eVoid);

	TerminalLine terminallineObj(m_ipcFramework,*buf);

	return terminallineObj;
}
TerminalLine CiscoDevice::getVtyLine(int num)
{
	std::string callName= "getVtyLine";
	CPtmpBuffer* buf= new CPtmpBuffer(m_ptmpBuffer);
	buf->write(callName);
	buf->write(eInt);
	buf->write(num);

	buf->write(eVoid);

	TerminalLine terminallineObj(m_ipcFramework,*buf);

	return terminallineObj;
}
std::pair<int,std::string> CiscoDevice::enterCommand(std::string commandStr,std::string modeStr)
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="enterCommand";
	newBuf->write(callName);
	newBuf->write(eString);

	newBuf->write(commandStr);

	newBuf->write(eString);

	newBuf->write(modeStr);

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
		std::pair<int,std::string> returnInfo;
		callResult.returnDataBuffer.readInt();


		int pairMemType1_0=callResult.returnDataBuffer.readInt();

		returnInfo.first=pairMemType1_0;
		callResult.returnDataBuffer.readInt();


		std::string pairMemType2_0=callResult.returnDataBuffer.readString();

		returnInfo.second=pairMemType2_0;
		return returnInfo;
	}
}
void CiscoDevice::skipBoot()
{
	CPtmpBuffer *newBuf= new CPtmpBuffer(m_ptmpBuffer);
	std::string callName="skipBoot";
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
		return ;
	}
}
