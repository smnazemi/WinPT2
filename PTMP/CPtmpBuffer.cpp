//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************

#include "CPtmpBuffer.h"
#include <QtCore/QtEndian>
#include "../support/stringUtil.h"
#include "../IPC/CIpcData.h"

using namespace Ptmp;
using namespace std;

CPtmpBuffer::CPtmpBuffer(EPtmpBufferMode mode, EPtmpBufferEncoding encoding)
{
	m_mode = mode;
	m_encoding = encoding;
	m_readIndex = 0;
	m_qbuffer = new QBuffer(&m_buffer);
	m_qbuffer->open(QBuffer::ReadWrite);
	m_dataStream = new QDataStream(m_qbuffer);
}

CPtmpBuffer::CPtmpBuffer(const CPtmpBuffer& other)
{
	m_mode = other.m_mode;
	m_encoding = other.m_encoding;
	m_readIndex = 0;
	m_buffer = other.m_buffer;
	m_qbuffer = new QBuffer(&m_buffer);
	m_qbuffer->open(QBuffer::ReadWrite);
	m_dataStream = new QDataStream(m_qbuffer);
}

CPtmpBuffer::~CPtmpBuffer()
{
	m_qbuffer->close();
	delete m_dataStream;
	delete m_qbuffer;
}

void CPtmpBuffer::operator=(const CPtmpBuffer& other)
{
	m_mode = other.m_mode;
	m_encoding = other.m_encoding;
	m_readIndex = 0;
	m_buffer = other.m_buffer;
	m_qbuffer = new QBuffer(&m_buffer);
	m_qbuffer->open(QBuffer::ReadWrite);
	m_dataStream = new QDataStream(m_qbuffer);
}

void CPtmpBuffer::setEncoding(EPtmpBufferEncoding encoding)
{
	if (m_encoding == encoding)
		return;

	//TODO: flush? or clear buffer?

	m_encoding = encoding;
}

CPtmpBuffer CPtmpBuffer::extract(unsigned int size)
{
	CPtmpBuffer newBuffer(m_mode, m_encoding);
	newBuffer.m_buffer = m_buffer.left(size);
	m_buffer.remove(0, size);
	m_readIndex = 0;
	return newBuffer;
}

char CPtmpBuffer::readByte(bool bAdvanceIndex)
{
	char val;

	if (m_encoding == ePtmpBufferText)
	{
		int delimiterIndex = m_buffer.indexOf('\0', m_readIndex);
		if (delimiterIndex < 0)
			throw CPtmpBufferError("error reading byte");

		bool ok;
		val = m_buffer.mid(m_readIndex, delimiterIndex - m_readIndex).toInt(&ok);
		if ((!ok) || (val < SCHAR_MIN) || (val > SCHAR_MAX))
			throw CPtmpBufferError("error reading byte");

		if (bAdvanceIndex)
			m_readIndex = delimiterIndex + 1;
	}
	else if (m_encoding == ePtmpBufferBinary)
	{
		if ((m_readIndex + 1) > m_buffer.size())
			throw CPtmpBufferError("error reading byte");

		val = m_buffer[m_readIndex];

		if (bAdvanceIndex)
			m_readIndex += 1;
	}
	else
		throw CPtmpBufferError("read encoding error");

	return val;
}


bool CPtmpBuffer::readBool(bool bAdvanceIndex)
{
	bool val;

	if (m_encoding == ePtmpBufferText)
	{
		int delimiterIndex = m_buffer.indexOf('\0', m_readIndex);
		if (delimiterIndex < 0)
			throw CPtmpBufferError("error reading bool");

		QByteArray valStr = m_buffer.mid(m_readIndex, delimiterIndex - m_readIndex);
		if (valStr == "true")
			val = true;
		else if (valStr == "false")
			val = false;
		else
			throw CPtmpBufferError("error reading bool");

		if (bAdvanceIndex)
			m_readIndex = delimiterIndex + 1;
	}
	else if (m_encoding == ePtmpBufferBinary)
	{
		if ((m_readIndex + 1) > m_buffer.size())
			throw CPtmpBufferError("error reading bool");

		val = (m_buffer.at(m_readIndex) > 0);

		if (bAdvanceIndex)
			m_readIndex += 1;
	}
	else
		throw CPtmpBufferError("read encoding error");

	return val;
}



