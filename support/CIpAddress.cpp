//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is
//  prohibited unless authorized in writing.
//
//************************************************************************

/*! /file
	File Name:	CIpAddress.cpp   <br>
	Author:		Vijay Tummala    <br>
	Date:		02/11/05         <br>
	Revision:	1.0              <br>
	Description:
		This file holds the ip address class definitions.
*/

#include <iostream>
#include <stdlib.h>
#include "CIpAddress.h"
#include "CMacAddress.h"
#include "../support/stringConvert.h"
#include "../support/stringUtil.h"

using namespace std;

const unsigned int CIpAddress::s_v4AddressSize = 4;
const unsigned int CIpAddress::s_v6AddressSize = 16;


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


S16bytes S16bytes::operator +( unsigned int other ) const
{
	S16bytes newBytes(*this);
	newBytes += other;
	return newBytes;
}

S16bytes& S16bytes::operator +=( unsigned int other )
{
	S16bytes newBytes;
	newBytes.bytes[12] = (other >> 24) & 0xff;
	newBytes.bytes[13] = (other >> 16) & 0xff;
	newBytes.bytes[14] = (other >> 8) & 0xff;
	newBytes.bytes[15] = other & 0xff;

	return operator+=(newBytes);
}

S16bytes S16bytes::operator +( const S16bytes& other ) const
{
	S16bytes newBytes(*this);
	newBytes += other;
	return newBytes;
}

S16bytes& S16bytes::operator +=( const S16bytes& other )
{
	int index = s_byteCount;
	int sum = 0;
	while (index > 0)
	{
		index--;
		sum = (bytes[index] & 0xff) + 
			  (other.bytes[index] & 0xff) + (sum >> 8);
		bytes[index] = static_cast<unsigned char>(sum);
	}

	return *this;
}


S16bytes S16bytes::operator -( unsigned int other ) const
{
	S16bytes newBytes(*this);
	newBytes -= other;
	return newBytes;
}

S16bytes& S16bytes::operator -=( unsigned int other )
{
	S16bytes newBytes;
	newBytes.bytes[12] = (other >> 24) & 0xff;
	newBytes.bytes[13] = (other >> 16) & 0xff;
	newBytes.bytes[14] = (other >> 8) & 0xff;
	newBytes.bytes[15] = other & 0xff;

	return operator-=(newBytes);
}

S16bytes S16bytes::operator -( const S16bytes& other ) const
{
	S16bytes newBytes(*this);
	newBytes -= other;
	return newBytes;
}

S16bytes& S16bytes::operator -=( const S16bytes& other )
{
	int index = s_byteCount;
	int diff = 0;
	while (index > 0)
	{
		index--;
		diff = (bytes[index] & 0xff) - 
			  (other.bytes[index] & 0xff) + (diff >> 8);
		bytes[index] = static_cast<unsigned char>(diff);
	}

	return *this;
}

CIpAddress::CIpAddress()
{
	m_v4Address = 0;
	m_bV4 = true;
	m_bValid = false;
	m_bUsedForId = false;
}

