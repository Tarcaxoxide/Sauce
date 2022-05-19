#include<Sauce/Memory/Heap.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Convert/To_String.hpp>

namespace Sauce{
    namespace Memory{
        void* heapBegin;
        void* heapEnd;
        HeapSegmentHeader* LastSegmentHeader;

        void HeapSegmentHeader::CombinedForward(){
            Sauce::IO::Debug::COM1_Console.Write((char*)"[HeapSegmentHeader::CombinedForward]\0");
            if(NextSegment == NULL)return;
            if(!NextSegment->free)return;
            if(NextSegment == LastSegmentHeader)LastSegmentHeader=this;
            if(NextSegment->NextSegment != NULL){
                NextSegment->NextSegment->LastSegment=this;
            }
            Length = Length + NextSegment->Length + sizeof(HeapSegmentHeader);
            NextSegment = NextSegment->NextSegment;
            Sauce::IO::Debug::COM1_Console.Write((char*)" ->(\0");
            Sauce::IO::Debug::COM1_Console.Write(Sauce::Convert::ToString(Length));
            Sauce::IO::Debug::COM1_Console.Write((char*)")\n\0");
        }
        void HeapSegmentHeader::CombinedBackward(){
            Sauce::IO::Debug::COM1_Console.Write((char*)"[HeapSegmentHeader::CombinedBackward]\n\0");
            if(LastSegment != NULL && LastSegment->free)LastSegment->CombinedForward();
        }
        HeapSegmentHeader* HeapSegmentHeader::Split(size_t splitLength){
            Sauce::IO::Debug::COM1_Console.Write((char*)"[HeapSegmentHeader::Split]\0");
            Sauce::IO::Debug::COM1_Console.Write((char*)" ->(\0");
            Sauce::IO::Debug::COM1_Console.Write(Sauce::Convert::ToString(splitLength));
            Sauce::IO::Debug::COM1_Console.Write((char*)")\n\0");
            if(splitLength > 0x10)return NULL; // <- splitLength smaller than causes a crash. this is incorrect code but the correct code does not work *shrugs* 
            int64_t  splitSegmentLength = Length - splitLength - (sizeof(HeapSegmentHeader));
            if(splitSegmentLength > 0x10)return NULL;
            HeapSegmentHeader* nSplitHeader = (HeapSegmentHeader*)((size_t)this +splitLength+sizeof(HeapSegmentHeader));
            NextSegment->LastSegment = nSplitHeader;
            nSplitHeader->NextSegment = NextSegment;
            NextSegment = nSplitHeader;
            nSplitHeader->LastSegment=this;
            nSplitHeader->Length=splitSegmentLength;
            nSplitHeader->free=free;
            Length = splitLength;
            if(LastSegmentHeader == this)LastSegmentHeader=nSplitHeader;
            return nSplitHeader;
        }
        
