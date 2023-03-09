#ifndef __Sauce_IO_RTC
#define __Sauce_IO_RTC
#include<Sauce/Types.hpp>
#include<Sauce/IO/IO.hpp>
#include<std/string.hpp>
namespace Sauce{
	namespace IO{
		namespace RTC{
			class RTC_cl{
				uint32_t century_register = 0x00; // Set by ACPI table parsing code if possible
				uint8_t second;
				uint8_t minute;
				uint8_t hour;
				uint8_t day;
				uint8_t month;
				uint32_t year;
				const static uint16_t cmos_address = 0x70;
				const static uint16_t cmos_data = 0x71;
				const static uint64_t CURRENT_YEAR=2023;
				private:
					int32_t get_update_in_progress_flag();
					uint8_t get_RTC_register(int reg);
					void read_rtc();
				public:
					RTC_cl();
					void Update();
					std::string ToString();
			};
		};
	};
};
#endif