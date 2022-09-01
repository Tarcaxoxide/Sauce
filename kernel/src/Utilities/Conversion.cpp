#include<Sauce/Utilities/Conversion.hpp>
#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace Convert{
        static unsigned char haxString[512] = {0};// instead of having seperate char arrays for every function, i just define 1 global char array.
        void Clear_haxString(){
            Sauce::IO::Debug::Print_Spammy_Call("Clear_haxString",Sauce::IO::Debug::CONVERSIONS);
            for(size_t a = 0;(a < 512);a++){
                haxString[a] = 0;
            }
            Sauce::IO::Debug::Print_Spammy_Return("<void>",Sauce::IO::Debug::CONVERSIONS);
        }
        char* HexToString(uint8_t value,bool ClearBefore){
            Sauce::IO::Debug::Print_Spammy_Call("HexToString (8)",Sauce::IO::Debug::CONVERSIONS);
            if(ClearBefore)Clear_haxString();
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
            Sauce::IO::Debug::Print_Spammy_Return((char*)haxString,Sauce::IO::Debug::CONVERSIONS);
            return (char*)haxString;
        }
        char* HexToString(uint16_t value,bool ClearBefore){
            Sauce::IO::Debug::Print_Spammy_Call("HexToString (16)",Sauce::IO::Debug::CONVERSIONS);
            if(ClearBefore)Clear_haxString();
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
            Sauce::IO::Debug::Print_Spammy_Return((char*)haxString,Sauce::IO::Debug::CONVERSIONS);
            return (char*)haxString;
        }
        char* HexToString(uint32_t value,bool ClearBefore){
            Sauce::IO::Debug::Print_Spammy_Call("HexToString (32)",Sauce::IO::Debug::CONVERSIONS);
            if(ClearBefore)Clear_haxString();
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
            Sauce::IO::Debug::Print_Spammy_Return((char*)haxString,Sauce::IO::Debug::CONVERSIONS);
            return (char*)haxString;
        }
        char* HexToString(uint64_t value,bool ClearBefore){
            Sauce::IO::Debug::Print_Spammy_Call("HexToString (64)",Sauce::IO::Debug::CONVERSIONS);
            if(ClearBefore)Clear_haxString();
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
            Sauce::IO::Debug::Print_Spammy_Return((char*)haxString,Sauce::IO::Debug::CONVERSIONS);
            return (char*)haxString;
        }
        char* ToString(uint8_t value,bool ClearBefore){
            return ToString((int64_t)value,ClearBefore);
        }
        char* ToString(uint16_t value,bool ClearBefore){
            return ToString((int64_t)value,ClearBefore);
        }
        char* ToString(uint32_t value,bool ClearBefore){
            return ToString((int64_t)value,ClearBefore);
        }
        char* ToString(int8_t value,bool ClearBefore){
            return ToString((int64_t)value,ClearBefore);
        }
        char* ToString(int16_t value,bool ClearBefore){
            return ToString((int64_t)value,ClearBefore);
        }
        char* ToString(int32_t value,bool ClearBefore){
            return ToString((int64_t)value,ClearBefore);
        }
        char* ToString(uint64_t value,bool ClearBefore){
            return ToString((int64_t)value,ClearBefore);
        }
		char* ToString(int64_t value,bool ClearBefore){
            Sauce::IO::Debug::Print_Spammy_Call("ToString (int)",Sauce::IO::Debug::CONVERSIONS);
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
            Sauce::IO::Debug::Print_Spammy_Return((char*)haxString,Sauce::IO::Debug::CONVERSIONS);
            return (char*)haxString;
        }
        char* ToString(float value,uint16_t decimalPlaces){
            Sauce::IO::Debug::Print_Spammy_Call("ToString (float)",Sauce::IO::Debug::CONVERSIONS);
            Clear_haxString();
            char* intPtr = (char*)ToString((int)value);
            char* floatPtr = (char*)haxString;
            
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
            Sauce::IO::Debug::Print_Spammy_Return((char*)haxString,Sauce::IO::Debug::CONVERSIONS);
            return (char*)haxString;
        }
        char* ToString(double value,uint16_t decimalPlaces){
            Sauce::IO::Debug::Print_Spammy_Call("ToString (double)",Sauce::IO::Debug::CONVERSIONS);
            Clear_haxString();
            char* intPtr = (char*)ToString((int)value);
            char* floatPtr = (char*)haxString;
            
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
            Sauce::IO::Debug::Print_Spammy_Return((char*)haxString,Sauce::IO::Debug::CONVERSIONS);
            return (char*)haxString;
        }
    };
};