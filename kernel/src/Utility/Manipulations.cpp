#include<Sauce/Utility/Manipulations.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
namespace Sauce{
	namespace Utility{
        namespace Manipulate{
            size_t strlen(char* str){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"strlen",_NAMESPACE_,_ALLOW_PRINT_);
                size_t size=0;
                char* strPtr=str;
                while(*(strPtr++) != '\0'){size++;}
                return size;
            }
            bool strcmp(const char* strA,const char* strB){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"strcmp",_NAMESPACE_,_ALLOW_PRINT_);
                if(strlen((char*)strA) != strlen((char*)strB))return false;
                size_t X=strlen((char*)strA);
                while(X){
                    if(strA[X] != strB[X])return false;
                    X--;
                }
                return true;
            }
            Sauce::Memory::List_cl<_std::string> split(_std::string path, char delimiter){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"split",_NAMESPACE_,_ALLOW_PRINT_);
                _std::string tmpString;
                Sauce::Memory::List_cl<_std::string> Result;
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
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"swap_address",_NAMESPACE_,_ALLOW_PRINT_);
                void* tmpPtr=(*AddressA);
                (*AddressA)=(*AddressB);
                (*AddressB)=tmpPtr;
            }
        };
    };
};