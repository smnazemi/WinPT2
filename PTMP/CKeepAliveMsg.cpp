
//************************************************************************
//
// Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************

/*! /file
	File Name:	CKeepAliveMsg.cpp     <br>
	Author:		Ajan U. Nair <br>
	Date:		10/09/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CKeepAliveMsg class definitions.
*/

/*************************************************************************
Oct 09, 07   Ajan U. Nair   Creation, Class definition, adding attributes/functions



*************************************************************************/

#include "CKeepAliveMsg.h"

using namespace Ptmp;
using namespace std;

// register creation for this type
const bool CKeepAliveMsg::s_registerStatus = CPtmpMsg::registerCreation(ePtmpKeepAlive, &CKeepAliveMsg::create);


CKeepAliveMsg::CKeepAliveMsg()
: CPtmpMsg(ePtmpKeepAlive)
{
}

void CKeepAliveMsg::serialize(CPtmpBuffer& buffer) const
{
	// CPtmpMsg writes type
	CPtmpMsg::serialize(buffer);
}

bool CKeepAliveMsg::deserialize(CPtmpBuffer& buffer)
{
	// read type in CPtmpMsg
	if (!CPtmpMsg::deserialize(buffer))
		return false;

	try
	{
	}
	catch (CPtmpBufferError error)
	{
		return false;
	}

	return true;
}

// static function to create msg from buffer
CPtmpMsg* CKeepAliveMsg::create(CPtmpBuffer& buffer)
{
	CKeepAliveMsg* msg = new CKeepAliveMsg();
	if (msg->deserialize(buffer))
		return msg;

	delete msg;
	return NULL;
}
