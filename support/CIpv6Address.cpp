//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is
//  prohibited unless authorized in writing.
//
//************************************************************************

/*! /file
	File Name:	CIpv6Address.cpp   <br>
	Author:		Michael Wang    <br>
	Date:		10/11/2007         <br>
	Revision:	1.0              <br>
	Description:
		This file holds the IPv6 address class definitions.
*/

/*****************************************************************************
******************************************************************************
THIS FILE IS NOT USE ANYMORE.
CIpv6Address is a typedef of CIpAddress.
******************************************************************************
*****************************************************************************/
#if 0

#include <iostream>
#include <stdlib.h>
#include "CIpv6Address.h"
#include "../util/stringConvert.h"
#include "../util/stringUtil.h"

using namespace std;


S16bytes::S16bytes()
{
	memset(bytes, 0, s_byteCount);
}

S16bytes S16bytes::operator &( const S16bytes& other ) const
{
	S16bytes newBytes;
	for (unsigned int i=0; i<s_byteCount; i++)
		newBytes.bytes[i] = bytes[i] & other.bytes[i];
	return newBytes;
}

S16bytes S16bytes::operator |( const S16bytes& other ) const
{
	S16bytes newBytes;
	for (unsigned int i=0; i<s_byteCount; i++)
		newBytes.bytes[i] = bytes[i] | other.bytes[i];
	return newBytes;
}

S16bytes S16bytes::operator ~() const
{
	S16bytes newBytes;
	for (unsigned int i=0; i<s_byteCount; i++)
		newBytes.bytes[i] = ~bytes[i];
	return newBytes;
}

bool S16bytes::operator >( const S16bytes& other ) const
{
	return (memcmp(bytes, other.bytes, s_byteCount) > 0);
}

bool S16bytes::operator >=( const S16bytes& other ) const
{
	return (memcmp(bytes, other.bytes, s_byteCount) >= 0);
}

bool S16bytes::operator <( const S16bytes& other ) const
{
	return (memcmp(bytes, other.bytes, s_byteCount) < 0);
}

bool S16bytes::operator <=( const S16bytes& other ) const
{
	return (memcmp(bytes, other.bytes, s_byteCount) <= 0);
}

bool S16bytes::operator ==( const S16bytes& other ) const
{
	return (memcmp(bytes, other.bytes, s_byteCount) == 0);
}

bool S16bytes::operator !=( const S16bytes& other ) const
{
	return (memcmp(bytes, other.bytes, s_byteCount) != 0);
}


const unsigned int CIpv6Address::s_addressSize = 16;


CIpv6Address::CIpv6Address()
{
	m_bValid = false;
}

/*
1:1:1:1:1:1:1:1
1:1::1:1
::1:1
1:1::
::1.1.1.1
*/

CIpv6Address::CIpv6Address(const string& str)
{
	m_bValid = false;

	int colonp = -1;
	char ch;
	bool saw_xdigit = false;
	int val = 0;
	const char *data = str.data();
	int dataSize = str.size();
	S16bytes ip;

	int i = 0, j = 0;

	if (dataSize < 2)
		return;

	// Leading :: requires some special handling.
	if (data[i] == ':')
		if (data[++i] != ':')
			return;

	int curtok = i;

	while (i < dataSize)
	{
		ch = data[i++];
		int chval = Util::hctoi(ch);
		if (chval != -1)
		{
			val <<= 4;
			val |= chval;
			if (val > 0xffff)
				return;
		
			saw_xdigit = true;
			continue;
		}

		if (ch == ':')
		{
			curtok = i;
			if (!saw_xdigit)
			{
				if (colonp != -1)
					return;
				colonp = j;
				continue;
			}
			else if (i == dataSize)
				return;

			if (j + 2 > S16bytes::s_byteCount)
				return;
	
			ip.bytes[j++] = ((val >> 8) & 0xff);
			ip.bytes[j++] = (val & 0xff);
	
			saw_xdigit = false;
			val = 0;
			continue;
		}

		if (ch == '.' && ((j + CIpAddress::s_addressSize) <= S16bytes::s_byteCount))
		{
			CIpAddress ipv4(str.substr(curtok));
			if (!ipv4.isAValidAddress())
				return;

			for (int k = 0; k < CIpAddress::s_addressSize; k++)
				ip.bytes[j++] = ipv4.getOctet(k);

			saw_xdigit = false;
			break;	// '\0' was seen by inet_pton4().
		}
	
		return;
	}

	if (saw_xdigit)
	{
		if (j + 2 > S16bytes::s_byteCount)
			return;
		ip.bytes[j++] = ((val >> 8) & 0xff);
		ip.bytes[j++] = (val & 0xff);
	}

	if (colonp != -1)
	{
		int n = j - colonp;

		if (j == S16bytes::s_byteCount)
			return;
	
		for (i = 1; i <= n; i++)
		{
			ip.bytes[S16bytes::s_byteCount - i] = ip.bytes[colonp + n - i];
			ip.bytes[colonp + n - i] = 0;
		}
	
		j = S16bytes::s_byteCount;
	}

	if (j != S16bytes::s_byteCount)
		return;

	m_address = ip;
	m_bValid = true;
}

