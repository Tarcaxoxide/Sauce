#include <Utils.hpp>

namespace Sauce{
    namespace Utils{
        static char *temp_ptr = NULL;


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
        char** split(char* str, char* delim) {
            char** res = NULL;
            char* p = strtok(str, delim);
            int nspaces = 0, i;
            while(p) {
                if(res != NULL){
                    res = (char**)Sauce::Memory::realloc(res, sizeof(char*) * ++nspaces);
                }else{
                    res = (char**)Sauce::Memory::alloc(sizeof(char*) * ++nspaces);
                }
                if(res == NULL) {
                    //fprintf(stderr, "out of memory.\n");
                    Sauce::Terminal::String("out of memory.\n");
                    //exit(1);
                }
                res[nspaces-1] = p;

                p = strtok(NULL, delim);
            }

            res = (char**)Sauce::Memory::realloc(res, sizeof(char*) * (nspaces+1));
            res[nspaces] = 0;

            return res;
        }
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
