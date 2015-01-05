//************************************************************************
//
// � Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************

/*! /file
	File Name:	CIpAddress.h  <br>
	Author:		Michael Wang <br>
	Date:		12/3/2007      <br>
	Revision:	2.0           <br>
	Description:	
		This file holds the IPv4 and IPv6 address class declarations.

	File Name:	CIpAddress.h  <br>
	Author:		Vijay Tummala <br>
	Date:		02/11/05      <br>
	Revision:	1.0           <br>
	Description:	
*/
#ifndef IPADDRESS_H
#define IPADDRESS_H

#include <string>

class CMacAddress;

struct S16bytes
{
	static const unsigned int s_byteCount = 16;
	static const unsigned int s_bitCount = 128;

	unsigned char bytes[s_byteCount];

	S16bytes();

	S16bytes operator &( const S16bytes& other ) const;
	S16bytes operator |( const S16bytes& other ) const;
	S16bytes operator ~() const;

	bool operator >( const S16bytes& other ) const;
	bool operator >=( const S16bytes& other ) const;
	bool operator <( const S16bytes& other ) const;
	bool operator <=( const S16bytes& other ) const;
	bool operator ==( const S16bytes& other ) const;
	bool operator !=( const S16bytes& other ) const;

	S16bytes operator +( unsigned int other ) const;
	S16bytes operator -( unsigned int other ) const;
	S16bytes& operator +=( unsigned int other );
	S16bytes& operator -=( unsigned int other );

	S16bytes operator +( const S16bytes& other ) const;
	S16bytes operator -( const S16bytes& other ) const;
	S16bytes& operator +=( const S16bytes& other );
	S16bytes& operator -=( const S16bytes& other );

};

/*! \class CIpAddress CIpAddress.h "include/CIpAddress.h"
    \brief This is an ip address base class.

    This is an ip address base class. 
*/

class CIpAddress
{
	public:

		// IPv6 address type
		enum EIpv6AddressType
		{
			eUnicast,
			eAnycast,
			eEui64,
			eNdAssigned,
			eDhcpAssigned,
			ePrefixAssigned
		};

		CIpAddress();
		CIpAddress( const std::string& strIPAddress );
		CIpAddress( const CIpAddress& ip);
		~CIpAddress(){};

		//******** IPv4 and IPv6 common functions
		inline bool isIpv4() const { return m_bV4; }

		inline bool isAValidAddress() const { return m_bValid; }
		inline bool isValid() const { return m_bValid; }
		inline bool isValidIpv4() const { return (m_bV4 && m_bValid); }
		inline bool isValidIpv6() const { return ((!m_bV4) && m_bValid); }

		std::string iPtoString() const;
		inline std::string toString() const { return iPtoString(); }

		CIpAddress* clone() const;

		unsigned char getOctet( unsigned int index ) const;

		CIpAddress operator &( const CIpAddress& ipAddress ) const;
		CIpAddress operator |( const CIpAddress& ipAddress ) const;
		CIpAddress operator ~() const;
		void operator =( const CIpAddress& ipAddress );
		bool operator >( const CIpAddress& ipAddress )const;
		bool operator >=( const CIpAddress& ipAddress )const;
		bool operator <( const CIpAddress& ipAddress )const;
		bool operator <=( const CIpAddress& ipAddress )const;
		bool operator ==( const CIpAddress & ipAddress )const;
		bool operator !=( const CIpAddress & ipAddress )const;

		CIpAddress operator +( unsigned int other ) const;
		CIpAddress operator -( unsigned int other ) const;
		CIpAddress& operator +=( unsigned int other );
		CIpAddress& operator -=( unsigned int other );

		CIpAddress operator +( const CIpAddress& other ) const;
		CIpAddress operator -( const CIpAddress& other ) const;
		CIpAddress& operator +=( const CIpAddress& other );
		CIpAddress& operator -=( const CIpAddress& other );

		unsigned int getNetworkBits() const;
		CIpAddress getFromNetworkBits( unsigned int bits ) const;

		bool isInNetwork( const CIpAddress& network, const CIpAddress& subnetMask ) const;
		inline bool isInNetwork( const CIpAddress& network, unsigned int networkBits ) const
		{ return isInNetwork(network, getFromNetworkBits(networkBits)); }

