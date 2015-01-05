//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	callManager.h   
	Author:		Ajan U. Nair 
	Date:		09-Jul-2008   
	Revision:	1.0           
	Description:
		This file holds the callManager class implementation
		This class holds all the PTMP connection related call backs 
		implementations

*/

#if !defined(EA_C3EE2043_433F_4a91_8204_5FC7F5695C70__INCLUDED_)
#define EA_C3EE2043_433F_4a91_8204_5FC7F5695C70__INCLUDED_

#include <QString>

#include "IPCFrameWork.h"
#include "IPCClientEngine.h"

#include "../PTMP/CPtmpMsg.h"
#include "../PTMP/CPtmpConnection.h"


using namespace Ptmp;

class IPCFrameWork;
class Network;

class callManager
{

public:
	callManager();
	callManager(IPCClientEngine * ipcClientEngInstance);
	virtual ~callManager();
	
	void callBackFunctor(IPCFrameWork * ipcFrameworkInstance);
	QString getPassword(CPtmpConnection * ptmpConnection,const QString &userName);
	void onData(CPtmpConnection * ptmpConnection, CPtmpMsg * ptmpMsg);
	void onDisconnect(CPtmpConnection * ptmpConnection);
	void onError(CPtmpConnection * ptmpConnection, EPtmpConnectionErrorType errorType);
	void onEstablished(CPtmpConnection * ptmpConnection);

private:
	IPCClientEngine * m_ipcClientEngObj;

};
#endif // !defined(EA_C3EE2043_433F_4a91_8204_5FC7F5695C70__INCLUDED_)