short CPtmpBuffer::readShort(bool bAdvanceIndex)
{
	short val;

	if (m_encoding == ePtmpBufferText)
	{
		int delimiterIndex = m_buffer.indexOf('\0', m_readIndex);
		if (delimiterIndex < 0)
			throw CPtmpBufferError("error reading short");

		bool ok;
		val = m_buffer.mid(m_readIndex, delimiterIndex - m_readIndex).toShort(&ok);
		if (!ok)
			throw CPtmpBufferError("error reading short");

		if (bAdvanceIndex)
			m_readIndex = delimiterIndex + 1;
	}
	else if (m_encoding == ePtmpBufferBinary)
	{
		if ((m_readIndex + 2) > m_buffer.size())
			throw CPtmpBufferError("error reading short");

		m_qbuffer->seek(m_readIndex);
		(*m_dataStream) >> val;

		if (bAdvanceIndex)
			m_readIndex += 2;
	}
	else
		throw CPtmpBufferError("read encoding error");

	return val;
}


		
int CPtmpBuffer::readInt(bool bAdvanceIndex)
{
	int val;

	if (m_encoding == ePtmpBufferText)
	{
		int delimiterIndex = m_buffer.indexOf('\0', m_readIndex);
		if (delimiterIndex < 0)
			throw CPtmpBufferError("error reading int");

		bool ok;
		val = m_buffer.mid(m_readIndex, delimiterIndex - m_readIndex).toInt(&ok);
		if (!ok)
			throw CPtmpBufferError("error reading int");

		if (bAdvanceIndex)
			m_readIndex = delimiterIndex + 1;
	}
	else if (m_encoding == ePtmpBufferBinary)
	{
		if ((m_readIndex + 4) > m_buffer.size())
			throw CPtmpBufferError("error reading int");

		m_qbuffer->seek(m_readIndex);
		(*m_dataStream) >> val;

		if (bAdvanceIndex)
			m_readIndex += 4;
	}
	else
		throw CPtmpBufferError("read encoding error");

	return val;
}



long long CPtmpBuffer::readLong(bool bAdvanceIndex)
{
	long long val;

	if (m_encoding == ePtmpBufferText)
	{
		int delimiterIndex = m_buffer.indexOf('\0', m_readIndex);
		if (delimiterIndex < 0)
			throw CPtmpBufferError("error reading long");

		bool ok;
		val = m_buffer.mid(m_readIndex, delimiterIndex - m_readIndex).toLongLong(&ok);
		if (!ok)
			throw CPtmpBufferError("error reading long");

		if (bAdvanceIndex)
			m_readIndex = delimiterIndex + 1;
	}
	else if (m_encoding == ePtmpBufferBinary)
	{
		if ((m_readIndex + 8) > m_buffer.size())
			throw CPtmpBufferError("error reading long");

		m_qbuffer->seek(m_readIndex);
		(*m_dataStream) >> val;

		if (bAdvanceIndex)
			m_readIndex += 8;
	}
	else
		throw CPtmpBufferError("read encoding error");

	return val;
}



float CPtmpBuffer::readFloat(bool bAdvanceIndex)
{
	float val;

	if (m_encoding == ePtmpBufferText)
	{
		int delimiterIndex = m_buffer.indexOf('\0', m_readIndex);
		if (delimiterIndex < 0)
			throw CPtmpBufferError("error reading float");

		bool ok;
		val = m_buffer.mid(m_readIndex, delimiterIndex - m_readIndex).toFloat(&ok);
		if (!ok)
			throw CPtmpBufferError("error reading float");

		if (bAdvanceIndex)
			m_readIndex = delimiterIndex + 1;
	}
	else if (m_encoding == ePtmpBufferBinary)
	{
		if ((m_readIndex + 4) > m_buffer.size())
			throw CPtmpBufferError("error reading float");

		m_qbuffer->seek(m_readIndex);
		(*m_dataStream) >> val;

		if (bAdvanceIndex)
			m_readIndex += 4;
	}
	else
		throw CPtmpBufferError("read encoding error");

	return val;
}



double CPtmpBuffer::readDouble(bool bAdvanceIndex)
{
	double val;

	if (m_encoding == ePtmpBufferText)
	{
		int delimiterIndex = m_buffer.indexOf('\0', m_readIndex);
		if (delimiterIndex < 0)
			throw CPtmpBufferError("error reading double");

		bool ok;
		val = m_buffer.mid(m_readIndex, delimiterIndex - m_readIndex).toDouble(&ok);
		if (!ok)
			throw CPtmpBufferError("error reading double");

		if (bAdvanceIndex)
			m_readIndex = delimiterIndex + 1;
	}
	else if (m_encoding == ePtmpBufferBinary)
	{
		if ((m_readIndex + 8) > m_buffer.size())
			throw CPtmpBufferError("error reading double");

		m_qbuffer->seek(m_readIndex);
		(*m_dataStream) >> val;

		if (bAdvanceIndex)
			m_readIndex += 8;
	}
	else
		throw CPtmpBufferError("read encoding error");

	return val;
}

