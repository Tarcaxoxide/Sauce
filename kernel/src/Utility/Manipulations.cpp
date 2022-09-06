#include<Sauce/Utility/Manipulations.hpp>

namespace Sauce{
	namespace Utility{
        size_t strlen(char* str){
            size_t size=0;
            char* strPtr=str;
            while(*(strPtr++) != '\0'){size++;}
            return size;
        }
        Sauce::Memory::List_cl<char*> split(char* path, char delimiter){
            Sauce::Memory::List_cl<char> tmpString;
            Sauce::Memory::List_cl<char*> Result;

            size_t strlength=strlen(path);
            for(size_t i=0;i<strlength;i++){
                if(path[i] != delimiter){
                    tmpString.AddLast(path[i]);
                }else{
                    Result.AddLast((char*)tmpString.Raw());
                    tmpString.Clear();
                }
            }
            return Result;
        }
    };
};