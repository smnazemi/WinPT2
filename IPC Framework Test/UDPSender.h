 #ifndef SENDER_H
 #define SENDER_H

 class QUdpSocket;

 class UDPSender : public QObject
 {

 public:
     UDPSender();
     void broadcastDatagram(QString msg);

 private:
     QUdpSocket *udpSocket;
 };

 #endif
	