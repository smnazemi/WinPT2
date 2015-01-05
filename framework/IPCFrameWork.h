//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	IPCFrameWork.h  
	Author:		Ajan U. Nair 
	Date:		09-Jul-2008   
	Revision:	1.0           
	Description:
		IPCFrameWork class, provides methods to access the IPC client implementation
		from the IPC files. 

		Objects of basic classes like AppWindow,Network etc. are provided by IPCFramework
		directly.
		
*/

#if !defined IPC_FRAME_WORK_INCLUDED
#define IPC_FRAME_WORK_INCLUDED

#include <QString>


#define ENABLE_DBG_MSG_FW_ENGINE 1
void fwDebug(QString outStr);



#include <QSemaphore>
#include <QThread>
#include "../PTMP/CNegoMsgParameter.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CPtmpBuffer.h"

#include "../framework/IpcBase.h"


#include "callManager.h"
#include "IPCClientEngine.h"
#include "EventHandler.h"

using namespace Ptmp;

class callManager;
class IPCClientEngine;
class EventHandler;

class Network;
class AppWindow;
class MultiUserManager;
class IpcManager;
class CommandLog;


class CallResult
{
public :
	int callId;
	bool callStatus;
	EPtmpTypeValue returnType;
	CPtmpBuffer  returnDataBuffer;
	std::string	errClassName;
	std::string	errInfo;
	CallResult():callStatus(0),returnType(eVoid),callId(-1){}
};

class IPCFrameWork 
{

public:
	virtual ~IPCFrameWork();

	IPCFrameWork(Ptmp::EPtmpBufferEncoding encoding=Ptmp::ePtmpBufferText,
		Ptmp::EPtmpEncryption encryption=Ptmp::eNoEncryption,
		Ptmp::EPtmpCompression compression=Ptmp::eNoCompression,
		Ptmp::EPtmpAuthentication authen=Ptmp::eMd5Authentication );

	static std::string getVersion();
	static std::string getBuildInfo();

	void setUserInfo(std::string userName, std::string password);
	int startFrameWork(std::string serverAddress = "localhost", int portNumber = 39000);
	std::string getPassword();//call back
	CallResult& makeIPCCall(CPtmpBuffer *ptmpBuffer = NULL);
	bool IPCFrameWork::sendSubscribeForEvents(std::string className,QUuid objectUuid,std::string eventName);
	bool IPCFrameWork::sendUnSubscribeForEvents(std::string className,QUuid objectUuid,std::string eventName);

	CommandLog* IPCFrameWork::commandLog();
	IpcManager* IPCFrameWork::ipcManager();
	MultiUserManager* IPCFrameWork::multiUserManager();
	AppWindow* IPCFrameWork::appWindow();
	Network* IPCFrameWork::network();

	inline int IPCFrameWork::getIpcFwState(){return m_ipcFwState;}
	inline void IPCFrameWork::setIpcFwState(int state){m_ipcFwState=state;}

	int IPCFrameWork::setCallResult(CPtmpMsg * ptmpMsg);
	CallResult IPCFrameWork::getLastCallResult();

	QSemaphore m_ipcCallSyncSema;
	
	EventHandler *m_eventHandler;

	friend class callManager;

protected:
	void run();
private:
	
	int m_ipcFwState;
	IPCClientEngine *m_ipcClientEng;
	/**
	 * Holds all the Negotiation params
	 */
	CNegoMsgParameters m_NegotiationParams;

	std::string m_password;

	/**
	 * Keeps the connection.
	 */
	CPtmpConnection *m_PtmpConnection;


	std::string m_serverAddress;
	int m_serverPort;
	std::string m_userName;
	int m_currentCallId;
	CallResult m_callResult;	
};
#endif // !defined(IPC_FRAME_WORK_INCLUDED)
