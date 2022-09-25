#include<Sauce/Memory/Bitmap.hpp>
#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace Memory{
        bool Bitmap_t::Get(Sauce::IO::Debug::Debugger_st* pDebugger,uint64_t index){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Bitmap_t::Get",_NAMESPACE_);
            if(index > Size*8)return false;
            uint64_t byteIndex = index/8;
            uint8_t bitIndex = index%8;
            uint8_t bitIndexer = 0b10000000 >> bitIndex;
            if((Buffer[byteIndex] & bitIndexer) > 0){return true;}
            return false;
        }
        bool Bitmap_t::operator[](uint64_t index){
            Sauce::IO::Debug::Debugger_st Debugger("Bitmap_t::operator[]",_NAMESPACE_);
            bool Ret = Get(&Debugger,index);
            return Ret;
        }
        bool Bitmap_t::Set(Sauce::IO::Debug::Debugger_st* pDebugger,uint64_t index,bool value){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Bitmap_t::Set",_NAMESPACE_);
            if(index > Size*8){return false;}
            uint64_t byteIndex = index/8;
            uint8_t bitIndex = index%8;
            uint8_t bitIndexer = 0b10000000 >> bitIndex;
            Buffer[byteIndex] &= ~bitIndexer;
            if(value)Buffer[byteIndex] |= bitIndexer;
            return true;
        }
        bool Bitmap_t::Flip(Sauce::IO::Debug::Debugger_st* pDebugger,uint64_t index){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Bitmap_t::Flip",_NAMESPACE_);
            bool Ret = Set(&Debugger,index,!Get(&Debugger,index));
            return Ret;
        }
    };
};
