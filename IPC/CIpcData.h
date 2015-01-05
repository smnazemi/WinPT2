 
//************************************************************************
//
// Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is
//  prohibited unless authorized in writing.
//
//************************************************************************

/*! /file
	File Name:	CIpcData.h     <br>
	Author:		Michael <br>
	Date:		1/2/2008      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CIpcData class definitions.
*/

/*************************************************************************



*************************************************************************/


#ifndef IPC_CIPCDATA_H
#define IPC_CIPCDATA_H

#include "../PTMP/CPtmpBuffer.h"

namespace Ipc
{
	class CIpcData
	{
	public:
		virtual void ipcDataSerialize(Ptmp::CPtmpBuffer& buffer) const = 0;
	};
}
#endif
