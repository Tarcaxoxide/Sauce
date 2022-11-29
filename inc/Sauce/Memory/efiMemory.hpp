#pragma once

#include<Sauce/Math/Types.hpp>

namespace Sauce{
    namespace Memory{
        struct EFI_MEMORY_DESCRIPTOR{
            uint32_t type;
            void* physAddr=nullptr;
            void* virtAddr=nullptr;
            uint64_t numPages;
            uint64_t attribs;
        };
        extern const char* EFI_MEMORY_TYPE_STRINGS[];
        enum EfiMemoryType: size_t{
            EfiMemoryType_EfiReservedMemoryType=0,
            EfiMemoryType_EfiLoaderCode,
            EfiMemoryType_EfiLoaderData,
            EfiMemoryType_EfiBootServicesCode,
            EfiMemoryType_EfiBootServicesData,
            EfiMemoryType_EfiRuntimeServicesCode,
            EfiMemoryType_EfiRuntimeServicesData,
            EfiMemoryType_EfiConventionalMemory,
            EfiMemoryType_EfiUnusableMemory,
            EfiMemoryType_EfiACPIReclaimMemory,
            EfiMemoryType_EfiACPIMemoryNVS,
            EfiMemoryType_EfiMemoryMappedIO,
            EfiMemoryType_EfiMemoryMappedPortSpace,
            EfiMemoryType_EfiPalCode
        };
    };
};