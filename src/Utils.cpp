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
        void split(char* str, char d, char** into) {
            if(str != NULL && into != NULL){
                int n = 0;
                int c = 0;
                for(int i = 0; str[c] != '\0'; i++,c++)
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
