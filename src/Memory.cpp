#include <Memory.hpp>

extern uint8_t MemoryRegionCount;
extern uint16_t MemoryMapAddress;

extern "C" uint64_t GetFreeStack(); // Get the remaining space of the kernel stack
extern "C" uint64_t GetMaxStack(); // Get the total size of the kernel stack

namespace Sauce{
    namespace Memory{
        void PrintMemoryMap(MemoryMapEntry* MemoryMap){
            Sauce::Terminal::String("[Base:");
            Sauce::Terminal::String(Sauce::Convert::To_String::From_Integer(MemoryMap->BaseAddress));
            Sauce::Terminal::String(";");
            Sauce::Terminal::String("Length:");
            Sauce::Terminal::String(Sauce::Convert::To_String::From_Integer(MemoryMap->Region_Length));
            Sauce::Terminal::String(";");
            Sauce::Terminal::String("Type:");
            Sauce::Terminal::String(Sauce::Convert::To_String::From_Integer(MemoryMap->Region_Type));
            Sauce::Terminal::String(";");
            Sauce::Terminal::String("Attributes:");
            Sauce::Terminal::String(Sauce::Convert::To_String::From_Integer(MemoryMap->ExtendedAttributes));
            Sauce::Terminal::String("]");
        }
        void PrintMemoryMap_All(){
            for (uint8_t A = 0; A < MemoryRegionCount;A++){
                Sauce::Memory::MemoryMapEntry* memMap = (Sauce::Memory::MemoryMapEntry*)MemoryMapAddress;
                memMap += A;
                Sauce::Memory::PrintMemoryMap(memMap);
                Sauce::Terminal::String("\n\r");
            }
        }
        MemoryMapEntryMap GetMemoryRegions(uint32_t Type){
            MemoryMapEntry* MemoryRegions[24];
            MemoryMapEntryMap ReturnValue ={MemoryRegions,0};
            uint8_t B=0;
            for (uint8_t A = 0; A < MemoryRegionCount;A++){
                Sauce::Memory::MemoryMapEntry* memMap = (Sauce::Memory::MemoryMapEntry*)MemoryMapAddress;
                memMap += A;
                if(memMap->Region_Type == Type){
                    ReturnValue.MemoryMapEntries[ReturnValue.MemoryMapEntryCount] = memMap;
                    ReturnValue.MemoryMapEntryCount++;
                }
            }
            return ReturnValue;
        }
    };
    namespace Memory{
        MemorySegmentHeader* FirstFreeMemorySegment;
        void memset(void* address,uint64_t val,uint64_t size){
            if(size >= 8){
                uint8_t*valPtr = (uint8_t*)&val;
                for(uint8_t* ptr = (uint8_t*)address;ptr < (uint8_t*)((uint64_t)address+size);ptr++){
                    *ptr = *valPtr++;
                }
                return;
            }
            uint64_t proceedingBytes = size%8;
            uint64_t newsize = size - proceedingBytes;
            for(uint64_t* ptr = (uint64_t*)address;ptr < (uint64_t*)((uint64_t)address+newsize);ptr++){
                *ptr == val;
            }
            uint8_t* valPtr = (uint8_t*)&val;
            for(uint8_t* ptr = (uint8_t*)((uint64_t)address+newsize);ptr < (uint8_t*)((uint64_t)address+size);ptr++){
                *ptr = *valPtr++;
            }
        }
        void InitializeHeap(uint64_t HeapAddress,uint64_t HeapLength){
            FirstFreeMemorySegment = (MemorySegmentHeader*)HeapAddress+1;
            FirstFreeMemorySegment->MemoryLength=HeapLength-sizeof(MemorySegmentHeader);
            FirstFreeMemorySegment->NextSegment=0;
            FirstFreeMemorySegment->PreviousSegment=0;
            FirstFreeMemorySegment->NextFreeSegment=0;
            FirstFreeMemorySegment->PreviousFreeSegment=0;
            FirstFreeMemorySegment->Free=true;
        }
        void* realloc(void* address,uint64_t size){
            MemorySegmentHeader* oldSegment = NULL;
            MemorySegmentHeader* AMSH = (MemorySegmentHeader*)address-1;
            oldSegment = (MemorySegmentHeader*)(uint64_t)AMSH->MemorySegmentAddress;
            uint64_t smallerSize = size;
            if(oldSegment->MemoryLength < smallerSize)smallerSize=oldSegment->MemoryLength;
            void* newSegment = NULL;
            newSegment = alloc(size,AMSH->TheAlignment);
            memcpy(oldSegment,newSegment,smallerSize);
            free(address);
            return newSegment;
        }
        void* alloc(uint64_t size,uint64_t alighnment){
            uint64_t sizeRemainder = size % 8;
            size+=sizeRemainder;
            size+=(8*(sizeRemainder != 0));
            uint64_t fullsize=0;
            uint64_t alighnmentRemainder=0;
            alighnmentRemainder = alighnment % 8;
            alighnment+=alighnmentRemainder;
            size+=(8*(alighnmentRemainder != 0));
            fullsize=size+alighnment;
            void* mallocVal = NULL;

            MemorySegmentHeader* currentMemorySegment = FirstFreeMemorySegment;
            
            while(true){
                if(currentMemorySegment->MemoryLength >= fullsize){
                    if(currentMemorySegment->MemoryLength > fullsize + sizeof(MemorySegmentHeader)){
                        MemorySegmentHeader* newSegmentHeader = (MemorySegmentHeader*)((uint64_t)currentMemorySegment + sizeof(MemorySegmentHeader)+fullsize);
                        newSegmentHeader->Free=true;
                        newSegmentHeader->MemoryLength=((uint64_t)currentMemorySegment->MemoryLength - (sizeof(MemorySegmentHeader)+fullsize));
                        newSegmentHeader->NextFreeSegment = currentMemorySegment->NextFreeSegment;
                        newSegmentHeader->NextSegment = currentMemorySegment->NextSegment;
                        newSegmentHeader->PreviousSegment = currentMemorySegment;
                        newSegmentHeader->PreviousFreeSegment = currentMemorySegment->PreviousFreeSegment;
                        currentMemorySegment->NextFreeSegment = newSegmentHeader;
                        currentMemorySegment->NextSegment = newSegmentHeader;
                        currentMemorySegment->MemoryLength=fullsize;
                    }
                    if(currentMemorySegment == FirstFreeMemorySegment){
                        FirstFreeMemorySegment = currentMemorySegment->NextFreeSegment;
                    }
                    currentMemorySegment->Free=false;

                    if(currentMemorySegment->PreviousFreeSegment != 0)currentMemorySegment->PreviousFreeSegment->NextFreeSegment = currentMemorySegment->NextFreeSegment;
                    if(currentMemorySegment->NextFreeSegment != 0)currentMemorySegment->NextFreeSegment->PreviousFreeSegment =  currentMemorySegment->PreviousFreeSegment;
                    if(currentMemorySegment->PreviousSegment != 0)currentMemorySegment->PreviousSegment->NextFreeSegment = currentMemorySegment->NextFreeSegment;
                    if(currentMemorySegment->NextSegment != 0)currentMemorySegment->NextSegment->PreviousFreeSegment = currentMemorySegment->PreviousFreeSegment;
                    mallocVal = currentMemorySegment+1;
                    memset(mallocVal,0,fullsize);
                    uint64_t address = (uint64_t)mallocVal;
                    uint64_t remainder = address % alighnment;
                    address-=remainder;
                    address+=alighnment;
                    MemorySegmentHeader* AMSH = (MemorySegmentHeader*)address-1;
                    AMSH->TheAlignment = alighnment;
                    AMSH->MemorySegmentAddress = (uint64_t)mallocVal - sizeof(MemorySegmentHeader);
                    
                    return (void*)address;
                }
                if(currentMemorySegment->NextFreeSegment == 0){
                    return 0;
                }
                currentMemorySegment = currentMemorySegment->NextFreeSegment;
            }
            return 0;
        }
        void* calloc(uint64_t size,uint64_t alighnment){
            return alloc(size,alighnment);
        }
        void* malloc(uint64_t size){
            return alloc(size);
        }

