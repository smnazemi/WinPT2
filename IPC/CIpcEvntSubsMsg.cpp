
//************************************************************************
//
// � Copyright ------
//  All use, disclosure, and/or reproduction of this material is
//  prohibited unless authorized in writing.
//
//************************************************************************

/*! /file
	File Name:	CIpcEvntSubsMsg.cpp     <br>
	Author:		Ajan U. Nair <br>
	Date:		09/11/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CIpcManager class definitions.
*/

/*************************************************************************
Nov 11, 07   Ajan U. Nair   Creation, Class definition, adding attributes/functions



*************************************************************************/

#include "CIpcEvntSubsMsg.h"

using namespace Ipc;
using namespace Ptmp;

const bool CIpcEvntSubsMsg::s_registerStatus = CPtmpMsg::registerCreation(CIpcMsg::eIpcEventSubscribeMsg, &CIpcEvntSubsMsg::create);


CIpcEvntSubsMsg::CIpcEvntSubsMsg()
: CPtmpMsg(CIpcMsg::eIpcEventSubscribeMsg)
{
	m_bSubscribe = true;
}

CIpcEvntSubsMsg::CIpcEvntSubsMsg(const std::string& className,
					 const QUuid& objectUuid,
					 const std::string& eventName,
					 bool bSubscribe)
: CPtmpMsg(CIpcMsg::eIpcEventSubscribeMsg),
m_className(className),
m_objectUuid(objectUuid),
m_eventName(eventName),
m_bSubscribe(bSubscribe)
{
}


void CIpcEvntSubsMsg::serialize(Ptmp::CPtmpBuffer& buffer) const
{
	CPtmpMsg::serialize(buffer);

	buffer.write(m_className);
	buffer.write(m_objectUuid);
	buffer.write(m_eventName);
	buffer.write(m_bSubscribe);
}

bool CIpcEvntSubsMsg::deserialize(CPtmpBuffer& buffer)
{
	if (!CPtmpMsg::deserialize(buffer))
		return false;
	try
	{		
		m_className = buffer.readString();
		m_objectUuid = buffer.readUuid();
		m_eventName = buffer.readString();
		m_bSubscribe = buffer.readBool();
	}
	catch (CPtmpBufferError error)
	{
		return false;
	}

	return true;
}


CPtmpMsg* CIpcEvntSubsMsg::create(CPtmpBuffer& buffer)
{
	CIpcEvntSubsMsg* msg = new CIpcEvntSubsMsg();
	if (msg->deserialize(buffer))
		return msg;

	delete msg;
	return NULL;
}
