#include<Sauce/Utility/Conversion.hpp>
#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace Utility{
        static unsigned char haxString[512] = {0};// instead of having seperate char arrays for every function, i just define 1 global char array.
        void Clear_haxString(Sauce::IO::Debug::Debugger_st* pDebugger){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Clear_haxString",_NAMESPACE_);
            for(size_t a = 0;(a < 512);a++){
                haxString[a] = 0;
            }
        }
        char* HexToString(Sauce::IO::Debug::Debugger_st* pDebugger,uint8_t value,bool ClearBefore){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"HexToString",_NAMESPACE_);
            if(ClearBefore)Clear_haxString(&Debugger);
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
            return (char*)haxString;
        }
        char* HexToString(Sauce::IO::Debug::Debugger_st* pDebugger,uint16_t value,bool ClearBefore){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"HexToString",_NAMESPACE_);
            if(ClearBefore)Clear_haxString(&Debugger);
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
            return (char*)haxString;
        }
        char* HexToString(Sauce::IO::Debug::Debugger_st* pDebugger,uint32_t value,bool ClearBefore){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"HexToString",_NAMESPACE_);
            if(ClearBefore)Clear_haxString(&Debugger);
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
            return (char*)haxString;
        }
        char* HexToString(Sauce::IO::Debug::Debugger_st* pDebugger,uint64_t value,bool ClearBefore){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"HexToString",_NAMESPACE_);
            if(ClearBefore)Clear_haxString(&Debugger);
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
            return (char*)haxString;
        }
        char* ToString(Sauce::IO::Debug::Debugger_st* pDebugger,uint8_t value,bool ClearBefore){
            return ToString(pDebugger,(int64_t)value,ClearBefore);
        }
        char* ToString(Sauce::IO::Debug::Debugger_st* pDebugger,uint16_t value,bool ClearBefore){
            return ToString(pDebugger,(int64_t)value,ClearBefore);
        }
        char* ToString(Sauce::IO::Debug::Debugger_st* pDebugger,uint32_t value,bool ClearBefore){
            return ToString(pDebugger,(int64_t)value,ClearBefore);
        }
        char* ToString(Sauce::IO::Debug::Debugger_st* pDebugger,int8_t value,bool ClearBefore){
            return ToString(pDebugger,(int64_t)value,ClearBefore);
        }
        char* ToString(Sauce::IO::Debug::Debugger_st* pDebugger,int16_t value,bool ClearBefore){
            return ToString(pDebugger,(int64_t)value,ClearBefore);
        }
        char* ToString(Sauce::IO::Debug::Debugger_st* pDebugger,int32_t value,bool ClearBefore){
            return ToString(pDebugger,(int64_t)value,ClearBefore);
        }
        char* ToString(Sauce::IO::Debug::Debugger_st* pDebugger,uint64_t value,bool ClearBefore){
            return ToString(pDebugger,(int64_t)value,ClearBefore);
        }
		char* ToString(Sauce::IO::Debug::Debugger_st* pDebugger,int64_t value,bool ClearBefore){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"ToString",_NAMESPACE_);
            Clear_haxString(&Debugger);
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
            return (char*)haxString;
        }
        char* ToString(Sauce::IO::Debug::Debugger_st* pDebugger,float value,uint16_t decimalPlaces){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"ToString",_NAMESPACE_);
            Clear_haxString(&Debugger);
            char* intPtr = (char*)ToString(&Debugger,(int)value);
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
            return (char*)haxString;
        }
        char* ToString(Sauce::IO::Debug::Debugger_st* pDebugger,double value,uint16_t decimalPlaces){
            Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"ToString",_NAMESPACE_);
            Clear_haxString(&Debugger);
            char* intPtr = (char*)ToString(&Debugger,(int)value);
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
            return (char*)haxString;
        }
    };
};