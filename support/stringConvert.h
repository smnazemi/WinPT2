//************************************************************************
//
//  � Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************

/*! \file       stringConvert.h
    \brief	    This file declares and defines the string convert functions.
    \author	    Michael Wang
    \version	1.0
    \date	    4/8/2005

	This file declares and defines the string convert functions.
*/

#ifndef UTIL_STRINGCONVERT_H_
#define UTIL_STRINGCONVERT_H_

//#include "engine.h"
#include <string>
#include <iostream>
#include <sstream>
#include <typeinfo>
#include <stdexcept>
#include <vector>

/*! \namespace	Util
    \brief		Contains utility functions.

	The Util namespace contains commonly used utility functions.
*/
namespace Util
{
	/*! \class CInvalidConversion
		\brief Invalid conversion error from and to strings.

		This class is a runtime error that occurs if a string cannot be converted
		to the specified type or the specified type cannot be converted to
		a string.
	*/
	class CInvalidConversion : public std::runtime_error
	{
	public:
		CInvalidConversion(const std::string& str) : std::runtime_error(str) {}
	};

	/*! \param[in]	value	a value to be converted to string
		\return		a string representation of the value
		\exception	CInvalidConversion	if the value cannot be converted to string

		This function converts a value of any type to a string using the ostringstream.
		If the type cannot be called in "std::cout << value", then an exception
		would be thrown.
	*/
	template<typename T>
	std::string toString(const T& value);

	/*! \param[in]	str		a string to be converted to the specified type
		\return		the value of the string in the specified type
		\exception	CInvalidConversion	if the string cannot be converted to the specified type

		This function converts a string to the specified type using the istringstream.
		If the string cannot be called in "std::cin >> value", then an exception
		would be thrown.
	*/
	template<typename T>
	T fromString(const std::string& str, bool failIfLeftOverChars = true);

	template<typename T>
	T fromStringToUnsigned(const std::string& str, bool failIfLeftOverChars = true);

	template<typename T>
	bool isStringA(const std::string& str);

	template<typename T>
	std::string toString(const T& value)
	{
		std::ostringstream out;
		if (!(out << value))
			throw CInvalidConversion(std::string("toString(") + typeid(T).name() + ")");
		return out.str();
	}

	template<typename T>
	T fromString(const std::string& str, bool failIfLeftOverChars)
	{
		T value;
		std::istringstream in(str);
		char chr;
		
		// if value cannot be converted to type T
		// OR there are left over characters
		// OR type T is of type unsigned and the first char is not a digit
		if (!(in >> value) || (failIfLeftOverChars && in.get(chr)))
	//		|| ((std::string(typeid(T).name()).substr(0, 9) == "unsigned ") && (!isdigit(str[0]))))
			throw CInvalidConversion(std::string("fromString<") + typeid(T).name() + ">(" + str + ")");
		return value;
	}

	template<typename T>
	T fromStringToUnsigned(const std::string& str, bool failIfLeftOverChars)
	{
		T value;
		std::istringstream in(str);
		char chr;
		
		// if value cannot be converted to type T
		// OR there are left over characters
		// OR the first char is not a digit
		if (!(in >> value) || (failIfLeftOverChars && in.get(chr))
			|| (!isdigit(str[0])))
			throw CInvalidConversion(std::string("fromString<") + typeid(T).name() + ">(" + str + ")");
		return value;
	}

	template<> inline unsigned short fromString(const std::string& str, bool failIfLeftOverChars)
	{
		return fromStringToUnsigned<unsigned short>(str, failIfLeftOverChars);
	}

	template<> inline unsigned int fromString(const std::string& str, bool failIfLeftOverChars)
	{
		return Util::fromStringToUnsigned<unsigned int>(str, failIfLeftOverChars);
	}

	template<> inline unsigned long fromString(const std::string& str, bool failIfLeftOverChars)
	{
		return fromStringToUnsigned<unsigned long>(str, failIfLeftOverChars);
	}

	template<> inline unsigned long long fromString(const std::string& str, bool failIfLeftOverChars)
	{
		return fromStringToUnsigned<unsigned long long>(str, failIfLeftOverChars);
	}

	template<typename T>
	bool isStringA(const std::string& str)
	{
		bool is;
		try
		{
			fromString<T>(str);
			is = true;
		}
		catch (CInvalidConversion )
		{
			is = false;
		}

		return is;
	}
}

#endif
