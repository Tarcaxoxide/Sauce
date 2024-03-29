#ifndef __Sauce_Interrupts_PIT
#define __Sauce_Interrupts_PIT
#include<stddef.h>
#include<stdint.h>
namespace Sauce{
	namespace Interrupts{
		namespace PIT{
			extern long double TimeSinceBoot;
			const uint64_t BaseFrequency = 1193182;
			void Sleepd(long double seconds);
			void Sleep(uint64_t milliseconds);
			void SetDivisor(uint16_t divisor);
			uint64_t GetFrequency();
			void SetFrequency(uint64_t frequency);
			void Tick();
			long double GetTimeSinceBoot();
		};
	};
};
#endif