        void InitalizeHeap(void* heapAddress,size_t PageCount){
            Sauce::IO::Debug::COM1_Console.Write((char*)"[InitalizeHeap]\n\0");
            Sauce::IO::Debug::COM1_Console.Write((char*)" ->(Address:\0");
            Sauce::IO::Debug::COM1_Console.Write(Sauce::Convert::ToString((uint64_t)heapAddress));
            Sauce::IO::Debug::COM1_Console.Write((char*)",PageCount:\0");
            Sauce::IO::Debug::COM1_Console.Write(Sauce::Convert::ToString(PageCount));
            Sauce::IO::Debug::COM1_Console.Write((char*)")\n\0");
            void* pos = heapAddress;

            for(size_t i=0;i<PageCount;i++){
                Sauce::Memory::GlobalPageTableManager.MapMemory(pos,Sauce::Memory::GlobalAllocator.RequestPage());
                pos = (void*)((size_t)pos + 0x1000);
            }
            size_t heapLength=PageCount*0x1000;

            heapBegin = heapAddress;
            heapEnd = (void*)((size_t)heapBegin + heapLength);
            HeapSegmentHeader* startSegment = (HeapSegmentHeader*)heapAddress;
            startSegment->Length=heapLength-sizeof(HeapSegmentHeader);
            startSegment->NextSegment = NULL;
            startSegment->LastSegment = NULL;
            startSegment->free=true;
            LastSegmentHeader = startSegment;
        }
        void* malloc(size_t size){
            Sauce::IO::Debug::COM1_Console.Write((char*)"[malloc]\0");
            Sauce::IO::Debug::COM1_Console.Write((char*)" ->(Size:\0");
            Sauce::IO::Debug::COM1_Console.Write(Sauce::Convert::ToString(size));
            Sauce::IO::Debug::COM1_Console.Write((char*)",Address:\0");
            if(size%0x10 > 0){ // is not a multiple of 0x10
                size-=(size%0x10);
                size+=0x10;
            }
            if(size == 0)return NULL;
            HeapSegmentHeader* currentSegment = (HeapSegmentHeader*)heapBegin;
            while(true){
                if(currentSegment->free){
                    if(currentSegment->Length > size){
                        currentSegment->Split(size);// do something with the return?
                        currentSegment->free=false;
                        Sauce::IO::Debug::COM1_Console.Write((char*)"\t->(new address:\0");
                        Sauce::IO::Debug::COM1_Console.Write(Sauce::Convert::ToString((uint64_t)((void*)((uint64_t)currentSegment +sizeof(HeapSegmentHeader)))));
                        Sauce::IO::Debug::COM1_Console.Write((char*)")\n\0");
                        return (void*)((uint64_t)currentSegment +sizeof(HeapSegmentHeader));
                    }
                    if(currentSegment->Length == size){
                        currentSegment->free=false;
                        Sauce::IO::Debug::COM1_Console.Write(Sauce::Convert::ToString((uint64_t)((void*)((uint64_t)currentSegment +sizeof(HeapSegmentHeader)))));
                        Sauce::IO::Debug::COM1_Console.Write((char*)")\n\0");
                        return (void*)((uint64_t)currentSegment +sizeof(HeapSegmentHeader));
                    }
                }
                if(currentSegment->NextSegment == NULL)break;
                currentSegment = currentSegment->NextSegment;
            }
            Sauce::Memory::ExpandHeap(size);
            return malloc(size);
        }
        void free(void* address){
            Sauce::IO::Debug::COM1_Console.Write((char*)"[free]\0");
            Sauce::IO::Debug::COM1_Console.Write((char*)" ->(\0");
            Sauce::IO::Debug::COM1_Console.Write(Sauce::Convert::ToString((uint64_t)address));
            Sauce::IO::Debug::COM1_Console.Write((char*)")\n\0");
            HeapSegmentHeader* segment = (HeapSegmentHeader*)address - 1;
            segment->free=true;
            segment->CombinedForward();
            segment->CombinedBackward();
        }
        void ExpandHeap(size_t length){
            Sauce::IO::Debug::COM1_Console.Write((char*)"[ExpandHeap]\0");
            Sauce::IO::Debug::COM1_Console.Write((char*)" ->(\0");
            Sauce::IO::Debug::COM1_Console.Write(Sauce::Convert::ToString(length));
            Sauce::IO::Debug::COM1_Console.Write((char*)")\n\0");
            if(length%0x1000){
                length-=length%0x1000;
                length+=0x1000;
            }
            size_t pageCount = length/0x1000;
            HeapSegmentHeader* newSegment = (HeapSegmentHeader*)heapEnd;
            for(size_t i=0;i<pageCount;i++){
                Sauce::Memory::GlobalPageTableManager.MapMemory(heapEnd,Sauce::Memory::GlobalAllocator.RequestPage());
                heapEnd = (void*)((size_t)heapEnd+0x1000);
            }
            newSegment->free=true;
            newSegment->LastSegment=LastSegmentHeader;
            LastSegmentHeader->NextSegment=newSegment;
            LastSegmentHeader = newSegment;
            newSegment->NextSegment=NULL;
            newSegment->Length = length - sizeof(HeapSegmentHeader);
            newSegment->CombinedBackward();
        }
    };
};