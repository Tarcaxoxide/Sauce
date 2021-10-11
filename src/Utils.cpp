#include <Utils.hpp>

namespace Sauce{
    namespace Utils{
        size_t String_Length(const char* string){
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
            char* NewString = new char[Size];
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
            size_t i, j;
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
        bool Is_White_Space(char value){
            switch(value){
                case ' ':
                case '\n':
                case '\t':
                case '\r':return true;
            }
            return false;
        }
        bool Is_Alpha_Numeric(char value){
            return (Is_Alpha(value) || Is_Numeric(value));
        }
        bool Is_Numeric(char value){
            switch(value){
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case '0':return true;
            }
            return false;
        }
        bool Is_Alpha(char value){
            switch(value){
                case 'a':
                case 'b':
                case 'c':
                case 'd':
                case 'e':
                case 'f':
                case 'g':
                case 'h':
                case 'i':
                case 'j':
                case 'k':
                case 'l':
                case 'm':
                case 'n':
                case 'o':
                case 'p':
                case 'q':
                case 'r':
                case 's':
                case 't':
                case 'u':
                case 'v':
                case 'w':
                case 'x':
                case 'y':
                case 'z':return true;
            }
            switch(value){
                case 'A':
                case 'B':
                case 'C':
                case 'D':
                case 'E':
                case 'F':
                case 'G':
                case 'H':
                case 'I':
                case 'J':
                case 'K':
                case 'L':
                case 'M':
                case 'N':
                case 'O':
                case 'P':
                case 'Q':
                case 'R':
                case 'S':
                case 'T':
                case 'U':
                case 'V':
                case 'W':
                case 'X':
                case 'Y':
                case 'Z':return true;
            }
            return false;
        }
    };
};
