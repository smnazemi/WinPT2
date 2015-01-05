 
//************************************************************************
//
// Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is
//  prohibited unless authorized in writing.
//
//************************************************************************

/*! /file
	File Name:	CIpcCallMsg.h     <br>
	Author:		Ajan U. Nair <br>
	Date:		09/11/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CIpcManager class definitions.
*/

/*************************************************************************
Nov 11, 07   Ajan U. Nair   Creation, Class definition, adding attributes/functions



*************************************************************************/


#ifndef CIpc_CALL_MSG_H
#define CIpc_CALL_MSG_H

#include "CIpcMsg.h"
#include <vector>
#include "../PTMP/CPtmpBuffer.h"
/*
#include <list>

#include "../PTMP/CPtmpMsg.h"
*/


namespace Ipc
{
/*	class CIpcArgument
	{
	public:

		inline CIpcArgument()
		{
			m_ArgType=1;
			m_valueOfArgument;
		}
		unsigned char m_ArgType ;
		void* m_valueOfArgument;
		inline std::string getSerialized()
		{
			std::string srializedStr;
			srializedStr.append(m_ArgType,1);

			srializedStr.append("\0");
			srializedStr.append("29\0");

			srializedStr.append("Default Value Of CIpcArgument");
			srializedStr.append("\0");

			return srializedStr;
		}
		inline void setArgType(char type){m_ArgType=type;}
	};


	class CIpcCall
	{
	public:
		std::string m_callName;
		std::list<CIpcArgument>argumentList;

	};
*/

	class CIpcCall;

	class CIpcCallMsg:public Ptmp::CPtmpMsg
	{
	private:	
		static const bool s_registerStatus;

		int callId;
		Ptmp::CPtmpBuffer m_buffer;

	public:
		CIpcCallMsg();
		CIpcCallMsg(const CIpcCallMsg& msg);
		virtual ~CIpcCallMsg();

		inline Ptmp::CPtmpBuffer& getBuffer() { return m_buffer; }

		virtual void serialize(Ptmp::CPtmpBuffer& buffer) const;
		virtual bool deserialize(Ptmp::CPtmpBuffer& buffer);
		static CPtmpMsg* create(Ptmp::CPtmpBuffer& buffer);

		inline void setCallId(int newCallId){callId=newCallId;}
		inline unsigned int getCallId(){return callId;}

		CIpcCallMsg* clone() const;

		
	};
}
#endif
