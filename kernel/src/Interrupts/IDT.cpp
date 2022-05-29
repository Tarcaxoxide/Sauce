#include<Sauce/Interrupts/IDT.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utilities/Conversion.hpp>

namespace Sauce{
    namespace Interrupts{
        void IDTDescriptorEntry::SetOffset(uint64_t offset){
            Sauce::IO::Debug::Print_Call("IDTDescriptorEntry::SetOffset",Sauce::IO::Debug::INTERRUPT_DESCRIPTOR_TABLE,true);
            offset0 = (uint16_t)(offset & 0x000000000000ffff);
            offset1 = (uint16_t)((offset & 0x00000000ffff0000) >> 16);
            offset2 = (uint32_t)((offset & 0xffffffff00000000) >> 32);
            Sauce::IO::Debug::Print_Return("void",Sauce::IO::Debug::INTERRUPT_DESCRIPTOR_TABLE,true);
        }
        uint64_t IDTDescriptorEntry::GetOffset(){
            Sauce::IO::Debug::Print_Call("IDTDescriptorEntry::GetOffset",Sauce::IO::Debug::INTERRUPT_DESCRIPTOR_TABLE,true);
            uint64_t offset=0;
            offset |= (uint64_t)offset0;
            offset |= (uint64_t)offset1 << 16;
            offset |= (uint64_t)offset2 << 32;
            Sauce::IO::Debug::Print_Return(Sauce::Convert::HexToString(offset),Sauce::IO::Debug::INTERRUPT_DESCRIPTOR_TABLE,true);
            return offset;
        }
    };
};