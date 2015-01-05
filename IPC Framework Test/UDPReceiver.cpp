
#include <QtNetwork>
#include "UDPReceiver.h"
#include "IUDPReceiverListener.h"


UDPReceiver::UDPReceiver(IUDPReceiverListener* listener)
     : m_listener(listener),
	 m_expectedMsgIdx(0)

{
	udpSocket = new QUdpSocket(this);
	udpSocket->bind(7777, QUdpSocket::ShareAddress);
	connect(udpSocket, SIGNAL(readyRead()),	this, SLOT(processPendingDatagrams()));
}


void UDPReceiver::processPendingDatagrams()
{
	while (udpSocket->hasPendingDatagrams()) 
	{
		QByteArray datagram;
		datagram.resize(udpSocket->pendingDatagramSize());
		udpSocket->readDatagram(datagram.data(), datagram.size());
		receivedMessage = tr("%1").arg(datagram.data());
		QStringList receivedMessageList;
		receivedMessageList = receivedMessage.split(QRegExp("\\s+"));
		unsigned long receivedMessageIdx = receivedMessageList.takeFirst().toLong();


		if(receivedMessageIdx == m_expectedMsgIdx)
		{
			QString msgWithoutIdx;
			while(!receivedMessageList.empty())
			{
				msgWithoutIdx += receivedMessageList.takeFirst() + " ";
			}
			m_listener->MessageReceived(msgWithoutIdx);
			m_expectedMsgIdx = receivedMessageIdx + 1;
		}
	}
}