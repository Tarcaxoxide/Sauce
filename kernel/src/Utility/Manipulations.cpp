#include<Sauce/Utility/Manipulations.hpp>

namespace Sauce{
	namespace Utility{
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
        Sauce::Memory::List_cl<char*> split(char* path, char delimiter){
            Sauce::string tmpString;
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
        Sauce::Memory::List_cl<Sauce::string> split(Sauce::string path, char delimiter){
            Sauce::string tmpString;
            Sauce::Memory::List_cl<Sauce::string> Result;

            for(size_t i=0;i<path.Size();i++){
                if(path[i] != delimiter){
                    tmpString.AddLast(path[i]);
                }else{
                    Result.AddLast(tmpString);
                    tmpString.Clear();
                }
            }
            return Result;
        }
        Sauce::Memory::List_cl<Sauce::Memory::List_cl<wchar_t>> split(Sauce::Memory::List_cl<wchar_t> path, wchar_t delimiter){
            Sauce::Memory::List_cl<wchar_t> tmpString;
            Sauce::Memory::List_cl<Sauce::Memory::List_cl<wchar_t>> Result;

            for(size_t i=0;i<path.Size();i++){
                if(path[i] != delimiter){
                    tmpString.AddLast(path[i]);
                }else{
                    Result.AddLast(tmpString);
                    tmpString.Clear();
                }
            }
            return Result;
        }
        void swap_address(void** AddressA,void** AddressB){
            void* tmpPtr=(*AddressA);
            (*AddressA)=(*AddressB);
            (*AddressB)=tmpPtr;
        }
    };
};