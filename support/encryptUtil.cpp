#include "encryptUtil.h"
#include "stringUtil.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "md5.h"

char type7_xlat[] = {
        0x64, 0x73, 0x66, 0x64, 0x3b, 0x6b, 0x66, 0x6f,
        0x41, 0x2c, 0x2e, 0x69, 0x79, 0x65, 0x77, 0x72,
        0x6b, 0x6c, 0x64, 0x4a, 0x4b, 0x44, 0x48, 0x53,
		0x55, 0x42, 0x73, 0x67, 0x76, 0x63, 0x61, 0x36, 
		0x39, 0x38, 0x33, 0x34, 0x6e, 0x63, 0x78, 0x76
};
std::string Util::simpleHash(const std::string& text)
{
	std::string hash = text;
	for (unsigned int i=0; i<hash.length(); i++)
		hash[i] = 158 - hash.at(i);
	return hash;
}
std::string Util::md5Digest(const std::string& challenge, const std::string& text)
{
	unsigned char digest[16];
	MD5_CTX ctx;
	MD5Init(&ctx);
	MD5Update(&ctx, (unsigned char*)challenge.c_str(), challenge.length() );
    MD5Update(&ctx, (unsigned char*)text.c_str(), text.length());
	MD5Final(digest, &ctx);

	std::string strDigest;
	for (unsigned int i=0; i<16; i++)
		strDigest += Util::toHex(static_cast<unsigned int>(digest[i]), 2);
	return Util::toUpperCase(strDigest);
}


