#ifndef __Sauce_Memory_PageMapIndexer
#define __Sauce_Memory_PageMapIndexer
#include<stddef.h>
#include<stdint.h>
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
#endif