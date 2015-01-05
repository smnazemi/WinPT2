
//************************************************************************
//
// Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************

/*! /file
	File Name:	CNegoMsgParameter.cpp     <br>
	Author:		Ajan U. Nair <br>
	Date:		10/09/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CNegoMsgParameter class definitions.
*/

/*************************************************************************
Oct 09, 07   Ajan U. Nair   Creation, Class definition, adding attributes/functions



*************************************************************************/

#include "CNegoMsgParameter.h"

using namespace Ptmp;
using namespace std;

const std::string CNegoMsgParameters::s_defaultSignature = "PTMP";
const int CNegoMsgParameters::s_defaultVersion = 1;

CNegoMsgParameters::CNegoMsgParameters()
: m_signature(s_defaultSignature),
m_version(s_defaultVersion),
m_keepalive(0)
{
	// default for the following means accept all values
	m_encoding = EPtmpBufferEncoding(ePtmpBufferText | ePtmpBufferBinary);
	m_encryption = EPtmpEncryption(eNoEncryption | eXorEncryption);
	m_compression = EPtmpCompression(eNoCompression | eZlibDefault);
	m_authentication = EPtmpAuthentication(eClearText | eSimpleAuthentication | eMd5Authentication);
}
