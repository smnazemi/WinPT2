/*! /file
	File Name:	fwtest.cpp  
	Author:		Christopher Payet and .... 
	Date:		12-March-2009   
	Revision:	1.0           
	Description:
		
		
*/


#include "fwtest.h"
#include "UDPReceiver.h"
#include "UDPSender.h"
#include "../framework/IPCFrameWork.h"
#include "../IPCfiles/Device.h"
#include "../IPCfiles/NetworkFile.h"
#include "../IPCfiles/LogicalWorkspace.h"
#include "../IPCfiles/DeviceDialog.h"
#include "../IPCfiles/DialogManager.h"
#include "../IPCfiles/TelnetClientProcess.h"
#include "../IPCfiles/CiscoDevice.h"
#include "../IPCfiles/CommandLogEntry.h"
#include "../IPCfiles/CommandLog.h"
#include "../support/CIpAddress.h"
#include "../IPCfiles/RemoteNetwork.h"
#include <QThread>

Device d;
Device x;
CiscoDevice c;
CiscoDevice ciscoDevices[20];
int ciscoDeviceCounter = 0;
int commandLogCounter = 0;
Workspace myWorkSpace; //Create a Workspace object
LogicalWorkspace myLogicalWorkspace; //Create a logical Workspace object
QString qcomponent, deviceName, currentPrompt, previousPrompt;

fwtest::fwtest(QWidget *parent, Qt::WFlags flags) //main function
	: QMainWindow(parent, flags),
	m_udpReceiver(0),
	m_udpSender(0)
{
	ui.setupUi(this); //set up the GUI
	ui.workspaceCLI->setFrameShape(QLineEdit::NoFrame);
	ui.workspaceCLI->setFrameShadow(QLineEdit::Plain);
	ui.workspaceCLIO->setFrameShape(QTextEdit::NoFrame);
	ui.workspaceCLIO->setFrameShadow(QTextEdit::Plain);
	ui.workspaceCLIO->setReadOnly(1);
	ui.devCLIO->setReadOnly(1);
	ui.devCLI->setEnabled(false);
	ui.workspaceCLI->setEnabled(false);
	//start_Framework();
}

void fwtest::on_workspaceCLI_returnPressed()
{
read_Workspace_CLI();
ui.workspaceCLI->clear();
}
void fwtest::on_devCLI_returnPressed()
{
on_Manage();
}

fwtest::~fwtest()
{
	if(m_udpReceiver)
	{
		delete m_udpReceiver;
		m_udpReceiver = 0;
	}
	if(m_udpSender)
	{
		delete m_udpSender;
		m_udpSender = 0;
	}
}

class MyDeviceEvents:DeviceEvents
{
	fwtest *fT;
	int cc;
public:
	MyDeviceEvents(fwtest *ptr)	
	{
		fT=ptr;
	}
	void nameChanged(QString newName, QString oldName)
	{
	}
	void powerChanged(bool on)
	{
		if(on){
			
			fT->tree_Widget();
		}
		else 
			//fT->showMsg(" device Switched off ");
			fT->tree_Widget();
	}
	virtual void portAdded(std::string portName)
	{
	}
	virtual void portRemoved(std::string portName)
	{
	}


};
void fwtest::enterMsg(QString k)
{
	
	qcomponent = k;
	ui.Events->append(k);
	
}
void fwtest::showMsg(QString str)
{
	
	printf("%s",str.toAscii().data());
	ui.workspaceCLIO->append(str+"\n");
	
}

void fwtest::showMsg2(QString str)
{
	
	printf("%s",str.toAscii().data());
	ui.devCLIO->append(str+"\n");
	
}

class MyDeviceEvents2:LogicalWorkspaceEvents
{
	fwtest *fT;
	
public:
	MyDeviceEvents2(fwtest *ptr)	
	{
		fT=ptr;
	}
	

	virtual void deviceAdded (QString name)
	{
		cout<<"Device "<<name.toStdString() <<"added to logical workspace."<<endl;
		fT->tree_Widget();

	}
	
	virtual void deviceRemoved (QString name)
	{
		printf("Device removed");
		fT->tree_Widget();
	}
	virtual void linkCreated (QString deviceName1, std::string portName1, QString deviceName2, std::string portName2, int connType)
	{
	}
	
};


