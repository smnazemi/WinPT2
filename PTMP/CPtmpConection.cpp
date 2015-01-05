//************************************************************************
//
//  Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************

/*! /file
	File Name:	CPTMPConnection.cpp     <br>
	Author:		Ajan U. Nair <br>
	Date:		10/12/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CPTMPConnection class implementation
		PTMPConnection class is communicating with remote PT irrespective of client or server.

		If on the server side, an object of CPTMPServer is returned whenever a client connects.
		This object is received through the TPTMPServerCallBack.

		If on the client side, new CPTMPConnection is to be created ,initializing using a QTCPSocket
		and connect to the client using the clientconect function.
*/

/*************************************************************************
Oct 12, 07   Ajan U. Nair   Creation, Class definition, adding attributes and functions

*************************************************************************/
#include "CNegoMsgParameter.h"

#include "CPtmpBuffer.h"
#include "CPtmpMsg.h"
#include "CPtmpConnection.h"
#include "CNegoMsg.h"
#include "CAuthReqMsg.h"
#include "CAuthChallengeMsg.h"
#include "CAuthResponseMsg.h"
#include "CAuthStatusMsg.h"
#include "CDisconnectMsg.h"
#include "CDataMsg.h"
#include "CKeepAliveMsg.h"
#include "../support/encryptUtil.h"
#include <QDateTime>

///////////aj
#include "../support/md5.h"
/////////////////////////


using namespace Ptmp;
using namespace std;

//const int CPtmpConnection::s_keepaliveTime = 2000;
//const int CPtmpConnection::s_timeoutTime = 6000;

CPtmpConnection::CPtmpConnection(CNegoMsgParameters *negoParams)
: m_mutex(QMutex::Recursive)
{
	m_negoParams = negoParams;

	// create socket
	m_socket = new QTcpSocket(this);
	QObject::connect(m_socket, SIGNAL(readyRead()), this, SLOT(dataArrived()));
	QObject::connect(m_socket, SIGNAL(connected()), this, SLOT(socketConnected()));
	QObject::connect(m_socket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));
	QObject::connect(m_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(socketError(QAbstractSocket::SocketError)));

	m_state = eNotConnected;
	m_callback = NULL;
	m_bIsServer = false;

	m_keepaliveTimer = NULL;
	m_timeoutTimer = NULL;

	m_encryption = EPtmpEncryption(eNoEncryption | eXorEncryption);
	m_compression = EPtmpCompression(eNoCompression | eZlibDefault);
	m_authentication = EPtmpAuthentication(eClearText | eSimpleAuthentication | eMd5Authentication);


	QObject::connect(this, SIGNAL(sendReady(CPtmpBuffer*)), this, SLOT(sendNow(CPtmpBuffer*)));
}

CPtmpConnection::CPtmpConnection(QTcpSocket *connectedSocket, CNegoMsgParameters *negoParams)
: m_mutex(QMutex::Recursive)
{
	m_negoParams = negoParams;

	m_socket = connectedSocket;
	QObject::connect(m_socket, SIGNAL(readyRead()), this, SLOT(dataArrived()));
	QObject::connect(m_socket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));
	QObject::connect(m_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(socketError(QAbstractSocket::SocketError)));

	m_state = eNegotiating;
	m_callback = NULL;
	m_bIsServer = true;

	m_keepaliveTimer = NULL;
	m_timeoutTimer = NULL;
	
	m_encryption = EPtmpEncryption(eNoEncryption | eXorEncryption);
	m_compression = EPtmpCompression(eNoCompression | eZlibDefault);
	m_authentication = EPtmpAuthentication(eClearText | eSimpleAuthentication | eMd5Authentication);


	QObject::connect(this, SIGNAL(sendReady(CPtmpBuffer*)), this, SLOT(sendNow(CPtmpBuffer*)));
}

CPtmpConnection::~CPtmpConnection()
{
	QMutexLocker locker(&m_mutex);
//	qDebug("CPtmpConnection close: socket peer port: %d, host: %s", m_socket->peerPort(), m_socket->peerAddress().toString());

	if(m_socket !=NULL)
		m_socket->close();

	if (m_callback != NULL)
		delete m_callback;

	if (m_negoParams != NULL)
		delete m_negoParams;

	cancelTimers();
}

