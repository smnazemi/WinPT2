//************************************************************************
//
// � Copyright ------
//  All use, disclosure, and/or reproduction of this material is
//  prohibited unless authorized in writing.
//
//************************************************************************

/*! /file
	File Name:	CIpcEvntSubsMsg.h <br>
	Author:		Ajan U. Nair <br>
	Date:		09/11/07     <br>
	Revision:	1.0          <br>
	Description:
		This file holds the CIpcManager class definitions.
*/

/*************************************************************************
Nov 11, 07   Ajan U. Nair   Creation, Class definition, adding attributes/functions

*************************************************************************/


#ifndef CIpc_EVENT_SUBSCRIBE_MSG_H
#define CIpc_EVENT_SUBSCRIBE_MSG_H

#include "CIpcCallMsg.h"
#include <QUuid>

namespace Ipc
{
	class CIpcEvntSubsMsg: public Ptmp::CPtmpMsg
	{
	public:
		CIpcEvntSubsMsg();
		CIpcEvntSubsMsg(const std::string& className,
					 const QUuid& objectUuid,
					 const std::string& eventName,
					 bool bSubscribe);

		inline void setClassName(const std::string& className) { m_className = className; }
		inline std::string getClassName() const { return m_className; }

		inline void setObjectUuid(const QUuid& objectUuid) { m_objectUuid = objectUuid; }
		inline QUuid getObjectUuid() const { return m_objectUuid; }

		inline void setEventName(const std::string& eventName) { m_eventName = eventName; }
		inline std::string getEventName() const { return m_eventName; }

		inline void setSubscribe(bool bSubscribe) { m_bSubscribe = bSubscribe; }
		inline bool getSubscribe() const { return m_bSubscribe; }

		virtual void serialize(Ptmp::CPtmpBuffer& buffer) const;
		virtual bool deserialize(Ptmp::CPtmpBuffer& buffer);
		static CPtmpMsg* create(Ptmp::CPtmpBuffer& buffer);

	private:	
		static const bool s_registerStatus;

		std::string m_className;
		QUuid m_objectUuid;
		std::string m_eventName;
		bool m_bSubscribe;
	};
}
#endif
