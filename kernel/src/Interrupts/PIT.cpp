#include<Sauce/Interrupts/PIT.hpp>
#include<Sauce/IO/IO.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utility/Conversion.hpp>

namespace Sauce{
    namespace Interrupts{
        namespace PIT{
            double TimeSinceBoot = 0;
            uint16_t Divisor=65535;
            void Sleepd(Sauce::IO::Debug::Debugger_st* pDebugger,double seconds){
                Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Sleepd");
                Debugger.Print(Sauce::Utility::ToString(&Debugger,seconds));
                double startTime = TimeSinceBoot;
                while(TimeSinceBoot < startTime+seconds){
                    asm("hlt");
                }
            }
            void Sleep(Sauce::IO::Debug::Debugger_st* pDebugger,uint64_t milliseconds){
                Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Sleep");
                Sleepd(&Debugger,(double)milliseconds/1000);
            }
            void SetDivisor(Sauce::IO::Debug::Debugger_st* pDebugger,uint16_t divisor){
                Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"SetDivisor");
                if(divisor < 100)divisor=100;
                Divisor=divisor;
                Sauce::IO::outb_w(0x40,(uint8_t)(Divisor & 0x00ff));
                Sauce::IO::outb_w(0x40,(uint8_t)((Divisor & 0xff00)>>8));
            }
            uint64_t GetFrequency(Sauce::IO::Debug::Debugger_st* pDebugger){
                Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"GetFrequency");
                return BaseFrequency/Divisor;
            }
            void SetFrequency(Sauce::IO::Debug::Debugger_st* pDebugger,uint64_t frequency){
                Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"SetFrequency");
                SetDivisor(&Debugger,BaseFrequency/frequency);
            }
            void Tick(Sauce::IO::Debug::Debugger_st* pDebugger){
                Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Tick");
                TimeSinceBoot += 1 / (double)GetFrequency(&Debugger);
            }
        };
    };
};