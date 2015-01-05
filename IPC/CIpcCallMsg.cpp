

//************************************************************************
//
// � Copyright ------
//  All use, disclosure, and/or reproduction of this material is
//  prohibited unless authorized in writing.
//
//************************************************************************

/*! /file
	File Name:	CIpcCallMsg.cpp     <br>
	Author:		Ajan U. Nair <br>
	Date:		09/11/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CIpcManager class definitions.
*/

/*************************************************************************
Nov 11, 07   Ajan U. Nair   Creation, Class definition, adding attributes/functions



*************************************************************************/
#include "CIpcCallMsg.h"

using namespace Ptmp;
using namespace Ipc;


const bool CIpcCallMsg::s_registerStatus = CPtmpMsg::registerCreation(CIpcMsg::eIpcCallMsg, &CIpcCallMsg::create);



CIpcCallMsg::CIpcCallMsg():CPtmpMsg(CIpcMsg::eIpcCallMsg)
{
}

CIpcCallMsg::CIpcCallMsg(const CIpcCallMsg& msg)
: CPtmpMsg(msg.m_type),
callId(msg.callId),
m_buffer(msg.m_buffer)
{
}

CIpcCallMsg::~CIpcCallMsg()
{
}

void CIpcCallMsg::serialize(CPtmpBuffer& buffer) const
{
	CPtmpMsg::serialize(buffer);

	buffer.write(callId);
	buffer.append(m_buffer);
/*
	buffer.write(m_linkOperationID);
	buffer.write(static_cast<int>(m_opType));
	buffer.write(m_LinkID);
	buffer.write(m_PortID);
	buffer.write(m_cableType);
	buffer.write(static_cast<int>(m_portType));
	buffer.write(m_portPower);*/
}

bool CIpcCallMsg::deserialize(CPtmpBuffer& buffer)
{
	if (!CPtmpMsg::deserialize(buffer))
		return false;

	try
	{
		callId = buffer.readInt();
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


CPtmpMsg* CIpcCallMsg::create(CPtmpBuffer& buffer)
{
	CIpcCallMsg* msg = new CIpcCallMsg();
	if (msg->deserialize(buffer))
		return msg;

	delete msg;
	return NULL;
}

CIpcCallMsg* CIpcCallMsg::clone() const
{
	return new CIpcCallMsg(*this);
}