bool CPtmpConnection::connect(const QString& serverAddress, unsigned short serverPort)
{
	QMutexLocker locker(&m_mutex);
//	qDebug("CPtmpConnection::connect: attempt serverAddress %s, serverPort: %d", serverAddress, serverPort);

	// check connected
	if ((m_state != eNotConnected)
		|| (m_socket->state() != QAbstractSocket::UnconnectedState))
		return false;

	// init nego params
	if (m_negoParams->m_id.isNull())
		m_negoParams->m_id = QUuid::createUuid();

	m_negoParams->m_timestamp = QDateTime::currentDateTime().toString("yyyyMMddHHmmss").toStdString();

	// connect
	m_socket->connectToHost(serverAddress, serverPort);

	if((!m_socket->isOpen())||(!m_socket->isValid()))
	{
		return false;
	}

	m_buffer.clear();
	m_buffer.setEncoding(Ptmp::ePtmpBufferText);
	m_state = eConnecting;

	qDebug("CPtmpConnection::connect: successful");

	return true;
}

bool CPtmpConnection::disconnect(string disconnectReason)
{
	QMutexLocker locker(&m_mutex);

	// check not connected
	if ((m_state == eNotConnected)
		|| (m_socket->state() == QAbstractSocket::UnconnectedState))
		return false;

	cancelTimers();

	// send disconnect msg
	CDisconnectMsg msg;
	msg.setReason(disconnectReason);
	send(&msg);

	m_socket->close();
	m_state = eNotConnected;

//	qDebug("CPtmpConnection::disconnect: reason: %s", disconnectReason);

	return true;
}

void CPtmpConnection::socketConnected()
{
	QMutexLocker locker(&m_mutex);

	m_buffer.setEncoding(Ptmp::ePtmpBufferText);
	m_state = eNegotiating;

	// client sends negotiate msg first
	if (!m_bIsServer)
	{
		// send negotiate
		sendNegoMsg();
	}
}

void CPtmpConnection::socketDisconnected()
{
	m_state = eNotConnected;

	cancelTimers();

	if (m_callback != NULL)
		m_callback->onDisconnect();
}

void CPtmpConnection::socketError(QAbstractSocket::SocketError error)
{
	QMutexLocker locker(&m_mutex);

	qDebug("CPtmpConnection::socketError");

	cancelTimers();

	m_state = eNotConnected;

	if (m_callback != NULL)
		m_callback->onError(eConnectionError);
}


bool CPtmpConnection::send(CPtmpMsg* msg)
{
//	QMutexLocker locker(&m_mutex);

	if (m_state == eNotConnected)
		return false;

/*
	CPtmpBuffer msgBuffer(ePtmpBufferReadWrite, 
		(m_state <= eNegotiating) ? ePtmpBufferText : m_buffer.getEncoding());
	msg->serialize(msgBuffer);

	// compress and encrypt if after negotiating
	if (m_state > eNegotiating)
	{
		compress(msgBuffer);
		encrypt(msgBuffer);
	}

	// write msg size
	msgBuffer.writeSizeToFront();

//	qDebug("CPtmpConnection::send: PTMPMessageType: %d", msg->getType());
//	qDebug("CPtmpConnection::send: msgBuffer rawBuffer: %s", msgBuffer.getRawBuffer());

	m_socket->write(msgBuffer.getRawBuffer());
	m_socket->flush();
*/

	CPtmpBuffer* msgBuffer = new CPtmpBuffer(ePtmpBufferReadWrite, 
		(m_state <= eNegotiating) ? ePtmpBufferText : m_buffer.getEncoding());
	msg->serialize(*msgBuffer);

	// compress and encrypt if after negotiating
	if (m_state > eNegotiating)
	{
		compress(*msgBuffer);
		encrypt(*msgBuffer);
	}

	// write msg size
	msgBuffer->writeSizeToFront();

	emit sendReady(msgBuffer);

	return true;
}

void CPtmpConnection::sendNow(CPtmpBuffer* buffer)
{
	m_socket->write(buffer->getRawBuffer());
	m_socket->flush();
	delete buffer;
}

