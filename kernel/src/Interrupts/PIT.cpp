#include<Sauce/Interrupts/PIT.hpp>
#include<Sauce/IO/IO.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utilities/Conversion.hpp>

namespace Sauce{
    namespace Interrupts{
        namespace PIT{
            double TimeSinceBoot = 0;
            uint16_t Divisor=65535;
            void Sleepd(double seconds){
                Sauce::IO::Debug::Print_Spammy_Call("Sleepd",Sauce::IO::Debug::INTERRUPT_PIT,true);
                Sauce::IO::Debug::Print_Spammy_Detail(Sauce::Convert::ToString(seconds),Sauce::IO::Debug::INTERRUPT_PIT,true);
                double startTime = TimeSinceBoot;
                while(TimeSinceBoot < startTime+seconds){
                    asm("hlt");
                }
                Sauce::IO::Debug::Print_Spammy_Return("void",Sauce::IO::Debug::INTERRUPT_PIT,true);
            }
            void Sleep(uint64_t milliseconds){
                Sauce::IO::Debug::Print_Spammy_Call("Sleep",Sauce::IO::Debug::INTERRUPT_PIT,true);
                Sleepd((double)milliseconds/1000);
                Sauce::IO::Debug::Print_Spammy_Return("void",Sauce::IO::Debug::INTERRUPT_PIT,true);
            }
            void SetDivisor(uint16_t divisor){
                Sauce::IO::Debug::Print_Spammy_Call("SetDivisor",Sauce::IO::Debug::INTERRUPT_PIT,true);
                if(divisor < 100)divisor=100;
                Divisor=divisor;
                Sauce::IO::outb_w(0x40,(uint8_t)(Divisor & 0x00ff));
                Sauce::IO::outb_w(0x40,(uint8_t)((Divisor & 0xff00)>>8));
                Sauce::IO::Debug::Print_Spammy_Return("void",Sauce::IO::Debug::INTERRUPT_PIT,true);
            }
            uint64_t GetFrequency(){
                Sauce::IO::Debug::Print_Spammy_Call("GetFrequency",Sauce::IO::Debug::INTERRUPT_PIT,true);
                Sauce::IO::Debug::Print_Spammy_Return(Sauce::Convert::ToString(BaseFrequency/Divisor),Sauce::IO::Debug::INTERRUPT_PIT,true);
                return BaseFrequency/Divisor;
            }
            void SetFrequency(uint64_t frequency){
                Sauce::IO::Debug::Print_Spammy_Call("SetFrequency",Sauce::IO::Debug::INTERRUPT_PIT,true);
                SetDivisor(BaseFrequency/frequency);
                Sauce::IO::Debug::Print_Spammy_Return("void",Sauce::IO::Debug::INTERRUPT_PIT,true);
            }
            void Tick(){
                Sauce::IO::Debug::Print_Spammy_Call("Tick",Sauce::IO::Debug::INTERRUPT_PIT,true);
                TimeSinceBoot += 1 / (double)GetFrequency();
                Sauce::IO::Debug::Print_Spammy_Return("void",Sauce::IO::Debug::INTERRUPT_PIT,true);
            }
        };
    };
};