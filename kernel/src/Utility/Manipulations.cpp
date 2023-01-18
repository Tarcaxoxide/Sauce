#include<Sauce/Utility/Manipulations.hpp>

namespace Sauce{
	namespace Utility{
        namespace Manipulate{
            size_t strlen(char* str){
                size_t size=0;
                char* strPtr=str;
                while(*(strPtr++) != '\0'){size++;}
                return size;
            }
            bool strcmp(const char* strA,const char* strB){
                if(strlen((char*)strA) != strlen((char*)strB))return false;
                size_t X=strlen((char*)strA);
                while(X){
                    if(strA[X] != strB[X])return false;
                    X--;
                }
                return true;
            }
            Sauce::Memory::List_cl<std::string> split(std::string path, char delimiter){
                std::string tmpString;
                Sauce::Memory::List_cl<std::string> Result;

                for(size_t i=0;i<path.Size();i++){
                    if(path[i] != delimiter){
                        tmpString.AddLast(path[i]);
                    }else{
                        Result.AddLast(tmpString);
                        tmpString.Clear();
                    }
                }
                Result.AddLast(tmpString);
                tmpString.Clear();
                return Result;
            }
            void swap_address(void** AddressA,void** AddressB){
                void* tmpPtr=(*AddressA);
                (*AddressA)=(*AddressB);
                (*AddressB)=tmpPtr;
            }
        };
    };
};