void fwtest::on_Subscribe_clicked()
{
try
	{   ui.Un_Subscribe->setEnabled(true);
		d= myIpcFw->network()->getDevice("Router0");
		MyDeviceEvents *objDevEvents=new MyDeviceEvents(this);
		d.setEventCallBack((DeviceEvents*)objDevEvents);
		d.subscribeEvent("powerChanged");
		showMsg(" powerChanged Event Subscribed");
				
	}catch( IpcFwException e)
	{		
		showMsg(QString::fromStdString(e.getErrMsg()));
	}

}

void fwtest::on_Delete(QString devName)
{
		
try
	{  	
		if(myLogicalWorkspace.removeDevice(devName)==1){
					ui.workspaceCLIO->append("\n"+devName+" has been deleted.");
		}
		else{
			showMsg("Device Not Found!!! Please check Device name");
		}
				
	}catch( IpcFwException e)
	{		
		showMsg(QString::fromStdString(e.getErrMsg()));
	}

}


void fwtest::on_Create(int type, std::string model)
{
			
try
	{  	
	QString ret = myLogicalWorkspace.addDevice(type,model);

	if(!(QString::compare(ret, "", Qt::CaseInsensitive))){
		showMsg("Invalid Model!");
	}
	else{
		showMsg("Device created: "+ret);
	}

	}catch( IpcFwException e)
	{		
		showMsg(QString::fromStdString(e.getErrMsg()));
	}

}

