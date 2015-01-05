//************************************************************************
//
// � Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************

/*! \file
	File Name:	CMacAddress.h <br>
	Author:		Vijay Tummala <br>
	Date:		02/16/05      <br>
	Revision:	1.0           <br>
	Description:	
		This file holds the mac address class declarations.
*/

#ifndef MACADDRESS_H
#define MACADDRESS_H

#include <iostream>

class CIpAddress;

/*! \class CMacAddress CMacAddress.h "include/CMacAddress.h"
    \brief This is a Mac address base class.

    This is a Mac address base class. 
*/

class CMacAddress
{
	public:
		/*! \return        none
			
			This is an empty constructor with no arguments.
        */
		CMacAddress();

		CMacAddress(const CMacAddress& mac);

		/*! \param[in]     strNewMacAddress		a string
            \return        none
			
			This is a constructor with a string as an argument.
        */
		CMacAddress( const std::string& strNewMacAddress);

		/*! \return        none

            This is a destructor.
        */
		~CMacAddress(){};

		bool isAValidAddress() const;

		/*! \param[in]     macAddress	MacAddress object
			\return        void

            This function returns a void, copies one mac to another.
        */
		void operator = (const CMacAddress& macAddress);

		/*! \param[in]     macAddress	CMacAddress object
			\return        true or false

            This function returns a boolean, true if this Mac address 
			equals to the other Mac address, false otherwise.
        */
		bool operator == (const CMacAddress& macAddress)const;

		bool operator != (const CMacAddress& macAddress)const;

		/*! \param[in]     macAddress	CMacAddress object
			\return        true or false

            This function returns a boolean, true if this Mac address 
			less than the other Mac address, false otherwise.
        */
		bool operator < (const CMacAddress& macAddress)const;

		bool operator <= (const CMacAddress& macAddress)const;

		/*! \param[in]     macAddress	CMacAddress object
			\return        true or false

            This function returns a boolean, true if this Mac address 
			greater than the other Mac address, false otherwise.
        */
		bool operator > (const CMacAddress& macAddress)const;
		bool operator >= (const CMacAddress& macAddress)const;

		/*! \return        string representing Mac Address

            This function returns a a text representation of the 
			Mac address.
        */
		std::string macToString() const;

		/*! \return        CMacAddress object

            This function returns a random Mac Address as an object.
        */
		static CMacAddress getRandomMacAddress();

		/*! \param[in]     strMacAddress		a text representation of the Mac address
			\return        true or false

            This function returns a boolean, true if the string is a valid 
			Mac address, false otherwise.
        */
		static bool isValidMacAddress(std::string& strMacAddress);

		/*! \param[in]     strMacAddress		a text representation of the partial Mac address
			\return        true or false

            This function returns a boolean, true if the string is a valid 
			parial Mac address, false otherwise.
        */
		static bool isPartialMacAddressValid(std::string& strMacAddress);

		/*! \param[in]     strMacAddress		a text representation of the Mac address
			\return        CMacAddress object

            This function converts string Mac to canonical form.
        */
		static CMacAddress toCanonicalForm(std::string& strMacAddress);

		/*! \return        string

            This function returns a string, mac address in standard 
			form "XX:XX:XX:XX:XX:XX".
        */
		std::string toStandardForm() const;

		/*! \param[in]     macAddress		Mac address object
			\return        true or false

            This function returns a boolean, false if the string is not equals 
			to "0000.0000.0000", true otherwise.
        */
		bool isCompliant() const;

		/*! \return        MacAddress object

            This function returns a broadcast mac address "FFFF.FFFF.FFFF".
        */
		static CMacAddress getBroadcastAddress();

		bool isBroadcastAddress() const;
		bool isMulticastAddress() const;

		unsigned char getOctet(unsigned int index) const;
 
		static CMacAddress getMulticast(const CIpAddress& ip);

	private:
		std::string m_strMacAddress;	/*!< m_strMacAddress as a string. */
		unsigned char m_bytes[6];

		static const int TOTAL_MAC_OCTETS=3;
		static const int MAC_OCTET_LENGTH=4;
};

#endif