CIpAddress::CIpAddress(const string& strIPAddress)
{
	m_bUsedForId = false;

	try
	{
		unsigned int uiIpAddr[4], totalOctets=1, uiIpAddress=0;
		string strSubStr;

		if (strIPAddress.length() == 0)
		{
			throw "Invalid IP Address.";
//			m_bValid = false;
//			return;
		}

		//Find total number of octects
		for (unsigned int k=0; k < strIPAddress.length(); k++)
		{
			if ( strIPAddress[k] == '.' )
				totalOctets++;
		}

		//Check total octects greater or less than TOTAL_IP_OCTETS
		if ( totalOctets != TOTAL_IP_OCTETS )
		{
			throw "Invalid IP Address.";
//			m_bValid = false;
//			return;
		}

		unsigned int j=0;
		for (int i=0; i < TOTAL_IP_OCTETS; i++)
		{
			strSubStr = strIPAddress[j++];

			while ( (strIPAddress[j] != '.') && (j < strIPAddress.length()) )
				strSubStr += strIPAddress[j++];

/*			if (!Util::isStringA<uint>(strSubStr))
			{
				throw "Invalid IP Address.";
//				m_bValid = false;
//				return;
			}
*/
			uiIpAddr[i] = Util::fromString<uint> ( strSubStr );

			//check for octet value range (0 - 255)
			if ( uiIpAddr[i] > MAX_OCTET_VALUE )
			{
				throw "Invalid IP Address.";
//				m_bValid = false;
//				return;
			}

			j++;
		}
		
		for (int i=0; i<TOTAL_IP_OCTETS; i++)
		{
			uiIpAddress += (uiIpAddr[i] << (((TOTAL_IP_OCTETS - 1) - i) * EIGHT_BITS));
		}

		m_v4Address = uiIpAddress;
		m_bValid = true;
	}
	catch ( ... )
	{
		m_v4Address = 0;
		m_bValid = false;
	};

	m_bV4 = true;

	if (!m_bValid)
	{
		const std::string& str = strIPAddress;
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

			if ((ch == '.') && (curtok > 0)
				&& ((j + s_v4AddressSize) <= S16bytes::s_byteCount))
			{
				CIpAddress ipv4(str.substr(curtok));
				if (!ipv4.isAValidAddress())
					return;

				for (int k = 0; k < s_v4AddressSize; k++)
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

		m_v6Address = ip;
		m_bValid = true;
		m_bV4 = false;
	}
}

CIpAddress::CIpAddress(const CIpAddress& ip)
{
	if (!&ip)
		return;

	m_v4Address = ip.m_v4Address;
	m_v6Address = ip.m_v6Address;
	m_bV4 = ip.m_bV4;
	m_bValid = ip.m_bValid;
	m_bUsedForId = ip.m_bUsedForId;
}

string CIpAddress::iPtoString() const
{
	string str;
	if (m_bV4)
	{
		str = Util::toString<uint> ( (m_v4Address >> TWENTYFOUR_BITS) & 0xff )
			+ "."
			+ Util::toString<uint> ( (m_v4Address >> SIXTEEN_BITS)    & 0xff )
			+ "."
			+ Util::toString<uint> ( (m_v4Address >> EIGHT_BITS)      & 0xff )
			+ "."
			+ Util::toString<uint> ( m_v4Address & 0xff );
	}
	else
	{
		if (isIPv4MappedAddress() && (!isZeroAddress()))
		{
			str = "::";
			for (unsigned int i=12; i < S16bytes::s_byteCount; i++)
			{
				str += Util::toString<unsigned int>(m_v6Address.bytes[i]);
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
				if ((m_v6Address.bytes[i] == 0) && (m_v6Address.bytes[i+1] == 0))
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
					str += Util::toHex((m_v6Address.bytes[i] << 8) | m_v6Address.bytes[i+1], 1);
					
					if ((i + 2) < S16bytes::s_byteCount)
						str += ":";
				}

 			}
		}

		str = Util::toUpperCase(str);
	}

	return str;
}

CIpAddress* CIpAddress::clone() const
{
	return new CIpAddress(*this);
}

unsigned char CIpAddress::getOctet(unsigned int index) const
{
	if (m_bV4)
	{
		if ((index > 3) || (!m_bValid))
			return 0;

		return ((m_v4Address >> ((3 - index) * 8)) & 0xff);
	}
	else
	{
		if ((index >= S16bytes::s_byteCount) || (!m_bValid))
			return 0;

		return m_v6Address.bytes[index];
	}
}

CIpAddress CIpAddress::operator &(const CIpAddress & ip) const
{
	CIpAddress newIp;

	if (m_bV4 == ip.m_bV4)
	{
		newIp.m_bV4 = m_bV4;
//		if (m_bValid && ip.m_bValid)
		{
			newIp.m_v6Address = m_v6Address & ip.m_v6Address;
			newIp.m_v4Address = m_v4Address & ip.m_v4Address;
			newIp.m_bValid = true;
		}
	}

	return newIp;
}

