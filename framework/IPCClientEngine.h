//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	IPCClientEngine.h  
	Author:		Ajan U. Nair 
	Date:		09-Jul-2008   
	Revision:	1.0           
	Description:
		Implementation of IPCClientEngine class.
		This class has got a separate thread and an event loop, which 
		enables the framework to listen for communication from PT without
		blocking the user thread.
		
*/
#if !defined(EA_CLIENTENGINE_9F12_4de6_8F02_B175EADE5136__INCLUDED_)
#define EA_CLIENTENGINE_9F12_4de6_8F02_B175EADE5136__INCLUDED_

#include <QSemaphore>
#include <QThread>

#include "../PTMP/CNegoMsgParameter.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CPtmpBuffer.h"
#include "../IPC/CIpcEvntSubsMsg.h"

#include "callManager.h"
#include "IPCFramework.h"

using namespace Ptmp;

class callManager;
class Network;
class IPCFrameWork;

class IPCClientEngine : public QThread
{
Q_OBJECT
public:
	virtual ~IPCClientEngine();
	callManager *ipcCallManager;

	IPCClientEngine(IPCFrameWork* fwInstance);
	std::string getPassword();
	void setUserInfo(std::string userName, std::string password);
	int makeIPCCall(int callId=0,CPtmpBuffer *ptmpBuffer = NULL);

	void setNegoParams(Ptmp::EPtmpBufferEncoding encoding=Ptmp::ePtmpBufferText,
		Ptmp::EPtmpEncryption encryption=Ptmp::eNoEncryption,
		Ptmp::EPtmpCompression compression=Ptmp::eNoCompression,
		Ptmp::EPtmpAuthentication authen=Ptmp::eMd5Authentication );

	void IPCClientEngine::setServerInfo(std::string serverAddress, int portNumber);
	void IPCClientEngine::startEngine();

	
	bool  IPCClientEngine::sendMsg(Ipc::CIpcEvntSubsMsg msg);
	friend class callManager;
	IPCFrameWork* m_ipcFwInstance;

protected:
	void run();
private:
	callManager *m_frameWorkCallManager;

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
};
#endif // !defined(EA_CLIENTENGINE_9F12_4de6_8F02_B175EADE5136__INCLUDED_)