void fwtest::on_Manage()
{
int wordCounter=0;
QStringList myList;
QString indevCLI = ui.devCLI->text();
//QString mode = ui.comboBox->currentText();
myList = indevCLI.split(QRegExp("\\s+"));
QString word[3];
Device myDevice = myIpcFw->network()->getDevice(deviceName);
CiscoDevice myCiscoDevice = myDevice.castTo<CiscoDevice>();
previousPrompt=currentPrompt;
currentPrompt.clear();

ui.devCLIO->append(QString::fromStdString(myCiscoDevice.getHostName())+currentPrompt);
try
	{  	
	
		for(wordCounter=0;wordCounter<3;wordCounter++){
				if(!myList.isEmpty()){
					word[wordCounter] = myList.takeAt(0);
				}
					/*else{
					showMsg("Missing Parameter");
					}*/
	}
	try
		{  	
		if(!(QString::compare(word[2], "On", Qt::CaseInsensitive))&!(QString::compare(word[1], "Power", Qt::CaseInsensitive))&!(QString::compare(word[0], "set", Qt::CaseInsensitive))){
			myCiscoDevice.setPower(1);
			showMsg2("Device "+d.getName()+" has been powered on");

		}
		else if(!(QString::compare(word[2], "Off", Qt::CaseInsensitive))&!(QString::compare(word[1], "Power", Qt::CaseInsensitive))&!(QString::compare(word[0], "set", Qt::CaseInsensitive))){
			myCiscoDevice.setPower(0);
			showMsg2("Device "+d.getName()+" has been powered Off");
		}
		else if(!(QString::compare(word[0], "enable", Qt::CaseInsensitive))&!(QString::compare(word[1], "Secret", Qt::CaseInsensitive))){
			myCiscoDevice.setEnableSecret(word[2].toStdString());
			showMsg2("Secret Password Changed");
		}
		else if(!(QString::compare(word[0], "Banner", Qt::CaseInsensitive))&!(QString::compare(word[1], "Motd", Qt::CaseInsensitive))){
			myCiscoDevice.setBannerMotd(word[2].toStdString());
			showMsg2("Banner Changed");
		}
		else if(!(QString::compare(word[0], "hostname", Qt::CaseInsensitive))){
					myCiscoDevice.setHostName(word[1].toStdString());
		}
		else if(!(QString::compare(word[0], "ping", Qt::CaseInsensitive))){
			//parameter: ping ip interface
			int delay=0, received=0, sent=0, max=0, lost=0, min=0, average=0, receivedCounter=0;
			double percLost=0.0, percReceived=0.0;
			QString pingString;
			CIpAddress myIP (word[1].toStdString());
			Process myProcess = myCiscoDevice.getProcess("IcmpProcess");
			IcmpProcess myIcmpProcess = myProcess.castTo<IcmpProcess>();
			PingProcess myPingProcess;
			short t = myIcmpProcess.startPing(myIP,5,2,100,word[2].toStdString());
			try{ 
				while(1){
				myPingProcess = myIcmpProcess.getPingProcess(t);//test
				received = myPingProcess.getReceivedCount();
				sent= myPingProcess.getSentCount();
				delay = myPingProcess.getTotalDelay();
				max= myPingProcess.getMaxDelay();
				min= myPingProcess.getMinDelay();
				}
			}
			catch(IpcFwException e){
				//showMsg2("Ping Completed");
			}
			average =(min+max)/2;
			lost = sent - received;
			percLost = ((double)lost/(double)sent)*100;
			percReceived = ((double)received/(double)sent)*100;
			ui.devCLIO->append("Sending "+QString::number(sent)+", 100-byte ICMP Echos to "+QString::fromStdString(myIP.toString())+", timeout is 2 seconds:");
			receivedCounter=received;
				for(int packetCounter=0;packetCounter<sent;packetCounter++){
					if(receivedCounter>0){
					pingString.append("!");
					receivedCounter--;
					}
					else{
					pingString.append(".");
					}
				}
			ui.devCLIO->append(pingString);
			showMsg2("Success rate is "+QString::number(percReceived)+" percent ("+QString::number(received)+"/"+QString::number(sent)+"), round-trip min/avg/max = "+QString::number(min)+"/"+QString::number(average)+"/"+QString::number(max)+" ms");
		}
		else{
			std::pair <int,std::string> www;
			CommandLogEntry myEntry;
			QString mode = ("None");
			
			if(!(QString::compare(mode, "None", Qt::CaseInsensitive))){
				//www = myCiscoDevice.enterCommand(indevCLI.toStdString()," ");//provided there's no password
				if(!(QString::compare(word[0], "en", Qt::CaseInsensitive))){
					currentPrompt.append("#");
					www = myCiscoDevice.enterCommand(indevCLI.toStdString(),"user");
				}
				else if(!(QString::compare(word[0], "conf", Qt::CaseInsensitive))){
					currentPrompt.append("(config)#");
					www = myCiscoDevice.enterCommand(indevCLI.toStdString(),"");
				}
				else if(!(QString::compare(word[0], "interface", Qt::CaseInsensitive))){
					currentPrompt.append("(config-if)#");
					www = myCiscoDevice.enterCommand(indevCLI.toStdString(),"");
				}
				else{
					currentPrompt.append(">");
					www = myCiscoDevice.enterCommand(indevCLI.toStdString(),"");
				}
			
			}
			else{
				myCiscoDevice.enterCommand(indevCLI.toStdString(), mode.toStdString());
							
			}
		ui.devCLIO->append(QString::fromStdString(myCiscoDevice.getHostName())+previousPrompt+indevCLI);

		}
				
	}catch( IpcFwException e)
		{		
		showMsg2(QString::fromStdString(e.getErrMsg()));
	}
	//}

	

}catch( IpcFwException e)
{		
	//showMsg(QString::fromStdString(e.getErrMsg()));
	showMsg2("Unknown Command!");
}
				
				
}

int fwtest::getDeviceType(QString deviceName)
{
   int deviceType;

   if(!(QString::compare(deviceName, "Router", Qt::CaseInsensitive))){
	   deviceType=0;
   }
   else if(!(QString::compare(deviceName, "Switch", Qt::CaseInsensitive))){
	   deviceType=1;
   }
	else if(!(QString::compare(deviceName, "Cloud", Qt::CaseInsensitive))){
	   deviceType=2;
   }
	else if(!(QString::compare(deviceName, "Bridge", Qt::CaseInsensitive))){
	   deviceType=3;
   }
	else if(!(QString::compare(deviceName, "Hub", Qt::CaseInsensitive))){
	   deviceType=4;
   }
	else if(!(QString::compare(deviceName, "Repeater", Qt::CaseInsensitive))){
	   deviceType=5;
   }
	else if(!(QString::compare(deviceName, "Accesspoint", Qt::CaseInsensitive))){
	   deviceType=6;
   }
	else if(!(QString::compare(deviceName, "Pc", Qt::CaseInsensitive))){
	   deviceType=7;
   }
	else if(!(QString::compare(deviceName, "Remote", Qt::CaseInsensitive))){
	   deviceType=14;
   }
	else{
	showMsg("Unknown Device Type");
	}
	return deviceType;   
}

