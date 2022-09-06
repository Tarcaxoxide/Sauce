#include<Sauce/Utility/Manipulations.hpp>

namespace Sauce{
	namespace Utility{
        size_t strlen(char* str){
            size_t size=0;
            char* strPtr=str;
            while(*(strPtr++) != '\0'){size++;}
            return size;
        }
        void split(char* path, char delimiter,Sauce::Memory::List_cl<const char*> &result){
            Sauce::Memory::List_cl<char> tmpString;
            size_t strlength=strlen(path);
            for(size_t i=0;i<strlength;i++){
                if(path[i] != delimiter){
                    tmpString.AddLast(path[i]);
                }else{
                    result.AddLast((const char*)tmpString.Raw());
                    tmpString.Clear();
                }
            }
        }
    };
};