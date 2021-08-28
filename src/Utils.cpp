#include <Utils.hpp>

namespace Sauce{
    namespace Utils{
        size_t StringLength(char* string){
            size_t Result = 0;
            for(Result = 0;string[Result] != '\0';Result++);
            return Result;
        }
        int strCmp(const char* s1, const char* s2){
            while(*s1 && (*s1 == *s2))
            {
                s1++;
                s2++;
            }
            return *(const unsigned char*)s1 - *(const unsigned char*)s2;
        }
        bool StringCompare(char* StringA,char* StringB){
            return (strCmp((const char*)StringA,(const char*)StringB) == 0); // I don't care which character in the string does not match. does the string match or not was the question :)
        }
    };
};
