//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************

/*! \file
	File Name:	CPTMPServer.h     <br>
	Author:		Ajan U. Nair <br>
	Date:		10/04/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CPTMPConnection class definitions.
*/


/*************************************************************************
Oct 04, 07   Ajan U. Nair   Creation, Class definition, adding attributes and



*************************************************************************/

#ifndef CPtmp_CONNECTION_H
#define CPtmp_CONNECTION_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMutex>
#include "CPtmpBuffer.h"
#include "CNegoMsgParameter.h"
#include <QTimer>

namespace Ptmp
{
	class CPtmpConnection;
	class CPtmpMsg;
	class CNegoMsg;
	
	enum EPtmpConnectionState
	{	
		eNotConnected = 0,
		eConnecting,
		eNegotiating,
		eAuthenticating,
		eEstablished
	};

	enum EPtmpConnectionErrorType
	{
		eNoError = 0,
		eConnectionError,
		eNegotiationError,
		eAuthenticationError		
	};

	// functor class for callback from CPtmpConnection
	class CPtmpConnectionCallBack
	{
	public:
		CPtmpConnectionCallBack(CPtmpConnection* conn) : m_connection(conn) {}
		virtual ~CPtmpConnectionCallBack() {}

		CPtmpConnection* getConnection() const { return m_connection; }

		// calls when connection receives negotiation msg
		virtual bool onNegotiation(CPtmpMsg *ctrlMsg) { return true; }

		// if authentication type is built into PTMP,
		// it calls when it needs the password for a specific user during authentication
		virtual QString getPassword(const QString& userName) { return ""; }

		// if authentication type is custom
		// it calls when it receives any msg during authentication
		virtual bool onCustomAuthentication(CPtmpMsg *ctrlMsg) { return true; }

		// calls when state changes to established
		virtual void onEstablished() {}

		// calls when state changes from established to disconnect
		virtual void onDisconnect() {}

		// calls when an error occurs
		virtual void onError(EPtmpConnectionErrorType errorType) = 0;

		// calls when data msgs come in
		virtual void onData(CPtmpMsg *dataMsg) = 0;

	protected:
		CPtmpConnection* m_connection;
	};

	// template class for using a class' member function as CPtmpConnectionCallBack callback
	template <class TClass> class TPtmpConnectionCallBack : public CPtmpConnectionCallBack
	{
	public:
		typedef bool (TClass::*TOnNegotiation)(CPtmpConnection*, CPtmpMsg*);
		typedef QString (TClass::*TGetPassword)(CPtmpConnection*, const QString&);
		typedef bool (TClass::*TOnCustomAuthentication)(CPtmpConnection*, CPtmpMsg*);
		typedef void (TClass::*TOnEstablished)(CPtmpConnection*);
		typedef void (TClass::*TOnDisconnect)(CPtmpConnection*);
		typedef void (TClass::*TOnError)(CPtmpConnection*, EPtmpConnectionErrorType);
		typedef void (TClass::*TOnData)(CPtmpConnection*, CPtmpMsg*);

		TPtmpConnectionCallBack(CPtmpConnection* conn,
			TClass* obj,
			TOnNegotiation onNego,
			TGetPassword getPass,
			TOnCustomAuthentication onCustomAuthen,
			TOnEstablished onEst,
			TOnDisconnect onDiscon,
			TOnError onErr,
			TOnData onD)
			: CPtmpConnectionCallBack(conn)
		{
			m_obj = obj;
			m_onNegotiation = onNego;
			m_getPassword = getPass;
			m_onCustomAuthentication = onCustomAuthen;
			m_onEstablished = onEst;
			m_onDisconnect = onDiscon;
			m_onError = onErr;
			m_onData = onD;
		}

		virtual bool onNegotiation(CPtmpMsg *ctrlMsg)
		{
			if (m_onNegotiation == NULL)
				return CPtmpConnectionCallBack::onNegotiation(ctrlMsg);
			return (m_obj->*m_onNegotiation)(m_connection, ctrlMsg);
		}

		virtual QString getPassword(const QString& userName)
		{
			if (m_getPassword == NULL)
				return CPtmpConnectionCallBack::getPassword(userName);
			return (m_obj->*m_getPassword)(m_connection, userName);
		}

		virtual bool onCustomAuthentication(CPtmpMsg *ctrlMsg)
		{
			if (m_onCustomAuthentication == NULL)
				return CPtmpConnectionCallBack::onCustomAuthentication(ctrlMsg);
			return (m_obj->*m_onCustomAuthentication)(m_connection, ctrlMsg);
		}

		virtual void onEstablished()
		{
			if (m_onEstablished == NULL)
				CPtmpConnectionCallBack::onEstablished();
			else
				(m_obj->*m_onEstablished)(m_connection);
		}

		virtual void onDisconnect()
		{
			if (m_onDisconnect == NULL)
				CPtmpConnectionCallBack::onDisconnect();
			else
				(m_obj->*m_onDisconnect)(m_connection);
		}

		virtual void onError(EPtmpConnectionErrorType errorType)
		{
			if (m_onError != NULL)
				(m_obj->*m_onError)(m_connection, errorType);
		}

		virtual void onData(CPtmpMsg *dataMsg)
		{
			if (m_onData != NULL)
				(m_obj->*m_onData)(m_connection, dataMsg);
		}

	private:
		TClass* m_obj;
		TOnNegotiation m_onNegotiation;
		TGetPassword m_getPassword;
		TOnCustomAuthentication m_onCustomAuthentication;
		TOnEstablished m_onEstablished;
		TOnDisconnect m_onDisconnect;
		TOnError m_onError;
		TOnData m_onData;
	};