string CPtmpBuffer::readString(bool bAdvanceIndex)
{
	string val;
	
	if ((m_encoding == ePtmpBufferText) || (m_encoding == ePtmpBufferBinary))
	{
		int delimiterIndex = m_buffer.indexOf('\0', m_readIndex);
		if (delimiterIndex < 0)
			throw CPtmpBufferError("error reading string");

		val = m_buffer.mid(m_readIndex, delimiterIndex - m_readIndex).data();

		if (bAdvanceIndex)
			m_readIndex = delimiterIndex + 1;
	}
	else
		throw CPtmpBufferError("read encoding error");

	return val;
}

QString CPtmpBuffer::readQString(bool bAdvanceIndex)
{
	QString val;
	
	if ((m_encoding == ePtmpBufferText) || (m_encoding == ePtmpBufferBinary))
	{
		int delimiterIndex = m_buffer.indexOf('\0', m_readIndex);
		if (delimiterIndex < 0)
			throw CPtmpBufferError("error reading qstring");

		val = m_buffer.mid(m_readIndex, delimiterIndex - m_readIndex);

		if (bAdvanceIndex)
			m_readIndex = delimiterIndex + 1;
	}
	else
		throw CPtmpBufferError("read encoding error");

	return val;
}

CIpAddress CPtmpBuffer::readIpAddress(bool bAdvanceIndex)
{
	CIpAddress val;
	
	if (m_encoding == ePtmpBufferText)
	{
		int delimiterIndex = m_buffer.indexOf('\0', m_readIndex);
		if (delimiterIndex < 0)
			throw CPtmpBufferError("error reading ip address");

		val = CIpAddress(m_buffer.mid(m_readIndex, delimiterIndex - m_readIndex).data());

		if (!val.isAValidAddress())
			throw CPtmpBufferError("error reading ip address");

		if (bAdvanceIndex)
			m_readIndex = delimiterIndex + 1;
	}
	else if (m_encoding == ePtmpBufferBinary)
	{
		if ((m_readIndex + 4) > m_buffer.size())
			throw CPtmpBufferError("error reading ip address");

		unsigned int rawIp;
		m_qbuffer->seek(m_readIndex);
		(*m_dataStream) >> rawIp;
		val.setRawIPAddress(rawIp);

		if (bAdvanceIndex)
			m_readIndex += 4;
	}
	else
		throw CPtmpBufferError("read encoding error");

	return val;
}

CIpAddress CPtmpBuffer::readIpv6Address(bool bAdvanceIndex)
{
	CIpAddress val;
	
	if (m_encoding == ePtmpBufferText)
	{
		int delimiterIndex = m_buffer.indexOf('\0', m_readIndex);
		if (delimiterIndex < 0)
			throw CPtmpBufferError("error reading ipv6 address");

		val = CIpAddress(m_buffer.mid(m_readIndex, delimiterIndex - m_readIndex).data());

		if (!val.isAValidAddress())
			throw CPtmpBufferError("error reading ipv6 address");

		if (bAdvanceIndex)
			m_readIndex = delimiterIndex + 1;
	}
	else if (m_encoding == ePtmpBufferBinary)
	{
		if ((m_readIndex + 16) > m_buffer.size())
			throw CPtmpBufferError("error reading ipv6 address");

		S16bytes* rawIp = (S16bytes*) (m_buffer.data() + m_readIndex);
		val.setRawIpv6Address(*rawIp);

		if (bAdvanceIndex)
			m_readIndex += 16;
	}
	else
		throw CPtmpBufferError("read encoding error");

	return val;
}

