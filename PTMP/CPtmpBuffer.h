//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************

/*! /file
File Name:	CPTMPBuffer.h     <br>
Author:		Michael Wang, Ajan U.Nair <br>
Date:		10/23/07      <br>
Revision:	1.0           <br>
Description:
	This file holds the CPtmpBuffer class definitions.
*/

/*************************************************************************
Oct 22, 07   Michael   Creation, Class definition



*************************************************************************/


#ifndef PTMP_CPTMPBUFFER_H
#define PTMP_CPTMPBUFFER_H

#include <QByteArray>
#include <QString>
#include <QUuid>
#include <string>
#include <QBuffer>
#include <QDataStream>
#include <vector>
#include <map>

#include "../support/CIpAddress.h"
#include "../support/CMacAddress.h"

namespace Ipc { class CIpcData; }

namespace Ptmp
{
	enum EPtmpBufferMode
	{
		ePtmpBufferRead = 1,
		ePtmpBufferWrite = 2,
		ePtmpBufferReadWrite = 4
	};

	enum EPtmpBufferEncoding
	{
		ePtmpBufferText = 1,
		ePtmpBufferBinary = 2
	};

	enum EPtmpTypeValue
	{
		eVoid = 0,
		eByte,
		eBool,
		eShort,
		eInt,
		eLong,
		eFloat,
		eDouble,
		eString,
		eQString,
		eIpAddress,
		eIpv6Address,
		eMacAddress,
		eUuid,
		ePair,
		eVector,
		eData
	};
		
	class CPtmpBufferError : public std::exception
	{
	public:
		CPtmpBufferError(std::string str) : m_str(str) {}
		~CPtmpBufferError() throw() { }
		std::string m_str;
	};
	
	// buffer to store data received or to be sent on PTMP
	class CPtmpBuffer
	{
	public:

		CPtmpBuffer(EPtmpBufferMode mode=ePtmpBufferReadWrite, EPtmpBufferEncoding encoding=ePtmpBufferText);
		CPtmpBuffer(const CPtmpBuffer& other);
		~CPtmpBuffer();

		void operator=(const CPtmpBuffer& other);

		inline EPtmpBufferMode getMode() const { return m_mode; }
		inline EPtmpBufferEncoding getEncoding() const { return m_encoding; }

		void setEncoding(EPtmpBufferEncoding encoding);

		inline QByteArray& getRawBuffer() { return m_buffer; }
		inline unsigned int size() const { return m_buffer.size(); }
		inline void append(const QByteArray& array) { m_buffer.append(array); }
		inline void append(const CPtmpBuffer& other) { m_buffer.append(other.m_buffer); }
		inline void clear() { m_buffer.clear(); }
		inline unsigned int unreadSize() const { return m_buffer.size() - m_readIndex; }
		inline void resetReadIndex() { m_readIndex = 0; }
		inline void setReadIndex(unsigned int index) { if (index < m_buffer.size()) m_readIndex = index; }
		inline unsigned int getReadIndex() const { return m_readIndex; }

		inline void flushRead()
		{
			m_buffer.remove(0, m_readIndex);
			m_readIndex = 0;
		}

		CPtmpBuffer extract(unsigned int size);

		char readByte(bool bAdvanceIndex = true);
		bool readBool(bool bAdvanceIndex = true);
		short readShort(bool bAdvanceIndex = true);
		int readInt(bool bAdvanceIndex = true);
		long long readLong(bool bAdvanceIndex = true);
		float readFloat(bool bAdvanceIndex = true);
		double readDouble(bool bAdvanceIndex = true);
		std::string readString(bool bAdvanceIndex = true);
		QString readQString(bool bAdvanceIndex = true);
		CIpAddress readIpAddress(bool bAdvanceIndex = true);
		CIpAddress readIpv6Address(bool bAdvanceIndex = true);
		CMacAddress readMacAddress(bool bAdvanceIndex = true);
		QUuid readUuid(bool bAdvanceIndex = true);
		int readData(char* data, int length, bool bAdvanceIndex = true);
		//template<> readArray(bool bAdvanceIndex = true);
/*		template<typename T1, typename T2> std::pair<T1, T2> readPair()
		{
			std::pair<T1, T2> val;
			val.first = read<T1>();
			val.second = read<T2>();
			return val;
		}
*/

		inline char peekByte() { return readByte(false); }
		inline bool peekBool() { return readBool(false); }
		inline short peekShort() { return readShort(false); }
		inline int peekInt() { return readInt(false); }
		inline long long peekLong() { return readLong(false); }
		inline float peekFloat() { return readFloat(false); }
		inline double peekDouble() { return readDouble(false); }
		inline std::string peekString() { return readString(false); }
		inline QString peekQString() { return readQString(false); }
		inline CIpAddress peekIpAddress() { return readIpAddress(false); }
		inline CIpAddress peekIpv6Address() { return readIpv6Address(false); }
		inline CMacAddress peekMacAddress() { return readMacAddress(false); }
		inline QUuid peekUuid() { return readUuid(false); }
		inline int peekData(char* data, int length) { return readData(data, length, false); }

		void write(char val);
		inline void write(unsigned char val) { write(static_cast<char>(val)); }
		void write(bool val);
		void write(short val);
		inline void write(unsigned short val) { write(static_cast<short>(val)); }
		void write(int val);
		inline void write(unsigned int val) { write(static_cast<int>(val)); }
		void write(long long val);
		inline void write(unsigned long long val) { write(static_cast<long long>(val)); }
		void write(float val);
		void write(double val);
		void write(const std::string& val);
		void write(const QString& val);
		void write(const CIpAddress& val);
		void write(const CMacAddress& val);
		void write(const QUuid& val);
		void write(const char* val, int length);
		void write(const Ipc::CIpcData* val);
		void write(const Ipc::CIpcData& val);
//		template<typename T1, typename T2> void write(const std::pair<T1, T2>& val);
//		template<typename T> void write(const std::vector<T>& val);
//		template<typename T1, typename T2> void write(const std::map<T1, T2>& val);