	class CPtmpConnection : public QObject
	{
	Q_OBJECT

	public:
		friend class CPtmpServer;

		CPtmpConnection(CNegoMsgParameters *negoParams);
		~CPtmpConnection();

		inline EPtmpConnectionState getState() const { return m_state; }
		inline bool isConnected() const { return (m_state == eEstablished); }

		bool connect(const QString& serverAddress, unsigned short serverPort);
		bool disconnect(std::string disconnectReason);
		void registerCallBack(CPtmpConnectionCallBack *callback);

		bool send(CPtmpMsg* ptmpMsg);

		inline QString getRemoteAddress() const
		{
			return m_socket->peerName().size()
				? m_socket->peerName() : m_socket->peerAddress().toString();
		}
		inline unsigned short getLocalPort() const { return m_socket->localPort(); }
		inline unsigned short getRemotePort() const { return m_socket->peerPort(); }
		inline bool isServer() const { return m_bIsServer; }

		inline QString getDefaultUserName() const {return m_userName;}
		
		inline void setDefaultUserName(const QString& userName) { m_userName = userName; }

		inline QUuid getPeerUuid() const { return m_peerUuid; }

//		static const int s_keepaliveTime;
//		static const int s_timeoutTime;
		
	private slots:
		void socketConnected();
		void socketDisconnected();
		void socketError(QAbstractSocket::SocketError socketError);
		void dataArrived();

		void keepalive();
		void timeout();

		void sendNow(CPtmpBuffer* buffer);

	signals:
		void sendReady(CPtmpBuffer* buffer);

	private:
		CPtmpConnection(QTcpSocket* connectedSocket, CNegoMsgParameters* negoParams);
		
		void processCtrlMsg(CPtmpMsg* msg);
		void sendNegoMsg();

		bool negotiate(CNegoMsg* msg);

		void compress(CPtmpBuffer& buffer);
		void uncompress(CPtmpBuffer& buffer);
		void encrypt(CPtmpBuffer& buffer);
		void decrypt(CPtmpBuffer& buffer);

		void startTimers();
		void cancelTimers();

		bool m_bIsServer;

		QMutex m_mutex;

		QString m_userName;

		QTcpSocket* m_socket;
		EPtmpConnectionState m_state;
		CPtmpBuffer	m_buffer;
		CPtmpConnectionCallBack* m_callback;

		std::string m_ChallengeTextInConn;
		
		CNegoMsgParameters* m_negoParams;

		QUuid m_peerUuid;
		EPtmpEncryption m_encryption;
		QByteArray m_cryptKey;
		EPtmpCompression m_compression;
		EPtmpAuthentication m_authentication;

		QTimer* m_keepaliveTimer;
		QTimer* m_timeoutTimer;
	};
}


#endif
