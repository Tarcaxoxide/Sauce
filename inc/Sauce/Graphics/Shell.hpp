#pragma once

#include<Sauce/Graphics/Terminal.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/Graphics/Font.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/Types.hpp>
#include<Sauce/Math/Functions.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
    namespace Graphics{
        class Shell_cl : public Terminal_cl {
			Sauce::Point64_st Cursor{0,0,0};
            Sauce::Memory::List_cl<wchar_t> CharBuffer;
            public:
                Shell_cl(Sauce::Point64_st Size,Sauce::Point64_st Offset={0,0,0});
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
                void ShellClear();
        };
    };
};
