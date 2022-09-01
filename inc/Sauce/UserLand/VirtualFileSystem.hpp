#pragma once

#include<stddef.h>
#include<stdint.h>

#include<Sauce/Memory/DynamicArray.hpp>

namespace Sauce{
    namespace UserLand{

        struct VirtualFile_st{
            Sauce::Memory::List_cl<char> name;
            Sauce::Memory::List_cl<char> Content;
        };
        struct VirtualDirectory_st{
            Sauce::Memory::List_cl<char> name;
            Sauce::Memory::List_cl<VirtualFile_st> Files;
            Sauce::Memory::List_cl<VirtualDirectory_st> SubDirectories;
        };

        struct VirtualFileSystem_st{
            VirtualDirectory_st RootDirectory;
        };
    };
};