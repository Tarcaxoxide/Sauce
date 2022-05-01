#include<Sauce/GDT/GDT.hpp>


namespace Sauce{
    namespace GDT{
        __attribute__((aligned(0x1000)))
        GDT_st DefaultGDT = {
            {0,0,0,0x00,0x00,0}, //KernelNull
            {0,0,0,0x9a,0xa0,0}, //KernelCode
            {0,0,0,0x92,0xa0,0}, //KernelData
            {0,0,0,0x00,0x00,0}, //UserNull
            {0,0,0,0x9a,0xa0,0}, //UserCode (Please remove from ring 0)
            {0,0,0,0x92,0xa0,0}, //UserData (Please remove from ring 0)
        };
    };
};