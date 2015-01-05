//************************************************************************
//
// � Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************

/*! /file
	File Name:	CNegoMsgParameter.h     <br>
	Author:		Ajan U. Nair <br>
	Date:		10/09/07      <br>
	Revision:	1.0           <br>
	Description:
		This file has the negotiation parameters
*/

/*************************************************************************
Oct 09, 07   Ajan U. Nair   Creation, Class definition, adding attributes/functions


*************************************************************************/
#ifndef PTMP_CNEGOMSGPARAMETER_H
#define PTMP_CNEGOMSGPARAMETER_H

#include "CPtmpBuffer.h"

namespace Ptmp
{
	enum EPtmpEncryption
	{
		eNoEncryption = 1,
		eXorEncryption = 2
	};

	enum EPtmpCompression
	{
		eNoCompression = 1,
		eZlibDefault = 2
	};

	enum EPtmpAuthentication
	{
		eClearText = 1,
		eSimpleAuthentication = 2,
		eMd5Authentication = 4
	};

	class CNegoMsgParameters
	{
	public:
		CNegoMsgParameters();

		std::string				m_signature;
		int						m_version;
		QUuid					m_id;
//		int						m_capabilities;
		EPtmpBufferEncoding		m_encoding;
		EPtmpEncryption			m_encryption;
		EPtmpCompression		m_compression;
		EPtmpAuthentication		m_authentication;
		std::string				m_timestamp;
		int						m_keepalive;
		std::string				m_reserved;
//		int						m_timeout;

		static const std::string	s_defaultSignature;
		static const int			s_defaultVersion;
	};
}

#endif