void CPtmpConnection::registerCallBack(CPtmpConnectionCallBack *callback)
{
	QMutexLocker locker(&m_mutex);

	if (m_callback != NULL)
		delete m_callback;

	m_callback = callback;
}


//slot of readyReadSignal from connected socket
//slot connected from inside the CPTMPConnection constructor.
void CPtmpConnection::dataArrived()
{
	QMutexLocker locker(&m_mutex);

	// append to end of buffer
	m_buffer.append(m_socket->readAll());

	int msgSize = 0;

//	qDebug("CPtmpConnection::dataArrived: buffer size: %d", m_buffer.size());

	// size of ptmpBuffer is decremented by extract function.
	while (m_buffer.size())
	{	
		try
		{
			// read size
			msgSize = m_buffer.readInt();
		}
		catch (CPtmpBufferError error)
		{
			// error reading from buffer, either not an int or not enough data
			m_buffer.resetReadIndex();
			
			qDebug("CPtmpConnection::dataArrived: CPtmpBufferError error, error reading from buffer, either not an int or not enough data.");
			
			return;
		}
		
		//check to see if the buffer has that much data
		//if not, that means the msg is sent over multiple packets
		//then dont do anything, wait for the next time it receives more data
		if (m_buffer.unreadSize() < msgSize)
		{
			m_buffer.resetReadIndex();

			qDebug("CPtmpConnection::dataArrived: msg is sent over multiple packets, waiting for the next time it receives more data");

			return;
		}

		// flush the size field
		m_buffer.flushRead();

		CPtmpMsg *msg;
		CPtmpBuffer msgBuffer = m_buffer.extract(msgSize);

		// decrypt and uncompress if after negotiating
		if (m_state > eNegotiating)
		{
			decrypt(msgBuffer);
			uncompress(msgBuffer);
		}

		try
		{
			msg = CPtmpMsg::create(msgBuffer);
		}
		catch (CPtmpBufferError error)
		{
			// msg has invalid or unexpected format
			//TODO: send something back or ignore
			qDebug("CPtmpConnection::dataArrived: error parsing incoming PTMP msg");
			continue;
		}

		if (msg == NULL)
			msg = new CDataMsg(msgBuffer);

		// greater than or equal to means -- other than control messages
		if (msg->getType() >= ePtmpIPCMsg)
		{
			if (m_callback != NULL)
				m_callback->onData(msg);
		}
		else
		{
			processCtrlMsg(msg);
		}

		delete msg;
	}
}

