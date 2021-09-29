#include <Utils.hpp>

namespace Sauce{
    namespace Utils{
        size_t String_Length(char* string){
            size_t Result = 0;
            for(Result = 0;string[Result] != '\0';Result++);
            return Result;
        }
        int String_Compare(const char* s1, const char* s2){
            while(*s1 && (*s1 == *s2))
            {
                s1++;
                s2++;
            }
            return *(const unsigned char*)s1 - *(const unsigned char*)s2;
        }
        bool String_Compare_ReturnBool(char* StringA,char* StringB){
            return (String_Compare((const char*)StringA,(const char*)StringB) == 0);
        }
        char* Combined_Strings(char* StringA,char* StringB){
            size_t SizeA=String_Length(StringA);
            size_t SizeB=String_Length(StringB);
            size_t Size=SizeA+SizeB;
            char NewString[Size];
            size_t Counter=0;
            for(size_t I=0;I<SizeA;I++){
                NewString[Counter++]=StringA[I];
            }
            for(size_t I=0;I<SizeB;I++){
                NewString[Counter++]=StringB[I];
            }
            return NewString; // warning: address of local variable 'NewString' returned [-Wreturn-local-addr]
        }
        size_t Split(char* str, char d, char** into) {
            size_t n = 0;
            size_t c = 0;
            if(str != NULL && into != NULL){
                for(size_t i = 0; str[c] != '\0'; i++,c++)
                {
                    into[n][i] = str[c];
                    if(str[c] == d)
                    {
                        into[n][i] = '\0';
                        i = -1;
                        ++n;
                    }
                }
            }
            return n;
        }
        static char *TmpPtr = NULL;
        char *String_Tokenizer(char *str, char *delimiter){
            char *final_ptr = NULL;
            static int flag = 0;
            int i, j;
            if (delimiter == NULL) {
                return NULL;
            }
            if (flag == 1) {
                return NULL;
            }
            if (str != NULL) { 
                TmpPtr = str; 
            }
            final_ptr = TmpPtr;
            for (i = 0; i <= String_Length(TmpPtr); i++)
            {
                for (j = 0; j < String_Length(delimiter); j++) {
                
                    if (TmpPtr[i] == '\0') {
                        flag = 1;
                        return final_ptr;
                    }
                    if ((TmpPtr[i] == delimiter[j])) {
                        TmpPtr[i] = '\0';
                        TmpPtr += i+1;
                        return final_ptr;
                    }
                }
            }
            return NULL;
        }
    };
};
