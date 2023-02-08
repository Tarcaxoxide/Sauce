#include<Sauce/IO/Debug/Serial.hpp>
#pragma once
namespace Sauce{
    namespace IO{
        namespace Debug{
            class Console_cl{
                uint16_t DebugComPort;
                bool ready=false;
                public:
                void Initialize(uint16_t DebugComPort);
                void Write(const char* str);
            };
            extern Console_cl COM1_Console;
            extern Console_cl COM2_Console;
            extern Console_cl COM3_Console;
            extern Console_cl COM4_Console;
            extern Console_cl COM5_Console;
            extern Console_cl COM6_Console;
            extern Console_cl COM7_Console;
            extern Console_cl COM8_Console;

            enum StartOfPrint{
                Single=0,
                Start,
                Middle,
                End
            };
        };
    };
};