CMacAddress CPtmpBuffer::readMacAddress(bool bAdvanceIndex)
{
	CMacAddress val;
	
	if (m_encoding == ePtmpBufferText)
	{
		int delimiterIndex = m_buffer.indexOf('\0', m_readIndex);
		if (delimiterIndex < 0)
			throw CPtmpBufferError("error reading mac address");

		val = CMacAddress(m_buffer.mid(m_readIndex, delimiterIndex - m_readIndex).data());

		if (!val.isAValidAddress())
			throw CPtmpBufferError("error reading mac address");

		if (bAdvanceIndex)
			m_readIndex = delimiterIndex + 1;
	}
	else if (m_encoding == ePtmpBufferBinary)
	{
		if ((m_readIndex + 6) > m_buffer.size())
			throw CPtmpBufferError("error reading mac address");

		std::string mac = Util::toHex((unsigned char) m_buffer.at(m_readIndex), 2)
			+ Util::toHex((unsigned char) m_buffer.at(m_readIndex + 1), 2) + "."
			+ Util::toHex((unsigned char) m_buffer.at(m_readIndex + 2), 2)
			+ Util::toHex((unsigned char) m_buffer.at(m_readIndex + 3), 2) + "."
			+ Util::toHex((unsigned char) m_buffer.at(m_readIndex + 4), 2)
			+ Util::toHex((unsigned char) m_buffer.at(m_readIndex + 5), 2);

		val = CMacAddress(mac);

		if (bAdvanceIndex)
			m_readIndex += 6;
	}
	else
		throw CPtmpBufferError("read encoding error");

	return val;
}

QUuid CPtmpBuffer::readUuid(bool bAdvanceIndex)
{
	QUuid val;
	
	if (m_encoding == ePtmpBufferText)
	{
		int delimiterIndex = m_buffer.indexOf('\0', m_readIndex);
		if (delimiterIndex < 0)
			throw CPtmpBufferError("error reading uuid");

		val = QUuid(m_buffer.mid(m_readIndex, delimiterIndex - m_readIndex).data());

//		if (val.isNull())
//			throw CPtmpBufferError("error reading uuid");

		if (bAdvanceIndex)
			m_readIndex = delimiterIndex + 1;
	}
	else if (m_encoding == ePtmpBufferBinary)
	{
		if ((m_readIndex + 16) > m_buffer.size())
			throw CPtmpBufferError("error reading uuid");

		m_qbuffer->seek(m_readIndex);
		(*m_dataStream) >> val;

		if (bAdvanceIndex)
			m_readIndex += 16;
	}
	else
		throw CPtmpBufferError("read encoding error");

	return val;
}

int CPtmpBuffer::readData(char* data, int length, bool bAdvanceIndex)
{
	if ((m_encoding == ePtmpBufferText) || (m_encoding == ePtmpBufferBinary))
	{
		unsigned int oldReadIndex = m_readIndex;

		int readLength;
		
		try
		{
			readLength = readInt(true);
		}
		catch (CPtmpBufferError e)
		{
			m_readIndex = oldReadIndex;
			throw CPtmpBufferError("error reading data");
		}

		if (readLength > length)
		{
			m_readIndex = oldReadIndex;
			throw CPtmpBufferError("error reading data: more read data than allocated");
		}

		if ((m_readIndex + readLength) > m_buffer.size())
		{
			m_readIndex = oldReadIndex;
			throw CPtmpBufferError("error reading data");
		}

		memcpy(data, m_buffer.data() + m_readIndex, readLength);

		if (bAdvanceIndex)
			m_readIndex += readLength;
		else
			m_readIndex = oldReadIndex;

		return readLength;
	}
	else
		throw CPtmpBufferError("read encoding error");
}


/*
std::list CPtmpBuffer::readList()
{
//To do

}
void CPtmpBuffer::write(std::list val)
{
//to do
}
*/


void CPtmpBuffer::write(char val)
{
	if (m_encoding == ePtmpBufferText)
	{
		QByteArray array;
		array.setNum(static_cast<int>(val));
		m_buffer.append(array);
		m_buffer.append('\0'); // delimiter is \0 for text encoding
	}
	else if (m_encoding == ePtmpBufferBinary)
	{
		m_buffer.append(val);
	}
	else
		throw CPtmpBufferError("write encoding error");
}

void CPtmpBuffer::write(bool val)
{
	if (m_encoding == ePtmpBufferText)
	{
		m_buffer.append(val ? "true" : "false");
		m_buffer.append('\0');
	}
	else if (m_encoding == ePtmpBufferBinary)
	{
		m_buffer.append(static_cast<char>(val ? 1 : 0));

//		m_qbuffer->seek(m_qbuffer->size());
//		(*m_dataStream) << val;
	}
	else
		throw CPtmpBufferError("write encoding error");
}

