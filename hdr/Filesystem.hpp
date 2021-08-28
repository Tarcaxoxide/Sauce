#pragma once

#include <stdint.h>
#include <stddef.h>
#include <Terminal.hpp>
#include <Convert.hpp>
#include <Utils.hpp>

namespace Sauce{
    namespace Filesystem{
        struct _File{
            uint64_t ID;
            uint64_t Sector;
            uint64_t* AddressOnDisk=NULL;
            static const uint64_t NAME_SIZE=25;
            char Name[NAME_SIZE];
        };

        void InitializeFilesystem();
        void AddFile(uint64_t Sector,char Name[25]);
    };
};