#include "stringUtil.h"
#include "stringConvert.h"
#include <qstring.h>

using namespace std;

string Util::spaces(uint count)
{
	static const string s_spaces = "                                                                                ";
	static const uint s_size = s_spaces.size();
	if (count <= s_size)
		return s_spaces.substr(0, count);

	string str;
	for (; count > s_size; count -= s_size)
		str += s_spaces;
	str += s_spaces.substr(0, count);

	return str;
}

string Util::trim(const string& str)
{
	return trimRight(trimLeft(str));
}

string Util::trimLeft(const string& str)
{
	int index = str.find_first_not_of(" ");
	if ((index == -1) && (str.size() != 0) && (str.at(0) == ' '))
		return "";
	return (index > 0) ? str.substr(index) : str;
}

string Util::trimRight(const string& str)
{
	int index = str.find_last_not_of(" ");
	if ((index == -1) && (str.size() != 0) && (str.at(0) == ' '))
		return "";
	return (index >= 0) ? str.substr(0, index + 1) : str;
}

string Util::replace(const string& originalStr, const string& findStr, const string& replaceStr)
{
	string str = originalStr;
	uint findSize = findStr.size();
	uint replaceSize = replaceStr.size();
	uint index = 0;

	while ((index = str.find(findStr, index)) != string::npos)
	{
		str.replace(index, findSize, replaceStr);
		index += replaceSize;
	}

	return str;
}

string Util::pad(const string& str, uint width, char chr)
{
	if (width <= str.size())
		return str;

	if (chr == ' ')
		return str + spaces(width - str.size());

	string newStr = str;
	for (unsigned int i=width - str.size(); i>0; i--)
		newStr += chr;

	return newStr;
}

string Util::padLeft(const string& str, uint width, char chr)
{
	if (width <= str.size())
		return str;

	if (chr == ' ')
		return spaces(width - str.size()) + str;

	string newStr = "";
	for (unsigned int i=width - str.size(); i>0; i--)
		newStr += chr;

	return newStr + str;
}

int Util::indexOfDigit(const std::string& str, uint index)
{
	static const string s_digits = "0123456789";
	return str.find_first_of(s_digits, index);
}

string Util::toLowerCase(const std::string& originalStr)
{
	string str = originalStr;
	char* chr;
	
	for (uint i=0; i<str.size(); i++)
	{
		chr = &str.at(i);
		if ((*chr >= 'A') && (*chr <= 'Z'))
			*chr += 32;
	}

	return str;
}

string Util::toUpperCase(const std::string& originalStr)
{
	string str = originalStr;
	char* chr;
	
	for (uint i=0; i<str.size(); i++)
	{
		chr = &str.at(i);
		if ((*chr >= 'a') && (*chr <= 'z'))
			*chr -= 32;
	}

	return str;
}

int Util::diff(const std::string& str1, const std::string& str2)
{
	uint size1 = str1.size();
	uint size2 = str2.size();
	uint len = (size1 < size2) ? size1 : size2;

	for (uint i=0; i<len; i++)
		if (str1.at(i) != str2.at(i))
			return i;

	if (size1 != size2)
		return len;
	else
		return -1;
}

bool Util::isPartOf(const std::string& str1, const std::string& str2)
{
	uint size1 = str1.size();
	if ((size1 > str2.size()) || (size1 == 0))
		return false;

	for (uint i=0; i<size1; i++)
		if (str1.at(i) != str2.at(i))
			return false;

	return true;
}

std::string Util::getQuotedWord(const std::string& str)
{
	return (str.find(" ") == -1)
		? str
		: ("\"" + str + "\"");
}


std::string Util::vectorOfPairsToString(const std::vector<std::pair<unsigned int, unsigned int> >& value)
{
	if (value.size() == 0)
		return "";

	std::string str;

	for (unsigned int i=0; i<value.size(); i++)
	{
		str += toString(value.at(i).first);
		if (value.at(i).first != value.at(i).second)
			str += "-" + toString(value.at(i).second);
		str += ",";
	}

	return str.substr(0, str.size() - 1);
}

