//************************************************************************
//
// © Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************
/*! /file
	File Name:	 OspfDatabase.h 
	Author:		 Ajan U. Nair 
	Date:		 Thu August 21 2008  	Time: 13:14:47 pm
	Revision:	 1.1
	Description: IPCFiles are generated using IpcFwGenerator program.
*/
#ifndef IPC_FW_OSPFDATABASE_H
#define IPC_FW_OSPFDATABASE_H

#include "../framework/IPCFrameWork.h"
#include "TimedRouterLSA.h"
#include "TimedNetworkLSA.h"
#include "TimedSummaryLSA.h"
#include "TimedAsExternalLSA.h"
#include "TimedType7LSA.h"

using namespace std;



class OspfDatabase : public IpcBase
{
private:
	std::vector<TimedRouterLSA> m_routerLSAs;
	std::vector<TimedNetworkLSA> m_networkLSAs;
	std::vector<TimedSummaryLSA> m_summaryLSAs;
	std::vector<TimedAsExternalLSA> m_asExternalLSAs;
	std::vector<TimedType7LSA> m_type7LSAs;
	int m_routerLsaSeqNum;
	int m_networkLsaSeqNum;
	int m_summaryLsaSeqNum;
	int m_asExternalLsaSeqNum;
	int m_type7LsaSeqNum;
public:
	//Constructors and Distructor
	OspfDatabase()
	{	
	}	
	OspfDatabase(CPtmpBuffer  *buf)
	{	
		m_className="OspfDatabase";
		buf->readString();//skip the name of data obj

		buf->readInt();//skip the type of data
		{
			buf->readInt();//skip data type of vect contents
			int sizeOfVect=buf->readInt();
			for(int index_routerLSAs=0;index_routerLSAs<sizeOfVect;index_routerLSAs++)
			{
				buf->flushRead();
				TimedRouterLSA vectMem0(buf);
				m_routerLSAs.push_back(vectMem0);
			}
		}

		buf->readInt();//skip the type of data
		{
			buf->readInt();//skip data type of vect contents
			int sizeOfVect=buf->readInt();
			for(int index_networkLSAs=0;index_networkLSAs<sizeOfVect;index_networkLSAs++)
			{
				buf->flushRead();
				TimedNetworkLSA vectMem0(buf);
				m_networkLSAs.push_back(vectMem0);
			}
		}

		buf->readInt();//skip the type of data
		{
			buf->readInt();//skip data type of vect contents
			int sizeOfVect=buf->readInt();
			for(int index_summaryLSAs=0;index_summaryLSAs<sizeOfVect;index_summaryLSAs++)
			{
				buf->flushRead();
				TimedSummaryLSA vectMem0(buf);
				m_summaryLSAs.push_back(vectMem0);
			}
		}

		buf->readInt();//skip the type of data
		{
			buf->readInt();//skip data type of vect contents
			int sizeOfVect=buf->readInt();
			for(int index_asExternalLSAs=0;index_asExternalLSAs<sizeOfVect;index_asExternalLSAs++)
			{
				buf->flushRead();
				TimedAsExternalLSA vectMem0(buf);
				m_asExternalLSAs.push_back(vectMem0);
			}
		}

		buf->readInt();//skip the type of data
		{
			buf->readInt();//skip data type of vect contents
			int sizeOfVect=buf->readInt();
			for(int index_type7LSAs=0;index_type7LSAs<sizeOfVect;index_type7LSAs++)
			{
				buf->flushRead();
				TimedType7LSA vectMem0(buf);
				m_type7LSAs.push_back(vectMem0);
			}
		}

		buf->readInt();//skip the type of data
		m_routerLsaSeqNum=buf->readInt();

		buf->readInt();//skip the type of data
		m_networkLsaSeqNum=buf->readInt();

		buf->readInt();//skip the type of data
		m_summaryLsaSeqNum=buf->readInt();

		buf->readInt();//skip the type of data
		m_asExternalLsaSeqNum=buf->readInt();

		buf->readInt();//skip the type of data
		m_type7LsaSeqNum=buf->readInt();
	}
	~OspfDatabase()
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

	inline std::vector<TimedRouterLSA> getrouterLSAs()
	{
		return m_routerLSAs;
	}
	inline void setrouterLSAs(std::vector<TimedRouterLSA> valueToSet)
	{
		m_routerLSAs= valueToSet;
		return;
	}


	inline std::vector<TimedNetworkLSA> getnetworkLSAs()
	{
		return m_networkLSAs;
	}
	inline void setnetworkLSAs(std::vector<TimedNetworkLSA> valueToSet)
	{
		m_networkLSAs= valueToSet;
		return;
	}


	inline std::vector<TimedSummaryLSA> getsummaryLSAs()
	{
		return m_summaryLSAs;
	}
	inline void setsummaryLSAs(std::vector<TimedSummaryLSA> valueToSet)
	{
		m_summaryLSAs= valueToSet;
		return;
	}


	inline std::vector<TimedAsExternalLSA> getasExternalLSAs()
	{
		return m_asExternalLSAs;
	}
	inline void setasExternalLSAs(std::vector<TimedAsExternalLSA> valueToSet)
	{
		m_asExternalLSAs= valueToSet;
		return;
	}


	inline std::vector<TimedType7LSA> gettype7LSAs()
	{
		return m_type7LSAs;
	}
	inline void settype7LSAs(std::vector<TimedType7LSA> valueToSet)
	{
		m_type7LSAs= valueToSet;
		return;
	}


	inline int getrouterLsaSeqNum()
	{
		return m_routerLsaSeqNum;
	}
	inline void setrouterLsaSeqNum(int valueToSet)
	{
		m_routerLsaSeqNum= valueToSet;
		return;
	}


	inline int getnetworkLsaSeqNum()
	{
		return m_networkLsaSeqNum;
	}
	inline void setnetworkLsaSeqNum(int valueToSet)
	{
		m_networkLsaSeqNum= valueToSet;
		return;
	}


	inline int getsummaryLsaSeqNum()
	{
		return m_summaryLsaSeqNum;
	}
	inline void setsummaryLsaSeqNum(int valueToSet)
	{
		m_summaryLsaSeqNum= valueToSet;
		return;
	}


	inline int getasExternalLsaSeqNum()
	{
		return m_asExternalLsaSeqNum;
	}
	inline void setasExternalLsaSeqNum(int valueToSet)
	{
		m_asExternalLsaSeqNum= valueToSet;
		return;
	}


	inline int gettype7LsaSeqNum()
	{
		return m_type7LsaSeqNum;
	}
	inline void settype7LsaSeqNum(int valueToSet)
	{
		m_type7LsaSeqNum= valueToSet;
		return;
	}


};
#endif
//-----data class file : OspfDatabase.h --end----
