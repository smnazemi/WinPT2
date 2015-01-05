//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************

/*! /file
	File Name:	CPTMPMsg.cpp     <br>
	Author:		Ajan U. Nair <br>
	Date:		10/14/07  -Sunday    <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CPTMPMsg class implementation
		PTMPMsg class represents and holds a message received or to be sent
		from a client or server.

*/

/*************************************************************************
Oct 14, 07   Ajan U. Nair   Creation, Class definition, adding attributes and functions

*************************************************************************/

#include "CPtmpMsg.h"

using namespace Ptmp;
using namespace std;

void CPtmpMsg::serialize(CPtmpBuffer &buffer) const
{
	// serialize the type
	buffer.write(static_cast<int>(m_type));
}

bool CPtmpMsg::deserialize(CPtmpBuffer &buffer)
{
	try
	{
		// read the type
		m_type = EPtmpMsgType(buffer.readInt());
	}
	catch (CPtmpBufferError error)
	{
		return false;
	}

	return true;
}

bool CPtmpMsg::registerCreation(EPtmpMsgType type, TCreateFunction func)
{
	// if type is already registered, then throw exception
	if (getCreationMap().find(type) != getCreationMap().end())
		throw "type already registered in CPtmpMsg";
	getCreationMap()[type] = func;
	return true;
}

CPtmpMsg* CPtmpMsg::create(CPtmpBuffer& buffer)
{
	EPtmpMsgType type;
	try
	{
		// peek for the type
		type = EPtmpMsgType(buffer.peekInt());
	}
	catch (CPtmpBufferError error)
	{
		return NULL;
	}

	// look it up
	std::map<EPtmpMsgType, TCreateFunction>::const_iterator itr = getCreationMap().find(type);

	// if not found
	if (itr == getCreationMap().end())
	{
		// consume the type (int) that was not recognized
		buffer.readInt();
		return NULL;
	}

	// dispatch to the registered create function to create msg
	return (itr->second)(buffer);
}