CIpAddress CIpAddress::operator |(const CIpAddress & ip) const
{
	CIpAddress newIp;

	if (m_bV4 == ip.m_bV4)
	{
		newIp.m_bV4 = m_bV4;
//		if (m_bValid && ip.m_bValid)
		{
			newIp.m_v6Address = m_v6Address | ip.m_v6Address;
			newIp.m_v4Address = m_v4Address | ip.m_v4Address;
			newIp.m_bValid = true;
		}
	}

	return newIp;
}

CIpAddress CIpAddress::operator ~() const
{
	CIpAddress newIp;
//	if (m_bValid)
	{
		newIp.m_v4Address = ~m_v4Address;
		newIp.m_v6Address = ~m_v6Address;
		newIp.m_bValid = true;
		newIp.m_bV4 = m_bV4;
	}
	return newIp;
}

void CIpAddress::operator = (const CIpAddress & ip)
{
	m_v4Address = ip.m_v4Address;
	m_v6Address = ip.m_v6Address;
	m_bValid = ip.m_bValid;
	m_bV4 = ip.m_bV4;
 	m_bUsedForId = ip.m_bUsedForId;
}

bool CIpAddress::operator > (const CIpAddress & ip) const
{
//	if ((m_bV4 != ip.m_bV4) || (!m_bValid) || (!ip.m_bValid))
	if ((m_bV4 != ip.m_bV4) && m_bValid && ip.m_bValid)
		return false;

	if ((m_bV4 && m_bValid) || (ip.m_bV4 && ip.m_bValid))
		return (m_v4Address > ip.m_v4Address);
	else
		return m_v6Address > ip.m_v6Address;
}

bool CIpAddress::operator >= (const CIpAddress & ip) const
{
//	if ((m_bV4 != ip.m_bV4) || (!m_bValid) || (!ip.m_bValid))
	if ((m_bV4 != ip.m_bV4) && m_bValid && ip.m_bValid)
		return false;

	if ((m_bV4 && m_bValid) || (ip.m_bV4 && ip.m_bValid))
		return (m_v4Address >= ip.m_v4Address);
	else
		return m_v6Address >= ip.m_v6Address;
}

bool CIpAddress::operator < (const CIpAddress & ip) const
{
//	if ((m_bV4 != ip.m_bV4) || (!m_bValid) || (!ip.m_bValid))
	if ((m_bV4 != ip.m_bV4) && m_bValid && ip.m_bValid)
		return false;

	if ((m_bV4 && m_bValid) || (ip.m_bV4 && ip.m_bValid))
		return (m_v4Address < ip.m_v4Address);
	else
		return m_v6Address < ip.m_v6Address;
}

bool CIpAddress::operator <= (const CIpAddress & ip) const
{
//	if ((m_bV4 != ip.m_bV4) || (!m_bValid) || (!ip.m_bValid))
	if ((m_bV4 != ip.m_bV4) && m_bValid && ip.m_bValid)
		return false;

	if ((m_bV4 && m_bValid) || (ip.m_bV4 && ip.m_bValid))
		return (m_v4Address <= ip.m_v4Address);
	else
		return m_v6Address <= ip.m_v6Address;
}

bool CIpAddress::operator ==(const CIpAddress & ip) const
{
//	if ((m_bV4 != ip.m_bV4) || (!m_bValid) || (!ip.m_bValid))
	if ((m_bV4 != ip.m_bV4) && m_bValid && ip.m_bValid)
		return false;

	if ((m_bV4 && m_bValid) || (ip.m_bV4 && ip.m_bValid))
		return (((!m_bValid) && (!ip.m_bValid))
			|| ((m_v4Address == ip.m_v4Address) && (m_bValid == ip.m_bValid)));
	else
		return m_v6Address == ip.m_v6Address;
}

bool CIpAddress::operator !=(const CIpAddress & ip) const
{
//	if ((m_bV4 != ip.m_bV4) || (!m_bValid) || (!ip.m_bValid))
	if ((m_bV4 != ip.m_bV4) && m_bValid && ip.m_bValid)
		return false;

	if ((m_bV4 && m_bValid) || (ip.m_bV4 && ip.m_bValid))
		return ((m_v4Address != ip.m_v4Address) || (m_bValid != ip.m_bValid));
	else
		return m_v6Address != ip.m_v6Address;
}

