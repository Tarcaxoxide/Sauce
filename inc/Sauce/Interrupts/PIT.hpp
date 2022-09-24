#pragma once

#include<stddef.h>
#include<stdint.h>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
    namespace Interrupts{
        namespace PIT{
            extern double TimeSinceBoot;
            const uint64_t BaseFrequency = 1193182;
            void Sleepd(Sauce::IO::Debug::Debugger_st* pDebugger,double seconds);
            void Sleep(Sauce::IO::Debug::Debugger_st* pDebugger,uint64_t milliseconds);
            void SetDivisor(Sauce::IO::Debug::Debugger_st* pDebugger,uint16_t divisor);
            uint64_t GetFrequency(Sauce::IO::Debug::Debugger_st* pDebugger);
            void SetFrequency(Sauce::IO::Debug::Debugger_st* pDebugger,uint64_t frequency);
            void Tick(Sauce::IO::Debug::Debugger_st* pDebugger);
        };
    };
};