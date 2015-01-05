//************************************************************************
//
// Copyright Cisco Systems, All Rights Reserved.
//  All use, disclosure, and/or reproduction of this material is 
//  prohibited unless authorized in writing. 
//
//************************************************************************

/*! /file
	File Name:	CAuthChallengeMsg.cpp     <br>
	Author:		Ajan U. Nair <br>
	Date:		10/09/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CAuthChallengeMsg class definitions.
*/

/*************************************************************************
Oct 09, 07   Ajan U. Nair   Creation, Class definition, adding attributes/functions



*************************************************************************/

#include "CAuthChallengeMsg.h"
using namespace std;
using namespace Ptmp;

const bool CAuthChallengeMsg::s_registerStatus = CPtmpMsg::registerCreation(ePtmpAuthChallenge, &CAuthChallengeMsg::create);

//Srikant
const  std::string	CAuthChallengeMsg::s_defaultChallengetext = "CHALLENGE";

CAuthChallengeMsg::CAuthChallengeMsg():CPtmpMsg(ePtmpAuthChallenge)
{
	//TODO: init member variables
	m_Challengetext= s_defaultChallengetext;	//Srikant
}

void CAuthChallengeMsg::serialize(CPtmpBuffer& buffer) const
{
	CPtmpMsg::serialize(buffer);
	buffer.write(m_Challengetext);
}

bool CAuthChallengeMsg::deserialize(CPtmpBuffer& buffer)
{
	try
	{
		if (!CPtmpMsg::deserialize(buffer))
			return false;

		m_Challengetext=buffer.readString();
		
	}
	catch (CPtmpBufferError error)
	{
		return false;
	}

	return true;
}


CPtmpMsg* CAuthChallengeMsg::create(CPtmpBuffer& buffer)
{
	CAuthChallengeMsg* msg = new CAuthChallengeMsg();
	if (msg->deserialize(buffer))
		return msg;

	delete msg;
	return NULL;
}

/*
string CAuthChallengeMsg::createNewChallengetext()
{
	static char random_str[STRING_SIZE + 1];
//	srand((unsigned)time(NULL));
	random_str[STRING_SIZE] = '\0';
	random_string(STRING_SIZE, random_str);
	
	return (string) random_str;
}
*/
string	CAuthChallengeMsg::getChallengetext()
{
	return m_Challengetext;
}
void CAuthChallengeMsg::setChallengetext(string challengetext)
{
	m_Challengetext = challengetext;
	
}
/*
 char random_letter(int is_cap)
{
		int letter = (int)(LETTER * (rand() / (RAND_MAX + 1.0)));
		return((char)((is_cap == 1) ? (letter + 65) : (letter + 97)));
}

 char random_number()
{
		int number = (int)(NUMBER * (rand() / (RAND_MAX + 1.0)));
		return((char)(number + 48));
}

 void random_string(int length, char *str)
{
		int i;
		int char_type;

		for(i = 0; i < length; i++)
		{
				char_type = (int)(3 * (rand() / (RAND_MAX + 1.0)));

				switch(char_type)
				{
						case 0:
								str[i] = random_letter(0);
								break;
						case 1:
								str[i] = random_letter(1);
								break;
						case 2:
								str[i] = random_number();
								break;
						default:
								str[i] = random_number();
								break;
				}
		}
}
*/
