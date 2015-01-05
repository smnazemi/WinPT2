//************************************************************************
//
// � Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is
//  prohibited unless authorized in writing.
//
//************************************************************************

/*! /file
	File Name:	CKeepAliveMsg.h     <br>
	Author:		Michael Wang <br>
	Date:		05/17/2008      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CKeepAliveMsg class definitions.
*/

/*************************************************************************



*************************************************************************/

#ifndef PTMP_CKEEPALIVEMSG_H
#define PTMP_CKEEPALIVEMSG_H

#include "CPtmpMsg.h"

namespace Ptmp
{
	class CKeepAliveMsg : public CPtmpMsg
	{
	public:
		CKeepAliveMsg();

		virtual void serialize(CPtmpBuffer& buffer) const;
		virtual bool deserialize(CPtmpBuffer& buffer);

		// static function to create a msg from buffer
		static CPtmpMsg* create(CPtmpBuffer& buffer);

	private:

		// temp variables for registering nego msg creation
		static const bool s_registerStatus;
	};
}
#endif
