
 class IUDPReceiverListener 
 {
  public:
	virtual ~IUDPReceiverListener() {}
	virtual void MessageReceived(QString msg) = 0;
 };

	