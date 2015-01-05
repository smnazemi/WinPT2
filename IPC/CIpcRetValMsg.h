
//************************************************************************
//
// � Copyright ------
//  All use, disclosure, and/or reproduction of this material is
//  prohibited unless authorized in writing.
//
//************************************************************************

/*! /file
	File Name:	CIpcRetValMsg.h     <br>
	Author:		Ajan U. Nair <br>
	Date:		09/11/07      <br>	
	Revision:	1.0           <br>
	Description:
		This file holds the CIpcManager class definitions.
*/

/*************************************************************************
Nov 11, 07   Ajan U. Nair   Creation, Class definition, adding attributes/functions



*************************************************************************/


#ifndef CIpc_RETURN_VALUE_MSG_H
#define CIpc_RETURN_VALUE_MSG_H

#include "../PTMP/CPtmpBuffer.h"
#include "CIpcRetMsg.h"

namespace Ipc
{
	class CIpcRetValMsg: public CIpcRetMsg
	{
	private:	
		static const bool s_registerStatus;

		Ptmp::CPtmpBuffer m_buffer;

	public:
		CIpcRetValMsg(Ptmp::EPtmpBufferEncoding encoding = Ptmp::ePtmpBufferText);

		inline Ptmp::CPtmpBuffer& getBuffer() { return m_buffer; }

		virtual void serialize(Ptmp::CPtmpBuffer& buffer) const;
		virtual bool deserialize(Ptmp::CPtmpBuffer& buffer);
		static CPtmpMsg* create(Ptmp::CPtmpBuffer& buffer);


	};
}
#endif
