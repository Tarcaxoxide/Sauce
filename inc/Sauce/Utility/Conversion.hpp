#include<Sauce/Types.hpp>
#include<Sauce/Math.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
#pragma once
namespace Sauce{
	namespace Utility{
		namespace Conversion{
			char* HexToString(uint8_t value,bool ClearBefore=true);
			char* HexToString(uint16_t value,bool ClearBefore=true);
			char* HexToString(uint32_t value,bool ClearBefore=true);
			char* HexToString(uint64_t value,bool ClearBefore=true);
			char* ToString(int8_t value,bool ClearBefore=true);
			char* ToString(int16_t value,bool ClearBefore=true);
			char* ToString(int32_t value,bool ClearBefore=true);
			char* ToString(int64_t value,bool ClearBefore=true);
			char* ToString(uint8_t value,bool ClearBefore=true);
			char* ToString(uint16_t value,bool ClearBefore=true);
			char* ToString(uint32_t value,bool ClearBefore=true);
			char* ToString(uint64_t value,bool ClearBefore=true);
			char* ToString(float value,uint16_t decimalPlaces=4);
			char* ToString(double value,uint16_t decimalPlaces=4);
			uint64_t ToUint64(const char* value);
		}
	};
};
