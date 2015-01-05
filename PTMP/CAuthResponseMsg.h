//************************************************************************
//
// � Copyright ------
//  All use, disclosure, and/or reproduction of this material is
//  prohibited unless authorized in writing.
//
//************************************************************************

/*! /file
	File Name:	CAuthResponseMsg.h     <br>
	Author:		Ajan U. Nair <br>
	Date:		10/09/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CPTMPMsg class definitions.
*/

/*************************************************************************
Oct 09, 07   Ajan U. Nair   Creation, Class definition, adding attributes/functions



*************************************************************************/

#ifndef CPtmp_AUTH_RESP_MSG_H
#define CPtmp_AUTH_RESP_MSG_H

#include "CPtmpMsg.h"

#include "CAuthChallengeMsg.h"
#include <QString>

namespace Ptmp
{
	class CAuthResponseMsg : public CPtmpMsg
	{
	public:
		
		CAuthResponseMsg();
		virtual void serialize(CPtmpBuffer& buffer) const;
		virtual bool deserialize(CPtmpBuffer& buffer);

		static CPtmpMsg* create(CPtmpBuffer& buffer);
		
		std::string getDigestText();
		inline QString getUserName() const { return m_userName; }
		std::string getCustommessage();

		bool	validateResponse(std::string   password);
		
		void	setDigestText( std::string  digesttext);
		
		void	setCustommessage(std::string   custommessage);

		inline void setUserName(const QString& username) { m_userName = username; }
		
				
	private:

		
		std::string	m_Digesttext;
		QString m_userName;
		std::string	m_Custommessage;

		// temp variables for registering msg creation
		static const bool s_registerStatus;

		unsigned char* m_Digesttext1[16];
	};
}
#endif
