#pragma once

#include<stddef.h>
#include<stdint.h>

namespace Sauce{
    struct GDTDescriptor{
        uint16_t Size;
        uint64_t Offset;
    }__attribute__((packed));
};