//************************************************************************
//
// © Copyright ------
//  All use, disclosure, and/or reproduction of this material is
//  prohibited unless authorized in writing.
//
//************************************************************************

/*! /file
	File Name:	CAuthChallengeMsg.h     <br>
	Author:		Ajan U. Nair <br>
	Date:		10/09/07      <br>
	Revision:	1.0           <br>
	Description:
		This file holds the CPTMPMsg class definitions.
*/

/*************************************************************************
Oct 09, 07   Ajan U. Nair   Creation, Class definition, adding attributes/functions


*************************************************************************/

#ifndef CPtmp_AUTH_CHALLENGE_MSG_H
#define CPtmp_AUTH_CHALLENGE_MSG_H


#include "CPtmpMsg.h" 


static void random_string(int length, char *str);
static char random_number();
static char random_letter(int is_cap);
		
namespace Ptmp
{
	class CAuthChallengeMsg:public CPtmpMsg
	{
	
	public:
		//Srikant
		const static std::string	s_defaultChallengetext;	
		

		CAuthChallengeMsg();//:CPTMPMsg(msgByteArray)
		virtual void serialize(CPtmpBuffer& buffer) const;
		virtual bool deserialize(CPtmpBuffer& buffer);
		static CPtmpMsg* create(CPtmpBuffer& buffer);
		
//		std::string static createNewChallengetext();

		std::string	getChallengetext();
		void	setChallengetext(std::string challengetext);
		
	private:
		
		std::string m_Challengetext;
		
		// temp variables for registering msg creation
		const static bool s_registerStatus;    


	};
}

#endif

