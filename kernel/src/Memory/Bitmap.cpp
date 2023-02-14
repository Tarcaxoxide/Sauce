#include<Sauce/Memory/Bitmap.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
    namespace Memory{
        namespace Management{
            bool Bitmap_t::Get(uint64_t index){
                Sauce::IO::Debug::Debugger_st Debugger("Bitmap_t::Get",_NAMESPACE_,_ALLOW_PRINT_);
                if(index > Size*8)return false;
                uint64_t byteIndex = index/8;
                uint8_t bitIndex = index%8;
                uint8_t bitIndexer = 0b10000000 >> bitIndex;
                if((Buffer[byteIndex] & bitIndexer) > 0){return true;}
                return false;
            }
            bool Bitmap_t::operator[](uint64_t index){
                Sauce::IO::Debug::Debugger_st Debugger("Bitmap_t::operator[]",_NAMESPACE_,_ALLOW_PRINT_);
                bool Ret = Get(index);
                return Ret;
            }
            bool Bitmap_t::Set(uint64_t index,bool value){
                Sauce::IO::Debug::Debugger_st Debugger("Bitmap_t::Set",_NAMESPACE_,_ALLOW_PRINT_);
                if(index > Size*8){return false;}
                uint64_t byteIndex = index/8;
                uint8_t bitIndex = index%8;
                uint8_t bitIndexer = 0b10000000 >> bitIndex;
                Buffer[byteIndex] &= ~bitIndexer;
                if(value)Buffer[byteIndex] |= bitIndexer;
                return true;
            }
            bool Bitmap_t::Flip(uint64_t index){
                Sauce::IO::Debug::Debugger_st Debugger("Bitmap_t::Flip",_NAMESPACE_,_ALLOW_PRINT_);
                bool Ret = Set(index,!Get(index));
                return Ret;
            }
        };
    };
};
