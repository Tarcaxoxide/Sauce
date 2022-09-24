#include<Sauce/Memory/Memory.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utility/Conversion.hpp>

#define THRESHOLD sizeof(long)

namespace Sauce{
    namespace Memory{
        uint64_t GetMemorySize(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Memory::EFI_MEMORY_DESCRIPTOR*mMap,uint64_t mMapEntries,uint64_t mDescriptorSize){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"GetMemorySize");
            static uint64_t memorySizeBytes = 0;
            if(memorySizeBytes)return memorySizeBytes;
            for(int i=0;i<mMapEntries;i++){
                EFI_MEMORY_DESCRIPTOR* descriptor = (EFI_MEMORY_DESCRIPTOR*)((uint64_t)mMap + (i*mDescriptorSize));
                memorySizeBytes+=descriptor->numPages*4096;
            }
            return memorySizeBytes;
        }
        void memset(Sauce::IO::Debug::Debugger_st* pDebugger,void* address,uint8_t value,uint64_t size){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"memset");
            for(uint64_t i=0;i<size;i++){
                *(uint8_t*)((uint64_t)address+i)=value;
            }
        }
        void memcpy(Sauce::IO::Debug::Debugger_st* pDebugger,const void* srcPtr,const void* destPtr,size_t s){
            // EXPERIMENTAL! 
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"memcpy");
                char *pszDest = (char *)destPtr;
                const char *pszSource =( const char*)srcPtr;

                if((pszDest!= NULL) && (pszSource!= NULL))
                {
                    while(s) //till s
                    {
                        //Copy byte by byte
                        *(pszDest++)= *(pszSource++);
                        --s;
                    }
                }
        }
        int64_t memcmp(Sauce::IO::Debug::Debugger_st* pDebugger,const void* aptr,const void* bptr,size_t s){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"memcmp");
            const unsigned char *a=(const unsigned char *)aptr,*b=(const unsigned char *)bptr;
            for(size_t i=0;i<s;i++){// my memcmp is special, it returns the index of the first difference.
                if(a[i] < b[i]){return (int64_t)-i;}
                if(a[i] > b[i]){return (int64_t)i;}
            }
            return (int64_t)0;
        }
    };
};