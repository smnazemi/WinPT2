#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>

 class QUdpSocket;
 class IUDPReceiverListener;

 class UDPReceiver : public QObject
 {
     Q_OBJECT

 public:
     UDPReceiver(int port, IUDPReceiverListener* listener);

 private slots:
     void processPendingDatagrams();

 private:
	 IUDPReceiverListener* m_listener;
     QUdpSocket *udpSocket;
	 QString receivedMessage;
	 unsigned long m_expectedMsgIdx;
 };

 #endif
	