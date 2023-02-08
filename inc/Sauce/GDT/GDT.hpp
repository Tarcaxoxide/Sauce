#include<stddef.h>
#include<stdint.h>
#pragma once
namespace Sauce{
    namespace GDT{
        struct GDTDescriptor_st{
            uint16_t Size;
            uint64_t Offset;
        }__attribute__((packed));
        struct GDTEntry_st{
            uint16_t Limit0;
            uint16_t Base0;
            uint8_t Base1;
            uint8_t AccessByte;
            uint8_t Limit1_Flags;
            uint8_t Base2;
        }__attribute__((packed));
        struct GDT_st{
            GDTEntry_st KernelNull;
            GDTEntry_st KernelCode;
            GDTEntry_st KernelData;
            GDTEntry_st UserNull;
            GDTEntry_st UserCode;
            GDTEntry_st UserData;
        }__attribute__((packed))__attribute((aligned(0x1000)));
        extern "C" void LoadGDT(GDTDescriptor_st* gdtDescriptor);
        extern GDT_st DefaultGDT;
    };
};