CIpAddress CIpAddress::operator +( unsigned int other ) const
{
	CIpAddress newIp(*this);
	if (m_bV4)
		newIp.m_v4Address += other;
	else
		newIp.m_v6Address += other;

	return newIp;
}

CIpAddress CIpAddress::operator -( unsigned int other ) const
{
	CIpAddress newIp(*this);
	if (m_bV4)
		newIp.m_v4Address -= other;
	else
		newIp.m_v6Address -= other;

	return newIp;
}

CIpAddress& CIpAddress::operator +=( unsigned int other )
{
	if (m_bV4)
		m_v4Address += other;
	else
		m_v6Address += other;

	return *this;
}

CIpAddress& CIpAddress::operator -=( unsigned int other )
{
	if (m_bV4)
		m_v4Address -= other;
	else
		m_v6Address -= other;

	return *this;
}

CIpAddress CIpAddress::operator +( const CIpAddress& other ) const
{
	CIpAddress newIp(*this);
	if (m_bV4)
		newIp.m_v4Address += other.m_v4Address;
	else
		newIp.m_v6Address += other.m_v6Address;

	return newIp;
}


CIpAddress CIpAddress::operator -( const CIpAddress& other ) const
{
	CIpAddress newIp(*this);
	if (m_bV4)
		newIp.m_v4Address -= other.m_v4Address;
	else
		newIp.m_v6Address -= other.m_v6Address;

	return newIp;
}

CIpAddress& CIpAddress::operator +=( const CIpAddress& other )
{
	if (m_bV4)
		m_v4Address += other.m_v4Address;
	else
		m_v6Address += other.m_v6Address;

	return *this;
}

CIpAddress& CIpAddress::operator -=( const CIpAddress& other )
{
	if (m_bV4)
		m_v4Address -= other.m_v4Address;
	else
		m_v6Address -= other.m_v6Address;

	return *this;
}

unsigned int CIpAddress::getNetworkBits() const
{
	if (m_bV4)
	{
		for (int i=(TOTAL_NETWORK_BITS-1); i>=0; i--)
		{
			if ( ((m_v4Address >> i) & 0x1) == 0 )
				return ((TOTAL_NETWORK_BITS-1) - i);
		}
		return TOTAL_NETWORK_BITS;
	}
	else
	{
		for (int i=0; i<S16bytes::s_bitCount; i++)
		{
			if ( ((m_v6Address.bytes[i/8] >> (7 - i%8)) & 0x1) == 0 )
				return i;
		}
		return S16bytes::s_bitCount;
	}
}

CIpAddress CIpAddress::getFromNetworkBits(unsigned int bits) const
{
	CIpAddress ip;

	if (m_bV4)
		ip.setRawIPAddress(0xffffffff << ((bits < 32) ? (32 - bits) : 0));
	else
	{
		S16bytes s16bytes;
		memset(s16bytes.bytes, 0xFF, bits / 8);
		s16bytes.bytes[bits / 8] = 0xFF << (8 - bits % 8);
		ip.setRawIpv6Address(s16bytes);
	}

	return ip;
}

bool CIpAddress::isInNetwork(const CIpAddress& network, const CIpAddress& subnetMask) const
{
	if ((m_bV4 != network.m_bV4) || (m_bV4 != subnetMask.m_bV4))
		return false;

	if (m_bV4)
		return ( (m_v4Address & subnetMask.m_v4Address) == (network.m_v4Address & subnetMask.m_v4Address) );
	else
		return ( (m_v6Address & subnetMask.m_v6Address) == (network.m_v6Address & subnetMask.m_v6Address) );
}


bool CIpAddress::isInNetwork(const string& strNetwork, const string& strSubNet) const
{
	return isInNetwork(CIpAddress(strNetwork), CIpAddress(strSubNet));
}

CIpAddress CIpAddress::getNetworkID(const CIpAddress& mask) const
{
	return *this & mask;
}

CIpAddress CIpAddress::getNetworkBroadcast(const CIpAddress& mask) const
{
	return *this | (~mask);
}

