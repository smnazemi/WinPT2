
//************************************************************************
//
// Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************

/*! /file
	File Name:	CDataMsg.cpp     <br>
	Author:		Ajan U. Nair <br>
	Date:		10/09/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CDataMsg class definitions.
*/

/*************************************************************************
Oct 09, 07   Ajan U. Nair   Creation, Class definition, adding attributes/functions



*************************************************************************/

#include "CDataMsg.h"

using namespace Ptmp;
using namespace std;

CDataMsg::CDataMsg(CPtmpBuffer& buffer)
: CPtmpMsg(ePtmpIPCMsg),
m_buffer(buffer)
{
}

void CDataMsg::serialize(CPtmpBuffer& buffer) const
{
	// CPtmpMsg writes type
	CPtmpMsg::serialize(buffer);

	buffer.append(m_buffer);
}

bool CDataMsg::deserialize(CPtmpBuffer& buffer)
{
	try
	{
		// read type in CPtmpMsg
		if (!CPtmpMsg::deserialize(buffer))
			return false;
		
		// read all fields in this msg
		m_buffer = buffer.extract(buffer.size());
	}
	catch (CPtmpBufferError error)
	{
		return false;
	}

	return true;
}
