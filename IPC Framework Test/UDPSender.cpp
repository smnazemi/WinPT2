#include <QtGui>
#include <QtNetwork>

#include "UDPSender.h"

 UDPSender::UDPSender()
 {
     udpSocket = new QUdpSocket(this);
 }
 void UDPSender::broadcastDatagram(QString msg)
 {
     QByteArray datagram = msg;
     udpSocket->writeDatagram(datagram.data(), datagram.size(),QHostAddress::Broadcast, 7777);

 }
