 #ifndef SENDER_H
 #define SENDER_H

 class QUdpSocket;

 class UDPSender : public QObject
 {

 public:
     UDPSender(int port);
     void broadcastDatagram(QString msg);

 private:
     QUdpSocket *udpSocket;
	 int m_port;
 };

 #endif
	