		template<typename T> inline	void writeWithType(const T& val)
		{
			writeTypeOfValue<T>(val);
			write(val);
		}

		inline void writeTypeValue(EPtmpTypeValue type) { write(static_cast<char>(type)); }
		template<typename T> void writeType();
		template<typename T> void writeTypeOfValue(const T& val);

		void writeSizeToFront();

	private:

		QByteArray m_buffer;
		QBuffer* m_qbuffer;
		QDataStream* m_dataStream;
		EPtmpBufferMode m_mode;
		EPtmpBufferEncoding m_encoding;
		unsigned int m_readIndex;
	};
/*
	template<typename T1, typename T2> void CPtmpBuffer::write(const std::pair<T1, T2>& val)
	{
		write(val.first);
		write(val.second);
	}

	template<typename T> void CPtmpBuffer::write(const std::vector<T>& val)
	{
		write(val.size());
		for (std::vector<T>::iterator itr = val.begin();
			itr != val.end(); itr++)
		{
			write(*itr);
		}
	}

	// write it out like a vector
	template<typename T1, typename T2> void CPtmpBuffer::write(const std::map<T1, T2>& val)
	{
		write(val.size());
		for (std::map<T1, T2>::const_iterator itr = val.begin();
			itr != val.end(); itr++)
		{
			write(itr->second);
		}
	}
*/

	template<typename T> inline void CPtmpBuffer::writeType() { writeTypeValue(eData); }
	template<> inline void CPtmpBuffer::writeType<char>() { writeTypeValue(eByte); }
	template<> inline void CPtmpBuffer::writeType<unsigned char>() { writeTypeValue(eByte); }
	template<> inline void CPtmpBuffer::writeType<bool>() { writeTypeValue(eBool); }
	template<> inline void CPtmpBuffer::writeType<short>() { writeTypeValue(eShort); }
	template<> inline void CPtmpBuffer::writeType<unsigned short>() { writeTypeValue(eShort); }
	template<> inline void CPtmpBuffer::writeType<int>() { writeTypeValue(eInt); }
	template<> inline void CPtmpBuffer::writeType<unsigned int>() { writeTypeValue(eInt); }
	template<> inline void CPtmpBuffer::writeType<long long>() { writeTypeValue(eLong); }
	template<> inline void CPtmpBuffer::writeType<unsigned long long>() { writeTypeValue(eLong); }
	template<> inline void CPtmpBuffer::writeType<float>() { writeTypeValue(eFloat); }
	template<> inline void CPtmpBuffer::writeType<double>() { writeTypeValue(eDouble); }
	template<> inline void CPtmpBuffer::writeType<std::string>() { writeTypeValue(eString); }
	template<> inline void CPtmpBuffer::writeType<QString>() { writeTypeValue(eQString); }
	template<> inline void CPtmpBuffer::writeType<CIpAddress>() { writeTypeValue(eIpAddress); }
	template<> inline void CPtmpBuffer::writeType<CMacAddress>() { writeTypeValue(eMacAddress); }
	template<> inline void CPtmpBuffer::writeType<QUuid>() { writeTypeValue(eUuid); }

	template<typename T> inline void CPtmpBuffer::writeTypeOfValue(const T&) { writeTypeValue(eData); }
	template<> inline void CPtmpBuffer::writeTypeOfValue<char>(const char&) { writeTypeValue(eByte); }
	template<> inline void CPtmpBuffer::writeTypeOfValue<unsigned char>(const unsigned char&) { writeTypeValue(eByte); }
	template<> inline void CPtmpBuffer::writeTypeOfValue<bool>(const bool&) { writeTypeValue(eBool); }
	template<> inline void CPtmpBuffer::writeTypeOfValue<short>(const short&) { writeTypeValue(eShort); }
	template<> inline void CPtmpBuffer::writeTypeOfValue<unsigned short>(const unsigned short&) { writeTypeValue(eShort); }
	template<> inline void CPtmpBuffer::writeTypeOfValue<int>(const int&) { writeTypeValue(eInt); }
	template<> inline void CPtmpBuffer::writeTypeOfValue<unsigned int>(const unsigned int&) { writeTypeValue(eInt); }
	template<> inline void CPtmpBuffer::writeTypeOfValue<long long>(const long long&) { writeTypeValue(eLong); }
	template<> inline void CPtmpBuffer::writeTypeOfValue<unsigned long long>(const unsigned long long&) { writeTypeValue(eLong); }
	template<> inline void CPtmpBuffer::writeTypeOfValue<float>(const float&) { writeTypeValue(eFloat); }
	template<> inline void CPtmpBuffer::writeTypeOfValue<double>(const double&) { writeTypeValue(eDouble); }
	template<> inline void CPtmpBuffer::writeTypeOfValue<std::string>(const std::string&) { writeTypeValue(eString); }
	template<> inline void CPtmpBuffer::writeTypeOfValue<QString>(const QString&) { writeTypeValue(eQString); }
	template<> inline void CPtmpBuffer::writeTypeOfValue<CIpAddress>(const CIpAddress& ip) { writeTypeValue(ip.isIpv4() ? eIpAddress : eIpv6Address); }
	template<> inline void CPtmpBuffer::writeTypeOfValue<CMacAddress>(const CMacAddress&) { writeTypeValue(eMacAddress); }
	template<> inline void CPtmpBuffer::writeTypeOfValue<QUuid>(const QUuid&) { writeTypeValue(eUuid); }

}
#endif