void CPtmpBuffer::write(short val)
{
	if (m_encoding == ePtmpBufferText)
	{
		QByteArray array;
		array.setNum(val);
		m_buffer.append(array);
		m_buffer.append('\0'); // delimiter is \0 for text encoding
	}
	else if (m_encoding == ePtmpBufferBinary)
	{
/*		// convert to net order, then add
		short netval = qToBigEndian(val);
		QByteArray array((char*)&netval, 2);
		m_buffer.append(array); */

		m_qbuffer->seek(m_qbuffer->size());
		(*m_dataStream) << val;
	}
	else
		throw CPtmpBufferError("write encoding error");
}

void CPtmpBuffer::write(int val)
{
	if (m_encoding == ePtmpBufferText)
	{
		QByteArray array;
		array.setNum(val);
		m_buffer.append(array);
		m_buffer.append('\0'); // delimiter is \0 for text encoding
	}
	else if (m_encoding == ePtmpBufferBinary)
	{
/*		// convert to net order, then add
		int netval = qToBigEndian(val);
		QByteArray array((char*)&netval, 4);
		m_buffer.append(array);*/

		m_qbuffer->seek(m_qbuffer->size());
		(*m_dataStream) << val;
	}
	else
		throw CPtmpBufferError("write encoding error");
}

void CPtmpBuffer::write(long long val)
{
	if (m_encoding == ePtmpBufferText)
	{
		QByteArray array;
		array.setNum(val);
		m_buffer.append(array);
		m_buffer.append('\0'); // delimiter is \0 for text encoding
	}
	else if (m_encoding == ePtmpBufferBinary)
	{
/*		// convert to net order, then add
		long long netval = qToBigEndian(val);
		QByteArray array((char*)&netval, 8);
		m_buffer.append(array);*/

		m_qbuffer->seek(m_qbuffer->size());
		(*m_dataStream) << val;
	}
	else
		throw CPtmpBufferError("write encoding error");
}

void CPtmpBuffer::write(float val)
{
	if (m_encoding == ePtmpBufferText)
	{
		QByteArray array;
		array.setNum(val);
		m_buffer.append(array);
		m_buffer.append('\0'); // delimiter is \0 for text encoding
	}
	else if (m_encoding == ePtmpBufferBinary)
	{
		m_qbuffer->seek(m_qbuffer->size());
		(*m_dataStream) << val;
	}
	else
		throw CPtmpBufferError("write encoding error");
}

void CPtmpBuffer::write(double val)
{
	if (m_encoding == ePtmpBufferText)
	{
		QByteArray array;
		array.setNum(val);
		m_buffer.append(array);
		m_buffer.append('\0'); // delimiter is \0 for text encoding
	}
	else if (m_encoding == ePtmpBufferBinary)
	{
		m_qbuffer->seek(m_qbuffer->size());
		(*m_dataStream) << val;
	}
	else
		throw CPtmpBufferError("write encoding error");
}

void CPtmpBuffer::write(const std::string& val)
{
	if ((m_encoding == ePtmpBufferText) || (m_encoding == ePtmpBufferBinary))
	{
		m_buffer.append(val.c_str());
		m_buffer.append('\0'); // delimiter is \0 for text encoding
	}
	else
		throw CPtmpBufferError("write encoding error");
}

void CPtmpBuffer::write(const QString& val)
{
	if ((m_encoding == ePtmpBufferText) || (m_encoding == ePtmpBufferBinary))
	{
		m_buffer.append(val);
		m_buffer.append('\0'); // delimiter is \0 for text encoding
	}
	else
		throw CPtmpBufferError("write encoding error");
}

void CPtmpBuffer::write(const CIpAddress& val)
{
	if (m_encoding == ePtmpBufferText)
	{
		m_buffer.append(val.iPtoString().c_str());
		m_buffer.append('\0'); // delimiter is \0 for text encoding
	}
	else if (m_encoding == ePtmpBufferBinary)
	{
		if (val.isIpv4())
		{
/*			unsigned int netval = qToBigEndian(val.getRawIPAddress());
			QByteArray array((char*)&netval, 4);
			m_buffer.append(array);*/

			m_qbuffer->seek(m_qbuffer->size());
			(*m_dataStream) << val.getRawIPAddress();
		}
		else
		{
			QByteArray array((char*)val.getRawIpv6Address().bytes, 16);
			m_buffer.append(array);
		}
	}
	else
		throw CPtmpBufferError("write encoding error");
}

