#include<Sauce/Interrupts/IDT.hpp>
#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace Interrupts{
        void IDTDescriptorEntry::SetOffset(uint64_t offset){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::INTERRUPT_DESCRIPTOR_TABLE)Sauce::IO::Debug::COM1_Console.Write((char*)"[IDTDescriptorEntry::SetOffset]\n\0");
            offset0 = (uint16_t)(offset & 0x000000000000ffff);
            offset1 = (uint16_t)((offset & 0x00000000ffff0000) >> 16);
            offset2 = (uint32_t)((offset & 0xffffffff00000000) >> 32);
        }
        uint64_t IDTDescriptorEntry::GetOffset(){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::INTERRUPT_DESCRIPTOR_TABLE)Sauce::IO::Debug::COM1_Console.Write((char*)"[IDTDescriptorEntry::GetOffset]\n\0");
            uint64_t offset=0;
            offset |= (uint64_t)offset0;
            offset |= (uint64_t)offset1 << 16;
            offset |= (uint64_t)offset2 << 32;
            return offset;
        }
    };
};