#include<stddef.h>
#include<stdint.h>
#pragma once
namespace Sauce{
    namespace Memory{
        namespace Management{
            class PageMapIndexer{
                public:
                PageMapIndexer(uint64_t virtualAddress);
                uint64_t PDP_i;
                uint64_t PD_i;
                uint64_t PT_i;
                uint64_t P_i;
            };
        };
    };
};