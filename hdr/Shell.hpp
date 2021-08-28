#pragma once

#include <Keyboard.hpp>
#include <Terminal.hpp>
#include <Utils.hpp>

namespace Sauce{
    namespace Shell{
        
        void KeyPress(Sauce::Keyboard::KeyboardKey _Key);
        void ClockTick();
        void Command(char* cmd);
        void ClearBuffer();
    };
};