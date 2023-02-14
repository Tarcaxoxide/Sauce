#include<Sauce/Interrupts/IDT.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utility/Conversion.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
    namespace Interrupts{
        void IDTDescriptorEntry::SetOffset(uint64_t offset){
            Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"IDTDescriptorEntry::SetOffset",_NAMESPACE_,_ALLOW_PRINT_);
            offset0 = (uint16_t)(offset & 0x000000000000ffff);
            offset1 = (uint16_t)((offset & 0x00000000ffff0000) >> 16);
            offset2 = (uint32_t)((offset & 0xffffffff00000000) >> 32);
        }
        uint64_t IDTDescriptorEntry::GetOffset(){
            Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"IDTDescriptorEntry::GetOffset",_NAMESPACE_,_ALLOW_PRINT_);
            uint64_t offset=0;
            offset |= (uint64_t)offset0;
            offset |= (uint64_t)offset1 << 16;
            offset |= (uint64_t)offset2 << 32;
            return offset;
        }
    };
};