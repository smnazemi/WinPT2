//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************

/*! /file
	File Name:	CPTMPMsg.h     <br>
	Author:		Ajan U. Nair <br>
	Date:		10/12/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CPTMPMsg class definitions.
*/

/*************************************************************************
Oct12, 07   Ajan U. Nair   Creation, Class definition, adding attributes/functions



*************************************************************************/

#ifndef PTMP_CPTMPMSG_H
#define PTMP_CPTMPMSG_H

#include "CPtmpBuffer.h"
#include <map>

namespace Ptmp
{
	enum EPtmpMsgType
	{
		ePtmpNegoRequest = 0,
		ePtmpNegoResponse,
		ePtmpAuthRequest,
		ePtmpAuthChallenge,
		ePtmpAuthResponse,
		ePtmpAuthStatus,
		ePtmpKeepAlive,
		ePtmpDisconnect,
		ePtmpIPCMsg = 100,
		ePtmpMUMsg = 200
	};

	// base class of all msgs sent over PTMP
	class CPtmpMsg
	{
	public:
		CPtmpMsg(EPtmpMsgType type) : m_type(type) {}
		
		inline void setType(EPtmpMsgType type) { m_type = type; }
		inline EPtmpMsgType getType() const { return m_type; }

		// virtual functions to serialize and deserialize msgs to be sent over network
		virtual void serialize(CPtmpBuffer &buffer) const;
		virtual bool deserialize(CPtmpBuffer& buffer);

		// typedef for function to create a CPtmpMsg from a buffer
		typedef CPtmpMsg* (*TCreateFunction)(CPtmpBuffer& buffer);

		// static function to register a create function for a specified type of msg
		static bool registerCreation(EPtmpMsgType type, TCreateFunction func);

		// static function to dispatch the creation of CPtmpMsg from the buffer
		static CPtmpMsg* create(CPtmpBuffer& buffer);
			
	protected:
		EPtmpMsgType m_type;

	private:

		// static map used for creation
		inline static std::map<EPtmpMsgType, TCreateFunction>& getCreationMap()
		{
			static std::map<EPtmpMsgType, TCreateFunction> creationMap;
			return creationMap;
		}
	};
}

#endif