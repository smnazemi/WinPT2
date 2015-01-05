//************************************************************************
//
// © Copyright ------
//  All use, disclosure, and/or reproduction of this material is
//  prohibited unless authorized in writing.
//
//************************************************************************

/*! /file
	File Name:	CDataMsg.h     <br>
	Author:		Michael Wang <br>
	Date:		10/09/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CDataMsg class definitions.
*/

/*************************************************************************



*************************************************************************/

#ifndef CPtmp_DATA_MSG_H
#define CPtmp_DATA_MSG_H

#include "CPtmpMsg.h"

namespace Ptmp
{
	class CDataMsg : public CPtmpMsg
	{
	public:
		CDataMsg(CPtmpBuffer& buffer);

		virtual void serialize(CPtmpBuffer& buffer) const;
		virtual bool deserialize(CPtmpBuffer& buffer);

		inline void setBuffer(CPtmpBuffer& buffer) { m_buffer = buffer; }
		inline CPtmpBuffer& getBuffer() { return m_buffer; }

	private:

		CPtmpBuffer m_buffer;
	};
}
#endif