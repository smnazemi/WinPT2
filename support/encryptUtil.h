#ifndef UTIL_TYPE7_ENCRYPTION_H_
#define UTIL_TYPE7_ENCRYPTION_H_

#include <string>

namespace Util
{
	std::string md5Digest(const std::string& challenge, const std::string& text);
	std::string simpleHash(const std::string& text);
}

#endif
