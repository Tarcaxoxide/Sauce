#pragma once

#include <stdint.h>
#include <stddef.h>


namespace Sauce{
    namespace Utils{
        size_t StringLength(char* string);
        int strCmp(const char* s1, const char* s2);
        bool StringCompare(char* StringA,char* StringB);
    };
};