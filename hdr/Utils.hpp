#pragma once

#include <stdint.h>
#include <stddef.h>
#include <Memory.hpp>


namespace Sauce{
    namespace Utils{
        size_t StringLength(char* string);
        int strCmp(const char* s1, const char* s2);
        bool StringCompare(char* StringA,char* StringB);
        char* CombinedStrings(char* StringA,char* StringB);
        size_t split(char* str, char delim,char** res);
        char *strtok(char *str, char *delimiter);
    };
};