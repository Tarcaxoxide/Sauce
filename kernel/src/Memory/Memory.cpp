#include<Sauce/Memory/Memory.hpp>

namespace Sauce{
    namespace Memory{
        uint64_t GetMemorySize(Sauce::Memory::EFI_MEMORY_DESCRIPTOR*mMap,uint64_t mMapEntries,uint64_t mDescriptorSize){
            static uint64_t memorySizeBytes = 0;
            if(memorySizeBytes)return memorySizeBytes;
            for(int i=0;i<mMapEntries;i++){
                EFI_MEMORY_DESCRIPTOR* descriptor = (EFI_MEMORY_DESCRIPTOR*)((uint64_t)mMap + (i*mDescriptorSize));
                memorySizeBytes+=descriptor->numPages*4096;
            }
            return memorySizeBytes;
        }
        void memset(void* address,uint8_t value,uint64_t size){
            for(uint64_t i=0;i<size;i++){
                *(uint8_t*)((uint64_t)address+i)=value;
            }
        }
        int64_t memcmp(const void* aptr,const void* bptr,size_t s){
            const unsigned char *a=(const unsigned char *)aptr,*b=(const unsigned char *)bptr;
            for(size_t i=0;i<s;i++){// my memcmp is special, it returns the index of the first difference.
                if(a[i] < b[i])return (int64_t)-i;
                if(a[i] > b[i])return (int64_t)i;
            }
            return (int64_t)0;
        }
    };
};