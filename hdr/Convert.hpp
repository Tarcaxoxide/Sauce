#pragma once

#include <stdint.h>
#include <stddef.h>

namespace Sauce{
	namespace Convert{
		namespace To_String{
			char* From_uint8(uint8_t value);
			char* From_uint16(uint16_t value);
			char* From_uint32(uint32_t value);
			char* From_uint64(uint64_t value);
			char* From_Integer(int64_t value);
			char* From_Decimal(float value,uint16_t decimalPlaces);
			char* From_Decimal(double value,uint16_t decimalPlaces);
		};
	};
};