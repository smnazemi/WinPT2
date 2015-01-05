
//************************************************************************
//
// Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is
//  prohibited unless authorized in writing.
//
//************************************************************************

/*! /file
	File Name:	CIpcEventMsg.h     <br>
	Author:		Ajan U. Nair <br>
	Date:		09/11/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CIpcManager class definitions.
*/

/*************************************************************************
Nov 11, 07   Ajan U. Nair   Creation, Class definition, adding attributes/functions



*************************************************************************/


#ifndef CIpc_EVENT_MSG_H
#define CIpc_EVENT_MSG_H

#include "CIpcCallMsg.h"
#include <QUuid>

namespace Ipc
{
	class CIpcEventMsg: public Ptmp::CPtmpMsg
	{
	public:
		
		CIpcEventMsg();
		CIpcEventMsg(const std::string& className,
					 const QUuid& objectUuid,
					 const std::string& eventName);

		inline void setEventId(int id) { m_eventId = id; }
		inline int getEventId() const { return m_eventId; }

		inline void setClassName(const std::string& className) { m_className = className; }
		inline std::string getClassName() const { return m_className; }

		inline void setObjectUuid(const QUuid& objectUuid) { m_objectUuid = objectUuid; }
		inline QUuid getObjectUuid() const { return m_objectUuid; }

		inline void setEventName(const std::string& eventName) { m_eventName = eventName; }
		inline std::string getEventName() const { return m_eventName; }

		inline Ptmp::CPtmpBuffer& textParams() { return m_textParams; }
		inline Ptmp::CPtmpBuffer& binaryParams() { return m_binaryParams; }

		virtual void serialize(Ptmp::CPtmpBuffer& buffer) const;
		virtual bool deserialize(Ptmp::CPtmpBuffer& buffer);
		static Ptmp::CPtmpMsg* create(Ptmp::CPtmpBuffer& buffer);


	private:	

		static const bool s_registerStatus;

		int m_eventId;
		std::string m_className;
		QUuid m_objectUuid;
		std::string m_eventName;
		Ptmp::CPtmpBuffer m_textParams;
		Ptmp::CPtmpBuffer m_binaryParams;
	};
}

#endif
