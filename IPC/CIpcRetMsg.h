
//************************************************************************
//
// � Copyright ------
//  All use, disclosure, and/or reproduction of this material is
//  prohibited unless authorized in writing.
//
//************************************************************************

/*! /file
	File Name:	CIpcRetMsg.h     <br>
	Author:		Michael Wang <br>
	Date:		12/11/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CIpcRetMsg class definitions.
*/

/*************************************************************************



*************************************************************************/


#ifndef CIpc_RETURN_MSG_H
#define CIpc_RETURN_MSG_H

#include "CIpcMsg.h"

namespace Ipc
{
	class CIpcRetMsg: public Ptmp::CPtmpMsg
	{
	private:	
//		static const bool s_registerStatus;

		int m_callId;
//		char m_status;

	public:
		CIpcRetMsg(Ptmp::EPtmpMsgType msgType);

		inline void setCallId(int id) { m_callId = id; }
		inline int getCallId() const { return m_callId; }
//		inline void setStatus(char status) { m_status = status; }
//		inline char getStatus() const { return m_status; }

		virtual void serialize(Ptmp::CPtmpBuffer& buffer) const;
		virtual bool deserialize(Ptmp::CPtmpBuffer& buffer);
//		static CPtmpMsg* create(Ptmp::CPtmpBuffer& buffer);
	};
}
#endif
