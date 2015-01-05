//************************************************************************
//
// � Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************

/*! \file
	File Name:	CMacAddress.cpp  <br>
	Author:		Vijay Tummala    <br>
	Date:		02/16/05         <br>
	Revision:	1.0              <br>
	Description:
		This file holds the mac address class definitions.
*/

#include <string>
#include <ctime>
#include "CMacAddress.h"
#include "CIpAddress.h"
#include "CIpv6Address.h"
#include "../Support/stringUtil.h"
#include "../Support/stringConvert.h"
#include <qstring.h>

using namespace std;

CMacAddress::CMacAddress()
{
	CMacAddress mac = getRandomMacAddress();
	m_strMacAddress = mac.m_strMacAddress;
	memcpy(m_bytes, mac.m_bytes, 6);
}

CMacAddress::CMacAddress(const string& strMacAddress)
{
//	m_strMacAddress = Util::toUpperCase(strNewMacAddress);
	memset(m_bytes, 0, 6);

	unsigned int iTotalOctets=0, iLength=0;
	string strSubStr, strOctetStr[TOTAL_MAC_OCTETS];
	basic_string <char>::const_iterator str_Iter;
	
	//store octets in an array in Upper case
	for ( str_Iter = strMacAddress.begin(); str_Iter != strMacAddress.end(); str_Iter++ )
	{
		if (*str_Iter == '.')
		{
			iTotalOctets++;

			if (iTotalOctets >= TOTAL_MAC_OCTETS)
			{
				m_strMacAddress = "";
				return;
			}
		}
		else
			strOctetStr[iTotalOctets] += Util::toUpperCase(Util::toString<char>(*str_Iter));
	}

	iTotalOctets++;	

	if (iTotalOctets != TOTAL_MAC_OCTETS)
	{
		m_strMacAddress = "";
		return;
	}

	unsigned int i=0, j;
	for (i; i<TOTAL_MAC_OCTETS; i++)
	{
		iLength = MAC_OCTET_LENGTH - strOctetStr[i].length();

		if ( iLength < 0)	// truncate if it is long
            strOctetStr[i] = strOctetStr[i].substr(0, MAC_OCTET_LENGTH);

		for (j=0; j<iLength; j++) //Add '0' infront, if it is too short
			strOctetStr[i] = '0' + strOctetStr[i]; // add necessary 0s infront

		bool bOk;
		unsigned int shortOctet = QString(strOctetStr[i].c_str()).toUInt(&bOk, 16);

		if ((!bOk) || (shortOctet > 0xffff))
		{
			m_strMacAddress = "";
			memset(m_bytes, 0, 6);
			return;
		}

		m_bytes[i * 2] = (shortOctet >> 8) & 0xff;
		m_bytes[i * 2 + 1] = shortOctet & 0xff;
	}

	//add '.' in between octets
	m_strMacAddress = strOctetStr[0];
	for (i=1; i<TOTAL_MAC_OCTETS; i++)
	{
		m_strMacAddress += ".";
		m_strMacAddress += strOctetStr[i];
	}
}

CMacAddress::CMacAddress(const CMacAddress& mac)
{
	m_strMacAddress = mac.m_strMacAddress;
	memcpy(m_bytes, mac.m_bytes, 6);
}

bool CMacAddress::isAValidAddress() const
{
	string mac = m_strMacAddress;
	return isValidMacAddress(mac);
}

void CMacAddress::operator = (const CMacAddress& macAddress)
{
	m_strMacAddress = macAddress.m_strMacAddress;
	memcpy(m_bytes, macAddress.m_bytes, 6);
}

bool CMacAddress::operator == (const CMacAddress& macAddress) const
{
	return (m_strMacAddress == macAddress.m_strMacAddress);
}

bool CMacAddress::operator != (const CMacAddress& macAddress) const
{
	return (m_strMacAddress != macAddress.m_strMacAddress);
}

bool CMacAddress::operator < (const CMacAddress& macAddress) const
{
	return (m_strMacAddress < macAddress.m_strMacAddress);
}

bool CMacAddress::operator <= (const CMacAddress& macAddress) const
{
	return (m_strMacAddress <= macAddress.m_strMacAddress);
}

bool CMacAddress::operator > (const CMacAddress& macAddress) const
{
	return (m_strMacAddress > macAddress.m_strMacAddress);
}

bool CMacAddress::operator >= (const CMacAddress& macAddress) const
{
	return (m_strMacAddress >= macAddress.m_strMacAddress);
}

