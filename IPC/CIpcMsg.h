
//************************************************************************
//
// � Copyright ------
//  All use, disclosure, and/or reproduction of this material is
//  prohibited unless authorized in writing.
//
//************************************************************************

/*! /file
	File Name:	CIpcMsg.h     <br>
	Author:		Ajan U. Nair <br>
	Date:		09/11/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CIpcManager class definitions.
*/

/*************************************************************************
Nov 11, 07   Ajan U. Nair   Creation, Class definition, adding attributes/functions



*************************************************************************/

#ifndef CIpc_MSG_H
#define CIpc_MSG_H
#include "../PTMP/CPtmpMsg.h"

namespace Ipc
{
	class CIpcMsg		//: public Ptmp::CPtmpMsg
	{
	private:	

		//int m_ipcMsgId;
				
	public:
		
		static const Ptmp::EPtmpMsgType eIpcCallMsg;
		static const Ptmp::EPtmpMsgType eIpcReturnErrMsg;
		static const Ptmp::EPtmpMsgType eIpcReturnValueMsg;
		static const Ptmp::EPtmpMsgType eIpcEventMsg;
		static const Ptmp::EPtmpMsgType eIpcEventSubscribeMsg;
			
	};
}
#endif
