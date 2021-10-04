#pragma once
#include <Misc.hpp>
#include <stdint.h>
#include <stddef.h>
#include <Memory.hpp>



namespace Sauce{
    namespace Utils{
        size_t String_Length(char* string);
        int String_Compare(const char* s1, const char* s2);
        bool String_Compare_ReturnBool(char* StringA,char* StringB);
        char* Combined_Strings(char* StringA,char* StringB);
        size_t Split(char* str, char d, char** into);
        char *String_Tokenizer(char *str, char *delimiter);
        bool Is_White_Space(char value);
        bool Is_Alpha_Numeric(char value);
        bool Is_Numeric(char value);
        bool Is_Alpha(char value);
    };
};