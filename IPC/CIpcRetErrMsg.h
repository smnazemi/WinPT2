
//************************************************************************
//
// � Copyright ------
//  All use, disclosure, and/or reproduction of this material is
//  prohibited unless authorized in writing.
//
//************************************************************************

/*! /file
	File Name:	CIpcRetErrMsg.h     <br>
	Author:		Ajan U. Nair <br>
	Date:		09/11/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CIpcManager class definitions.
*/

/*************************************************************************
Nov 11, 07   Ajan U. Nair   Creation, Class definition, adding attributes/functions



*************************************************************************/


#ifndef CIpc_RETURN_ERR_MSG_H
#define CIpc_RETURN_ERR_MSG_H

#include "CIpcRetMsg.h"

namespace Ipc
{
	class CIpcRetErrMsg: public CIpcRetMsg
	{
	private:	
		static const bool s_registerStatus;
		std::string m_className;
		std::string m_error;
				
	public:
		CIpcRetErrMsg(const std::string& className = "", const std::string& error = "");

		inline std::string getClassName() { return m_className; }
		inline std::string getErrorInfo() { return m_error; }

		virtual void serialize(Ptmp::CPtmpBuffer& buffer) const;
		virtual bool deserialize(Ptmp::CPtmpBuffer& buffer);
		static CPtmpMsg* create(Ptmp::CPtmpBuffer& buffer);
				

	};
}
#endif
