#include <Memory.hpp>

extern uint8_t MemoryRegionCount;
extern uint16_t MemoryMapAddress;

extern "C" uint64_t GetFreeStack();
extern "C" uint64_t GetMaxStack();

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
            MemoryMapEntry* MemoryRegions[MemoryRegionCount];
            MemoryMapEntryMap ReturnValue ={MemoryRegions,0};
            uint8_t B=0;
            for (uint8_t A = 0; A < MemoryRegionCount;A++){
                Sauce::Memory::MemoryMapEntry* memMap = (Sauce::Memory::MemoryMapEntry*)MemoryMapAddress;
                memMap += A;
                if(memMap->Region_Type == Type){
                    ReturnValue.MemoryMapEntries[ReturnValue.MemoryMapEntryCount] = memMap;
                    Sauce::Convert::To_String::From_uint8(ReturnValue.MemoryMapEntryCount); // there is some witchcraft going on here.
                    Sauce::Memory::PrintMemoryMap(ReturnValue.MemoryMapEntries[ReturnValue.MemoryMapEntryCount]);
                    Sauce::Terminal::String("\n\r");
                    ReturnValue.MemoryMapEntryCount++;
                }
            }
            return ReturnValue;
        }
    };
};

