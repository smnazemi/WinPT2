
//************************************************************************
//
// � Copyright ------
//  All use, disclosure, and/or reproduction of this material is
//  prohibited unless authorized in writing.
//
//************************************************************************

/*! /file
	File Name:	CAuthStatusMsg.h     <br>
	Author:		Ajan U. Nair <br>
	Date:		10/09/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CPTMPMsg class definitions.
*/

/*************************************************************************
Oct 09, 07   Ajan U. Nair   Creation, Class definition, adding attributes/functions



*************************************************************************/


#ifndef CPtmp_AUTH_STATUS_MSG_H
#define CPtmp_AUTH_STATUS_MSG_H

#include "CPtmpMsg.h"

namespace Ptmp
{
	class CAuthStatusMsg : public CPtmpMsg
	{
	public:
		//Srikant
		static const bool	s_defaultStatus;

		CAuthStatusMsg();
		virtual void serialize(CPtmpBuffer& buffer) const;
		virtual bool deserialize(CPtmpBuffer& buffer);

		static CPtmpMsg* create(CPtmpBuffer& buffer);
				
		bool	getStatus();
		void	setStatus(bool status);

	private:
		bool	m_Status;

		// temp variables for registering msg creation
		static const bool s_registerStatus;
	};
}
#endif
