#include<Sauce/Storage/FileSystem/FAT.hpp>
#include<Sauce/Storage/AHCI.hpp>
#include<Sauce/Global.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
    namespace Storage{
        namespace FileSystem{
            namespace FAT{
                FAT32_cl::FAT32_cl(size_t Port){
                    Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"FAT32_cl::FAT32_cl",_NAMESPACE_,_ALLOW_PRINT_);
                    
                }
            };
        };
    };
};