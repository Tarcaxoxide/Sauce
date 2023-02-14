#include<_std/string.hpp>
#include<stddef.h>
#include<stdint.h>
#pragma once
namespace Sauce{
	namespace Utility{
		namespace Conversion{
			_std::string HexToString(uint8_t value,bool ClearBefore=true);
			_std::string HexToString(uint16_t value,bool ClearBefore=true);
			_std::string HexToString(uint32_t value,bool ClearBefore=true);
			_std::string HexToString(uint64_t value,bool ClearBefore=true);
			_std::string ToString(int8_t value,bool ClearBefore=true);
			_std::string ToString(int16_t value,bool ClearBefore=true);
			_std::string ToString(int32_t value,bool ClearBefore=true);
			_std::string ToString(int64_t value,bool ClearBefore=true);
			_std::string ToString(uint8_t value,bool ClearBefore=true);
			_std::string ToString(uint16_t value,bool ClearBefore=true);
			_std::string ToString(uint32_t value,bool ClearBefore=true);
			_std::string ToString(uint64_t value,bool ClearBefore=true);
			_std::string ToString(float value,uint16_t decimalPlaces=4);
			_std::string ToString(double value,uint16_t decimalPlaces=4);
			uint64_t ToUint64(_std::string value);
		}
	};
};
