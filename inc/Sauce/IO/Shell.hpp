#pragma once
#include<stddef.h>
#include<stdint.h>
#include<Sauce/Common.h>
#include<Sauce/Math.hpp>
#include<Sauce/IO/InputData.hpp>
#include<Sauce/IO/Terminal.hpp>


namespace Sauce{
    namespace Shell{
        class Kshell{
            Kshell* Self=NULL;
            DataStructure* DFBL;
            Sauce::IO::Terminal Term;
            static Sauce::IO::Mouse_st* MouseRef;
            public:
                Kshell(DataStructure* DFBL); 
                void InputKeyboard(Sauce::IO::Keyboard_st xKeyboard);
                void InputMouse(Sauce::IO::Mouse_st* xMouse);
                void SetMouse(Point64_t NewMousePosition);
        };
    };
};