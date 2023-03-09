#include<Sauce/IO/RTC.hpp>
#include<std/to_string.hpp>

namespace Sauce{
	namespace IO{
		namespace RTC{
			int32_t RTC_cl::get_update_in_progress_flag(){
				Sauce::IO::outb(cmos_address, 0x0A);
      			return (Sauce::IO::inb(cmos_data) & 0x80);
			}
			uint8_t RTC_cl::get_RTC_register(int reg){
				Sauce::IO::outb(cmos_address, reg);
      			return Sauce::IO::inb(cmos_data);
			}
			void RTC_cl::read_rtc(){
				uint8_t century;
      			uint8_t last_second;
      			uint8_t last_minute;
      			uint8_t last_hour;
      			uint8_t last_day;
      			uint8_t last_month;
      			uint8_t last_year;
      			uint8_t last_century;
      			uint8_t registerB;
				while (get_update_in_progress_flag()){} // Make sure an update isn't in progress
				second = get_RTC_register(0x00);
      			minute = get_RTC_register(0x02);
      			hour = get_RTC_register(0x04);
      			day = get_RTC_register(0x07);
      			month = get_RTC_register(0x08);
      			year = get_RTC_register(0x09);
				if(century_register != 0) {
      			      century = get_RTC_register(century_register);
      			}
				do {
            		last_second = second;
            		last_minute = minute;
            		last_hour = hour;
            		last_day = day;
            		last_month = month;
            		last_year = year;
            		last_century = century;
            		while(get_update_in_progress_flag()){} // Make sure an update isn't in progress
      				second = get_RTC_register(0x00);
      				minute = get_RTC_register(0x02);
      				hour = get_RTC_register(0x04);
      				day = get_RTC_register(0x07);
      				month = get_RTC_register(0x08);
      				year = get_RTC_register(0x09);
      				if(century_register != 0) {
      				    century = get_RTC_register(century_register);
      				}
      			} while( (last_second != second) || (last_minute != minute) || (last_hour != hour) || (last_day != day) || (last_month != month) || (last_year != year) || (last_century != century) );
				registerB = get_RTC_register(0x0B);
				if (!(registerB & 0x04)) {
      			      second = (second & 0x0F) + ((second / 16) * 10);
      			      minute = (minute & 0x0F) + ((minute / 16) * 10);
      			      hour = ( (hour & 0x0F) + (((hour & 0x70) / 16) * 10) ) | (hour & 0x80);
      			      day = (day & 0x0F) + ((day / 16) * 10);
      			      month = (month & 0x0F) + ((month / 16) * 10);
      			      year = (year & 0x0F) + ((year / 16) * 10);
      			      if(century_register != 0) {
      			            century = (century & 0x0F) + ((century / 16) * 10);
      			      }
      			}
				if (!(registerB & 0x02) && (hour & 0x80)) { // Convert 12 hour clock to 24 hour clock if necessary
      			      hour = ((hour & 0x7F) + 12) % 24;
      			}
				if(century_register != 0) {
      			      year += century * 100;
      			} else {
      			      year += (CURRENT_YEAR / 100) * 100;
      			      if(year < CURRENT_YEAR) year += 100;
      			}
			}
			RTC_cl::RTC_cl(){
				Update();
			}
			void RTC_cl::Update(){
				read_rtc();
			}
			std::string RTC_cl::ToString(){
				std::string Result="";
				Result+=std::to_string(year);
				Result+=":";
				Result+=std::to_string(month);
				Result+=":";
				Result+=std::to_string(day);
				Result+=":";
				Result+=std::to_string(hour);
				Result+=":";
				Result+=std::to_string(minute);
				Result+=":";
				Result+=std::to_string(second);
				return Result;
			}
		};
	};
};