void CPtmpConnection::processCtrlMsg(CPtmpMsg *msg)
{
	//qDebug("CPtmpConnection::processCtrlMsg");

	if (m_state == eNegotiating)
	{
		qDebug("CPtmpConnection::processCtrlMsg: m_state: eNegotiating");
		
		bool bError = false;

		// if server receives nego request OR client receives nego response
		if ((m_bIsServer && (msg->getType() == ePtmpNegoRequest))
			|| ((!m_bIsServer) && (msg->getType() == ePtmpNegoResponse)))
		{
			bool bAccept = true;
			if (m_callback != NULL)
				bAccept = m_callback->onNegotiation(msg);
		
			if (bAccept)
			{
				// set nego values
				if (!negotiate((CNegoMsg*)msg))
					bAccept = false;
			}

			if (bAccept)
			{
				if (m_bIsServer)
				{	
					// send nego response then set state to authenticating
					// so that the nego msg is in text and not compress or encrypted
					sendNegoMsg();
					m_state = eAuthenticating;
				}
				else
				{
//					qDebug("CPtmpConnection::processCtrlMsg: Accept client: %s. change state to eAuthenticating.", m_userName);

					// set state to authenticating so that authen msgs
					// are using the negotiated params
					m_state = eAuthenticating;
					
					//TODO: change to send authen request
						CAuthReqMsg authR;
//						m_userName="net.netacad.cisco.autoIP";
						authR.setUsername(m_userName);
						//m_callback->getPassword(username);
						send(&authR);

				/*	QString password;
					if (m_callback != NULL)
						password = m_callback->getPassword("");
									
					CAuthResponseMsg auth;
					auth.setDigestText(password.ascii());
					send(&auth);*/
				}
			}
			else
				bError = true;
		}
		
		if (bError)
		{
			qDebug("CPtmpConnection::processCtrlMsg: disconnecting: Negotiation error");
			
			if (m_callback != NULL)
				m_callback->onError(eNegotiationError);
			disconnect("Negotiation error");
		}
	}
	else if (m_state == eAuthenticating)
	{
		bool bError = false;
		//if (m_bIsServer)
		//{
		//	if (msg->getType() == ePtmpAuthRequest)
		//	{
		//		qDebug("CPtmpConnection::processCtrlMsg: ePtmpAuthRequest, sending challenge");

		//		//Creating challeng ,stores it into m_ChallengeTextInConn to check later and sends
		//		m_ChallengeTextInConn = Util::randomChallengeText(32);
		//		
		//		CAuthChallengeMsg authC;
		//		authC.setChallengetext(m_ChallengeTextInConn);
		//		send(&authC);					
		//	}

		//	else if (msg->getType() == ePtmpAuthResponse)
		//	{
		//		qDebug("CPtmpConnection::processCtrlMsg: ePtmpAuthResponse");
		//		
		//		CAuthResponseMsg* response = dynamic_cast<CAuthResponseMsg*>(msg);
		//		if (response == NULL)
		//			bError = true;
		//		else
		//		{
		//			// In server side after getting the response from client side
		//			//creates another digest text using MD5 functions with inputs password got from client
		//			//and stored challengtext in m_ChallengeTextInConn and compares with sent digesttext 

		//			m_userName = response->getUserName();
		//			std::string digest = response->getDigestText();
		//			
		//			QString localPassword;
		//			if (m_callback != NULL)
		//				localPassword = m_callback->getPassword(m_userName);
		//			
		//			string localDigest;
		//			
		//			if (m_negoParams->m_authentication == Ptmp::eMd5Authentication)
		//				localDigest = Util::md5Digest(m_ChallengeTextInConn, localPassword.ascii());
		//			else if (m_negoParams->m_authentication == Ptmp::eSimpleAuthentication)
		//				localDigest = Util::simpleHash(localPassword.ascii());
		//			else if (m_negoParams->m_authentication == Ptmp::eClearText)
		//				localDigest = localPassword.toAscii();
		//			
		//			if (localDigest == digest)
		//			{
		//				// send success
		//				CAuthStatusMsg statusMsg;
		//				statusMsg.setStatus( true);
		//				send(&statusMsg);

		//				m_state = eEstablished;

		//				startTimers();

		//				if (m_callback != NULL)
		//					m_callback->onEstablished();
		//			}
		//			else
		//			{
		//				bError = true;
		//			}
		//		}
		//	}
		//	else
		//		bError = true;

		//}//	 end of  if (m_bIsServer)  ie; if it is client side
		//
		//else
		{
			if (msg->getType() == ePtmpAuthChallenge)
			{
				qDebug("CPtmpConnection::processCtrlMsg: ePtmpAuthChallenge");

				QString	password;
				if (m_callback != NULL)
					password = m_callback->getPassword(m_userName);//by ajan modified the name to check the IPC working.

				//In client side after ,Gets the challenge and creating the digesttext
				//using MD5 functions and sending it as response to server

				CAuthResponseMsg authRe;

				if (m_negoParams->m_authentication == Ptmp::eMd5Authentication)
				{
					CAuthChallengeMsg* chlngMsg = (CAuthChallengeMsg*)msg;
					authRe.setDigestText( Util::md5Digest(chlngMsg->getChallengetext(), password.ascii()) );
				}
				else if (m_negoParams->m_authentication == Ptmp::eSimpleAuthentication)
				{
					authRe.setDigestText( Util::simpleHash(password.ascii()) );
				}
				else if (m_negoParams->m_authentication == Ptmp::eClearText)
				{
					authRe.setDigestText(password.ascii());
				}

				authRe.setUserName(m_userName);

				send(&authRe);
			}
			else if (msg->getType() == ePtmpAuthStatus)
			{
				qDebug("CPtmpConnection::processCtrlMsg: ePtmpAuthStatus");
				
				m_state = eEstablished;

				startTimers();

				if (m_callback != NULL)
					m_callback->onEstablished();
			}
			
			else
				bError = true;
		}

		if (bError)
		{
			if (m_callback != NULL)
				m_callback->onError(eAuthenticationError);
			disconnect("");
		}
	}
	else if (m_state == eEstablished)
	{
		//qDebug("CPtmpConnection::processCtrlMsg: eEstablished");

		if (msg->getType() == ePtmpKeepAlive)
		{
			if (m_timeoutTimer)
				m_timeoutTimer->start();
		}
		else
		{
			if (m_callback != NULL)
				m_callback->onDisconnect();
			disconnect("");
		}
	}
}

