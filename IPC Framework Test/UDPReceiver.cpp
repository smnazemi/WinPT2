
#include "UDPReceiver.h"
#include "IUDPReceiverListener.h"
#include <QtGui>
#include <QtNetwork>

UDPReceiver::UDPReceiver(IUDPReceiverListener* listener, QWidget *parent)
     : QDialog(parent),
	 m_listener(listener),
	 m_expectedMsgIdx(0)

{
	statusLabel = new QLabel(tr("Listening for broadcasted messages"));
	quitButton = new QPushButton(tr("&Quit"));

	udpSocket = new QUdpSocket(this);
	udpSocket->bind(7777, QUdpSocket::ShareAddress);

	connect(udpSocket, SIGNAL(readyRead()),
	this, SLOT(processPendingDatagrams()));
	connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));


	QHBoxLayout *buttonLayout = new QHBoxLayout;
	buttonLayout->addStretch(1);
	buttonLayout->addWidget(quitButton);
	buttonLayout->addStretch(1);

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget(statusLabel);
	mainLayout->addLayout(buttonLayout);
	setLayout(mainLayout);

	setWindowTitle(tr("Broadcast Receiver"));
}


void UDPReceiver::processPendingDatagrams()
{
	while (udpSocket->hasPendingDatagrams()) 
	{
		QByteArray datagram;
		datagram.resize(udpSocket->pendingDatagramSize());
		udpSocket->readDatagram(datagram.data(), datagram.size());
		statusLabel->setText(tr("Received datagram: \"%1\"").arg(datagram.data()));
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