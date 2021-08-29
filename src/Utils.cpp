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
            return (strCmp((const char*)StringA,(const char*)StringB) == 0);
        }
        char* CombinedStrings(char* StringA,char* StringB){
            size_t SizeA=StringLength(StringA);
            size_t SizeB=StringLength(StringB);
            size_t Size=SizeA+SizeB;
            char NewString[Size];
            size_t Counter=0;
            for(size_t I=0;I<SizeA;I++){
                NewString[Counter++]=StringA[I];
            }
            for(size_t I=0;I<SizeB;I++){
                NewString[Counter++]=StringB[I];
            }
            return NewString;
        }
        size_t split(char* str, char delim,char** res) {

            char tmstr[500];
            size_t tmstrCounter=0;
            size_t nspaces=0;
            for(size_t II=0;II<StringLength(tmstr);II++){
                tmstr[II]=0;
            }
            for(size_t I=0;I<StringLength(str);I++){
                if(str[I] != delim){
                    tmstr[tmstrCounter++]=str[I];
                }else{
                    tmstr[tmstrCounter++]=0;
                    res[nspaces++]=tmstr;
                    tmstrCounter=0;
                    for(size_t II=0;II<StringLength(tmstr);II++){
                        tmstr[II]=0;
                    }
                }
            }
            return nspaces;
        }
        static char *temp_ptr = NULL;
        char *strtok(char *str, char *delimiter){
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
                temp_ptr = str; 
            }
            final_ptr = temp_ptr;
            for (i = 0; i <= StringLength(temp_ptr); i++)
            {
                for (j = 0; j < StringLength(delimiter); j++) {
                
                    if (temp_ptr[i] == '\0') {
                        flag = 1;
                        return final_ptr;
                    }
                    if ((temp_ptr[i] == delimiter[j])) {
                        temp_ptr[i] = '\0';
                        temp_ptr += i+1;
                        return final_ptr;
                    }
                }
            }
            return NULL;
        }
    };
};