string CMacAddress::macToString() const
{
	return m_strMacAddress;
}

CMacAddress CMacAddress::getRandomMacAddress()
{
	string strRandomMacAddress;
	// hexa decimal string
    static const char HEX_STRING[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

	//CISCO MAC Address prefixes
	static const string CISCO_MAC_PREFIX[49] = {"0000.0C","0001.42","0001.43","0001.63","0001.64","0001.96","0001.97",
        						"0001.C7","0001.C9","0002.16","0002.17","0002.4A","0003.E4","0004.9A",
                                "0005.5E","0006.2A","0007.EC","0009.7C","000A.41","000A.F3","000B.BE",
                                "000C.85","000C.CF","000D.BD","0010.11","0030.A3","0030.F2","0040.0B",
                                "0050.0F","0060.2F","0060.3E","0060.47","0060.5C","0060.70","0090.0C",
                                "0090.21","0090.2B","00D0.58","00D0.97","00D0.BA","00D0.BC","00D0.D3",
								"00D0.FF","00E0.8F","00E0.A3","00E0.B0","00E0.F7","00E0.F9","00E0.FE"};
	
//	srand(static_cast<unsigned>(time(0)));

	strRandomMacAddress  = CISCO_MAC_PREFIX[rand() % 48];
	strRandomMacAddress += HEX_STRING[rand() % 15]; strRandomMacAddress += HEX_STRING[rand() % 15];
	strRandomMacAddress += '.';
	strRandomMacAddress += HEX_STRING[rand() % 15]; strRandomMacAddress += HEX_STRING[rand() % 15];
	strRandomMacAddress += HEX_STRING[rand() % 15]; strRandomMacAddress += HEX_STRING[rand() % 15];

	//create an object with random number, and return
	CMacAddress macAddress(strRandomMacAddress);	
	return macAddress;
}

bool CMacAddress::isValidMacAddress(string& strMacAddress)
{
	unsigned int uiMacAddr=0;
	unsigned int iTotalOctets=1;
	string strSubStr;
	basic_string <char>::iterator str_Iter;
	
	for ( str_Iter = strMacAddress.begin(); str_Iter != strMacAddress.end(); str_Iter++ )
	{
		if (*str_Iter == '.')
			iTotalOctets++;
	}

	if (iTotalOctets != TOTAL_MAC_OCTETS)
		return false;
	
	unsigned int i=0, j=0;
	for (i; i<TOTAL_MAC_OCTETS; i++)
	{
		strSubStr = strMacAddress[j++];

		if (strSubStr.length() <= 0)
			return false;

		while ((j < strMacAddress.size()) && (strMacAddress[j] != '.'))
			strSubStr += strMacAddress[j++];

        //if address is too long, return false
		if (strSubStr.length() > MAC_OCTET_LENGTH)
			return false;

		bool bOk;
		uiMacAddr = QString(strSubStr.c_str()).toUInt(&bOk, 16);

		if ((!bOk) || (uiMacAddr > 0xffff))
			return false;
		j++;
	}
	return true;
}

bool CMacAddress::isPartialMacAddressValid(string& strMacAddress)
{
	unsigned int uiMacAddr=0;
	unsigned int iTotalOctets=1;
	string strSubStr;
	basic_string <char>::iterator str_Iter;
	
	for ( str_Iter = strMacAddress.begin(); str_Iter != strMacAddress.end(); str_Iter++ )
	{
		if (*str_Iter == '.')
			iTotalOctets++;
	}

	if (iTotalOctets > TOTAL_MAC_OCTETS)
		return false;
	
	unsigned int i=0, j=0;
	for (i; i<TOTAL_MAC_OCTETS; i++)
	{
		strSubStr = strMacAddress[j++];

		if (strSubStr.length() <= 0)
			return false;

		while ((j < strMacAddress.size()) && (strMacAddress[j] != '.'))
			strSubStr += strMacAddress[j++];

		//if address is too long, return false
		if (strSubStr.length() > MAC_OCTET_LENGTH)
			return false;

		bool bOk;
		uiMacAddr = QString(strSubStr.c_str()).toUInt(&bOk, 16);

		if ((!bOk) || (uiMacAddr > 0xffff))
			return false;
		j++;
	}
	return true;
}

//Return mac address as canonical form XXXX.XXXX.XXXX 
CMacAddress CMacAddress::toCanonicalForm(string& strMacAddress)
{
//	CMacAddress macAddress;
	int iTotalOctets=0, iLength=0;
	string strSubStr, strOctetStr[TOTAL_MAC_OCTETS];
	basic_string <char>::iterator str_Iter;
	
	//store octets in an array in Upper case
	for ( str_Iter = strMacAddress.begin(); str_Iter != strMacAddress.end(); str_Iter++ )
	{
		if (*str_Iter == '.')
			iTotalOctets++;
		else
            strOctetStr[iTotalOctets] += toupper(*str_Iter);
	}
	iTotalOctets++;	

	int i=0, j;
	for (i; i<TOTAL_MAC_OCTETS; i++)
	{
		iLength = (MAC_OCTET_LENGTH - (int)strOctetStr[i].length());

		if ( iLength < 0)	// truncate if it is long
            strOctetStr[i] = strOctetStr[i].substr(0, MAC_OCTET_LENGTH);

		for (j=0; j<iLength; j++) //Add '0' infront, if it is too short
			strOctetStr[i] = '0' + strOctetStr[i]; // add necessary 0s infront
	}
	//add '.' in between octets
	strMacAddress = strOctetStr[0];
	for (i=1; i<TOTAL_MAC_OCTETS; i++)
	{
		strMacAddress += ".";
		strMacAddress += strOctetStr[i];
	}

//	macAddress.m_strMacAddress = strMacAddress;
//	return macAddress;
	return CMacAddress(strMacAddress);
}

//change mac address to standard form XX:XX:XX:XX:XX:XX 
string CMacAddress::toStandardForm() const
{
	int iTotalOctets=0, iLength=0;
	string strMacAddress, strAddress, strSubStr, strOctetStr[TOTAL_MAC_OCTETS];
	basic_string <char>::iterator str_Iter;

	strMacAddress = CMacAddress::m_strMacAddress;	

	//store octets in an array in Upper case
	for ( str_Iter = strMacAddress.begin(); str_Iter != strMacAddress.end(); str_Iter++ )
	{
		if (*str_Iter == '.')
			continue;
		else
			strAddress += toupper(*str_Iter);
	}
	
	//add ':' in the middle
	strMacAddress = strAddress.substr(0,2);
	for (int i=2; i<=10; i+=2)
	{
		strMacAddress += ":";
		strMacAddress += strAddress.substr(i,2);
	}

	return strMacAddress;
}

bool CMacAddress::isCompliant() const
{
	//The MAC address should not equal to "0000.0000.0000"
	//Also the Least Significat Bit(LSB) of first byte should not be 1
	string strSubStr = m_strMacAddress.substr(0, 2);
	bool bOk;

	if ( (m_strMacAddress == "0000.0000.0000") || (QString(strSubStr.c_str()).toUInt(&bOk, 16) & 0x01) )
		return false;
	else
        return true;
}

CMacAddress CMacAddress::getBroadcastAddress()
{
	CMacAddress broadCast("FFFF.FFFF.FFFF");
	return broadCast;
}

bool CMacAddress::isBroadcastAddress() const
{
	return (m_strMacAddress == "FFFF.FFFF.FFFF");
}

bool CMacAddress::isMulticastAddress() const
{
	return ((m_strMacAddress.substr(0, 7) == "0100.5E") // ip multicast
		|| (m_strMacAddress.substr(0, 5) == "3333.") // ipv6 multicast
		|| (m_strMacAddress == "0180.C200.0000") // stp
		|| (m_strMacAddress == "0100.0CCC.CCCC")// cdp
		|| (m_strMacAddress == "0100.0CCC.CCCD") // SSTP (part of STP)
		|| (m_strMacAddress == "0180.C200.0002") // lacp
		);
}

CMacAddress CMacAddress::getMulticast(const CIpAddress& ip)
{
	if (ip.isIpv4())
		return CMacAddress("0100.5E"
			+ Util::toHex(ip.getOctet(1) & 0x7f, 2) + "."
			+ Util::toHex(ip.getOctet(2), 2)
			+ Util::toHex(ip.getOctet(3), 2));
	else
		return CMacAddress("3333."
			+ Util::toHex(ip.getOctet(12), 2)
			+ Util::toHex(ip.getOctet(13), 2) + "."
			+ Util::toHex(ip.getOctet(14), 2)
			+ Util::toHex(ip.getOctet(15), 2));
}

unsigned char CMacAddress::getOctet(unsigned int index) const
{
	return m_bytes[index];
}

