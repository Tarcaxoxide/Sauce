#include<Sauce/Interrupts/PIT.hpp>
#include<Sauce/IO/IO.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utility/Conversion.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
	namespace Interrupts{
		namespace PIT{
			long double TimeSinceBoot = 0;
			uint16_t Divisor=65535;
			void Sleepd(long double seconds){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Sleepd",_NAMESPACE_,_ALLOW_PRINT_);
				Debugger.Print(Sauce::Utility::Conversion::ToString(seconds));
				long double startTime = TimeSinceBoot;
				while(TimeSinceBoot < startTime+seconds){
					asm("hlt");
				}
			}
			void Sleep(uint64_t milliseconds){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Sleep",_NAMESPACE_,_ALLOW_PRINT_);
				Sleepd((long double)milliseconds/1000);
			}
			void SetDivisor(uint16_t divisor){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"SetDivisor",_NAMESPACE_,_ALLOW_PRINT_);
				if(divisor < 100)divisor=100;
				Divisor=divisor;
				Sauce::IO::outb_w(0x40,(uint8_t)(Divisor & 0x00ff));
				Sauce::IO::outb_w(0x40,(uint8_t)((Divisor & 0xff00)>>8));
			}
			uint64_t GetFrequency(){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"GetFrequency",_NAMESPACE_,_ALLOW_PRINT_);
				return BaseFrequency/Divisor;
			}
			void SetFrequency(uint64_t frequency){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"SetFrequency",_NAMESPACE_,_ALLOW_PRINT_);
				SetDivisor(BaseFrequency/frequency);
			}
			void Tick(){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Tick",_NAMESPACE_,_ALLOW_PRINT_);
				TimeSinceBoot += 1 / (long double)GetFrequency();
			}
			long double GetTimeSinceBoot(){return TimeSinceBoot;}
		};
	};
};