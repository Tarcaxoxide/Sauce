#include<Sauce/Memory/Bitmap.hpp>
#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace Memory{
        bool Bitmap_t::Get(uint64_t index){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::BITMAP && Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)"[Bitmap_t::Get]\n\0");
            if(index > Size*8)return false;
            uint64_t byteIndex = index/8;
            uint8_t bitIndex = index%8;
            uint8_t bitIndexer = 0b10000000 >> bitIndex;
            if((Buffer[byteIndex] & bitIndexer) > 0)return true;
            return false;
        }
        bool Bitmap_t::operator[](uint64_t index){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::BITMAP && Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)"[Bitmap_t::operator[]]\n\0");
            return Get(index);
        }
        bool Bitmap_t::Set(uint64_t index,bool value){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::BITMAP && Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)"[Bitmap_t::Set]\n\0");
            if(index > Size*8)return false;
            uint64_t byteIndex = index/8;
            uint8_t bitIndex = index%8;
            uint8_t bitIndexer = 0b10000000 >> bitIndex;
            Buffer[byteIndex] &= ~bitIndexer;
            if(value)Buffer[byteIndex] |= bitIndexer;
            return true;
        }
        bool Bitmap_t::Flip(uint64_t index){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::BITMAP && Sauce::IO::Debug::MEMORY && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)"[Bitmap_t::Flip]\n\0");
            return Set(index,!Get(index));
        }
    };
};
