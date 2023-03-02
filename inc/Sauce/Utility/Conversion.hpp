#ifndef __Sauce_Utility_Conversion
#define __Sauce_Utility_Conversion
#include<std/string.hpp>
#include<stddef.h>
#include<stdint.h>
#include<Sauce/Types.hpp>
namespace Sauce{
	namespace Utility{
		namespace Conversion{
			std::string HexToString(uint8_t value);
			std::string HexToString(uint16_t value);
			std::string HexToString(uint32_t value);
			std::string HexToString(uint64_t value);
			std::string ToString(int8_t value);
			std::string ToString(int16_t value);
			std::string ToString(int32_t value);
			std::string ToString(int64_t value);
			std::string ToString(uint8_t value);
			std::string ToString(uint16_t value);
			std::string ToString(uint32_t value);
			std::string ToString(uint64_t value);
			std::string ToString(float value,uint16_t decimalPlaces=4);
			std::string ToString(long double value,uint16_t decimalPlaces=4);
			///
			std::string ToString(Sauce::uPoint8_st value);
			std::string ToString(Sauce::uPoint16_st value);
			std::string ToString(Sauce::uPoint32_st value);
			std::string ToString(Sauce::uPoint64_st value);
			std::string ToString(Sauce::Point8_st value);
			std::string ToString(Sauce::Point16_st value);
			std::string ToString(Sauce::Point32_st value);
			std::string ToString(Sauce::Point64_st value);
			///
			int64_t ToInt64(std::string value);
			uint64_t ToUint64(std::string value);
			long double ToDouble(std::string value);
			Sauce::uPoint8_st TouPoint8(std::string value);
			Sauce::uPoint16_st TouPoint16(std::string value);
			Sauce::uPoint32_st TouPoint32(std::string value);
			Sauce::uPoint64_st TouPoint64(std::string value);
			Sauce::Point8_st ToPoint8(std::string value);
			Sauce::Point16_st ToPoint16(std::string value);
			Sauce::Point32_st ToPoint32(std::string value);
			Sauce::Point64_st ToPoint64(std::string value);
		}
	};
};
#endif