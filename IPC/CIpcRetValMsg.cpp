
//************************************************************************
//
// � Copyright ------
//  All use, disclosure, and/or reproduction of this material is
//  prohibited unless authorized in writing.
//
//************************************************************************

/*! /file
	File Name:	CIpcRetValMsg.cpp     <br>
	Author:		Ajan U. Nair <br>
	Date:		09/11/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CIpcManager class definitions.
*/

/*************************************************************************
Nov 11, 07   Ajan U. Nair   Creation, Class definition, adding attributes/functions



*************************************************************************/


#include "../PTMP/CPtmpBuffer.h"
#include "../PTMP/CPtmpMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsg.h"
#include "../PTMP/CAuthResponseMsg.h"
#include "../PTMP/CAuthStatusMsg.h"
#include "../PTMP/CDisconnectMsg.h"
//#include "../PTMP/CPtmpServer.h"

#include "CIpcMsg.h"

#include "CIpcCallMsg.h"
#include "CIpcEventMsg.h"

//#include "CCepInstance.h"
//#include "CEventDispatcher.h"
//#include "CCep.h"
#include "CIpcRetValMsg.h"


//#include "CParser.h"
//#include "CIpcManager.h"

using namespace Ipc;
using namespace Ptmp;

const bool CIpcRetValMsg::s_registerStatus = CPtmpMsg::registerCreation(CIpcMsg::eIpcReturnValueMsg, &CIpcRetValMsg::create);


CIpcRetValMsg::CIpcRetValMsg(Ptmp::EPtmpBufferEncoding encoding)
: CIpcRetMsg(CIpcMsg::eIpcReturnValueMsg),
m_buffer(ePtmpBufferReadWrite, encoding)
{
}


void CIpcRetValMsg::serialize(Ptmp::CPtmpBuffer& buffer) const
{
	CIpcRetMsg::serialize(buffer);
	buffer.append(m_buffer);
}

bool CIpcRetValMsg::deserialize(Ptmp::CPtmpBuffer& buffer)
{
	if (!CIpcRetMsg::deserialize(buffer))
		return false;

	try
	{
		buffer.flushRead();
		m_buffer = buffer.extract(buffer.size());
		/*m_linkOperationID=buffer.readInt();
		m_opType=EOperationType(buffer.readInt());
		m_LinkID=buffer.readInt();
		m_PortID=buffer.readInt();
		m_cableType=buffer.readInt();
		m_portType = Port::EPortType(buffer.readInt());
		m_portPower = buffer.readBool();*/
	}
	catch (CPtmpBufferError error)
	{
		return false;
	}

	return true;
}


CPtmpMsg* CIpcRetValMsg::create(Ptmp::CPtmpBuffer& buffer)
{
	CIpcRetValMsg* msg = new CIpcRetValMsg();
	if (msg->deserialize(buffer))
		return msg;

	delete msg;
	return NULL;
}
