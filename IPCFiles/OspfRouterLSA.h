//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 OspfRouterLSA.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:47 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_OSPFROUTERLSA_H
#define IPC_FW_OSPFROUTERLSA_H

#include "../framework/IPCFrameWork.h"

#include "OspfLSA.h"
#include "OspfRouterLink.h"

using namespace std;



class OspfRouterLSA : public OspfLSA
{
private:
	bool m_eBit;
	bool m_bBit;
	bool m_vBit;
	std::vector<OspfRouterLink> m_links;
public:
	//Constructors and Distructor
	OspfRouterLSA()
	{	
	}	
	OspfRouterLSA(CPtmpBuffer  *buf)
	{	
		m_className="OspfRouterLSA";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		m_eBit=buf->readBool();

		buf->readInt();//skip the type of data
		m_bBit=buf->readBool();

		buf->readInt();//skip the type of data
		m_vBit=buf->readBool();

		buf->readInt();//skip the type of data
		{
			buf->readInt();//skip data type of vect contents
			int sizeOfVect=buf->readInt();
			for(int index_links=0;index_links<sizeOfVect;index_links++)
			{
				buf->flushRead();
				OspfRouterLink vectMem0(buf);
				m_links.push_back(vectMem0);
			}
		}
	}
	~OspfRouterLSA()
	{
	}

	static inline std::string getFwVersion()
	{
		return "1.1";
	}

	static inline std::string getFwBuildInfo()
	{
		return "Thu August 21 2008  13:14:47 pm";
	}

	virtual void event(Ipc::CIpcEventMsg eventMsg){}

	//get and set functions

	inline bool geteBit()
	{
		return m_eBit;
	}
	inline void seteBit(bool valueToSet)
	{
		m_eBit= valueToSet;
		return;
	}


	inline bool getbBit()
	{
		return m_bBit;
	}
	inline void setbBit(bool valueToSet)
	{
		m_bBit= valueToSet;
		return;
	}


	inline bool getvBit()
	{
		return m_vBit;
	}
	inline void setvBit(bool valueToSet)
	{
		m_vBit= valueToSet;
		return;
	}


	inline std::vector<OspfRouterLink> getlinks()
	{
		return m_links;
	}
	inline void setlinks(std::vector<OspfRouterLink> valueToSet)
	{
		m_links= valueToSet;
		return;
	}


};
#endif
//-----data class file : OspfRouterLSA.h --end----
