#pragma once

#include<stddef.h>
#include<stdint.h>

namespace Sauce{
        namespace GDT{
        struct GDTDescriptor_t{
            uint16_t Size;
            uint64_t Offset;
        }__attribute__((packed));
        struct GDTEntry_t{
            uint16_t Limit0;
            uint16_t Base0;
            uint8_t Base1;
            uint8_t AccessByte;
            uint8_t Limit1_Flags;
            uint8_t Base2;
        }__attribute__((packed));
        struct GDT_t{
            GDTEntry_t KernelNull;
            GDTEntry_t KernelCode;
            GDTEntry_t KernelData;
            GDTEntry_t UserNull;
            GDTEntry_t UserCode;
            GDTEntry_t UserData;
        }__attribute__((packed))__attribute((aligned(0x1000)));
        extern "C" void LoadGDT(GDTDescriptor_t* gdtDescriptor);
        extern GDT_t DefaultGDT;
    };
};