//************************************************************************
//
// Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************

/*! /file
	File Name:	CAuthReqMsg.cpp     <br>
	Author:		Ajan U. Nair <br>
	Date:		10/09/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CAuthReqMsg class definitions.
*/

/*************************************************************************
Oct 09, 07   Ajan U. Nair   Creation, Class definition, adding attributes/functions



*************************************************************************/
#include "CAuthReqMsg.h"

using namespace std;
using namespace Ptmp;

const bool CAuthReqMsg::s_registerStatus = CPtmpMsg::registerCreation(ePtmpAuthRequest, &CAuthReqMsg::create);
//Srikant


CAuthReqMsg::CAuthReqMsg():CPtmpMsg(ePtmpAuthRequest)
{
}

void CAuthReqMsg::serialize(CPtmpBuffer& buffer) const
{
	CPtmpMsg::serialize(buffer);
	buffer.write(m_username);
}

bool CAuthReqMsg::deserialize(CPtmpBuffer& buffer)
{
	try
	{
		if (!CPtmpMsg::deserialize(buffer))
			return false;

		m_username=buffer.readQString();
		
	}
	catch (CPtmpBufferError error)
	{
		return false;
	}

	return true;
}


CPtmpMsg* CAuthReqMsg::create(CPtmpBuffer& buffer)
{
	CAuthReqMsg* msg = new CAuthReqMsg();
	if (msg->deserialize(buffer))
		return msg;

	delete msg;
	return NULL;
}