void CPtmpBuffer::write(const CMacAddress& val)
{
	if (m_encoding == ePtmpBufferText)
	{
		m_buffer.append(val.macToString().c_str());
		m_buffer.append('\0'); // delimiter is \0 for text encoding
	}
	else if (m_encoding == ePtmpBufferBinary)
	{
		char netval[6];
		for (unsigned int i=0; i<6; i++)
			netval[i] = (char) val.getOctet(i);
		QByteArray array(netval, 6);
		m_buffer.append(array);
	}
	else
		throw CPtmpBufferError("write encoding error");
}

void CPtmpBuffer::write(const QUuid& val)
{
	if (m_encoding == ePtmpBufferText)
	{
		m_buffer.append(val.toString());
		m_buffer.append('\0'); // delimiter is \0 for text encoding
	}
	else if (m_encoding == ePtmpBufferBinary)
	{
		m_qbuffer->seek(m_qbuffer->size());
		(*m_dataStream) << val;
	}
	else
		throw CPtmpBufferError("write encoding error");
}

void CPtmpBuffer::write(const char* val, int length)
{
	if ((m_encoding == ePtmpBufferText) || (m_encoding == ePtmpBufferBinary))
	{
		write(length);
		QByteArray array(val, length);
		m_buffer.append(array);
	}
	else
		throw CPtmpBufferError("write encoding error");
}

void CPtmpBuffer::write(const Ipc::CIpcData* val)
{
	val->ipcDataSerialize(*this);
}

void CPtmpBuffer::write(const Ipc::CIpcData& val)
{
	val.ipcDataSerialize(*this);
}

void CPtmpBuffer::writeSizeToFront()
{
	if (m_encoding == ePtmpBufferText)
	{
		QByteArray array;
		array.setNum(m_buffer.size());
		m_buffer.prepend(array + '\0');
	}
	else if (m_encoding == ePtmpBufferBinary)
	{
		// convert to net order, then add
		int netval = qToBigEndian(m_buffer.size());
		QByteArray array((char*)&netval, 4);
		m_buffer.prepend(array);
	}
	else
		throw CPtmpBufferError("write encoding error");
}

/*
namespace Ptmp
{
	void testPtmpBuffer()
	{
#define PTMPBUFFER_ASSERT(a, b) if ((a) != (b)) throw "not equal";
		Ptmp::CPtmpBuffer buffer;
		char c = 0x12;
		bool b1 = true;
		bool b2 = false;
		short s = 0x2345;
		int i = 0x7662;
		long long l = 0x2345109828390912LL;
		float f = 123.589742;
		double d = 982736.283463412314;
		string st = "lsiajfiwjefjijifwljwa aw flawjfe ij wefljawfj awiljf wef\nlijw eflji awfe";
		QString qs = "liaj fj awlefiljf jw wf\n asfjlij f2234 \nl ijwlefwiljf2\rli asfse\tl iasjfilj ewf";
		CIpAddress ip("1.1.1.1");
		CIpAddress ipv6("fe80::1:2345:def1:a");
		CMacAddress m;
		QUuid u = QUuid::createUuid();

		for (unsigned int j=0; j<1; j++)
		{
			buffer.write(c);
			buffer.write(b1);
			buffer.write(b2);
			buffer.write(s);
			buffer.write(i);
			buffer.write(l);
			buffer.write(f);
			buffer.write(d);
			buffer.write(st);
			buffer.write(qs);
			buffer.write(ip);
			buffer.write(ipv6);
			buffer.write(m);
			buffer.write(u);
		}

		unsigned int size = buffer.size();
		buffer.writeSizeToFront();

		PTMPBUFFER_ASSERT(buffer.readInt(), size);
		PTMPBUFFER_ASSERT(buffer.readByte(), c);
		PTMPBUFFER_ASSERT(buffer.readBool(), b1);
		PTMPBUFFER_ASSERT(buffer.readBool(), b2);
		PTMPBUFFER_ASSERT(buffer.readShort(), s);
		PTMPBUFFER_ASSERT(buffer.readInt(), i);
		PTMPBUFFER_ASSERT(buffer.readLong(), l);
		buffer.readFloat();
		buffer.readDouble();
		PTMPBUFFER_ASSERT(buffer.readString(), st);
		PTMPBUFFER_ASSERT(buffer.readQString(), qs);
		PTMPBUFFER_ASSERT(buffer.readIpAddress(), ip);
		PTMPBUFFER_ASSERT(buffer.readIpv6Address(), ipv6);
		PTMPBUFFER_ASSERT(buffer.readMacAddress(), m);
		PTMPBUFFER_ASSERT(buffer.readUuid(), u);

#undef PTMPBUFFER_ASSERT
	}
}
*/
