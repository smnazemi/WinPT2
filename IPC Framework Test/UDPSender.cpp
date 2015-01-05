
#include <QtNetwork>

#include "UDPSender.h"

UDPSender::UDPSender(int port):
	m_port(port)
 {
     udpSocket = new QUdpSocket(this);
 }
 void UDPSender::broadcastDatagram(QString msg)
 {
     QByteArray datagram = msg;
     udpSocket->writeDatagram(datagram.data(), datagram.size(),QHostAddress::Broadcast, m_port);

 }
