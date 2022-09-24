#pragma once

#include<Sauce/Types.hpp>
#include<Sauce/Math/Functions.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

#define PS2LeftButton 0b00000001
#define PS2RightButton 0b00000010
#define PS2MiddleButton 0b00000100
#define PS2XSign 0b00010000
#define PS2YSign 0b00100000
#define PS2XOverflow 0b01000000
#define PS2YOverflow 0b10000000

namespace Sauce{
    namespace IO{
        void MouseWait(Sauce::IO::Debug::Debugger_st* pDebugger);
        void MouseWaitInput(Sauce::IO::Debug::Debugger_st* pDebugger);
        void MouseWrite(Sauce::IO::Debug::Debugger_st* pDebugger,uint8_t value);
        uint8_t MouseRead(Sauce::IO::Debug::Debugger_st* pDebugger);
        void HandlePS2Mouse(Sauce::IO::Debug::Debugger_st* pDebugger,uint8_t data);
        Sauce::Mouse_st* ProcessMousePacket(Sauce::IO::Debug::Debugger_st* pDebugger);
        void PS2MouseInitialize(Sauce::IO::Debug::Debugger_st* pDebugger,Sauce::Point64_st InitMousePosition);
        extern Sauce::Point64_st MousePosition;
    };
};
