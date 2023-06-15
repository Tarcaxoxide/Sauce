#include<Sauce/Interrupts/PIT.hpp>
#include<Sauce/IO/IO.hpp>
#include<std/to_string.hpp>

namespace Sauce{
	namespace Interrupts{
		namespace PIT{
			long double TimeSinceBoot = 0;
			uint16_t Divisor=65535;
			void Sleepd(long double seconds){
				long double startTime = TimeSinceBoot;
				while(TimeSinceBoot < startTime+seconds){
					asm("hlt");
				}
			}
			void Sleep(uint64_t milliseconds){
				Sleepd((long double)milliseconds/1000);
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
				TimeSinceBoot += 1 / (long double)GetFrequency();
			}
			long double GetTimeSinceBoot(){return TimeSinceBoot;}
		};
	};
};