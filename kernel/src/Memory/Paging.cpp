#include<Sauce/Memory/Paging.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utilities/Conversion.hpp>

namespace Sauce{
    namespace Memory{
        void PageDirectoryEntry::SetFlag(PT_Flag flag,bool enabled){
            Sauce::IO::Debug::Print_Spammy_Call("PageDirectoryEntry::SetFlag",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::PAGING);
            uint64_t bitSelector = (uint64_t)1<< flag;
            Value &= ~bitSelector;
            if(enabled)Value |= bitSelector;
            Sauce::IO::Debug::Print_Spammy_Return("<void>",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::PAGING);
        }
        bool PageDirectoryEntry::GetFlag(PT_Flag flag){
            Sauce::IO::Debug::Print_Spammy_Call("PageDirectoryEntry::GetFlag",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::PAGING);
            uint64_t bitSelector = (uint64_t)1<< flag;
            bool Ret = Value & bitSelector > 0 ? true : false;
            Ret? Sauce::IO::Debug::Print_Spammy_Return("<True>",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::PAGING) : Sauce::IO::Debug::Print_Spammy_Return("<False>",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::PAGING);
            return Ret;
        }
        void PageDirectoryEntry::SetAddress(uint64_t address){
            Sauce::IO::Debug::Print_Spammy_Call("PageDirectoryEntry::SetAddress",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::PAGING);
            address &= 0x000000ffffffffff;
            Value &= 0xfff0000000000fff;
            Value |= (address << 12);
            Sauce::IO::Debug::Print_Spammy_Return("<void>",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::PAGING);
        }
        uint64_t PageDirectoryEntry::GetAddress(){
            Sauce::IO::Debug::Print_Spammy_Call("PageDirectoryEntry::GetAddress",Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::PAGING);
            uint64_t Ret = (Value & 0x000ffffffffff000) >> 12;
            Sauce::IO::Debug::Print_Spammy_Return(Sauce::Convert::HexToString(Ret),Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::PAGING);
            return Ret;
        }
    };
};