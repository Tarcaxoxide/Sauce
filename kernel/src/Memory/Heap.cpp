#include<Sauce/Memory/Heap.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utilities/Conversion.hpp>
#include<Sauce/Global/Global.hpp>

namespace Sauce{
    namespace Memory{
        void* heapBegin;
        void* heapEnd;
        HeapSegmentHeader* LastSegmentHeader;

        void HeapSegmentHeader::CombinedForward(){
            Sauce::IO::Debug::Print_Call("HeapSegmentHeader::CombinedForward",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::HEAP);
            if(NextSegment == NULL)return;
            if(!NextSegment->free)return;
            if(NextSegment == LastSegmentHeader)LastSegmentHeader=this;
            if(NextSegment->NextSegment != NULL){
                NextSegment->NextSegment->LastSegment=this;
            }
            Length = Length + NextSegment->Length + sizeof(HeapSegmentHeader);
            NextSegment = NextSegment->NextSegment;
            Sauce::IO::Debug::Print_Return(Sauce::Convert::ToString(Length),Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::HEAP);
        }
        void HeapSegmentHeader::CombinedBackward(){
            Sauce::IO::Debug::Print_Call("HeapSegmentHeader::CombinedBackward",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::HEAP);
            if(LastSegment != NULL && LastSegment->free)LastSegment->CombinedForward();
            Sauce::IO::Debug::Print_Return("void",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::HEAP);
        }
        HeapSegmentHeader* HeapSegmentHeader::Split(size_t splitLength){
            Sauce::IO::Debug::Print_Call("HeapSegmentHeader::Split",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::HEAP);
            Sauce::IO::Debug::Print_Detail(Sauce::Convert::ToString(splitLength),Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::HEAP);
            if(splitLength > 0x10){Sauce::IO::Debug::Print_Return("NULL",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::HEAP);return NULL;} // <- splitLength smaller than causes a crash. this is incorrect code but the correct code does not work *shrugs* 
            int64_t  splitSegmentLength = Length - splitLength - (sizeof(HeapSegmentHeader));
            if(splitSegmentLength > 0x10){Sauce::IO::Debug::Print_Return("NULL",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::HEAP);return NULL;}
            HeapSegmentHeader* nSplitHeader = (HeapSegmentHeader*)((size_t)this +splitLength+sizeof(HeapSegmentHeader));
            NextSegment->LastSegment = nSplitHeader;
            nSplitHeader->NextSegment = NextSegment;
            NextSegment = nSplitHeader;
            nSplitHeader->LastSegment=this;
            nSplitHeader->Length=splitSegmentLength;
            nSplitHeader->free=free;
            Length = splitLength;
            if(LastSegmentHeader == this)LastSegmentHeader=nSplitHeader;

            Sauce::IO::Debug::Print_Return(Sauce::Convert::HexToString((uint64_t)nSplitHeader),Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::HEAP);
            return nSplitHeader;
        }
        
        void InitalizeHeap(void* heapAddress,size_t PageCount){
            Sauce::IO::Debug::Print_Call("InitalizeHeap",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::HEAP);

            Sauce::IO::Debug::Print_Detail("Address:",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::HEAP,Sauce::IO::Debug::StartOfPrint::Start);
            Sauce::IO::Debug::Print_Detail(Sauce::Convert::ToString((uint64_t)heapAddress),Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::HEAP,Sauce::IO::Debug::StartOfPrint::Middle);
            Sauce::IO::Debug::Print_Detail(",PageCount:",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::HEAP,Sauce::IO::Debug::StartOfPrint::Middle);
            Sauce::IO::Debug::Print_Detail(Sauce::Convert::ToString(PageCount),Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::HEAP,Sauce::IO::Debug::StartOfPrint::End);
            void* pos = heapAddress;

            for(size_t i=0;i<PageCount;i++){
                Sauce::Global::PageTableManager.MapMemory(pos,Sauce::Global::PageFrameAllocator.RequestPage());
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
            Sauce::IO::Debug::Print_Return("void",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::HEAP);
        }
        void* malloc(size_t size){
            Sauce::IO::Debug::Print_Call("malloc",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::HEAP);
            Sauce::IO::Debug::Print_Detail(Sauce::Convert::ToString(size),Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::HEAP);
            
            if(size%0x10 > 0){ // is not a multiple of 0x10
                size-=(size%0x10);
                size+=0x10;
            }
            if(size == 0){Sauce::IO::Debug::Print_Return("NULL",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::HEAP);return NULL;}
            HeapSegmentHeader* currentSegment = (HeapSegmentHeader*)heapBegin;
            while(true){
                if(currentSegment->free){
                    if(currentSegment->Length > size){
                        currentSegment->Split(size);// do something with the return?
                        currentSegment->free=false;
                        
                        void* TheAddress = (void*)((uint64_t)currentSegment +sizeof(HeapSegmentHeader));
                        Sauce::IO::Debug::Print_Return(Sauce::Convert::HexToString((uint64_t)TheAddress),Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::HEAP);
                        return TheAddress;
                    }
                    if(currentSegment->Length == size){
                        currentSegment->free=false;
                        
                        Sauce::IO::Debug::Print_Return("",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::HEAP);
                        void* TheAddress = (void*)((uint64_t)currentSegment +sizeof(HeapSegmentHeader));
                        Sauce::IO::Debug::Print_Return(Sauce::Convert::HexToString((uint64_t)TheAddress),Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::HEAP);
                        return TheAddress;
                    }
                }
                if(currentSegment->NextSegment == NULL)break;
                currentSegment = currentSegment->NextSegment;
            }
            Sauce::Memory::ExpandHeap(size);
            void* TheAddress = malloc(size);
            Sauce::IO::Debug::Print_Return(Sauce::Convert::HexToString((uint64_t)TheAddress),Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::HEAP);
            return TheAddress;
        }
        void free(void* address){
            Sauce::IO::Debug::Print_Call("free",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::HEAP);
            Sauce::IO::Debug::Print_Detail(Sauce::Convert::ToString((uint64_t)address),Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::HEAP);
            HeapSegmentHeader* segment = (HeapSegmentHeader*)address - 1;
            segment->free=true;
            segment->CombinedForward();
            segment->CombinedBackward();
            Sauce::IO::Debug::Print_Return("void",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::HEAP);
        }
        void ExpandHeap(size_t length){
            Sauce::IO::Debug::Print_Call("ExpandHeap",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::HEAP);
            Sauce::IO::Debug::Print_Detail(Sauce::Convert::ToString(length),Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::HEAP);
            if(length%0x1000){
                length-=length%0x1000;
                length+=0x1000;
            }
            size_t pageCount = length/0x1000;
            HeapSegmentHeader* newSegment = (HeapSegmentHeader*)heapEnd;
            for(size_t i=0;i<pageCount;i++){
                Sauce::Global::PageTableManager.MapMemory(heapEnd,Sauce::Global::PageFrameAllocator.RequestPage());
                heapEnd = (void*)((size_t)heapEnd+0x1000);
            }
            newSegment->free=true;
            newSegment->LastSegment=LastSegmentHeader;
            LastSegmentHeader->NextSegment=newSegment;
            LastSegmentHeader = newSegment;
            newSegment->NextSegment=NULL;
            newSegment->Length = length - sizeof(HeapSegmentHeader);
            newSegment->CombinedBackward();
            Sauce::IO::Debug::Print_Return("void",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::HEAP);
        }
    };
};