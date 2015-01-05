#ifndef RECEIVER_H
#define RECEIVER_H

 #include <QDialog>

 class QLabel;
 class QPushButton;
 class QUdpSocket;
 class IUDPReceiverListener;

 class UDPReceiver : public QDialog
 {
     Q_OBJECT

 public:
     UDPReceiver(IUDPReceiverListener* listener, QWidget *parent = 0);

 private slots:
     void processPendingDatagrams();

 private:
	 IUDPReceiverListener* m_listener;
     QLabel *statusLabel;
     QPushButton *quitButton;
     QUdpSocket *udpSocket;
	 QString receivedMessage;
	 unsigned long m_expectedMsgIdx;
 };

 #endif
	