#pragma once
#include<stddef.h>
#include<stdint.h>
#include<Sauce/Memory/PageFrameAllocator.hpp>
#include<Sauce/Memory/PageTableManager.hpp>
#include<Sauce/IO/Terminal.hpp>
#include<Sauce/Math.hpp>
#include<Sauce/IO/InputData.hpp>
#include<Sauce/Common.h>
#include<Sauce/Convert/To_String.hpp>


namespace Sauce{
    namespace Shell{
        class Kshell{
            Kshell* Self=NULL;
            DataStructure* DFBL;
            Sauce::IO::Terminal Term;
            public:
                Kshell(DataStructure* DFBL); 
                void InputKeyboard(Sauce::IO::Keyboard_st xKeyboard);
                void InputMouse(Sauce::IO::Mouse_st* xMouse);
        };
    };
};