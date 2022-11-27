#include<Sauce/Memory/Paging.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utility/Conversion.hpp>

namespace Sauce{
    namespace Memory{
        void PageDirectoryEntry::SetFlag(PT_Flag flag,bool enabled){
            Sauce::IO::Debug::Debugger_st Debugger("PageDirectoryEntry::SetFlag",_NAMESPACE_,_ALLOW_PRINT_);
            uint64_t bitSelector = (uint64_t)1<< flag;
            Value &= ~bitSelector;
            if(enabled)Value |= bitSelector;
        }
        bool PageDirectoryEntry::GetFlag(PT_Flag flag){
            Sauce::IO::Debug::Debugger_st Debugger("PageDirectoryEntry::GetFlag",_NAMESPACE_,_ALLOW_PRINT_);
            uint64_t bitSelector = (uint64_t)1<< flag;
            bool Ret = Value & bitSelector > 0 ? true : false;
            return Ret;
        }
        void PageDirectoryEntry::SetAddress(uint64_t address){
            Sauce::IO::Debug::Debugger_st Debugger("PageDirectoryEntry::SetAddress",_NAMESPACE_,_ALLOW_PRINT_);
            address &= 0x000000ffffffffff;
            Value &= 0xfff0000000000fff;
            Value |= (address << 12);
        }
        uint64_t PageDirectoryEntry::GetAddress(){
            Sauce::IO::Debug::Debugger_st Debugger("PageDirectoryEntry::GetAddress",_NAMESPACE_,_ALLOW_PRINT_);
            uint64_t Ret = (Value & 0x000ffffffffff000) >> 12;
            return Ret;
        }
    };
};