CIpv6Address::CIpv6Address(const CIpv6Address& ip)
: CIpAddress()
{
	if (!&ip)
		return;

	m_address = ip.m_address;
	m_bValid = ip.m_bValid;
}

CIpv6Address::CIpv6Address(const CIpAddress& ip)
: CIpAddress()
{
	try
	{
		const CIpv6Address& ipv6 = dynamic_cast<const CIpv6Address&>(ip);
		m_address = ipv6.m_address;
		m_bValid = ipv6.m_bValid;
	}
	catch (std::exception ex)
	{
		m_address = S16bytes();
		m_bValid = false;
	}
}

std::string CIpv6Address::iPtoString() const
{
	string str;

	if (isIPv4Address() && (!isZeroAddress()))
	{
		str = "::";
		for (unsigned int i=12; i < S16bytes::s_byteCount; i++)
		{
			str += Util::toString<unsigned int>(m_address.bytes[i]);
			if ((i + 1) < S16bytes::s_byteCount)
				str += ".";
		}
	}
	else
	{
		int startZero = -1;
		int startMostZero = -1;
		int mostZeroCount = 0;

		for (int i=0; i<S16bytes::s_byteCount; i+=2)
		{
			if ((m_address.bytes[i] == 0) && (m_address.bytes[i+1] == 0))
			{
				if (startZero < 0)
					startZero = i;
			}
			else if (startZero >= 0)
			{
				int zeroCount = i - startZero;
				if ((zeroCount > 2) && (zeroCount > mostZeroCount))
				{
					startMostZero = startZero;
					mostZeroCount = zeroCount;
				}

				startZero = -1;
			}
		}

		if (startZero >= 0)
		{
			int zeroCount = S16bytes::s_byteCount - startZero;
			if ((zeroCount > 2) && (zeroCount > mostZeroCount))
			{
				startMostZero = startZero;
				mostZeroCount = zeroCount;
			}
		}

		for (unsigned int i = 0; i < S16bytes::s_byteCount; i+=2)
		{
			if (startMostZero == i)
			{
				if (i == 0)
					str += ":";
				str += ":";
				i += mostZeroCount - 2;
			}
			else
			{
				str += Util::toHex((m_address.bytes[i] << 8) | m_address.bytes[i+1], 1);
				
				if ((i + 2) < S16bytes::s_byteCount)
					str += ":";
			}
		}
	}

	return Util::toUpperCase(str);
}

bool CIpv6Address::isValidAddress(const std::string& str)
{
	CIpv6Address ip(str);
	return ip.m_bValid;
}

