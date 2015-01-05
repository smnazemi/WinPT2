
//************************************************************************
//
// Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************

/*! /file
	File Name:	CDisconnectMsg.cpp     <br>
	Author:		Ajan U. Nair <br>
	Date:		10/09/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CDisconnectMsg class definitions.
*/

/*************************************************************************
Oct 09, 07   Ajan U. Nair   Creation, Class definition, adding attributes/functions



*************************************************************************/

#include "CDisconnectMsg.h"

using namespace Ptmp;
using namespace std;

const bool CDisconnectMsg::s_registerStatus = CPtmpMsg::registerCreation(ePtmpDisconnect, &CDisconnectMsg::create);

const std::string	CDisconnectMsg::s_defaultReason = ""; //Srikant

CDisconnectMsg::CDisconnectMsg():CPtmpMsg(ePtmpDisconnect)
{
	//TODO: init member variables
	m_Reason = s_defaultReason;			//Srikant
}

void CDisconnectMsg::serialize(CPtmpBuffer& buffer) const
{
	CPtmpMsg::serialize(buffer);
	buffer.write(m_Reason);
}

bool CDisconnectMsg::deserialize(CPtmpBuffer& buffer)
{
	try
	{
		if (!CPtmpMsg::deserialize(buffer))
			return false;

		m_Reason=buffer.readString();
	}
	catch (CPtmpBufferError error)
	{
		return false;
	}

	return true;
}

CPtmpMsg* CDisconnectMsg::create(CPtmpBuffer& buffer)
{
	CDisconnectMsg* msg = new CDisconnectMsg();
	if (msg->deserialize(buffer))
		return msg;

	delete msg;
	return NULL;
}


string CDisconnectMsg::getReason()
{
	return m_Reason;
}

void CDisconnectMsg::setReason(string reason)
{
	m_Reason=reason;
}