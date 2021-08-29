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
            Sauce::Terminal::String("Initializing Heap: ");
            Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64(HeapAddress));
            Sauce::Terminal::String(" : ");
            Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64(HeapLength));
            Sauce::Terminal::String("\n\r");
            FirstFreeMemorySegment = (MemorySegmentHeader*)HeapAddress+1;
            FirstFreeMemorySegment->MemoryLength=HeapLength-sizeof(MemorySegmentHeader);
            FirstFreeMemorySegment->NextSegment=0;
            FirstFreeMemorySegment->PreviousSegment=0;
            FirstFreeMemorySegment->NextFreeSegment=0;
            FirstFreeMemorySegment->PreviousFreeSegment=0;
            FirstFreeMemorySegment->Free=true;
        }
        void* realloc(void* address,uint64_t newSize){
            MemorySegmentHeader* oldSegmentHeader=(MemorySegmentHeader*)address -1;
            uint64_t smallerSize = newSize;
            if(oldSegmentHeader->MemoryLength < newSize)smallerSize=oldSegmentHeader->MemoryLength;
            void* newMem = alloc(newSize,oldSegmentHeader->Alignment);
            memcpy(address,newMem,smallerSize);
            free(address);
            return newMem;
        }
        void* alloc(uint64_t size,uint64_t Alignment){
            Sauce::Terminal::String("alloc:: ");
            Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64(size));
            Sauce::Terminal::String(" : ");
            Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64(Alignment));
            Sauce::Terminal::String(" = ");
            uint64_t fullSize = 0;
            void* Address=0;
            bool isAligned=false;
            if(Alignment == 0){ // since you can't align with 0 (or at least i don't think its a good idea)
                                // i'll use 0 for not set.
                uint64_t remainder = size % 8;
                size -= remainder;
                if(remainder != 0)size+=8;
                fullSize=size;
            }else{
                isAligned=true;
                uint64_t alignmentRemainder = Alignment%8;
                Alignment-=alignmentRemainder;
                if(alignmentRemainder != 0)Alignment+=8;

                uint64_t sizeRemainder = size%8;
                size-=sizeRemainder;
                if(sizeRemainder != 0)size+=8;
                fullSize=size+Alignment;
            }

            MemorySegmentHeader* currentMemorySegment = FirstFreeMemorySegment;
            while(true){
                if(currentMemorySegment->MemoryLength >= fullSize){
                    if(currentMemorySegment->MemoryLength > fullSize + sizeof(MemorySegmentHeader)){
                        MemorySegmentHeader* newSegmentHeader = (MemorySegmentHeader*)((uint64_t)currentMemorySegment+sizeof(MemorySegmentHeader)+fullSize);
                        newSegmentHeader->Free=true;
                        newSegmentHeader->MemoryLength=((uint64_t)currentMemorySegment->MemoryLength)-(sizeof(MemorySegmentHeader)+fullSize);
                        newSegmentHeader->NextFreeSegment = currentMemorySegment->NextFreeSegment;
                        newSegmentHeader->NextSegment = currentMemorySegment->NextSegment;
                        newSegmentHeader->PreviousFreeSegment = currentMemorySegment;
                        newSegmentHeader->PreviousFreeSegment = currentMemorySegment->PreviousFreeSegment;

                        currentMemorySegment->NextFreeSegment = newSegmentHeader;
                        currentMemorySegment->NextSegment = newSegmentHeader;
                        currentMemorySegment->MemoryLength = fullSize;
                    }
                    if(currentMemorySegment == FirstFreeMemorySegment){
                        FirstFreeMemorySegment = currentMemorySegment->NextFreeSegment;
                    }
                    currentMemorySegment->Free=false;
                    if(currentMemorySegment->PreviousFreeSegment != 0) currentMemorySegment->PreviousFreeSegment->NextFreeSegment = currentMemorySegment->NextFreeSegment;
                    if(currentMemorySegment->NextFreeSegment != 0) currentMemorySegment->NextFreeSegment->PreviousFreeSegment = currentMemorySegment->PreviousFreeSegment;
                    if(currentMemorySegment->PreviousSegment != 0) currentMemorySegment->PreviousSegment->NextFreeSegment = currentMemorySegment->NextFreeSegment;
                    if(currentMemorySegment->NextSegment != 0) currentMemorySegment->NextSegment->PreviousFreeSegment = currentMemorySegment->PreviousFreeSegment;
                    Address=currentMemorySegment + 1;break;
                }
                if (currentMemorySegment->NextFreeSegment == 0){
                    Address=0;break; // no memory remaining.
                }
                currentMemorySegment = currentMemorySegment->NextFreeSegment;
            }
            uint64_t fullAddress = (uint64_t)Address;
            if(isAligned){
                uint64_t addressRemainer = fullAddress % Alignment;
                fullAddress-=addressRemainer;
                if(addressRemainer != 0){
                    fullAddress+=Alignment;
                }
                MemorySegmentHeader* AMSH = (MemorySegmentHeader*)fullAddress - sizeof(MemorySegmentHeader);;
                AMSH->Alignment = Alignment;
                AMSH->MemorySegmentAddress = fullAddress;//(uint64_t)Address - sizeof(MemorySegmentHeader);
            }
            Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64(fullAddress));
            Sauce::Terminal::String(" \n\r");
            return (void*)fullAddress;
        }
        void* calloc(uint64_t size,uint64_t alighnment){
            return alloc(size,alighnment);
        }
        void* malloc(uint64_t size){
            return alloc(size);
        }

        void memcpy(void* Source,void* Destination,uint64_t size){
            Sauce::Terminal::String("memcpy : ");
            Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64((uint64_t)Source));
            Sauce::Terminal::String(" to ");
            Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64((uint64_t)Destination));
            Sauce::Terminal::String(" \n\r");
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
            Sauce::Terminal::String("free : ");
            Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64((uint64_t)address));
            Sauce::Terminal::String(" \n\r");
            MemorySegmentHeader* currentMemorySegment = ((MemorySegmentHeader*)address)-1;
            currentMemorySegment = (MemorySegmentHeader*)(uint64_t)currentMemorySegment->MemorySegmentAddress;
            
            currentMemorySegment->Free=true;
            if(currentMemorySegment < FirstFreeMemorySegment)FirstFreeMemorySegment = currentMemorySegment;
            Sauce::Terminal::String("DEBUG?");
            if(currentMemorySegment->NextFreeSegment != 0){
                if(currentMemorySegment->NextFreeSegment->PreviousFreeSegment < currentMemorySegment)currentMemorySegment->NextFreeSegment->PreviousFreeSegment = currentMemorySegment;
            }
            Sauce::Terminal::String("DEBUG?");
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
            Sauce::Terminal::String("CombinedSegments : ");
            Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64((uint64_t)a));
            Sauce::Terminal::String(" + ");
            Sauce::Terminal::String(Sauce::Convert::To_String::From_uint64((uint64_t)b));
            Sauce::Terminal::String(" \n\r");
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

