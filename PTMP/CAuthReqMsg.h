//************************************************************************
//
// © Copyright ------
//  All use, disclosure, and/or reproduction of this material is
//  prohibited unless authorized in writing.
//
//************************************************************************

/*! /file
	File Name:	CAuthReqMsg.h     <br>
	Author:		Ajan U. Nair <br>
	Date:		10/09/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CPTMPMsg class definitions.
*/

/*************************************************************************
Oct 09, 07   Ajan U. Nair   Creation, Class definition, adding attributes/functions



*************************************************************************/


#ifndef CPtmp_AUTH_REQ_MSG_H
#define CPtmp_AUTH_REQ_MSG_H

#include "CPtmpMsg.h" 
#include <QString>

namespace Ptmp
{
	class CAuthReqMsg:public CPtmpMsg
	{
	
	public:

		CAuthReqMsg();//:CPTMPMsg(msgByteArray);
		virtual void serialize(CPtmpBuffer& buffer) const;
		virtual bool deserialize(CPtmpBuffer& buffer);
		static CPtmpMsg* create(CPtmpBuffer& buffer);		
		inline QString getUsername() const { return m_username; }
		inline void setUsername(QString username) { m_username = username; }
	
	private:
		QString m_username;
		// temp variables for registering msg creation
		const static bool s_registerStatus;    
		
	};
}

#endif