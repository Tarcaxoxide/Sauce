#pragma once

#include<Sauce/Graphics/Terminal.hpp>
#include<Sauce/Memory/Memory.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/Graphics/Font.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/Math/Types.hpp>
#include<Sauce/Math/Functions.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
#include<std/string.hpp>
#include<std/iostream.hpp>

namespace Sauce{
    namespace Graphics{
        class Shell_cl : public Terminal_cl {
			Sauce::Point64_st Cursor{0,0,0};
            std::string CharBuffer;
            public:
                Shell_cl(Sauce::Point64_st Size,Sauce::Point64_st Offset={0,0,0});
                void PutChar(char chr,bool AddToBuffer);
                void PutString(std::string str,bool AddToBuffer);
                bool GoDown(size_t amount=1);
                bool GoUp(size_t amount=1);
                bool GoRight(size_t amount=1);
                bool GoLeft(size_t amount=1);
                void GoFarDown();
                void GoFarUp();
                void GoFarRight();
                void GoFarLeft();
                void ParseAndRunCommand();
                void ShellClear(bool ClearScreen);
        };
    };
};