bool CIpv6Address::isPartialAddressValid(const std::string& str)
{
	if (str.empty())
		return false;

	int colonp = -1;
	char ch;
	bool saw_xdigit = false;
	int val = 0;
	const char *data = str.data();
	int dataSize = str.size();
	S16bytes ip;

	int i = 0, j = 0;

	// Leading :: requires some special handling.
	if (data[i] == ':')
	{
		if (dataSize == 1)
			return true;
		else if (data[++i] != ':')
			return false;
	}

	int curtok = i;

	while (i < dataSize)
	{
		ch = data[i++];
		int chval = Util::hctoi(ch);
		if (chval != -1)
		{
			val <<= 4;
			val |= chval;
			if (val > 0xffff)
				return false;
		
			saw_xdigit = true;
			continue;
		}

		if (ch == ':')
		{
			curtok = i;
			if (!saw_xdigit)
			{
				if (colonp != -1)
					return false;
				colonp = j;
				continue;
			}
			else if (i == dataSize)
			{
				if (colonp == -1)
					return (j + 2 < S16bytes::s_byteCount);
				else
					return (j + 4 < S16bytes::s_byteCount);
			}

			if (j + 2 > S16bytes::s_byteCount)
				return false;
	
			ip.bytes[j++] = ((val >> 8) & 0xff);
			ip.bytes[j++] = (val & 0xff);
	
			saw_xdigit = false;
			val = 0;
			continue;
		}

		if (ch == '.' && ((j + CIpAddress::s_addressSize) <= S16bytes::s_byteCount))
		{
			return CIpAddress::isPartialIPAddressValid(str.substr(curtok));
		}
	
		return false;
	}

	if (saw_xdigit)
	{
		if (j + 2 > S16bytes::s_byteCount)
			return false;
		ip.bytes[j++] = ((val >> 8) & 0xff);
		ip.bytes[j++] = (val & 0xff);
	}

	if (colonp != -1)
	{
		int n = j - colonp;

		if (j == S16bytes::s_byteCount)
			return false;
	
		for (i = 1; i <= n; i++)
		{
			ip.bytes[S16bytes::s_byteCount - i] = ip.bytes[colonp + n - i];
			ip.bytes[colonp + n - i] = 0;
		}
	
		j = S16bytes::s_byteCount;
	}

	return (j <= S16bytes::s_byteCount);
}

// FEC0::/48
bool CIpv6Address::isSiteLocalAddress() const
{
	S16bytes zero;
	return ((m_address.bytes[0] == 0xFE)
		&& (m_address.bytes[1] == 0xC0)
		&& (memcmp(m_address.bytes + 2, zero.bytes + 2, 4) == 0)
		);
}

CIpv6Address CIpv6Address::getSiteLocalAddress() const
{
	CIpv6Address ip = *this;
	ip.m_address.bytes[0] = 0xFE;
	ip.m_address.bytes[1] = 0xC0;
	memset(ip.m_address.bytes + 2, 0, 4);
	return ip;
}


// FE80::/64
bool CIpv6Address::isLinkLocalAddress() const
{
	S16bytes zero;
	return ((m_address.bytes[0] == 0xFE)
		&& (m_address.bytes[1] == 0x80)
		&& (memcmp(m_address.bytes + 2, zero.bytes + 2, 6) == 0)
		);
}

CIpv6Address CIpv6Address::getLinkLocalAddress() const
{
	CIpv6Address ip = *this;
	ip.m_address.bytes[0] = 0xFE;
	ip.m_address.bytes[1] = 0x80;
	memset(ip.m_address.bytes + 2, 0, 6);
	return ip;
}

// ::/96 OR ::FFFF:0:0/96
bool CIpv6Address::isIPv4Address() const
{
	S16bytes zero;
	return ((memcmp(m_address.bytes, zero.bytes, 10) == 0)
		&& (((m_address.bytes[10] == 0) && (m_address.bytes[11] == 0))
			|| ((m_address.bytes[10] == 0xff) && (m_address.bytes[11] == 0xff)))
		);
/*	return ((memcmp(m_address.bytes, zero.bytes, 12) == 0)
		&& (m_address.bytes[12] != 0)
		&& (m_address.bytes[13] != 0)
		);*/
}

// FF00::/8
bool CIpv6Address::isMulticastAddress() const
{
	return (m_address.bytes[0] == 0xFF);
}

// bits 8 to 11 are 0
bool CIpv6Address::isMulticastPermanent() const
{
	return ((m_address.bytes[1] & 0xF0) == 0);
}

// return bits 12 to 15
unsigned char CIpv6Address::getMulticastScope() const
{
	return (m_address.bytes[1] & 0x0F);
}

