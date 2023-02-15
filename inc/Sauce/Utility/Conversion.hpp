#pragma once
#include<_std/string.hpp>
#include<stddef.h>
#include<stdint.h>
#include<Sauce/Types.hpp>
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
			_std::string ToString(long double value,uint16_t decimalPlaces=4);
			///
			_std::string ToString(Sauce::uPoint8_st value);
			_std::string ToString(Sauce::uPoint16_st value);
			_std::string ToString(Sauce::uPoint32_st value);
			_std::string ToString(Sauce::uPoint64_st value);
			_std::string ToString(Sauce::Point8_st value);
			_std::string ToString(Sauce::Point16_st value);
			_std::string ToString(Sauce::Point32_st value);
			_std::string ToString(Sauce::Point64_st value);
			///
			int64_t ToInt64(_std::string value);
			uint64_t ToUint64(_std::string value);
			long double ToDouble(_std::string value);
			Sauce::uPoint8_st TouPoint8(_std::string value);
			Sauce::uPoint16_st TouPoint16(_std::string value);
			Sauce::uPoint32_st TouPoint32(_std::string value);
			Sauce::uPoint64_st TouPoint64(_std::string value);
			Sauce::Point8_st ToPoint8(_std::string value);
			Sauce::Point16_st ToPoint16(_std::string value);
			Sauce::Point32_st ToPoint32(_std::string value);
			Sauce::Point64_st ToPoint64(_std::string value);
		}
	};
};
