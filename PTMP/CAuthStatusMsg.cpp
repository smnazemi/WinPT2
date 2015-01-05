
//************************************************************************
//
// Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************

/*! /file
	File Name:	CAuthStatusMsg.cpp     <br>
	Author:		Ajan U. Nair <br>
	Date:		10/09/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CAuthStatusMsg class definitions.
*/

/*************************************************************************
Oct 09, 07   Ajan U. Nair   Creation, Class definition, adding attributes/functions



*************************************************************************/
#include "CAuthStatusMsg.h"

using namespace Ptmp;
using namespace std;


const bool CAuthStatusMsg::s_registerStatus = CPtmpMsg::registerCreation(ePtmpAuthStatus, &CAuthStatusMsg::create);
//Srikant
const bool	CAuthStatusMsg::s_defaultStatus = false;


CAuthStatusMsg::CAuthStatusMsg()
: CPtmpMsg(ePtmpAuthStatus)
{
	//TODO: init member variables
	m_Status = s_defaultStatus;	//Srikant
}

void CAuthStatusMsg::serialize(CPtmpBuffer& buffer) const
{
 	CPtmpMsg::serialize(buffer);
	buffer.write(m_Status);
}

bool CAuthStatusMsg::deserialize(CPtmpBuffer& buffer)
{
	try
	{
		if (!CPtmpMsg::deserialize(buffer))
			return false;

		m_Status=buffer.readBool();
	}
	catch (CPtmpBufferError error)
	{
		return false;
	}

	return true;
}

CPtmpMsg* CAuthStatusMsg::create(CPtmpBuffer& buffer)
{
	CAuthStatusMsg* msg = new CAuthStatusMsg();
	if (msg->deserialize(buffer))
		return msg;

	delete msg;
	return NULL;
}

bool CAuthStatusMsg::getStatus()
{
	return m_Status;
}

void CAuthStatusMsg::setStatus(bool status)
{
	m_Status=status;
}