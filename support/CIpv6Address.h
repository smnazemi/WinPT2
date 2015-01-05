//************************************************************************
//
// � Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is
//  prohibited unless authorized in writing.
//
//************************************************************************

/*! /file
	File Name:	CIpv6Address.h  <br>
	Author:		Michael Wang <br>
	Date:		10/11/2007      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the IPv6 address class declarations.
*/

/*****************************************************************************
******************************************************************************
THIS FILE IS NOT USE ANYMORE.
CIpv6Address is a typedef of CIpAddress.
******************************************************************************
*****************************************************************************/

#include "CIpAddress.h"

#if 0

#ifndef CIPV6ADDRESS_H
#define CIPV6ADDRESS_H

#include <string>
#include "CIpAddress.h"
#include "CMacAddress.h"

struct S16bytes
{
	static const unsigned int s_byteCount = 16;

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
};



/*! \class CIpv6Address CIpv6Address.h
    \brief This is an IPv6 address base class.

    This is an IPv6 address base class.
*/

class CIpv6Address : public CIpAddress
{
	public:

		enum EIpv6AddressType
		{
			eUnicast,
			eAnycast,
			eEui64
		};

		/*! \return        none

			This is an empty constructor with no arguments.
        */
		CIpv6Address();

		/*! \param[in]     newIPAddress		a string
            \return        none

			This is a constructor with a string as an argument.
        */
		CIpv6Address( const std::string& strIPAddress );

		CIpv6Address( const CIpv6Address& ip );
		CIpv6Address( const CIpAddress& ip );

		void setRawAddress( const S16bytes bytes );
		S16bytes getRawAddress() const;

		virtual std::string iPtoString() const;

		static bool isValidAddress(const std::string& str);
		static bool isPartialAddressValid(const std::string& str);

		// FEC0::/48
		bool isSiteLocalAddress() const;
		CIpv6Address getSiteLocalAddress() const;

		// FE80::/64
		bool isLinkLocalAddress() const;
		CIpv6Address getLinkLocalAddress() const;

		// ::/96
		bool isIPv4Address() const;

		// FF00::/8
		bool isMulticastAddress() const;

		// bits 8 to 11 are 0
		bool isMulticastPermanent() const;

		// return bits 12 to 15
		unsigned char getMulticastScope() const;

		// FF02:0:0:0:0:1:FF00:0000/104
		bool isSolicitedNodeAddress() const;
		CIpv6Address getSolicitedNodeAddress() const;

		// FF02::1
		static CIpv6Address allNodesMulticastAddress();

		// FF02::2
		static CIpv6Address allRoutersMulticastAddress();

		static CIpv6Address zeroAddress();
		bool isZeroAddress() const;

		bool isInNetwork( const CIpv6Address& network, const CIpv6Address& mask ) const;
		inline bool isInNetwork( const CIpv6Address& network, unsigned int prefix ) const
		{ return isInNetwork(network, getFromPrefix(prefix)); }

		CIpv6Address getNetworkID(const CIpv6Address& mask) const;
		inline CIpv6Address getNetworkID(unsigned int prefix) const
		{ return getNetworkID(getFromPrefix(prefix)); }

		CIpv6Address getNetworkBroadcast(const CIpv6Address& mask) const;
		inline CIpv6Address getNetworkBroadcast(unsigned int prefix) const
		{ return getNetworkBroadcast(getFromPrefix(prefix)); }

		static CIpv6Address getFromPrefix( unsigned int prefix );
		inline static CIpv6Address getFromNetworkBits( unsigned int prefix )
		{ return getFromPrefix(prefix); }

		unsigned int getNetworkBits() const;
		inline unsigned int getPrefixBits() const { return getNetworkBits(); }

		static CIpv6Address getEui64(const CMacAddress& mac);

		CIpv6Address operator &( const CIpv6Address& ip ) const;
		CIpv6Address operator |( const CIpv6Address& ip ) const;
		CIpv6Address operator ~() const;

		bool operator >( const CIpv6Address& ip ) const;
		bool operator >=( const CIpv6Address& ip ) const;
		bool operator <( const CIpv6Address& ip ) const;
		bool operator <=( const CIpv6Address& ip ) const;
		bool operator ==( const CIpv6Address & ip ) const;
		bool operator !=( const CIpv6Address & ip ) const;
		void operator =( const CIpv6Address & ip );
		void operator =( const CIpAddress & ip );

		virtual CIpAddress* clone() const;

		inline virtual bool isIpv4() const { return false; }

		virtual unsigned char getOctet( unsigned int index ) const;

#if 0
		/*! \return        true or false

            This function returns boolean, true if this IP address is
			a private address, false otherwise.
        */
		bool isPrivateAddress() const;

		/*! \return        true or false

            This function returns a boolean, true this IP address
			is a valid subnet mask, false otherwise.
        */
		bool isAValidSubnetMask() const;

		/*! \return        true or false

            This function returns a boolean, true if this IP address
			is in a valid network, false otherwise.
        */
		bool isAValidNetwork() const;

		/*! \param[in]     subnetMask        subnet mask object
			\return        true or false

            This function returns a boolean, true if this IP address is a
			valid IP address with the specified subnet mask, false otherwise.
        */
		bool isIPSubnetValid( const CIpAddress& subnetMask ) const;

#endif

		static const unsigned int s_addressSize;

	private:

		S16bytes m_address;		/*!< m_address as 128 bits. */
//		bool m_bValid;				/*!< m_bValid is a boolean value. */

};

#endif
#endif
