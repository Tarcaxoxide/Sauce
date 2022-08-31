#pragma once

#include<Sauce/Graphics/Terminal.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/Graphics/Font.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/Math/Types.hpp>
#include<Sauce/Math/Functions.hpp>

namespace Sauce{
    namespace Graphics{
        class Shell_cl : public Terminal_cl {
			Sauce::Math::Point64_t Cursor{0,0,0};
            Sauce::Memory::List_cl<wchar_t> CharBuffer;
            public:
                Shell_cl(Sauce::Math::Point64_t Size,Sauce::Math::Point64_t Offset={0,0,0});
                void PutChar(wchar_t chr,bool AddToBuffer=true);
                void PutString(const wchar_t* str,bool AddToBuffer=true);
                void PutString(const char* str,bool AddToBuffer=true);
                bool GoDown(size_t amount=1);
                bool GoUp(size_t amount=1);
                bool GoRight(size_t amount=1);
                bool GoLeft(size_t amount=1);
                void GoFarDown();
                void GoFarUp();
                void GoFarRight();
                void GoFarLeft();
                void RunCmd();
        };
    };
};
