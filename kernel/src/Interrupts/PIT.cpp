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
                if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::INTERRUPT_PIT)Sauce::IO::Debug::COM1_Console.Write((char*)"[Sleepd]\n\0");
                if(Sauce::IO::Debug::FUNCTION_DETAILS && Sauce::IO::Debug::INTERRUPT_PIT)Sauce::IO::Debug::COM1_Console.Write((char*)"\t->(\0");
                if(Sauce::IO::Debug::FUNCTION_DETAILS && Sauce::IO::Debug::INTERRUPT_PIT)Sauce::IO::Debug::COM1_Console.Write(Sauce::Convert::ToString(seconds));
                if(Sauce::IO::Debug::FUNCTION_DETAILS && Sauce::IO::Debug::INTERRUPT_PIT)Sauce::IO::Debug::COM1_Console.Write((char*)")\n\0");
                double startTime = TimeSinceBoot;
                while(TimeSinceBoot < startTime+seconds){
                    asm("hlt");
                }
                if(Sauce::IO::Debug::FUNCTION_RETURNS && Sauce::IO::Debug::INTERRUPT_PIT)Sauce::IO::Debug::COM1_Console.Write((char*)"\t<-(void)\n\0");
            }
            void Sleep(uint64_t milliseconds){
                if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::INTERRUPT_PIT)Sauce::IO::Debug::COM1_Console.Write((char*)"[Sleep]\n\0");
                Sleepd((double)milliseconds/1000);
                if(Sauce::IO::Debug::FUNCTION_RETURNS && Sauce::IO::Debug::INTERRUPT_PIT)Sauce::IO::Debug::COM1_Console.Write((char*)"\t<-(void)\n\0");
            }
            void SetDivisor(uint16_t divisor){
                if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::INTERRUPT_PIT)Sauce::IO::Debug::COM1_Console.Write((char*)"[SetDivisor]\n\0");
                if(divisor < 100)divisor=100;
                Divisor=divisor;
                Sauce::IO::outb_w(0x40,(uint8_t)(Divisor & 0x00ff));
                Sauce::IO::outb_w(0x40,(uint8_t)((Divisor & 0xff00)>>8));
                if(Sauce::IO::Debug::FUNCTION_RETURNS && Sauce::IO::Debug::INTERRUPT_PIT)Sauce::IO::Debug::COM1_Console.Write((char*)"\t<-(void)\n\0");
            }
            uint64_t GetFrequency(){
                if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::INTERRUPT_PIT && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)"[GetFrequency]\n\0");
                
                if(Sauce::IO::Debug::FUNCTION_RETURNS && Sauce::IO::Debug::INTERRUPT_PIT){
                    Sauce::IO::Debug::COM1_Console.Write((char*)"\t<-(\0");
                    Sauce::IO::Debug::COM1_Console.Write(Sauce::Convert::ToString(BaseFrequency/Divisor));
                    Sauce::IO::Debug::COM1_Console.Write((char*)")\n\0");
                }
                return BaseFrequency/Divisor;
            }
            void SetFrequency(uint64_t frequency){
                if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::INTERRUPT_PIT)Sauce::IO::Debug::COM1_Console.Write((char*)"[SetFrequency]\n\0");
                SetDivisor(BaseFrequency/frequency);
                if(Sauce::IO::Debug::FUNCTION_RETURNS && Sauce::IO::Debug::INTERRUPT_PIT)Sauce::IO::Debug::COM1_Console.Write((char*)"\t<-(void)\n\0");
            }
            void Tick(){
                if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::INTERRUPT_PIT && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)"[Tick]\n\0");
                TimeSinceBoot += 1 / (double)GetFrequency();
                if(Sauce::IO::Debug::FUNCTION_RETURNS && Sauce::IO::Debug::INTERRUPT_PIT && Sauce::IO::Debug::SPAMMY)Sauce::IO::Debug::COM1_Console.Write((char*)"\t<-(void)\n\0");
            }
        };
    };
};