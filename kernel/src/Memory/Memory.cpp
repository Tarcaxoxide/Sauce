#include<Sauce/Memory/Memory.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utility/Conversion.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

#define THRESHOLD sizeof(long)

namespace Sauce{
    namespace Memory{
        uint64_t GetMemorySize(Sauce::Memory::EFI_MEMORY_DESCRIPTOR*mMap,uint64_t mMapEntries,uint64_t mDescriptorSize){
            Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"GetMemorySize",_NAMESPACE_,_ALLOW_PRINT_);
            static uint64_t memorySizeBytes = 0;
            if(memorySizeBytes)return memorySizeBytes;
            for(int i=0;i<mMapEntries;i++){
                EFI_MEMORY_DESCRIPTOR* descriptor = (EFI_MEMORY_DESCRIPTOR*)((uint64_t)mMap + (i*mDescriptorSize));
                memorySizeBytes+=descriptor->numPages*4096;
            }
            return memorySizeBytes;
        }
        void memset(void* address,uint8_t value,uint64_t size){
            Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"memset",_NAMESPACE_,_ALLOW_PRINT_);
            for(uint64_t i=0;i<size;i++){
                *(uint8_t*)((uint64_t)address+i)=value;
            }
        }
        void memcpy(const void* srcPtr,const void* destPtr,size_t s){
            // EXPERIMENTAL! 
            Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"memcpy",_NAMESPACE_,_ALLOW_PRINT_);
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
        void memcpy(const void* srcPtr,const void* destPtr,size_t s,size_t ts){
            // EXPERIMENTAL! 
            Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"memcpy+ts",_NAMESPACE_,_ALLOW_PRINT_);
            uint8_t *pszDest = (uint8_t *)destPtr;
            const uint8_t *pszSource =( const uint8_t*)srcPtr;
            uint64_t TotalSizeInBytes = s*ts;
            while(TotalSizeInBytes){
                if(TotalSizeInBytes/sizeof(uint64_t)){
                    *((uint64_t*)pszDest) = *((uint64_t*)pszSource);
                    pszDest+=(sizeof(uint64_t)/sizeof(uint8_t));
                    pszSource+=(sizeof(uint64_t)/sizeof(uint8_t));
                    TotalSizeInBytes-=(sizeof(uint64_t)/sizeof(uint8_t));
                }else if(TotalSizeInBytes/sizeof(uint32_t)){
                    *((uint32_t*)pszDest) = *((uint32_t*)pszSource);
                    pszDest+=(sizeof(uint32_t)/sizeof(uint8_t));
                    pszSource+=(sizeof(uint32_t)/sizeof(uint8_t));
                    TotalSizeInBytes-=(sizeof(uint32_t)/sizeof(uint8_t));
                }else if(TotalSizeInBytes/sizeof(uint16_t)){
                    *((uint16_t*)pszDest) = *((uint16_t*)pszSource);
                    pszDest+=(sizeof(uint16_t)/sizeof(uint8_t));
                    pszSource+=(sizeof(uint16_t)/sizeof(uint8_t));
                    TotalSizeInBytes-=(sizeof(uint16_t)/sizeof(uint8_t));
                }else{
                    *(pszDest++)= *(pszSource++);
                    TotalSizeInBytes--;
                }
            }
        }
        int64_t memcmp(const void* aptr,const void* bptr,size_t s){
            Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"memcmp",_NAMESPACE_,_ALLOW_PRINT_);
            const unsigned char *a=(const unsigned char *)aptr,*b=(const unsigned char *)bptr;
            for(size_t i=0;i<s;i++){// my memcmp is special, it returns the index of the first difference.
                if(a[i] < b[i]){return (int64_t)-i;}
                if(a[i] > b[i]){return (int64_t)i;}
            }
            return (int64_t)0;
        }
    };
};