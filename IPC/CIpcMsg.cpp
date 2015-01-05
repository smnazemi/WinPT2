

//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************

/*! \file
	File Name:	CIpcMsg.cpp       <br>
	Author:		Ajan U. Nair          <br>
	Date:		21-Nov-2007                 <br>
	Revision:	1.0                      <br>
	Description:
		Implementation of the Class CIpcMsg
*/
#include "CIpcMsg.h"


using namespace Ipc;
using namespace Ptmp;

const Ptmp::EPtmpMsgType CIpcMsg::eIpcCallMsg = Ptmp::EPtmpMsgType(Ptmp::ePtmpIPCMsg + 0);
const Ptmp::EPtmpMsgType CIpcMsg::eIpcReturnErrMsg = Ptmp::EPtmpMsgType(Ptmp::ePtmpIPCMsg + 1);
const Ptmp::EPtmpMsgType CIpcMsg::eIpcReturnValueMsg = Ptmp::EPtmpMsgType(Ptmp::ePtmpIPCMsg + 2);
const Ptmp::EPtmpMsgType CIpcMsg::eIpcEventMsg = Ptmp::EPtmpMsgType(Ptmp::ePtmpIPCMsg + 3);
const Ptmp::EPtmpMsgType CIpcMsg::eIpcEventSubscribeMsg = Ptmp::EPtmpMsgType(Ptmp::ePtmpIPCMsg + 4);
//const Ptmp::EPtmpMsgType CIpcMsg::eMUSaveNetResp = Ptmp::EPtmpMsgType(Ptmp::ePtmpMUMsg + 5);
