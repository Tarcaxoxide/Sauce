#pragma once
#include<stddef.h>
#include<stdint.h>

namespace Sauce{
    struct PageDirectoryEntry{
        bool Present : 1; // Does the page exist?
        bool ReadWrite : 1; // Can it be both read and written to?
        bool UserSuper : 1; // UserUser access only?
        bool WriteThrough : 1;
        bool CacheDisabled : 1;
        bool Accessed : 1; // Set to 1 when the cpu access it.
        bool ignore0 : 1; // can't use
        bool LargerPages : 1; //turns the next page directory table into a page the size of what the page directory would have held.
        bool ignore1 : 1; // can't use
        uint8_t Available : 3; // Available for me to use in whatever way i want.
        uint64_t Address : 52;
    };

    struct PageTable{
        PageDirectoryEntry entries[512];
    }__attribute__((aligned(0x1000)));
};