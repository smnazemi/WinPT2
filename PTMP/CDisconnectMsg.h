
//************************************************************************
//
// � Copyright ------
//  All use, disclosure, and/or reproduction of this material is
//  prohibited unless authorized in writing.
//
//************************************************************************

/*! /file
	File Name:	CDisconnectMsg.h     <br>
	Author:		Ajan U. Nair <br>
	Date:		10/09/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CPTMPMsg class definitions.
*/

/*************************************************************************
Oct 09, 07   Ajan U. Nair   Creation, Class definition, adding attributes/functions



*************************************************************************/

#ifndef CPtmp_DISCONNECT_MSG_H
#define CPtmp_DISCONNECT_MSG_H

#include"CPtmpMsg.h"

namespace Ptmp
{
	class CDisconnectMsg:public CPtmpMsg
	{
	public:
		//Srikant
		static const std::string	s_defaultReason;

		CDisconnectMsg();//:CPTMPMsg(msgByteArray)
		virtual void serialize(CPtmpBuffer& buffer) const;
		virtual bool deserialize(CPtmpBuffer& buffer);
		static CPtmpMsg* create(CPtmpBuffer& buffer);
		std::string	getReason();
		void	setReason(std::string reason);
	private:
		std::string	m_Reason;
		// temp variables for registering msg creation
		static const bool s_registerStatus;//to copy
	};
}

#endif
