#include<Sauce/Memory/Bitmap.hpp>
#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace Memory{
        bool Bitmap_t::Get(uint64_t index){
            Sauce::IO::Debug::Print_Spammy_Call("Bitmap_t::Get",Sauce::IO::Debug::BITMAP && Sauce::IO::Debug::MEMORY);
            if(index > Size*8)return false;
            uint64_t byteIndex = index/8;
            uint8_t bitIndex = index%8;
            uint8_t bitIndexer = 0b10000000 >> bitIndex;
            if((Buffer[byteIndex] & bitIndexer) > 0){Sauce::IO::Debug::Print_Spammy_Return("True",Sauce::IO::Debug::BITMAP && Sauce::IO::Debug::MEMORY);return true;}
            Sauce::IO::Debug::Print_Spammy_Return("False",Sauce::IO::Debug::BITMAP && Sauce::IO::Debug::MEMORY);
            return false;
        }
        bool Bitmap_t::operator[](uint64_t index){
            Sauce::IO::Debug::Print_Spammy_Call("Bitmap_t::operator[]",Sauce::IO::Debug::BITMAP && Sauce::IO::Debug::MEMORY);
            bool Ret = Get(index);
            Ret? Sauce::IO::Debug::Print_Spammy_Return("True",Sauce::IO::Debug::BITMAP && Sauce::IO::Debug::MEMORY) : Sauce::IO::Debug::Print_Spammy_Return("False",Sauce::IO::Debug::BITMAP && Sauce::IO::Debug::MEMORY);
            return Ret;
        }
        bool Bitmap_t::Set(uint64_t index,bool value){
            Sauce::IO::Debug::Print_Spammy_Call("Bitmap_t::Set",Sauce::IO::Debug::BITMAP && Sauce::IO::Debug::MEMORY);
            if(index > Size*8){Sauce::IO::Debug::Print_Spammy_Return("False",Sauce::IO::Debug::BITMAP && Sauce::IO::Debug::MEMORY);return false;}
            uint64_t byteIndex = index/8;
            uint8_t bitIndex = index%8;
            uint8_t bitIndexer = 0b10000000 >> bitIndex;
            Buffer[byteIndex] &= ~bitIndexer;
            if(value)Buffer[byteIndex] |= bitIndexer;
            Sauce::IO::Debug::Print_Spammy_Return("True",Sauce::IO::Debug::BITMAP && Sauce::IO::Debug::MEMORY);
            return true;
        }
        bool Bitmap_t::Flip(uint64_t index){
            Sauce::IO::Debug::Print_Spammy_Call("Bitmap_t::Flip",Sauce::IO::Debug::BITMAP && Sauce::IO::Debug::MEMORY);
            bool Ret = Set(index,!Get(index));
            Ret? Sauce::IO::Debug::Print_Spammy_Return("True",Sauce::IO::Debug::BITMAP && Sauce::IO::Debug::MEMORY) : Sauce::IO::Debug::Print_Spammy_Return("False",Sauce::IO::Debug::BITMAP && Sauce::IO::Debug::MEMORY);
            return Ret;
        }
    };
};
