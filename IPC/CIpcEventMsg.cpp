
//************************************************************************
//
// � Copyright ------
//  All use, disclosure, and/or reproduction of this material is
//  prohibited unless authorized in writing.
//
//************************************************************************

/*! /file
	File Name:	CIpcEventMsg.cpp     <br>
	Author:		Ajan U. Nair <br>
	Date:		09/11/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CIpcManager class definitions.
*/

/*************************************************************************
Nov 11, 07   Ajan U. Nair   Creation, Class definition, adding attributes/functions



*************************************************************************/
#include "CIpcEventMsg.h"

using namespace Ptmp;
using namespace Ipc;

const bool CIpcEventMsg::s_registerStatus = CPtmpMsg::registerCreation(CIpcMsg::eIpcEventMsg, &CIpcEventMsg::create);

CIpcEventMsg::CIpcEventMsg()
: CPtmpMsg(CIpcMsg::eIpcEventMsg),
m_textParams(Ptmp::ePtmpBufferReadWrite, Ptmp::ePtmpBufferText),
m_binaryParams(Ptmp::ePtmpBufferReadWrite, Ptmp::ePtmpBufferBinary)
{
	m_eventId = rand();
}

CIpcEventMsg::CIpcEventMsg(const std::string& className,
					 const QUuid& objectUuid,
					 const std::string& eventName)
: CPtmpMsg(CIpcMsg::eIpcEventMsg),
m_className(className),
m_objectUuid(objectUuid),
m_eventName(eventName),
m_textParams(Ptmp::ePtmpBufferReadWrite, Ptmp::ePtmpBufferText),
m_binaryParams(Ptmp::ePtmpBufferReadWrite, Ptmp::ePtmpBufferBinary)
{
	m_eventId = rand();
}

void CIpcEventMsg::serialize(CPtmpBuffer& buffer) const
{
	CPtmpMsg::serialize(buffer);

	buffer.write(m_eventId);
	buffer.write(m_className);
	buffer.write(m_objectUuid);
	buffer.write(m_eventName);

	if (buffer.getEncoding() == Ptmp::ePtmpBufferText)
		buffer.append(m_textParams);
	else
		buffer.append(m_binaryParams);
}

bool CIpcEventMsg::deserialize(CPtmpBuffer& buffer)
{
	if (!CPtmpMsg::deserialize(buffer))
		return false;
	try
	{
		m_eventId = buffer.readInt();
		m_className = buffer.readString();
		m_objectUuid = buffer.readUuid();
		m_eventName = buffer.readString();

		if (buffer.getEncoding() == Ptmp::ePtmpBufferText)
		{
			//m_textParams = buffer.extract(buffer.unreadSize()); 
			buffer.flushRead();
			m_textParams = buffer;//Ajan	
		}
		else
		{
			//m_binaryParams = buffer.extract(buffer.unreadSize());
			buffer.flushRead();
			m_binaryParams = buffer;//Ajan
		}

	}
	catch (CPtmpBufferError error)
	{
		return false;
	}

	return true;
}


CPtmpMsg* CIpcEventMsg::create(CPtmpBuffer& buffer)
{
	CIpcEventMsg* msg = new CIpcEventMsg();
	if (msg->deserialize(buffer))
		return msg;

	delete msg;
	return NULL;
}
