#include<Sauce/Memory.hpp>

namespace Sauce{
    uint64_t GetMemorySize(Sauce::EFI_MEMORY_DESCRIPTOR*mMap,uint64_t mMapEntries,uint64_t mDescriptorSize){
        static uint64_t memorySizeBytes = 0;
        if(memorySizeBytes)return memorySizeBytes;
        for(int i=0;i<mMapEntries;i++){
            EFI_MEMORY_DESCRIPTOR* descriptor = (EFI_MEMORY_DESCRIPTOR*)((uint64_t)mMap + (i*mDescriptorSize));
            memorySizeBytes+=descriptor->numPages*4096;
        }
        return memorySizeBytes;
    }
};