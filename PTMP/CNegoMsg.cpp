
//************************************************************************
//
//Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************

/*! /file
	File Name:	CNegoMsg.cpp     <br>
	Author:		Ajan U. Nair <br>
	Date:		10/09/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CNegoMsg class definitions.
*/

/*************************************************************************
Oct 09, 07   Ajan U. Nair   Creation, Class definition, adding attributes/functions



*************************************************************************/

#include "CNegoMsgParameter.h"
#include "CNegoMsg.h"

using namespace Ptmp;
using namespace std;

// register creation for these two msg types
const bool CNegoMsg::s_requestRegisterStatus = CPtmpMsg::registerCreation(ePtmpNegoRequest, &CNegoMsg::create);
const bool CNegoMsg::s_responseRegisterStatus = CPtmpMsg::registerCreation(ePtmpNegoResponse, &CNegoMsg::create);


CNegoMsg::CNegoMsg(CNegoMsgParameters *negoParams, EPtmpMsgType type)
: CPtmpMsg(type)
{
	m_negoMsgparameters = negoParams;
}

void CNegoMsg::serialize(CPtmpBuffer& buffer) const
{
	// CPtmpMsg writes type
	CPtmpMsg::serialize(buffer);

	buffer.write(m_negoMsgparameters->m_signature);
	buffer.write(m_negoMsgparameters->m_version);
	buffer.write(m_negoMsgparameters->m_id);
//	buffer.write(m_negoMsgparameters->getCapabilities());
	buffer.write(static_cast<int>(m_negoMsgparameters->m_encoding));
	buffer.write(static_cast<int>(m_negoMsgparameters->m_encryption));
	buffer.write(static_cast<int>(m_negoMsgparameters->m_compression));
	buffer.write(static_cast<int>(m_negoMsgparameters->m_authentication));
	buffer.write(m_negoMsgparameters->m_timestamp);
	buffer.write(m_negoMsgparameters->m_keepalive);
	buffer.write(m_negoMsgparameters->m_reserved);
//	buffer.write(m_negoMsgparameters->getTimeout());
}

bool CNegoMsg::deserialize(CPtmpBuffer& buffer)
{
	// read type in CPtmpMsg
	if (!CPtmpMsg::deserialize(buffer))
		return false;

	try
	{
		// read all fields in this msg
		m_negoMsgparameters->m_signature = buffer.readString();
		m_negoMsgparameters->m_version = buffer.readInt();
		m_negoMsgparameters->m_id = buffer.readUuid();
		m_negoMsgparameters->m_encoding = EPtmpBufferEncoding(buffer.readInt());
		m_negoMsgparameters->m_encryption = EPtmpEncryption(buffer.readInt());
		m_negoMsgparameters->m_compression = EPtmpCompression(buffer.readInt());
		m_negoMsgparameters->m_authentication = EPtmpAuthentication(buffer.readInt());
		m_negoMsgparameters->m_timestamp = buffer.readString();
		m_negoMsgparameters->m_keepalive = buffer.readInt();
		m_negoMsgparameters->m_reserved = buffer.readString();		
	}
	catch (CPtmpBufferError error)
	{
		return false;
	}

	return true;
}

// static function to create msg from buffer
CPtmpMsg* CNegoMsg::create(CPtmpBuffer& buffer)
{
	CNegoMsgParameters *negoParams= new CNegoMsgParameters();

	CNegoMsg* msg = new CNegoMsg(negoParams);
	if (msg->deserialize(buffer))
		return msg;

	delete msg;
	return NULL;
}
