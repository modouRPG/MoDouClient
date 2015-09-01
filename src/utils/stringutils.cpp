#include "stringutils.h"
#include <string.h>

static size_t UTF8_MAX_SIZE = 10;

const char* getSafeUtf8String(const std::string text)
{
    const size_t sz = text.size();
    const size_t size = sz + UTF8_MAX_SIZE;
    char *const buf = new char[size];
    memcpy(buf, text.c_str(), sz);
    memset(buf + sz, 0, UTF8_MAX_SIZE);
    return buf;
}
