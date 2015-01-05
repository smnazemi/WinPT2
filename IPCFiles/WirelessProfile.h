//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 WirelessProfile.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:48 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_WIRELESSPROFILE_H
#define IPC_FW_WIRELESSPROFILE_H

#include "../framework/IPCFrameWork.h"

using namespace std;



class WirelessProfile : public IpcBase
{
private:
	std::string m_name;
	std::string m_ssid;
	int m_networkType;
	int m_radioBand;
	CMacAddress  m_macAddress;
	double m_strength;
	int m_authenType;
	std::string m_wepKey;
	bool m_isDhcpEnabled;
	CIpAddress m_ipAddress;
	CIpAddress m_subnetMask;
	CIpAddress m_defaultGateway;
	CIpAddress m_dnsServer;
public:
	//Constructors and Distructor
	WirelessProfile()
	{	
	}	
	WirelessProfile(CPtmpBuffer  *buf)
	{	
		m_className="WirelessProfile";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_name=buf->readString();

		buf->readInt();//skip the type of data
		m_ssid=buf->readString();

		buf->readInt();//skip the type of data
		m_networkType=buf->readInt();

		buf->readInt();//skip the type of data
		m_radioBand=buf->readInt();

		buf->readInt();//skip the type of data
		m_macAddress=buf->readMacAddress();

		buf->readInt();//skip the type of data
		m_strength=buf->readDouble();

		buf->readInt();//skip the type of data
		m_authenType=buf->readInt();

		buf->readInt();//skip the type of data
		m_wepKey=buf->readString();

		buf->readInt();//skip the type of data
		m_isDhcpEnabled=buf->readBool();

		buf->readInt();//skip the type of data
		m_ipAddress=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_subnetMask=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_defaultGateway=buf->readIpAddress();

		buf->readInt();//skip the type of data
		m_dnsServer=buf->readIpAddress();
	}
	~WirelessProfile()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:48 pm";
	}

	virtual void event(Ipc::CIpcEventMsg eventMsg){}

	//get and set functions

	inline std::string getname()
	{
		return m_name;
	}
	inline void setname(std::string valueToSet)
	{
		m_name= valueToSet;
		return;
	}


	inline std::string getssid()
	{
		return m_ssid;
	}
	inline void setssid(std::string valueToSet)
	{
		m_ssid= valueToSet;
		return;
	}


	inline int getnetworkType()
	{
		return m_networkType;
	}
	inline void setnetworkType(int valueToSet)
	{
		m_networkType= valueToSet;
		return;
	}


	inline int getradioBand()
	{
		return m_radioBand;
	}
	inline void setradioBand(int valueToSet)
	{
		m_radioBand= valueToSet;
		return;
	}


	inline CMacAddress  getmacAddress()
	{
		return m_macAddress;
	}
	inline void setmacAddress(CMacAddress  valueToSet)
	{
		m_macAddress= valueToSet;
		return;
	}


	inline double getstrength()
	{
		return m_strength;
	}
	inline void setstrength(double valueToSet)
	{
		m_strength= valueToSet;
		return;
	}


	inline int getauthenType()
	{
		return m_authenType;
	}
	inline void setauthenType(int valueToSet)
	{
		m_authenType= valueToSet;
		return;
	}


	inline std::string getwepKey()
	{
		return m_wepKey;
	}
	inline void setwepKey(std::string valueToSet)
	{
		m_wepKey= valueToSet;
		return;
	}


	inline bool getisDhcpEnabled()
	{
		return m_isDhcpEnabled;
	}
	inline void setisDhcpEnabled(bool valueToSet)
	{
		m_isDhcpEnabled= valueToSet;
		return;
	}


	inline CIpAddress getipAddress()
	{
		return m_ipAddress;
	}
	inline void setipAddress(CIpAddress valueToSet)
	{
		m_ipAddress= valueToSet;
		return;
	}


	inline CIpAddress getsubnetMask()
	{
		return m_subnetMask;
	}
	inline void setsubnetMask(CIpAddress valueToSet)
	{
		m_subnetMask= valueToSet;
		return;
	}


	inline CIpAddress getdefaultGateway()
	{
		return m_defaultGateway;
	}
	inline void setdefaultGateway(CIpAddress valueToSet)
	{
		m_defaultGateway= valueToSet;
		return;
	}


	inline CIpAddress getdnsServer()
	{
		return m_dnsServer;
	}
	inline void setdnsServer(CIpAddress valueToSet)
	{
		m_dnsServer= valueToSet;
		return;
	}


};
#endif
//-----data class file : WirelessProfile.h --end----