void CPtmpConnection::sendNegoMsg()
{
	CNegoMsg msg(m_negoParams, 
		m_bIsServer ? ePtmpNegoResponse : ePtmpNegoRequest);

	send(&msg);
}

void CPtmpConnection::startTimers()
{
	cancelTimers();

	if (m_negoParams->m_keepalive > 0)
	{
		m_keepaliveTimer = new QTimer(this);
		QObject::connect(m_keepaliveTimer, SIGNAL(timeout()), this, SLOT(keepalive()));
		m_keepaliveTimer->start(m_negoParams->m_keepalive * 1000 * (1 - 0.2 * rand() / RAND_MAX) );

		m_timeoutTimer = new QTimer(this);
		QObject::connect(m_timeoutTimer, SIGNAL(timeout()), this, SLOT(timeout()));
		m_timeoutTimer->start(m_negoParams->m_keepalive * 3000);
	}
}

void CPtmpConnection::cancelTimers()
{
	if (m_keepaliveTimer)
	{
		m_keepaliveTimer->stop();
		delete m_keepaliveTimer;
		m_keepaliveTimer = NULL;
	}

	if (m_timeoutTimer)
	{
		m_timeoutTimer->stop();
		delete m_timeoutTimer;
		m_timeoutTimer = NULL;
	}
}

void CPtmpConnection::keepalive()
{
	CKeepAliveMsg msg;
	send(&msg);
}

void CPtmpConnection::timeout()
{
	disconnect("");
	socketError(QAbstractSocket::UnknownSocketError);
}

bool CPtmpConnection::negotiate(CNegoMsg* msg)
{
	if (msg == NULL)
		return false;

	CNegoMsgParameters* negoParams = msg->getNegoMsgParameters();

	// check signature and version
	if ((negoParams->m_signature != CNegoMsgParameters::s_defaultSignature)
		|| (negoParams->m_version != CNegoMsgParameters::s_defaultVersion))
		return false;

	m_peerUuid = negoParams->m_id;

	// negotiate encoding with preference in the order of binary then text
	EPtmpBufferEncoding encoding = EPtmpBufferEncoding(negoParams->m_encoding & m_negoParams->m_encoding);
	if (encoding & ePtmpBufferBinary)
		encoding = ePtmpBufferBinary;
	else if (encoding & ePtmpBufferText)
		encoding = ePtmpBufferText;
	else
		return false;

	// negotiate encryption with preference in the order of XOR then no encryption
	EPtmpEncryption encryption = EPtmpEncryption(negoParams->m_encryption & m_negoParams->m_encryption);
	if (encryption & eXorEncryption)
		encryption = eXorEncryption;
	else if (encryption & eNoEncryption)
		encryption = eNoEncryption;
	else
		return false;
	
	// negotiate compression with preference in the order of zlib default then no compression
	EPtmpCompression compression = EPtmpCompression(negoParams->m_compression & m_negoParams->m_compression);
	if (compression & eZlibDefault)
		compression = eZlibDefault;
	else if (compression & eNoCompression)
		compression = eNoCompression;
	else
		return false;

	// negotiate authentication with preference in the order of md5, simple, then clear text
	EPtmpAuthentication authentication = EPtmpAuthentication(negoParams->m_authentication & m_negoParams->m_authentication);
	if (authentication & eMd5Authentication)
		authentication = eMd5Authentication;
	else if (authentication & eSimpleAuthentication)
		authentication = eSimpleAuthentication;
	else if (authentication & eClearText)
		authentication = eClearText;
	else
		return false;

	int keepalive = 0;
	if (m_negoParams->m_keepalive == 0)
		keepalive = negoParams->m_keepalive;
	else if (negoParams->m_keepalive == 0)
		keepalive = m_negoParams->m_keepalive;
	else
		keepalive = std::min(m_negoParams->m_keepalive, negoParams->m_keepalive);

	m_buffer.setEncoding(encoding);
	m_encryption = encryption;
	m_compression = compression;
	m_authentication = authentication;

	m_negoParams->m_encoding = encoding;
	m_negoParams->m_encryption = encryption;
	m_negoParams->m_compression = compression;
	m_negoParams->m_authentication = authentication;
	m_negoParams->m_keepalive = keepalive;

//	QDataStream dataStream(&m_cryptKey, QIODevice::Append);

	if (m_bIsServer)
	{
//		dataStream << m_negoParams->m_id << negoParams->m_id;
		m_cryptKey.append(m_negoParams->m_id.toString());
		m_cryptKey.append(negoParams->m_id.toString());
		m_cryptKey.append("PTMP");
		m_cryptKey.append(m_negoParams->m_timestamp.c_str());
		m_cryptKey.append(negoParams->m_timestamp.c_str());
	}
	else
	{
//		dataStream << negoParams->m_id << m_negoParams->m_id;
		m_cryptKey.append(negoParams->m_id.toString());
		m_cryptKey.append(m_negoParams->m_id.toString());
		m_cryptKey.append("PTMP");
		m_cryptKey.append(negoParams->m_timestamp.c_str());
		m_cryptKey.append(m_negoParams->m_timestamp.c_str());
	}

	return true;
}

