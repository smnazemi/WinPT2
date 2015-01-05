//************************************************************************
//
// � Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************

/*! /file
	File Name:	CNegoMsg.h     <br>
	Author:		Ajan U. Nair <br>
	Date:		10/09/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CPTMPMsg class definitions.
*/

/*************************************************************************
Oct 09, 07   Ajan U. Nair   Creation, Class definition, adding attributes/functions



*************************************************************************/

#ifndef PTMP_CNEGOMSG_H
#define PTMP_CNEGOMSG_H

#include "CPtmpMsg.h"

namespace Ptmp
{
	class CNegoMsgParameters;

	class CNegoMsg : public CPtmpMsg
	{
	public:
		CNegoMsg(CNegoMsgParameters *negoParams, EPtmpMsgType type=ePtmpNegoRequest);

		virtual void serialize(CPtmpBuffer& buffer) const;
		virtual bool deserialize(CPtmpBuffer& buffer);

		// static function to create a msg from buffer
		static CPtmpMsg* create(CPtmpBuffer& buffer);
		
		inline CNegoMsgParameters* getNegoMsgParameters() const { return m_negoMsgparameters; }
		inline void setNegoMsgParameters(CNegoMsgParameters* parameters) { m_negoMsgparameters = parameters; }

	private:

		CNegoMsgParameters *m_negoMsgparameters;
		
		// temp variables for registering nego msg creation
		static const bool s_requestRegisterStatus;
		static const bool s_responseRegisterStatus;
	};
}
#endif
