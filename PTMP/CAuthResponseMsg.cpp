//************************************************************************
//
//  Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************

/*! /file
	File Name:	CAuthResponseMsg.cpp     <br>
	Author:		Ajan U. Nair <br>
	Date:		10/09/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CAuthRespMsg class definitions.
*/

/*************************************************************************
Oct 09, 07   Ajan U. Nair   Creation, Class definition, adding attributes/functions



*************************************************************************/
#include "CAuthResponseMsg.h"
#include "CAuthChallengeMsg.h"

using namespace std;
using namespace Ptmp;


const bool CAuthResponseMsg::s_registerStatus = CPtmpMsg::registerCreation(ePtmpAuthResponse, &CAuthResponseMsg::create);


CAuthResponseMsg::CAuthResponseMsg()
: CPtmpMsg(ePtmpAuthResponse)
{
}

void CAuthResponseMsg::serialize(CPtmpBuffer& buffer) const
{
 	CPtmpMsg::serialize(buffer);
	buffer.write(m_userName);
	buffer.write(m_Digesttext);
	buffer.write(m_Custommessage);
}

bool CAuthResponseMsg::deserialize(CPtmpBuffer& buffer)
{
	try
	{
		if (!CPtmpMsg::deserialize(buffer))
			return false;

		m_userName=buffer.readQString();
		m_Digesttext=buffer.readString();
		m_Custommessage=buffer.readString();
	}
	catch (CPtmpBufferError error)
	{
		return false;
	}

	return true;
}


CPtmpMsg* CAuthResponseMsg::create(CPtmpBuffer& buffer)
{
	CAuthResponseMsg* msg = new CAuthResponseMsg();
	if (msg->deserialize(buffer))
		return msg;

	delete msg;
	return NULL;
}


string CAuthResponseMsg::getDigestText()//(string	digesttext)
{
	return m_Digesttext;
}


string CAuthResponseMsg::getCustommessage()
{
	return m_Custommessage;
}

bool CAuthResponseMsg::validateResponse(string  password)
{
	return 1;
}

void CAuthResponseMsg::setDigestText(std::string digesttext)
{
	m_Digesttext= digesttext;

}

void CAuthResponseMsg::setCustommessage(string custommessage)
{
	m_Custommessage=custommessage;
}