int fwtest::getLinkType(QString LinkName)
{
   int LinkType;

   if(!(QString::compare(LinkName, "Straight", Qt::CaseInsensitive))){
	   LinkType=8100;
   }
   else if(!(QString::compare(LinkName, "Cross", Qt::CaseInsensitive))){
	   LinkType=8101;
   }
	else if(!(QString::compare(LinkName, "Roll", Qt::CaseInsensitive))){
	   LinkType=8102;
   }
	else if(!(QString::compare(LinkName, "Fiber", Qt::CaseInsensitive))){
	   LinkType=8103;
   }
	else if(!(QString::compare(LinkName, "Phone", Qt::CaseInsensitive))){
	   LinkType=8104;
   }
	else if(!(QString::compare(LinkName, "Cable", Qt::CaseInsensitive))){
	   LinkType=8105;
   }
	else if(!(QString::compare(LinkName, "Serial", Qt::CaseInsensitive))){
	   LinkType=8106;
   }
	else if(!(QString::compare(LinkName, "Auto", Qt::CaseInsensitive))){
	   LinkType=8107;
   }
	else{
	showMsg("Unknown Link Type");
	}
	return LinkType;   
}
QString fwtest::getLinkName(int linkType)
{
   QString linkName = ("Unknown");

   if(linkType==8100){
	   linkName = ("Straight");
   }
  /* else if(!(QString::compare(LinkName, "Cross", Qt::CaseInsensitive))){
	   LinkType=8101;
   }
	else if(!(QString::compare(LinkName, "Roll", Qt::CaseInsensitive))){
	   LinkType=8102;
   }
	else if(!(QString::compare(LinkName, "Fiber", Qt::CaseInsensitive))){
	   LinkType=8103;
   }
	else if(!(QString::compare(LinkName, "Phone", Qt::CaseInsensitive))){
	   LinkType=8104;
   }
	else if(!(QString::compare(LinkName, "Cable", Qt::CaseInsensitive))){
	   LinkType=8105;
   }
	else if(!(QString::compare(LinkName, "Serial", Qt::CaseInsensitive))){
	   LinkType=8106;
   }
	else if(!(QString::compare(LinkName, "Auto", Qt::CaseInsensitive))){
	   LinkType=8107;
   }
	else{
	showMsg("Unknown Link Type");
	}*/
	return linkName;   
}
void fwtest::on_Un_Subscribe_clicked()
{
try
	{		
		d.unSubscribeEvent("powerChanged");
		showMsg(" powerChanged Event Unsubscribed");
	}catch( IpcFwException e)
	{
		e.print();
	}
}

void fwtest::MessageReceived(QString msg)
{
	ui.workspaceCLIO->append(msg);

	ui.workspaceCLI->setText(msg);
	read_Workspace_CLI();


	m_udpSender->broadcastDatagram("Received :" + msg);
}
void fwtest::on_sendUDP_clicked()
{
	if(m_udpSender == 0)
	{
		m_udpSender = new UDPSender();
	}

	if(m_udpReceiver == 0)
	{
		m_udpReceiver = new UDPReceiver(this);
	}
	m_udpReceiver->show();
	m_udpReceiver->exec();
}

void fwtest::on_Start_Framework_clicked()
{
	start_Framework();
}

void fwtest::start_Framework()
{
	myIpcFw = new IPCFrameWork();//use defaultconfig options 
	myIpcFw->setUserInfo("net.netacad.cisco.ipctest","cisco"); 

	std::string address = ui.ledAddress->text().toStdString();
	int port = ui.ledPort->text().toInt();

	try
	{
		if(myIpcFw->startFrameWork(address,port)!=0) 
		{ 
			showMsg("Framework Not started!!!!");
			
			return; 
		} 

		showMsg("Fw Version:"+QString::fromStdString(IPCFrameWork::getVersion()));
		showMsg("Fw Build Info:"+QString::fromStdString(IPCFrameWork::getBuildInfo()));
		showMsg("Framework started!!!!");
		myWorkSpace = myIpcFw->appWindow()->getActiveWorkspace();
		myLogicalWorkspace = myWorkSpace.getLogicalWorkspace();

		ui.Subscribe->setEnabled(true);
		ui.workspaceCLI->setEnabled(true);

	}catch( IpcFwException e)
	{
		showMsg(QString::fromStdString(e.getErrMsg()));
	}
}