// FF02:0:0:0:0:1:FF00:0000/104
bool CIpv6Address::isSolicitedNodeAddress() const
{
	S16bytes zero;
	return ((m_address.bytes[0] == 0xFF)
		&& (m_address.bytes[1] == 0x02)
		&& (memcmp(m_address.bytes + 2, zero.bytes + 2, 9) == 0)
		&& (m_address.bytes[11] == 0x01)
		&& (m_address.bytes[12] == 0xFF)
		);
}

CIpv6Address CIpv6Address::getSolicitedNodeAddress() const
{
	CIpv6Address ip = *this;
	ip.m_address.bytes[0] = 0xFF;
	ip.m_address.bytes[1] = 0x02;
	memset(ip.m_address.bytes + 2, 0, 9);
	ip.m_address.bytes[11] = 0x01;
	ip.m_address.bytes[12] = 0xFF;
	return ip;
}

// FF02::1
CIpv6Address CIpv6Address::allNodesMulticastAddress()
{
	static CIpv6Address address("FF02::1");
	return address;
}

// FF02::2
CIpv6Address CIpv6Address::allRoutersMulticastAddress()
{
	static CIpv6Address address("FF02::2");
	return address;
}

bool CIpv6Address::isZeroAddress() const
{
	S16bytes zero;
	return (memcmp(m_address.bytes, zero.bytes, S16bytes::s_byteCount) == 0);
}

// ::
CIpv6Address CIpv6Address::zeroAddress()
{
	CIpv6Address ip;
	ip.m_bValid = true;
	return ip;
}

void CIpv6Address::setRawAddress(const S16bytes ip)
{
	m_address = ip;
	m_bValid = true;
}

S16bytes CIpv6Address::getRawAddress() const
{
	return m_address;
}

bool CIpv6Address::isInNetwork(const CIpv6Address& network, const CIpv6Address& mask) const
{
	return ( (m_address & mask.m_address) == (network.m_address & mask.m_address) );
}

CIpv6Address CIpv6Address::getNetworkID(const CIpv6Address& mask) const
{
	return *this & mask;
}

CIpv6Address CIpv6Address::getNetworkBroadcast(const CIpv6Address& mask) const
{
	return *this | (~mask);
}

CIpv6Address CIpv6Address::getFromPrefix(unsigned int prefix)
{
	CIpv6Address ip;
	memset(ip.m_address.bytes, 0xFF, prefix / 8);
	ip.m_address.bytes[prefix / 8] = 0xFF << (8 - prefix % 8);
	ip.m_bValid = true;
	return ip;
}

CIpv6Address CIpv6Address::getEui64(const CMacAddress& mac)
{
	CIpv6Address ip;
	memset(ip.m_address.bytes, 0, 8);
	ip.m_address.bytes[8] = mac.getOctet(0);
	ip.m_address.bytes[9] = mac.getOctet(1) | 0x02;
	ip.m_address.bytes[10] = mac.getOctet(2);
	ip.m_address.bytes[11] = 0xFF;
	ip.m_address.bytes[12] = 0xFE;
	ip.m_address.bytes[13] = mac.getOctet(3);
	ip.m_address.bytes[14] = mac.getOctet(4);
	ip.m_address.bytes[15] = mac.getOctet(5);

	ip.m_bValid = true;
	return ip;
}

CIpv6Address CIpv6Address::operator &( const CIpv6Address& ip ) const
{
	CIpv6Address newIp;
	if (m_bValid && ip.m_bValid)
	{
		newIp.m_address = m_address & ip.m_address;
		newIp.m_bValid = true;
	}
	return newIp;
}

CIpv6Address CIpv6Address::operator |( const CIpv6Address& ip ) const
{
	CIpv6Address newIp;
	if (m_bValid && ip.m_bValid)
	{
		newIp.m_address = m_address | ip.m_address;
		newIp.m_bValid = true;
	}
	return newIp;
}

CIpv6Address CIpv6Address::operator ~() const
{
	CIpv6Address newIp;
	if (m_bValid)
	{
		newIp.m_address = ~m_address;
		newIp.m_bValid = true;
	}
	return newIp;
}

bool CIpv6Address::operator >( const CIpv6Address& ip ) const
{
	return m_address > ip.m_address;
}