		bool isInNetwork( const std::string& network, const std::string& subnetMask ) const;

		CIpAddress getNetworkID( const CIpAddress& subnetMask ) const;
		inline CIpAddress getNetworkID( unsigned int networkBits ) const
		{ return getNetworkID(getFromNetworkBits(networkBits)); }

		CIpAddress getNetworkBroadcast( const CIpAddress& subnetMask ) const;
		inline CIpAddress getNetworkBroadcast( unsigned int networkBits ) const
		{ return getNetworkBroadcast(getFromNetworkBits(networkBits)); }

		bool isPrivateAddress() const;
		bool isLoopbackAddress() const;
		bool isZeroAddress() const;

		// 224 to 239 or FF00::/8
		bool isMulticastAddress() const;

		void setUsedForId(bool forId) { m_bUsedForId = forId; }
		bool getUsedForId() const { return m_bUsedForId; }
		std::string getId();		

		//******** IPv4 specific functions
		void setRawIPAddress( const unsigned int ip );
		unsigned int getRawIPAddress() const;

		static bool isValidIpv4Address( const std::string& ip );
		static bool isPartialIpv4AddressValid( const std::string& strIPAddress );

		bool isClassDAddress() const;
		bool isClassEAddress() const;

		CIpAddress getClassNetwork() const;
		CIpAddress getClassSubnetMask() const;

		bool isAValidSubnetMask() const;
		bool isAValidNetwork() const;

		bool isIPSubnetValid( const CIpAddress& subnetMask ) const;

		std::string getIPasHexString() const;

		static CIpAddress broadCastAddress();
		bool isBroadcastAddress() const;

		static CIpAddress zeroAddress();
		static CIpAddress ipv4LoopbackAddress();

		static CIpAddress getIpv4FromNetworkBits( unsigned int bits );

		inline static CIpAddress invalidIpv4Address() { return CIpAddress(); }

		//******** IPv6 specific functions
		void setRawIpv6Address( const S16bytes bytes );
		S16bytes getRawIpv6Address() const;

		static bool isValidIpv6Address(const std::string& str);
		static bool isPartialIpv6AddressValid(const std::string& str);

		static CIpAddress ipv6ZeroAddress();
		static CIpAddress ipv6LoopbackAddress();

		// FEC0::/48
		bool isSiteLocalAddress() const;
		CIpAddress getSiteLocalAddress() const;

		// FE80::/64
		bool isLinkLocalAddress() const;
		CIpAddress getLinkLocalAddress() const;

		// ::/96
		bool isIPv4MappedAddress() const;

		// bits 8 to 11 are 0
		bool isMulticastPermanent() const;

		// return bits 12 to 15
		unsigned char getMulticastScope() const;

		// FF02:0:0:0:0:1:FF00:0000/104
		bool isSolicitedNodeAddress() const;
		CIpAddress getSolicitedNodeAddress() const;

		// FF02::1
		static CIpAddress allNodesMulticastAddress();

		// FF02::2
		static CIpAddress allRoutersMulticastAddress();

		static CIpAddress getEui64(const CMacAddress& mac);

		static CIpAddress getIpv6FromNetworkBits( unsigned int bits );
		inline static CIpAddress getIpv6FromPrefix( unsigned int bits ) { return getIpv6FromNetworkBits(bits); }

		static CIpAddress invalidIpv6Address();

		static const unsigned int s_v4AddressSize;
		static const unsigned int s_v6AddressSize;

	private:

		unsigned int m_v4Address;	/*!< m_uiAddress as an unsigned interger. */
		S16bytes m_v6Address;
		bool m_bV4;
		bool m_bValid;				/*!< m_bValid is a boolean value. */
		bool m_bUsedForId;			/*!< m_bUsedForId indicates whether the Address is used for ID */

		static const int TOTAL_IP_OCTETS=4;
		static const int FOUR_BITS=4;
		static const int EIGHT_BITS=8;
		static const int SIXTEEN_BITS=16;
		static const int TWENTYFOUR_BITS=24;
		static const int TOTAL_NETWORK_BITS=32;
		static const int MAX_OCTET_VALUE=255;
};

typedef CIpAddress CIpv6Address;

#endif