        void memcpy(void* Source,void* Destination,uint64_t size){
            if(size >= 8){
                uint8_t*valPtr = (uint8_t*)Source;
                for(uint8_t* ptr = (uint8_t*)Destination;ptr < (uint8_t*)((uint64_t)Destination+size);ptr++){
                    *ptr = *valPtr++;
                }
                return;
            }
            uint64_t proceedingBytes = size%8;
            uint64_t newsize = size - proceedingBytes;
            uint64_t* srcptr = (uint64_t*)Source;
            for(uint64_t* destptr = (uint64_t*)Destination;destptr < (uint64_t*)((uint64_t)Destination+newsize);destptr++){
                *destptr == *srcptr++;
            }
            uint8_t* srcptr8 = (uint8_t*)(Source+newsize);
            for(uint8_t* destptr8 = (uint8_t*)((uint64_t)Destination+newsize);destptr8 < (uint8_t*)((uint64_t)Destination+size);destptr8++){
                *destptr8 = *srcptr8++;
            }
        }
        void free(void* address){
            MemorySegmentHeader* currentMemorySegment = ((MemorySegmentHeader*)address)-1;
            currentMemorySegment = (MemorySegmentHeader*)(uint64_t)currentMemorySegment->MemorySegmentAddress;
            
            currentMemorySegment->Free=true;
            if(currentMemorySegment < FirstFreeMemorySegment)FirstFreeMemorySegment = currentMemorySegment;
            
            if(currentMemorySegment->NextFreeSegment != 0){
                if(currentMemorySegment->NextFreeSegment->PreviousFreeSegment < currentMemorySegment)currentMemorySegment->NextFreeSegment->PreviousFreeSegment = currentMemorySegment;
            }
            
            if(currentMemorySegment->PreviousFreeSegment != 0){
                if(currentMemorySegment->PreviousFreeSegment->NextFreeSegment > currentMemorySegment)currentMemorySegment->PreviousFreeSegment->NextFreeSegment = currentMemorySegment;
            }
            if(currentMemorySegment->NextSegment != 0){
                currentMemorySegment->NextSegment->PreviousSegment=currentMemorySegment;
                if(currentMemorySegment->NextSegment->Free)CombinedSegments(currentMemorySegment,currentMemorySegment->NextSegment);
            }
            if(currentMemorySegment->PreviousSegment != 0){
                currentMemorySegment->PreviousSegment->NextSegment=currentMemorySegment; // this freezes when using unaligned address?
                if(currentMemorySegment->PreviousSegment->Free)CombinedSegments(currentMemorySegment,currentMemorySegment->PreviousSegment);
            }
        }
        void CombinedSegments(MemorySegmentHeader* a,MemorySegmentHeader* b){
            if(a == 0 || b == 0)return;
            if(a < b){
                a->MemoryLength+=b->MemoryLength + sizeof(MemorySegmentHeader);
                a->NextSegment = b->NextSegment;
                a->NextFreeSegment = b->NextFreeSegment;
                b->NextSegment->PreviousSegment = a;
                b->NextSegment->PreviousFreeSegment = a;
                b->NextFreeSegment->PreviousFreeSegment = a;
            }else{
                b->MemoryLength+=a->MemoryLength + sizeof(MemorySegmentHeader);
                b->NextSegment = a->NextSegment;
                b->NextFreeSegment = a->NextFreeSegment;
                a->NextSegment->PreviousSegment = b;
                a->NextSegment->PreviousFreeSegment = b;
                a->NextFreeSegment->PreviousFreeSegment = b;
            }
        }
    };
};