bool CIpv6Address::operator >=( const CIpv6Address& ip ) const
{
	return m_address >= ip.m_address;
}

bool CIpv6Address::operator <( const CIpv6Address& ip ) const
{
	return m_address < ip.m_address;
}

bool CIpv6Address::operator <=( const CIpv6Address& ip ) const
{
	return m_address <= ip.m_address;
}

bool CIpv6Address::operator ==( const CIpv6Address & ip ) const
{
	return m_address == ip.m_address;
}

bool CIpv6Address::operator !=( const CIpv6Address & ip ) const
{
	return m_address != ip.m_address;
}

void CIpv6Address::operator =( const CIpv6Address & ip )
{
	m_address = ip.m_address;
	m_bValid = ip.m_bValid;
}

void CIpv6Address::operator =( const CIpAddress & ip )
{
	try
	{
		const CIpv6Address& ipv6 = dynamic_cast<const CIpv6Address&>(ip);
		m_address = ipv6.m_address;
		m_bValid = ipv6.m_bValid;
	}
	catch (std::exception ex)
	{
		m_address = S16bytes();
		m_bValid = false;
	}
}

CIpAddress* CIpv6Address::clone() const
{
	return new CIpv6Address(*this);
}

unsigned char CIpv6Address::getOctet(unsigned int index) const
{
	if ((index >= S16bytes::s_byteCount) || (!m_bValid))
		return 0;

	return m_address.bytes[index];
}



#if 0

bool CIpAddress::isPrivateAddress() const
{
	return ( (isInNetwork("10.0.0.0", "255.0.0.0")) ||
			 (isInNetwork("172.16.0.0", "255.240.0.0")) ||
			 (isInNetwork("192.168.0.0", "255.255.0.0")) );
}


bool CIpAddress::isInNetwork(const string& strNetwork, const string& strSubNet) const
{
	return isInNetwork(CIpAddress(strNetwork), CIpAddress(strSubNet));
//	return ( (m_uiAddress & stringToIPAddress(strSubNet)) == (stringToIPAddress(strNetwork) & stringToIPAddress(strSubNet)) );
}

int CIpAddress::getNetworkBits() const
{
	for (int i=(TOTAL_NETWORK_BITS-1); i>=0; i--)
	{
		if ( ((m_uiAddress >> i) & 0x1) == 0 )
			return ((TOTAL_NETWORK_BITS-1) - i);
	}
	return TOTAL_NETWORK_BITS;
}

CIpAddress CIpAddress::getNetworkID(const CIpAddress& subnetMask) const
{
	CIpAddress networkID;

	networkID.setRawIPAddress(m_uiAddress & subnetMask.m_uiAddress);

	return networkID;
}

CIpAddress CIpAddress::getNetworkBroadcast(const CIpAddress& subnetMask) const
{
	CIpAddress networkBroadcast;

	networkBroadcast.setRawIPAddress(m_uiAddress | (~subnetMask.m_uiAddress));

	return networkBroadcast;
}

bool CIpAddress::isClassDAddress ( ) const
{
	return ( (m_uiAddress & 0xe0000000) == 0xe0000000 );
}

bool CIpAddress::isClassEAddress ( ) const
{
	return ( (m_uiAddress & 0xf0000000) == 0xf0000000 );
}

CIpAddress CIpAddress::getClassNetwork() const
{
	CIpAddress network;

	network.setRawIPAddress(((m_uiAddress & 0x80000000) == 0) ? (m_uiAddress & 0xff000000)
					    : ((m_uiAddress & 0x40000000) == 0) ? (m_uiAddress & 0xffff0000)
					    :  (m_uiAddress & 0xffffff00));

	return network;
}

CIpAddress CIpAddress::getClassSubnetMask() const
{
	CIpAddress mask;

	if (m_uiAddress == 0)
		return CIpAddress::zeroAddress();
	mask.setRawIPAddress(((m_uiAddress & 0x80000000) == 0) ? (0xff000000)
		             : ((m_uiAddress & 0x40000000) == 0) ? (0xffff0000)
				     : (0xffffff00));

	return mask;
}

