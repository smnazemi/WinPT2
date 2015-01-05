#ifndef UTIL_STRINGUTIL_H_
#define UTIL_STRINGUTIL_H_

#include "engine.h"
#include <string>
#include <vector>

namespace Util
{
	std::string spaces(uint count);

	std::string trim(const std::string& str);
	std::string trimLeft(const std::string& str);
	std::string trimRight(const std::string& str);

	std::string replace(const std::string& str, const std::string& findStr, const std::string& replaceStr);

	std::string pad(const std::string& str, uint width, char chr = ' ');
	std::string padLeft(const std::string& str, uint width, char chr = ' ');

	int indexOfDigit(const std::string& str, uint index = 0);

	std::string toLowerCase(const std::string& str);
	std::string toUpperCase(const std::string& str);

	int diff(const std::string& str1, const std::string& str2);
	bool isPartOf(const std::string& str1, const std::string& str2);

	std::string getQuotedWord(const std::string& str);

	std::string vectorOfPairsToString(const std::vector<std::pair<unsigned int, unsigned int> >& value);
	std::vector<std::pair<unsigned int, unsigned int> > stringToVectorOfPairs(const std::string& value);

	std::string toHex(unsigned int num, unsigned int padTo);

	int hctoi(char chr);

	std::string toFormattedTime(unsigned int sec);
	std::string toFormattedTimeNoComma(unsigned int sec);
	
	std::string fromVec(std::vector<std::string>& strVec, std::string delim);
}

#endif
