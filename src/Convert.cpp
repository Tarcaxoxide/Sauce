#include "Convert.hpp"

// this file contains conversions from 1 data type to another.
// currently we only have int types to string but eventually i plan on implementing a way to go the other way as well
// and even conversions to custom types.


namespace Sauce{
    namespace Convert{
        namespace To_String{
            char haxString[512] = {0};
            void Clear_haxString(){
                for(size_t a = 0;(a < 512);a++){
                    haxString[a] = 0;
                }
            }
            char* From_uint8(uint8_t value){
                Clear_haxString();
                uint8_t* valPtr = &value;
                uint8_t* ptr;
                uint8_t temp;
                uint8_t size = ((sizeof(uint8_t) * 2) - 1);
                uint8_t i;
                for(i = 0;(i < size);i++){
                    ptr = ((uint8_t*)valPtr+i);
                    temp = ((*ptr & 0xF0) >> 4);
                    haxString[(size - (i * 2 + 1))]= (temp + (temp > 9 ? 55 : 48));
                    temp = ((*ptr & 0x0F));
                    haxString[(size - (i * 2 + 0))]= (temp + (temp > 9 ? 55 : 48));
                }
                return haxString;
            }
            char* From_uint16(uint16_t value){
                Clear_haxString();
                uint16_t* valPtr = &value;
                uint8_t* ptr;
                uint8_t temp;
                uint8_t size = ((sizeof(uint16_t) * 2) - 1);
                uint8_t i;
                for(i = 0;(i < size);i++){
                    ptr = ((uint8_t*)valPtr+i);
                    temp = ((*ptr & 0xF0) >> 4);
                    haxString[(size - (i * 2 + 1))]= (temp + (temp > 9 ? 55 : 48));
                    temp = ((*ptr & 0x0F));
                    haxString[(size - (i * 2 + 0))]= (temp + (temp > 9 ? 55 : 48));
                }
                return haxString;
            }
            char* From_uint32(uint32_t value){
                Clear_haxString();
                uint32_t* valPtr = &value;
                uint8_t* ptr;
                uint8_t temp;
                uint8_t size = ((sizeof(uint32_t) * 2) - 1);
                uint8_t i;
                for(i = 0;(i < size);i++){
                    ptr = ((uint8_t*)valPtr+i);
                    temp = ((*ptr & 0xF0) >> 4);
                    haxString[(size - (i * 2 + 1))]= (temp + (temp > 9 ? 55 : 48));
                    temp = ((*ptr & 0x0F));
                    haxString[(size - (i * 2 + 0))]= (temp + (temp > 9 ? 55 : 48));
                }
                return haxString;
            }
            char* From_uint64(uint64_t value){
                Clear_haxString();
                uint64_t* valPtr = &value;
                uint8_t* ptr;
                uint8_t temp;
                uint8_t size = ((sizeof(uint64_t) * 2) - 1);
                uint8_t i;
                for(i = 0;(i < size);i++){
                    ptr = ((uint8_t*)valPtr+i);
                    temp = ((*ptr & 0xF0) >> 4);
                    haxString[(size - (i * 2 + 1))]= (temp + (temp > 9 ? 55 : 48));
                    temp = ((*ptr & 0x0F));
                    haxString[(size - (i * 2 + 0))]= (temp + (temp > 9 ? 55 : 48));
                }
                return haxString;
            }
			char* From_Integer(int64_t value){
                Clear_haxString();
                uint8_t isNegative = 0;

                if(value < 0){
                    isNegative=1;
                    value*=-1;
                    haxString[0]='-';
                }

                uint8_t size = 0;
                uint64_t sizeTester = (uint64_t)value;
                while(sizeTester / 10 > 0){
                    sizeTester /= 10;
                    size++;
                }
                uint8_t index = 0;
                uint64_t newValue = (uint64_t)value;
                while(newValue / 10 > 0){
                    uint8_t remainder = (newValue % 10);
                    newValue /= 10;
                    haxString[((isNegative + size) - index)] = (remainder + 48);
                    index++;
                }
                uint8_t remainder = (newValue % 10);
                haxString[((isNegative + size) - index)] = (remainder + 48);
                return haxString;
            }
            char* From_Decimal(float value,uint16_t decimalPlaces){
                Clear_haxString();
                char* intPtr = (char*)From_Integer((int)value);
                char* floatPtr = haxString;
                
                if(value < 0){
                    value *= -1;
                }

                while(*intPtr != 0){
                    *floatPtr++ = *intPtr++;
                }
                *floatPtr++ = '.';

                float newValue = (value - (int)value);
                for(uint16_t i=0;i<decimalPlaces;i++){
                    newValue *= 10;
                    *floatPtr++ = ((int)newValue +48);
                    newValue -= (int)newValue;
                }
                *floatPtr = 0;
                return haxString;
            }
            char* From_Decimal(double value,uint16_t decimalPlaces){
                Clear_haxString();
                char* intPtr = (char*)From_Integer((int)value);
                char* floatPtr = haxString;
                
                if(value < 0){
                    value *= -1;
                }

                while(*intPtr != 0){
                    *floatPtr++ = *intPtr++;
                }
                *floatPtr++ = '.';

                float newValue = (value - (int)value);
                for(uint16_t i=0;i<decimalPlaces;i++){
                    newValue *= 10;
                    *floatPtr++ = ((int)newValue +48);
                    newValue -= (int)newValue;
                }
                *floatPtr = 0;
                return haxString;
            }
        };
    };
};
