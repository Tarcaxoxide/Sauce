#include<Sauce/Interrupts/PIT.hpp>
#include<Sauce/IO/IO.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Convert/To_String.hpp>

namespace Sauce{
    namespace Interrupts{
        namespace PIT{
            double TimeSinceBoot = 0;
            uint16_t Divisor=65535;
            void Sleepd(double seconds){
                Sauce::IO::Debug::COM1_Console.Write((char*)"[Sleepd] ->(\0");
                Sauce::IO::Debug::COM1_Console.Write(Sauce::Convert::ToString(seconds));
                Sauce::IO::Debug::COM1_Console.Write((char*)")\n\0");
                double startTime = TimeSinceBoot;
                while(TimeSinceBoot < startTime+seconds){
                    asm("hlt");
                }
            }
            void Sleep(uint64_t milliseconds){
                Sleepd((double)milliseconds/1000);
            }
            void SetDivisor(uint16_t divisor){
                if(divisor < 100)divisor=100;
                Divisor=divisor;
                Sauce::IO::outb_w(0x40,(uint8_t)(Divisor & 0x00ff));
                Sauce::IO::outb_w(0x40,(uint8_t)((Divisor & 0xff00)>>8));

            }
            uint64_t GetFrequency(){
                return BaseFrequency/Divisor;
            }
            void SetFrequency(uint64_t frequency){
                SetDivisor(BaseFrequency/frequency);
            }
            void Tick(){
                TimeSinceBoot += 1 / (double)GetFrequency();
            }
        };
    };
};