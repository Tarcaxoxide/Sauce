#include<Sauce/Memory/Paging.hpp>
#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace Memory{
        void PageDirectoryEntry::SetFlag(PT_Flag flag,bool enabled){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageDirectoryEntry::SetFlag]\n\0");
            uint64_t bitSelector = (uint64_t)1<< flag;
            Value &= ~bitSelector;
            if(enabled)Value |= bitSelector;
        }
        bool PageDirectoryEntry::GetFlag(PT_Flag flag){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageDirectoryEntry::GetFlag]\n\0");
            uint64_t bitSelector = (uint64_t)1<< flag;
            return Value & bitSelector > 0 ? true : false;
        }
        void PageDirectoryEntry::SetAddress(uint64_t address){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageDirectoryEntry::SetAddress]\n\0");
            address &= 0x000000ffffffffff;
            Value &= 0xfff0000000000fff;
            Value |= (address << 12);
        }
        uint64_t PageDirectoryEntry::GetAddress(){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)"[PageDirectoryEntry::GetAddress]\n\0");
            return (Value & 0x000ffffffffff000) >> 12;
        }
    };
};