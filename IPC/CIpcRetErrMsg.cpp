

//************************************************************************
//
// � Copyright ------
//  All use, disclosure, and/or reproduction of this material is
//  prohibited unless authorized in writing.
//
//************************************************************************

/*! /file
	File Name:	CIpcRetErrMsg.cpp     <br>
	Author:		Ajan U. Nair <br>
	Date:		09/11/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CIpcManager class definitions.
*/

/*************************************************************************
Nov 11, 07   Ajan U. Nair   Creation, Class definition, adding attributes/functions



*************************************************************************/

#include "CIpcRetErrMsg.h"
//#include "CIpcManager.h"


/*#include "../PTMP/CPtmpBuffer.h"
#include "../PTMP/CPtmpMsg.h"
#include "../PTMP/CPtmpConnection.h"
#include "../PTMP/CNegoMsg.h"
#include "../PTMP/CAuthResponseMsg.h"
#include "../PTMP/CAuthStatusMsg.h"
#include "../PTMP/CDisconnectMsg.h"
#include "../PTMP/CPtmpServer.h"

#include "CIpcMsg.h"

#include "CIpcCallMsg.h"
#include "CIpcEventMsg.h"

#include "CCepInstance.h"
#include "CEventDispatcher.h"
#include "CCep.h"
#include "CIpcRetErrMsg.h"


#include "CParser.h"
#include "CIpcManager.h"
*/
using namespace Ipc;
using namespace Ptmp;

const bool CIpcRetErrMsg::s_registerStatus = CPtmpMsg::registerCreation(CIpcMsg::eIpcReturnErrMsg, &CIpcRetErrMsg::create);


CIpcRetErrMsg::CIpcRetErrMsg(const std::string& className, const std::string& error)
: CIpcRetMsg(CIpcMsg::eIpcReturnErrMsg)
{
	m_className = className;
	m_error = error;
}

void CIpcRetErrMsg::serialize(CPtmpBuffer& buffer) const
{
	CIpcRetMsg::serialize(buffer);

	buffer.write(m_className);
	buffer.write(m_error);


/*
	buffer.write(m_linkOperationID);
	buffer.write(static_cast<int>(m_opType));
	buffer.write(m_LinkID);
	buffer.write(m_PortID);
	buffer.write(m_cableType);
	buffer.write(static_cast<int>(m_portType));
	buffer.write(m_portPower);*/
}

bool CIpcRetErrMsg::deserialize(CPtmpBuffer& buffer)
{
	if (!CIpcRetMsg::deserialize(buffer))
		return false;

	try
	{
		m_className = buffer.readString();
		m_error = buffer.readString();
	}
	catch (CPtmpBufferError error)
	{
		return false;
	}

	return true;
}


CPtmpMsg* CIpcRetErrMsg::create(CPtmpBuffer& buffer)
{
	CIpcRetErrMsg* msg = new CIpcRetErrMsg();
	if (msg->deserialize(buffer))
		return msg;

	delete msg;
	return NULL;
}
