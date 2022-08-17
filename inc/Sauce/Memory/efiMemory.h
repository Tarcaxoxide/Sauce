#pragma once

#include<stddef.h>
#include<stdint.h>


//typedef struct{
//    uint32_t type;
//    uint32_t pad;
//    void* physAddr;
//    void* virtAddr;
//    uint64_t numPages;
//    uint64_t attribs;
//} EFI_MEMORY_DESCRIPTOR;

extern const char* EFI_MEMORY_TYPE_STRINGS[];
enum EfiMemoryType{
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