bool CIpAddress::isPrivateAddress() const
{
	if (m_bV4)
		return ( (isInNetwork("10.0.0.0", "255.0.0.0")) ||
				(isInNetwork("172.16.0.0", "255.240.0.0")) ||
				(isInNetwork("192.168.0.0", "255.255.0.0")) );
	else
		return isLinkLocalAddress() || isSiteLocalAddress();
}

bool CIpAddress::isLoopbackAddress() const
{
	if (m_bV4)
		return (*this == ipv4LoopbackAddress());
	else
		return (*this == ipv6LoopbackAddress());
}

bool CIpAddress::isZeroAddress() const
{
	if (m_bV4)
		return (*this == zeroAddress());
	else
		return (*this == ipv6ZeroAddress());
}

bool CIpAddress::isMulticastAddress() const
{
	if (m_bV4)
	{
		unsigned char octet0 = getOctet(0);
		return ((octet0 >= 224) && (octet0 <= 239));
	}
	else
	{
		return (m_v6Address.bytes[0] == 0xFF);
	}
}

std::string CIpAddress::getId()
{
	if (m_bUsedForId)
		return Util::toString<unsigned long>(m_v4Address);
	else
		return toString();
}

void CIpAddress::setRawIPAddress(const unsigned int uiNewIPAddress)
{
	m_v4Address = uiNewIPAddress;
	m_bValid = true;
	m_bV4 = true;
}

unsigned int CIpAddress::getRawIPAddress() const
{
	return m_v4Address;
}

bool CIpAddress::isValidIpv4Address(const string& str)
{
	CIpAddress ip(str);
	return (ip.m_bV4 && ip.m_bValid);
}

bool CIpAddress::isPartialIpv4AddressValid(const string& strIPAddress)
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



bool CIpAddress::isClassDAddress ( ) const
{
	return (m_bV4 && m_bValid && ((m_v4Address & 0xe0000000) == 0xe0000000) );
}

bool CIpAddress::isClassEAddress ( ) const
{
	return (m_bV4 && m_bValid && ( (m_v4Address & 0xf0000000) == 0xf0000000) );
}

CIpAddress CIpAddress::getClassNetwork() const
{
	CIpAddress network;

	if (m_bV4 && m_bValid)
		network.setRawIPAddress(((m_v4Address & 0x80000000) == 0) ? (m_v4Address & 0xff000000)
							: ((m_v4Address & 0x40000000) == 0) ? (m_v4Address & 0xffff0000)
							:  (m_v4Address & 0xffffff00));

	return network;
}

CIpAddress CIpAddress::getClassSubnetMask() const
{
	CIpAddress mask;

	if (m_bV4 && m_bValid)
	{
		if (m_v4Address == 0)
			return CIpAddress::zeroAddress();

		mask.setRawIPAddress(((m_v4Address & 0x80000000) == 0) ? (0xff000000)
						: ((m_v4Address & 0x40000000) == 0) ? (0xffff0000)
						: (0xffffff00));
	}

	return mask;
}

bool CIpAddress::isAValidSubnetMask() const
{
	if ((!m_bV4) || (!m_bValid))
		return false;

	int i;

	for (i=(TOTAL_NETWORK_BITS-1); i>=0; i--)
		if ( ((m_v4Address >> i) & 0x1) == 0 )
			break;

	for (; i>=0; i--)
		if ( ((m_v4Address >> i) & 0x1) == 1 )
			return false;

	return true;
}

bool CIpAddress::isAValidNetwork() const
{
	if ((!m_bV4) || (!m_bValid))
		return false;

	int iFirstOctet = ((m_v4Address >> 24) & 0xff);
	return ((iFirstOctet > 0) && (iFirstOctet < 224) && (iFirstOctet != 127));
}

bool CIpAddress::isIPSubnetValid(const CIpAddress& subnetMask) const
{
	if ((!m_bV4) || (!m_bValid)
		|| (!subnetMask.m_bV4) || (!subnetMask.m_bValid))
		return false;

	CIpAddress networkID;
	int iHost;
	networkID = getNetworkID(subnetMask);

	iHost = m_v4Address - networkID.m_v4Address;
	return ( (iHost != 0) && (iHost != ((1 << (32 - subnetMask.getNetworkBits())) - 1)) );
}


