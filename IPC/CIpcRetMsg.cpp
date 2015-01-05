#include "CIpcRetMsg.h"

using namespace Ipc;
using namespace Ptmp;

CIpcRetMsg::CIpcRetMsg(Ptmp::EPtmpMsgType msgType)
: CPtmpMsg(msgType)
{
	m_callId = 0;
//	m_status = 0;
}

/*
const bool CIpcRetValMsg::s_registerStatus = CPtmpMsg::registerCreation(CIpcMsg::eIpcReturnValueMsg, &CIpcRetValMsg::create);


CIpcRetValMsg::CIpcRetValMsg(Ptmp::EPtmpBufferEncoding encoding)
: CPtmpMsg(CIpcMsg::eIpcReturnValueMsg),
m_buffer(ePtmpBufferReadWrite, encoding)
{
}
*/

void CIpcRetMsg::serialize(Ptmp::CPtmpBuffer& buffer) const
{
	CPtmpMsg::serialize(buffer);
	buffer.write(m_callId);
}

bool CIpcRetMsg::deserialize(Ptmp::CPtmpBuffer& buffer)
{
	if (!CPtmpMsg::deserialize(buffer))
		return false;

	try
	{
		m_callId = buffer.readInt();
	}
	catch (CPtmpBufferError error)
	{
		return false;
	}

	return true;
}

/*
CPtmpMsg* CIpcRetValMsg::create(Ptmp::CPtmpBuffer& buffer)
{
	CIpcRetValMsg* msg = new CIpcRetValMsg();
	if (msg->deserialize(buffer))
		return msg;

	delete msg;
	return NULL;
}
*/
