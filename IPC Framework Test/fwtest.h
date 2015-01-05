//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	fwtest.h   
	Author:		Visweswar K. Rao 
	Date:		19-Aug-2008   
	Revision:	1.1           
	Description:
		This file holds the fwtest class implementation
		This class holds all the gui related functions implementation .

*/

#ifndef FWTEST2_H
#define FWTEST2_H

#include <QtGui/QMainWindow>
#include "../ui_fwtest.h"
#include "../IPCHeaders.h"
#include "IUDPReceiverListener.h"

class MyDeviceEvents;
class MyDeviceEvents2;
class UDPReceiver;
class UDPSender;


class fwtest : public QMainWindow , IUDPReceiverListener
{
	Q_OBJECT

public:
	friend class MyDeviceEvents;
	friend class MyDeviceEvents2;
	
	fwtest(QWidget *parent = 0, Qt::WFlags flags = 0);
	~fwtest();
	void showMsg(QString str);
	void showMsg2(QString str);
	void enterMsg(QString m);
	void MessageReceived(QString msg) override;
private:
	Ui::fwtestClass ui;
	IPCFrameWork *myIpcFw;
	UDPReceiver* m_udpReceiver;
	UDPSender* m_udpSender;

private slots:

	void on_Start_Framework_clicked();
	void on_Un_Subscribe_clicked();
	void on_sendUDP_clicked();
	void on_Subscribe_clicked();
	void on_Delete(QString deviceName);
	void on_Create(int type, std::string model);
	int getDeviceType(QString deviceName);
	int getLinkType(QString LinkName);
	QString getLinkName(int linkType);
	void on_workspaceCLI_returnPressed();
	void on_devCLI_returnPressed();
	void on_Manage();
	void start_Framework();
	void tree_Widget();
	void read_Workspace_CLI();
	//void showMsg(QString str);
	//void showMsg2(QString str);

};

#endif // FWTEST_H