string CIpAddress::getIPasHexString() const
{
	if ((!m_bV4) || (!m_bValid))
		return "";

	// hexa decimal string
    static char HEX_STRING[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

	string strIPAddress="";
	int iAddress;

	if (m_v4Address == 0)
		return strIPAddress;

	iAddress = m_v4Address;

	for (int i=0; ((i<EIGHT_BITS) && (iAddress != 0)); i++)
	{
		strIPAddress = HEX_STRING[iAddress & 0xf] + strIPAddress;
		iAddress >>= FOUR_BITS;
	}

	return strIPAddress;
}

CIpAddress CIpAddress::broadCastAddress()
{
	static CIpAddress broadCast("255.255.255.255");
	return broadCast;
}

bool CIpAddress::isBroadcastAddress( ) const
{
	static CIpAddress v6Broadcast("FFFF:FFFF:FFFF:FFFF:FFFF:FFFF:FFFF:FFFF");

	return ((m_bV4 && m_bValid && (m_v4Address == 0xffffffff))
		|| (!m_bV4 && m_bValid && (*this == v6Broadcast)));
}

CIpAddress CIpAddress::zeroAddress()
{
	static CIpAddress zeroAddr("0.0.0.0");
	return zeroAddr;
}

CIpAddress CIpAddress::ipv4LoopbackAddress()
{
	static CIpAddress loopback("127.0.0.1");
	return loopback;
}

CIpAddress CIpAddress::getIpv4FromNetworkBits(unsigned int iBits)
{
	CIpAddress newIPAddress;

	if (iBits == 0)
		newIPAddress.setRawIPAddress(0);
	else
		newIPAddress.setRawIPAddress(0xffffffff << ((iBits < 32) ? (32 - iBits) : 0));
//	newIPAddress.setRawIPAddress(0x80000000 >> ((iBits > 0) ? (iBits - 1) : 0));

	return newIPAddress;
}



void CIpAddress::setRawIpv6Address(const S16bytes ip)
{
	m_v6Address = ip;
	m_bValid = true;
	m_bV4 = false;
}

S16bytes CIpAddress::getRawIpv6Address() const
{
	return m_v6Address;
}

bool CIpAddress::isValidIpv6Address(const std::string& str)
{
	CIpAddress ip(str);
	return ((!ip.m_bV4) && ip.m_bValid);
}

bool CIpAddress::isPartialIpv6AddressValid(const std::string& str)
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

		if (ch == '.' && ((j + s_v4AddressSize) <= S16bytes::s_byteCount))
		{
			return isPartialIpv4AddressValid(str.substr(curtok));
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

// ::
CIpAddress CIpAddress::ipv6ZeroAddress()
{
	CIpAddress ip;
	ip.m_bV4 = false;
	ip.m_bValid = true;
	return ip;
}

CIpAddress CIpAddress::ipv6LoopbackAddress()
{
	static CIpAddress ip("::1");
	return ip;
}

// FEC0::/48
bool CIpAddress::isSiteLocalAddress() const
{
	if (m_bV4)
		return false;

	S16bytes zero;
	return ((m_v6Address.bytes[0] == 0xFE)
		&& (m_v6Address.bytes[1] == 0xC0)
		&& (memcmp(m_v6Address.bytes + 2, zero.bytes + 2, 4) == 0)
		);
}

CIpAddress CIpAddress::getSiteLocalAddress() const
{
	if (m_bV4)
		return CIpAddress();

	CIpAddress ip = *this;
	ip.m_v6Address.bytes[0] = 0xFE;
	ip.m_v6Address.bytes[1] = 0xC0;
	memset(ip.m_v6Address.bytes + 2, 0, 4);
	return ip;
}

// FE80::/64
bool CIpAddress::isLinkLocalAddress() const
{
	if (m_bV4)
		return false;

	S16bytes zero;
	return ((m_v6Address.bytes[0] == 0xFE)
		&& (m_v6Address.bytes[1] == 0x80)
		&& (memcmp(m_v6Address.bytes + 2, zero.bytes + 2, 6) == 0)
		);
}

CIpAddress CIpAddress::getLinkLocalAddress() const
{
	if (m_bV4)
		return CIpAddress();

	CIpAddress ip = *this;
	ip.m_v6Address.bytes[0] = 0xFE;
	ip.m_v6Address.bytes[1] = 0x80;
	memset(ip.m_v6Address.bytes + 2, 0, 6);
	return ip;
}

// ::/96 OR ::FFFF:0:0/96
bool CIpAddress::isIPv4MappedAddress() const
{
	if (m_bV4)
		return false;

	S16bytes zero;
	return ((memcmp(m_v6Address.bytes, zero.bytes, 10) == 0)
		&& (((m_v6Address.bytes[10] == 0) && (m_v6Address.bytes[11] == 0))
			|| ((m_v6Address.bytes[10] == 0xff) && (m_v6Address.bytes[11] == 0xff)))
		);
/*	return ((memcmp(m_v6Address.bytes, zero.bytes, 12) == 0)
		&& (m_v6Address.bytes[12] != 0)
		&& (m_v6Address.bytes[13] != 0)
		);*/
}

// bits 8 to 11 are 0
bool CIpAddress::isMulticastPermanent() const
{
	return ((!m_bV4) && ((m_v6Address.bytes[1] & 0xF0) == 0));
}

// return bits 12 to 15
unsigned char CIpAddress::getMulticastScope() const
{
	return (m_v6Address.bytes[1] & 0x0F);
}

// FF02:0:0:0:0:1:FF00:0000/104
bool CIpAddress::isSolicitedNodeAddress() const
{
	if (m_bV4)
		return false;

	S16bytes zero;
	return ((m_v6Address.bytes[0] == 0xFF)
		&& (m_v6Address.bytes[1] == 0x02)
		&& (memcmp(m_v6Address.bytes + 2, zero.bytes + 2, 9) == 0)
		&& (m_v6Address.bytes[11] == 0x01)
		&& (m_v6Address.bytes[12] == 0xFF)
		);
}

CIpAddress CIpAddress::getSolicitedNodeAddress() const
{
	if (m_bV4)
		return CIpAddress();

	CIpAddress ip = *this;
	ip.m_v6Address.bytes[0] = 0xFF;
	ip.m_v6Address.bytes[1] = 0x02;
	memset(ip.m_v6Address.bytes + 2, 0, 9);
	ip.m_v6Address.bytes[11] = 0x01;
	ip.m_v6Address.bytes[12] = 0xFF;
	return ip;
}

// FF02::1
CIpAddress CIpAddress::allNodesMulticastAddress()
{
	static CIpAddress address("FF02::1");
	return address;
}

// FF02::2
CIpAddress CIpAddress::allRoutersMulticastAddress()
{
	static CIpAddress address("FF02::2");
	return address;
}


CIpAddress CIpAddress::getEui64(const CMacAddress& mac)
{
	CIpAddress ip;
	memset(ip.m_v6Address.bytes, 0, 8);
	ip.m_v6Address.bytes[8] = mac.getOctet(0);
	ip.m_v6Address.bytes[9] = mac.getOctet(1) | 0x02;
	ip.m_v6Address.bytes[10] = mac.getOctet(2);
	ip.m_v6Address.bytes[11] = 0xFF;
	ip.m_v6Address.bytes[12] = 0xFE;
	ip.m_v6Address.bytes[13] = mac.getOctet(3);
	ip.m_v6Address.bytes[14] = mac.getOctet(4);
	ip.m_v6Address.bytes[15] = mac.getOctet(5);

	ip.m_bV4 = false;
	ip.m_bValid = true;
	return ip;
}

CIpAddress CIpAddress::getIpv6FromNetworkBits(unsigned int prefix)
{
	CIpAddress ip;
	memset(ip.m_v6Address.bytes, 0xFF, prefix / 8);
	ip.m_v6Address.bytes[prefix / 8] = 0xFF << (8 - prefix % 8);
	ip.m_bV4 = false;
	ip.m_bValid = true;
	return ip;
}

CIpAddress CIpAddress::invalidIpv6Address()
{
	static CIpAddress ip;
	ip.m_bV4 = false;
	return ip;
}