bool CIpAddress::isAValidSubnetMask() const
{
	if (!m_bValid)
		return false;

	int i;

	for (i=(TOTAL_NETWORK_BITS-1); i>=0; i--)
		if ( ((m_uiAddress >> i) & 0x1) == 0 )
			break;

	for (; i>=0; i--)
		if ( ((m_uiAddress >> i) & 0x1) == 1 )
			return false;

	return true;
}

bool CIpAddress::isAValidNetwork() const
{
	int iFirstOctet = ((m_uiAddress >> 24) & 0xff);
	return ((iFirstOctet > 0) && (iFirstOctet < 224) && (iFirstOctet != 127));
}

bool CIpAddress::isIPSubnetValid(const CIpAddress& subnetMask) const
{
	CIpAddress networkID;
	int iHost;
	networkID = getNetworkID(subnetMask);

	iHost = m_uiAddress - networkID.m_uiAddress;
	return ( (iHost != 0) && (iHost != ((1 << (32 - subnetMask.getNetworkBits())) - 1)) );
}

CIpAddress CIpAddress::operator &(const CIpAddress & ipAddress) const
{
	CIpAddress newIPAddress;

	newIPAddress.setRawIPAddress(m_uiAddress & ipAddress.m_uiAddress);

	return newIPAddress;
}

CIpAddress CIpAddress::operator |(const CIpAddress & ipAddress) const
{
	CIpAddress newIPAddress;

	newIPAddress.setRawIPAddress( m_uiAddress | ipAddress.m_uiAddress );

	return newIPAddress;
}

CIpAddress CIpAddress::operator ~() const
{
	CIpAddress newIPAddress;

	newIPAddress.setRawIPAddress(~m_uiAddress);

	return newIPAddress;
}

void CIpAddress::operator = (const CIpAddress & ipAddress)
{
	m_uiAddress = ipAddress.m_uiAddress;
	m_bValid = ipAddress.m_bValid;
	m_bUsedForId = ipAddress.m_bUsedForId;
}

bool CIpAddress::operator > (const CIpAddress & ipAddress) const
{
	return (m_uiAddress > ipAddress.m_uiAddress);
}

bool CIpAddress::operator >= (const CIpAddress & ipAddress) const
{
	return (m_uiAddress >= ipAddress.m_uiAddress);
}

bool CIpAddress::operator < (const CIpAddress & ipAddress) const
{
	return (m_uiAddress < ipAddress.m_uiAddress);
}

bool CIpAddress::operator <= (const CIpAddress & ipAddress) const
{
	return (m_uiAddress <= ipAddress.m_uiAddress);
}

bool CIpAddress::operator ==(const CIpAddress & ipAddress) const
{
/*	bool addEqual = (m_uiAddress == ipAddress.m_uiAddress);
	bool validEqual = ;
	bool ret = addEqual && validEqual;
	return ret;*/
	return (((!m_bValid) && (!ipAddress.m_bValid))
		|| ((m_uiAddress == ipAddress.m_uiAddress) && (m_bValid == ipAddress.m_bValid)));
}

bool CIpAddress::operator !=(const CIpAddress & ipAddress) const
{
	return ((m_uiAddress != ipAddress.m_uiAddress) || (m_bValid != ipAddress.m_bValid));
}

CIpAddress CIpAddress::clone() const
{
	CIpAddress newIPAddress;

	newIPAddress.setRawIPAddress(m_uiAddress);

	return newIPAddress;
}

