#pragma once

#include <stdint.h>
#include <stddef.h>
#include <Terminal.hpp>
#include <Convert.hpp>
#include <Utils.hpp>

namespace Sauce{
    namespace Filesystem{
        struct _File{
            static const uint64_t NAME_SIZE=25;
            uint64_t ID; // this is like linux's "inodes" (I think).
            uint64_t Sector;
            uint64_t* AddressOnDisk=NULL;
            char Name[NAME_SIZE];
        };

        void Initialize_Filesystem();
        void Add_File(uint64_t Sector,char Name[25]);
    };
};