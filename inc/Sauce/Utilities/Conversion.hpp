#pragma once

#include<stddef.h>
#include<stdint.h>
#include<Sauce/Math/Types.hpp>
#include<Sauce/Math/Functions.hpp>

namespace Sauce{
	namespace Convert{
		//Hex 0x0123456789ABC
		char* HexToString(uint8_t value,bool ClearBefore=true);
		char* HexToString(uint16_t value,bool ClearBefore=true);
		char* HexToString(uint32_t value,bool ClearBefore=true);
		char* HexToString(uint64_t value,bool ClearBefore=true);
		//Numeric 1234567890
		char* ToString(int8_t value,bool ClearBefore=true);
		char* ToString(int16_t value,bool ClearBefore=true);
		char* ToString(int32_t value,bool ClearBefore=true);
		char* ToString(int64_t value,bool ClearBefore=true);
		char* ToString(uint8_t value,bool ClearBefore=true);
		char* ToString(uint16_t value,bool ClearBefore=true);
		char* ToString(uint32_t value,bool ClearBefore=true);
		char* ToString(uint64_t value,bool ClearBefore=true);
		//Decimal 0.0
		char* ToString(float value,uint16_t decimalPlaces=4);
		char* ToString(double value,uint16_t decimalPlaces=4);
    };
};