string CIpAddress::iPtoString() const
{
	string strIpAddress;

	strIpAddress = Util::toString<uint> ( (m_uiAddress >> TWENTYFOUR_BITS) & 0xff );
	strIpAddress += ".";
	strIpAddress += Util::toString<uint> ( (m_uiAddress >> SIXTEEN_BITS)    & 0xff );
	strIpAddress += ".";
	strIpAddress += Util::toString<uint> ( (m_uiAddress >> EIGHT_BITS)      & 0xff );
	strIpAddress += ".";
	strIpAddress += Util::toString<uint> ( m_uiAddress & 0xff );

	return strIpAddress;
}
/*
unsigned int CIpAddress::stringToIPAddress(const string& strIPAddress) throw
{
	unsigned int uiIpAddr[4], totalOctets=1, uiIpAddress=0;
	string strSubStr;

	if (strIPAddress.length() == 0)
		throw "Invalid IP Address.";

	//Find total number of octects
	for (unsigned int k=0; k < strIPAddress.length(); k++)
	{
		if ( strIPAddress[k] == '.' )
			totalOctets++;
	}

	//Check total octects greater or less than TOTAL_IP_OCTETS
	if ( totalOctets != TOTAL_IP_OCTETS )
		throw "Invalid IP Address.";

	unsigned int j=0;
	for (int i=0; i < TOTAL_IP_OCTETS; i++)
	{
		strSubStr = strIPAddress[j++];

		while ( (strIPAddress[j] != '.') && (j < strIPAddress.length()) )
			strSubStr += strIPAddress[j++];

		uiIpAddr[i] = Util::fromString<uint> ( strSubStr );

		//check for octet value range (0 - 255)
		if ( uiIpAddr[i] > MAX_OCTET_VALUE )
			throw "Invalid IP Address.";

		j++;
	}

	for (int i=0; i<TOTAL_IP_OCTETS; i++)
	{
		uiIpAddress += (uiIpAddr[i] << (((TOTAL_IP_OCTETS - 1) - i) * EIGHT_BITS));
	}

	return uiIpAddress;
}
*/

string CIpAddress::getIPasHexString() const
{
	// hexa decimal string
    static char HEX_STRING[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

	string strIPAddress="";
	int iAddress;

	if (m_uiAddress == 0)
		return strIPAddress;

	iAddress = m_uiAddress;

	for (int i=0; ((i<EIGHT_BITS) && (iAddress != 0)); i++)
	{
		strIPAddress = HEX_STRING[iAddress & 0xf] + strIPAddress;
		iAddress >>= FOUR_BITS;
	}

	return strIPAddress;
}

bool CIpAddress::isAValidAddress() const
{
	return m_bValid;
}

bool CIpAddress::isValidIPAddress(const string& ipAddress)
{
	return CIpAddress(ipAddress).m_bValid;
/*
	unsigned int address;

	try
	{
        address = stringToIPAddress(ipAddress);
	}
	catch ( ... )
	{
		return false;
	};

	return true;
*/
}

bool CIpAddress::isPartialIPAddressValid(const string& strIPAddress)
{
	unsigned int uiIpAddr=0;
	string strSubStr;

	int i=0, j=0;
	for (i; (i<TOTAL_IP_OCTETS) && (j < strIPAddress.size()); i++)
	{
		strSubStr = strIPAddress[j++];

		if (strSubStr.length() <= 0)
			return false;

		while ((strIPAddress[j] != '.') && (j < strIPAddress.size()))
			strSubStr += strIPAddress[j++];

		try
		{
			uiIpAddr = Util::fromString<uint> ( strSubStr );
		}
		catch ( ... )
		{
			return false;
		}

		if (uiIpAddr > MAX_OCTET_VALUE)
			return false;

		j++;
	}

	//if more than TOTAL_IP_OCTETS, return false
	if ((i == TOTAL_IP_OCTETS) && ( j <= strIPAddress.size() ))
		return false;

	return true;
}

CIpAddress CIpAddress::getFromNetworkBits(int iBits)
{
	CIpAddress newIPAddress;

	newIPAddress.setRawIPAddress(0xffffffff << ((iBits < 32) ? (32 - iBits) : 0));
//	newIPAddress.setRawIPAddress(0x80000000 >> ((iBits > 0) ? (iBits - 1) : 0));

	return newIPAddress;
}

CIpAddress CIpAddress::broadCastAddress()
{
	CIpAddress broadCast("255.255.255.255");

	return broadCast;
}

bool CIpAddress::isBroadcastAddress( ) const
{
	return (( (m_uiAddress & 0xffffffff) == 0xffffffff ) && m_bValid);
}

CIpAddress CIpAddress::zeroAddress()
{
	CIpAddress zeroAddr("0.0.0.0");

	return zeroAddr;
}

bool CIpAddress::isMulticastAddress() const
{
	unsigned char octet0 = getOctet(0);
	return ((octet0 >= 224) && (octet0 <= 239));
}

#endif
#endif