void fwtest::tree_Widget()
{
	ui.treeWidget->clear();//repaint widget
	int counter, deviceCount= myIpcFw->network()->getDeviceCount();
	
	try
	{
		QTreeWidgetItem *workspace = new QTreeWidgetItem(ui.treeWidget);
		workspace->setText(0, tr("PT Workspace Components"));
		QTreeWidgetItem *routerWidgetItem = new QTreeWidgetItem(workspace);
		QTreeWidgetItem *switchWidgetItem = new QTreeWidgetItem(workspace);
		QTreeWidgetItem *cloudWidgetItem = new QTreeWidgetItem(workspace);
		QTreeWidgetItem *bridgeWidgetItem = new QTreeWidgetItem(workspace);
		QTreeWidgetItem *hubWidgetItem = new QTreeWidgetItem(workspace);
		QTreeWidgetItem *repeaterWidgetItem = new QTreeWidgetItem(workspace);
		QTreeWidgetItem *accessPointWidgetItem = new QTreeWidgetItem(workspace);
		QTreeWidgetItem *pcWidgetItem = new QTreeWidgetItem(workspace);
		QTreeWidgetItem *serverWidgetItem = new QTreeWidgetItem(workspace);
		routerWidgetItem->setText(0, tr("Routers"));
		switchWidgetItem->setText(0,"Switches");
		cloudWidgetItem->setText(0,"Clouds");
		bridgeWidgetItem->setText(0,"Bridges");
		hubWidgetItem->setText(0,"Hubs");
		repeaterWidgetItem->setText(0,"Repeaters");
		accessPointWidgetItem->setText(0,"Access Points");
		pcWidgetItem->setText(0,"PCs");
		serverWidgetItem->setText(0,"Servers");
		
		for(counter=0;counter<deviceCount;counter++){
			Device currentDevice = myIpcFw->network()->getDeviceAt(counter);
			int deviceType = currentDevice.getType();
			QString deviceName = currentDevice.getName();
	
			if(deviceType == 0){
				QTreeWidgetItem *currentDeviceWidget = new QTreeWidgetItem();
				routerWidgetItem->addChild(currentDeviceWidget);
				currentDeviceWidget->setText(0, tr(deviceName));
			}

			if(deviceType == 1){
				QTreeWidgetItem *currentDeviceWidget = new QTreeWidgetItem();
				switchWidgetItem->addChild(currentDeviceWidget);
				currentDeviceWidget->setText(0, tr(deviceName));
			}
			if(deviceType == 2){
				QTreeWidgetItem *currentDeviceWidget = new QTreeWidgetItem();
				cloudWidgetItem->addChild(currentDeviceWidget);
				currentDeviceWidget->setText(0, tr(deviceName));
			}
			if(deviceType == 3){
				QTreeWidgetItem *currentDeviceWidget = new QTreeWidgetItem();
				bridgeWidgetItem->addChild(currentDeviceWidget);
				currentDeviceWidget->setText(0, tr(deviceName));
			}
			if(deviceType == 4){
				QTreeWidgetItem *currentDeviceWidget = new QTreeWidgetItem();
				hubWidgetItem->addChild(currentDeviceWidget);
				currentDeviceWidget->setText(0, tr(deviceName));
			}
			if(deviceType == 5){
				QTreeWidgetItem *currentDeviceWidget = new QTreeWidgetItem();
				repeaterWidgetItem->addChild(currentDeviceWidget);
				currentDeviceWidget->setText(0, tr(deviceName));
			}
			if(deviceType == 6){
				QTreeWidgetItem *currentDeviceWidget = new QTreeWidgetItem();
				accessPointWidgetItem->addChild(currentDeviceWidget);
				currentDeviceWidget->setText(0, tr(deviceName));
			}
			if(deviceType == 7){
				QTreeWidgetItem *currentDeviceWidget = new QTreeWidgetItem();
				pcWidgetItem->addChild(currentDeviceWidget);
				currentDeviceWidget->setText(0, tr(deviceName));
			}
			if(deviceType == 8){
				QTreeWidgetItem *currentDeviceWidget = new QTreeWidgetItem();
				serverWidgetItem->addChild(currentDeviceWidget);
				currentDeviceWidget->setText(0, tr(deviceName));
			}
		}
		ui.treeWidget->expandAll();
	
	}catch( IpcFwException e)
	{
		showMsg(QString::fromStdString(e.getErrMsg()));
	}
}
void fwtest::read_Workspace_CLI()
{
	QString inworkspaceCLI;
	int counter, wordCounter;
	DeviceDialog myDeviceDialog; 
	QStringList myList;
	DialogManager myDialogManager= myIpcFw->appWindow()->getDialogManager();
	inworkspaceCLI = ui.workspaceCLI->text();
	MyDeviceEvents2 *obj2DevEvents=new MyDeviceEvents2(this);

	showMsg(">"+inworkspaceCLI);
	
	int deviceCount= myIpcFw->network()->getDeviceCount();
	int deviceCount2= myLogicalWorkspace.getComponentItemsCount();
	//showMsg("No of devices is " + QString::number(deviceCount));
	//showMsg("No of components is " + QString::number(deviceCount2));
			
try
	{  	
		myList = inworkspaceCLI.split(QRegExp("\\s+"));
		QString word[6];
		

		if(!myList.isEmpty()){
			word[0] = myList.takeAt(0);

			if(!(QString::compare(word[0], "subscribe", Qt::CaseInsensitive))){
				
				if(!myList.isEmpty()){
					word[1] = myList.takeAt(0);
					myLogicalWorkspace.setEventCallBack((LogicalWorkspaceEvents*)obj2DevEvents);
					myLogicalWorkspace.subscribeEvent(word[1].toStdString()); //**deviceAdded or deviceRemoved
					showMsg("device Event Subscribed: "+word[1]);
				}
				else{
					showMsg("Missing Parameter");
				}
			}		
			
			else if(!(QString::compare(word[0], "unsubscribe", Qt::CaseInsensitive))){
				
				if(!myList.isEmpty()){
					word[1] = myList.takeAt(0);
					myLogicalWorkspace.setEventCallBack((LogicalWorkspaceEvents*)obj2DevEvents);
					myLogicalWorkspace.unSubscribeEvent(word[1].toStdString()); //**deviceAdded or deviceRemoved
					showMsg("device Event Unsubscribed: "+word[1]);
				}
				else{
					showMsg("Missing Parameter");
				}
			}	

			else if(!(QString::compare(word[0], "delete", Qt::CaseInsensitive))){
				
				if(!myList.isEmpty()){
					word[1] = myList.takeAt(0);
					on_Delete(word[1]);
				}
				else{
					showMsg("Missing Parameter");
				}
			}		
			
			else if(!(QString::compare(word[0], "create", Qt::CaseInsensitive))){
				
				if(!myList.isEmpty()){
					word[1] = myList.takeAt(0);
					int deviceType2= getDeviceType(word[1]);
					if(!myList.isEmpty()){	
						word[2]=myList.takeAt(0);
						if(!(QString::compare(word[2], "network", Qt::CaseInsensitive))){
							QString ret = myLogicalWorkspace.addRemoteNetwork();
							showMsg("Remote Network created: "+ret);
							
						}
						else{
							on_Create(deviceType2,word[2].toStdString());
						}
					}
					else{
					showMsg("Missing Parameter");
					}
				}
				else{
					showMsg("Missing Parameter");							
				}
			}

			else if(!(QString::compare(word[0], "link", Qt::CaseInsensitive))){
				
				for(wordCounter=0;wordCounter<5;wordCounter++){
					if(!myList.isEmpty()){
						word[wordCounter] = myList.takeAt(0);
						}
					else{
					showMsg("Missing Parameter");
					}
				}
				if(wordCounter==5){
					try
						{  	
							if(myLogicalWorkspace.createLink(word[0], word[1].toStdString(),word[2], word[3].toStdString(), getLinkType(word[4]))){
							showMsg("Link Created");
						}
						else{
							showMsg("Device Not Found!!! Please check Device name");
						}
					}catch(IpcFwException e)
					{		
						showMsg(QString::fromStdString(e.getErrMsg()));
					}
				}
			}
			
			
				

			else if(!(QString::compare(word[0], "view", Qt::CaseInsensitive))){
				
				if(!myList.isEmpty()){
						word[1] = myList.takeAt(0);
						if(!(QString::compare(word[1], "network", Qt::CaseInsensitive))){
							 showMsg("################ NETWORK MAP ##################");
								for(counter=0;counter<deviceCount;counter++){
											Device currentDevice = myIpcFw->network()->getDeviceAt(counter);
											int deviceType = currentDevice.getType();
											int portCount = currentDevice.getPortCount();
											QString deviceName = currentDevice.getName();
											QString portName[50];
											QString portName2[50];
											QString linkName[50];
											int myConn = 0;
											Link myLink;
											Cable myCable;
											Port myPort2;
											ui.workspaceCLIO->append("Device "+deviceName+" has "+QString::number(portCount)+" ports: ");
											for(int portCounter=0;portCounter<portCount;portCounter++){
												Port myPort=currentDevice.getPortAt(portCounter);
												portName[portCounter] = QString::fromStdString(myPort.getName());
									
												try{
													myLink = myPort.getLink();
													myCable = myLink.castTo<Cable>();
													myPort2= myCable.getPort2();
													portName2[portCounter] = QString::fromStdString(myPort2.getName());
													
													try{
														//h =myCable.getDevice2();
														//hh = h.getName();
													}
													catch(IpcFwException e){
													showMsg(QString::fromStdString(e.getErrMsg()));
													}
												}catch(IpcFwException e){
													portName2[portCounter] = ("Not Connected");
													//myLinkType=0;
													//showMsg(QString::fromStdString(e.getErrMsg()));
												}
												
												ui.workspaceCLIO->append(portName[portCounter]+" connected to remote port: "+portName2[portCounter]+" on device: ");
											}
											
									 ui.workspaceCLIO->append("\n___________________________________________________");
								}
								showMsg("############### END OF NETWORK MAP ################");		
						}
				}
				
				
			}

			else if(!(QString::compare(word[0], "manage", Qt::CaseInsensitive))){
				
				if(!myList.isEmpty()){
						word[1] = myList.takeAt(0);
						try{
							d = myIpcFw->network()->getDevice(word[1]);
							deviceName = word[1];			
							showMsg("Managing "+word[1]);
							d.getPortCount();//check if device truly exists
							currentPrompt.append(">");
							ui.devCLIO->append(deviceName+currentPrompt);
							ui.devCLI->setEnabled(true);
						}catch(IpcFwException e){
							showMsg(QString::fromStdString(e.getErrMsg()));
							showMsg("Device does not exist");
						}
						
				}
				
			}
			
			else if(!(QString::compare(word[0], "connect", Qt::CaseInsensitive))){
				
				if(!myList.isEmpty()){
						word[1] = myList.takeAt(0);
						word[2] = myList.takeAt(0);
						word[3] = myList.takeAt(0);
						word[4] = myList.takeAt(0);
						word[5] = myList.takeAt(0);
				}
				int myRemoteNetworkCount = myIpcFw->multiUserManager()->getRemoteNetworkCount();
				RemoteNetwork RN = myIpcFw->multiUserManager()->getRemoteNetworkByName(word[1]);
				//d = m_ipcFw->network()->getDevice("Peer2");
				RN.connect(word[2],word[3].toInt(),word[4], word[5]);
				int a = RN.isConnected();
				showMsg("Number of remote connections: "+QString::number(myRemoteNetworkCount));
				showMsg("Network Connection is "+QString::number(a));
				//showMsg("Remote Network Type = "+QString::fromStdString(d.getClassName()));
				
			}
			
			else{
				showMsg("Unknown Command! Available Commands: Create, Delete, Link, Manage, View, Subscribe, Unsubscribe");
			}
		}			
				
	}catch( IpcFwException e)
	{		
		showMsg(QString::fromStdString(e.getErrMsg()));
	}

}