std::vector<std::pair<unsigned int, unsigned int> > Util::stringToVectorOfPairs(const std::string& value)
{
	std::vector<std::pair<unsigned int, unsigned int> > vec;
	std::pair<unsigned int, unsigned int> pairOfTwoInt;
	const char* str = value.c_str();
	unsigned int oldNum = 0;

	//////to check if there is a cama at the end or beginning of the string.
	unsigned int i = value.size();
	i--;
	if ((value.at(i) == ',') || (value.at(0) == ','))
		throw Util::CInvalidConversion(std::string("stringToVectorOfPairs(" + value + ")"));
	/////////

	while (*str) //while not end of the string \0
	{
		unsigned int num = 0;
		while ((*str >= '0') && (*str <= '9'))
		{
			num = (num * 10 + (*str - '0'));
			str++;
		}

		//num is none zero
		if (!num)
		{
			throw Util::CInvalidConversion(std::string("stringToVectorOfPairs(" + value + ")"));
//			vec.clear();		
//			break;
		}

		//!*str means even if we are at the end of the string \0 we could replace it with (*str == 0)
		if ((*str == ',') || (!*str)) 
		{
			if (*str) 
				str++;
			if (oldNum)
			{
				pairOfTwoInt.first = oldNum;
				pairOfTwoInt.second = num;
				
				if ( pairOfTwoInt.second < pairOfTwoInt.first )
				{
					throw Util::CInvalidConversion(std::string("stringToVectorOfPairs(" + value + ")"));
//					vec.empty();
//					return vec;
				}
				else
				{
					vec.push_back(pairOfTwoInt);
					oldNum = 0;
					continue; //back to the loop
				}
			}
			pairOfTwoInt.first = num;
			pairOfTwoInt.second = num;
			vec.push_back(pairOfTwoInt);
			continue; //back to the loop
		}
		if ( *str == '-' )
		{
			if (oldNum)
			{
				throw Util::CInvalidConversion(std::string("stringToVectorOfPairs(" + value + ")"));
//				vec.clear();
//				break;
			}
			oldNum = num;
			str++ ;
			continue;
		}
		break;
		
	}
	
	return vec;
}

std::string Util::toHex(unsigned int num, unsigned int padTo)
{
//	std::string str(QString::number(num, 16).ascii());
	std::string str(QString::number(num, 16).toAscii());
	
	while (str.size() < padTo)
		str.insert(0, "0");

	return str;
}

int Util::hctoi(char chr)
{
	return
		((chr >= '0') && (chr <= '9'))
			? (chr - '0')
		: ((chr >= 'A') && (chr <= 'F'))
			? (chr - 'A' + 10)
		: ((chr >= 'a') && (chr <= 'f'))
			? (chr - 'a' + 10)
		: -1;
}


std::string Util::toFormattedTime(unsigned int seconds)
{
	unsigned int hours = seconds / 3600;
	seconds %= 3600;
	unsigned int minutes = seconds / 60;
	seconds %= 60;
	return ( Util::padLeft(Util::toString<unsigned int>( hours ), 2, '0') + ":" +
			 Util::padLeft(Util::toString<unsigned int>( minutes ), 2, '0') + ":" +
			 Util::padLeft(Util::toString<unsigned int>( seconds ), 2, '0') + ", " );
}

std::string Util::toFormattedTimeNoComma(unsigned int seconds)
{
	unsigned int hours = seconds / 3600;
	seconds %= 3600;
	unsigned int minutes = seconds / 60;
	seconds %= 60;
	return ( Util::padLeft(Util::toString<unsigned int>( hours ), 2, '0') + ":" +
			 Util::padLeft(Util::toString<unsigned int>( minutes ), 2, '0') + ":" +
			 Util::padLeft(Util::toString<unsigned int>( seconds ), 2, '0') + " ");
}
//Put in ~ as delimiter and then get them back in case of running/start Config
std::string Util::fromVec(std::vector<std::string>& strVec, std::string delim)
{
	std::vector<std::string>::iterator it = strVec.begin();
	std::string strConfig;
	for(; it !=	strVec.end(); it++)
	{
		strConfig += *it;
		strConfig += delim;
	}
	return strConfig;
}

