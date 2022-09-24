#include<Sauce/Memory/Paging.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utility/Conversion.hpp>

namespace Sauce{
    namespace Memory{
        void PageDirectoryEntry::SetFlag(Sauce::IO::Debug::Debugger_st* pDebugger,PT_Flag flag,bool enabled){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"PageDirectoryEntry::SetFlag");
            uint64_t bitSelector = (uint64_t)1<< flag;
            Value &= ~bitSelector;
            if(enabled)Value |= bitSelector;
        }
        bool PageDirectoryEntry::GetFlag(Sauce::IO::Debug::Debugger_st* pDebugger,PT_Flag flag){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"PageDirectoryEntry::GetFlag");
            uint64_t bitSelector = (uint64_t)1<< flag;
            bool Ret = Value & bitSelector > 0 ? true : false;
            return Ret;
        }
        void PageDirectoryEntry::SetAddress(Sauce::IO::Debug::Debugger_st* pDebugger,uint64_t address){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"PageDirectoryEntry::SetAddress");
            address &= 0x000000ffffffffff;
            Value &= 0xfff0000000000fff;
            Value |= (address << 12);
        }
        uint64_t PageDirectoryEntry::GetAddress(Sauce::IO::Debug::Debugger_st* pDebugger){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"PageDirectoryEntry::GetAddress");
            uint64_t Ret = (Value & 0x000ffffffffff000) >> 12;
            return Ret;
        }
    };
};