#include<Sauce/Memory/Memory.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utilities/Conversion.hpp>

namespace Sauce{
    namespace Memory{
        uint64_t GetMemorySize(Sauce::Memory::EFI_MEMORY_DESCRIPTOR*mMap,uint64_t mMapEntries,uint64_t mDescriptorSize){
            Sauce::IO::Debug::Print_Spammy_Call("GetMemorySize",Sauce::IO::Debug::MEMORY);
            static uint64_t memorySizeBytes = 0;
            if(memorySizeBytes)return memorySizeBytes;
            for(int i=0;i<mMapEntries;i++){
                EFI_MEMORY_DESCRIPTOR* descriptor = (EFI_MEMORY_DESCRIPTOR*)((uint64_t)mMap + (i*mDescriptorSize));
                memorySizeBytes+=descriptor->numPages*4096;
            }

            Sauce::IO::Debug::Print_Spammy_Return(Sauce::Convert::ToString(memorySizeBytes),Sauce::IO::Debug::MEMORY);
            return memorySizeBytes;
        }
        void memset(void* address,uint8_t value,uint64_t size){
            Sauce::IO::Debug::Print_Spammy_Call("memset",Sauce::IO::Debug::MEMORY);
            for(uint64_t i=0;i<size;i++){
                *(uint8_t*)((uint64_t)address+i)=value;
            }
            Sauce::IO::Debug::Print_Spammy_Return("void",Sauce::IO::Debug::MEMORY);
        }
        int64_t memcmp(const void* aptr,const void* bptr,size_t s){
            Sauce::IO::Debug::Print_Spammy_Call("memcmp",Sauce::IO::Debug::MEMORY);
            const unsigned char *a=(const unsigned char *)aptr,*b=(const unsigned char *)bptr;
            for(size_t i=0;i<s;i++){// my memcmp is special, it returns the index of the first difference.
                if(a[i] < b[i]){Sauce::IO::Debug::Print_Return(Sauce::Convert::ToString(-i),Sauce::IO::Debug::MEMORY);return (int64_t)-i;}
                if(a[i] > b[i]){Sauce::IO::Debug::Print_Return(Sauce::Convert::ToString(i),Sauce::IO::Debug::MEMORY);return (int64_t)i;}
            }
            Sauce::IO::Debug::Print_Spammy_Return(Sauce::Convert::ToString(0),Sauce::IO::Debug::MEMORY);
            return (int64_t)0;
        }
    };
};