/*
class StringTokenizer
{

   public:

    StringTokenizer(const std::string& _str, const std::string& _delim);
   ~StringTokenizer(){};

    int         countTokens();
    bool        hasMoreTokens();
    std::string nextToken();
    int         nextIntToken();
    double      nextFloatToken();
    std::string nextToken(const std::string& delim);
    std::string remainingString();
    std::string filterNextToken(const std::string& filterStr);

   private:

    std::string  token_str;
    std::string  delim;

};

StringTokenizer::StringTokenizer(const std::string& _str, const std::string& _delim)
{

   if ((_str.length() == 0) || (_delim.length() == 0)) return;

   token_str = _str;
   delim     = _delim;

//     Remove sequential delimiter
   unsigned int curr_pos = 0;

   while(true)
   {
      if ((curr_pos = token_str.find(delim,curr_pos)) != std::string::npos)
      {
         curr_pos += delim.length();

         while(token_str.find(delim,curr_pos) == curr_pos)
         {
            token_str.erase(curr_pos,delim.length());
         }
      }
      else
       break;
   }

//     Trim leading delimiter
   if (token_str.find(delim,0) == 0)
   {
      token_str.erase(0,delim.length());
   }

//     Trim ending delimiter
   curr_pos = 0;
   if ((curr_pos = token_str.rfind(delim)) != std::string::npos)
   {
      if (curr_pos != (token_str.length() - delim.length())) return;
      token_str.erase(token_str.length() - delim.length(),delim.length());
   }

}


int StringTokenizer::countTokens()
{

   unsigned int prev_pos = 0;
   int num_tokens        = 0;

   if (token_str.length() > 0)
   {
      num_tokens = 0;

      unsigned int curr_pos = 0;
      while(true)
      {
         if ((curr_pos = token_str.find(delim,curr_pos)) != std::string::npos)
         {
            num_tokens++;
            prev_pos  = curr_pos;
            curr_pos += delim.length();
         }
         else
          break;
      }
      return ++num_tokens;
   }
   else
   {
      return 0;
   }

}


bool StringTokenizer::hasMoreTokens()
{
   return (token_str.length() > 0);
}


std::string StringTokenizer::nextToken()
{

   if (token_str.length() == 0)
     return "";

   std::string  tmp_str = "";
   unsigned int pos     = token_str.find(delim,0);

   if (pos != std::string::npos)
   {
      tmp_str   = token_str.substr(0,pos);
      token_str = token_str.substr(pos+delim.length(),token_str.length()-pos);
   }
   else
   {
      tmp_str   = token_str.substr(0,token_str.length());
      token_str = "";
   }

   return tmp_str;
}


int StringTokenizer::nextIntToken()
{
   return atoi(nextToken().c_str());
}


double StringTokenizer::nextFloatToken()
{
   return atof(nextToken().c_str());
}


std::string StringTokenizer::nextToken(const std::string& delimiter)
{
   if (token_str.length() == 0)
     return "";

   std::string  tmp_str = "";
   unsigned int pos     = token_str.find(delimiter,0);

   if (pos != std::string::npos)
   {
      tmp_str   = token_str.substr(0,pos);
      token_str = token_str.substr(pos + delimiter.length(),token_str.length() - pos);
   }
   else
   {
      tmp_str   = token_str.substr(0,token_str.length());
      token_str = "";
   }

   return tmp_str;
}


std::string StringTokenizer::remainingString()
{
   return token_str;
}


std::string StringTokenizer::filterNextToken(const std::string& filterStr)
{
   std::string  tmp_str    = nextToken();
   unsigned int currentPos = 0;

   while((currentPos = tmp_str.find(filterStr,currentPos)) != std::string::npos)
   {
      tmp_str.erase(currentPos,filterStr.length());
   }

   return tmp_str;
}
*/