void CPtmpConnection::compress(CPtmpBuffer& buffer)
{
	if (m_compression == eZlibDefault)
	{
		qDebug("CPtmpConnection::compress");

		QByteArray newData = qCompress(buffer.getRawBuffer());
		buffer.getRawBuffer() = newData;
	}
}

void CPtmpConnection::uncompress(CPtmpBuffer& buffer)
{
	if (m_compression == eZlibDefault)
	{
		qDebug("CPtmpConnection::uncompress");

		QByteArray newData = qUncompress(buffer.getRawBuffer());
		buffer.getRawBuffer() = newData;
	}
}

void CPtmpConnection::encrypt(CPtmpBuffer& buffer)
{
	if (m_encryption == eXorEncryption)
	{
		qDebug("CPtmpConnection::encrypt");

		QByteArray& byteArray = buffer.getRawBuffer();
		unsigned int arraySize = byteArray.size();
		unsigned int keySize = m_cryptKey.size();

		// xor with the crypt key
		for (unsigned int i=0; i<arraySize; i++)
			byteArray[i] = byteArray.at(i) ^ m_cryptKey.at(i % keySize);
	}
}

void CPtmpConnection::decrypt(CPtmpBuffer& buffer)
{
	if (m_encryption == eXorEncryption)
	{
		qDebug("CPtmpConnection::decrypt");
	
		QByteArray& byteArray = buffer.getRawBuffer();
		unsigned int arraySize = byteArray.size();
		unsigned int keySize = m_cryptKey.size();

		// xor with the crypt key
		for (unsigned int i=0; i<arraySize; i++)
			byteArray[i] = byteArray.at(i) ^ m_cryptKey.at(i % keySize);
	}
}

/*
void  CPtmpConnection::setUserName(std::string userName)
{
	m_userName=userName;
	return;
}
*/


/*void md5Test()
{

		create Random text
		CPtmpMsg *msg;
		CAuthResponseMsg* response = dynamic_cast<CAuthResponseMsg*>(msg);

		QString username = response->getUserName().c_str();
		QString password = response->getDigestText().c_str();

		MD5_CTX ctx;
		MD5Init(&ctx);
	
		MD5Update(&ctx, (unsigned char*)password.data(), password.length());


		input ( random text)
		input (password)

		dgst1= getDigest()

	

		input ( random text)
		input (password)

		dgst2= getDigest()


}
*/


	