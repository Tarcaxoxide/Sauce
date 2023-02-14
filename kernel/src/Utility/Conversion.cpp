#include<Sauce/Utility/Conversion.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
    namespace Utility{
        namespace Conversion{
            _std::string HexToString(uint8_t value,bool ClearBefore){
                Sauce::IO::Debug::Debugger_st Debugger("HexToString",_NAMESPACE_,_ALLOW_PRINT_);
                unsigned char haxString[512] = {0};
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
                _std::string Result((char*)haxString);
                return Result;
            }
            _std::string HexToString(uint16_t value,bool ClearBefore){
                Sauce::IO::Debug::Debugger_st Debugger("HexToString",_NAMESPACE_,_ALLOW_PRINT_);
                unsigned char haxString[512] = {0};
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
                _std::string Result((char*)haxString);
                return Result;
            }
            _std::string HexToString(uint32_t value,bool ClearBefore){
                Sauce::IO::Debug::Debugger_st Debugger("HexToString",_NAMESPACE_,_ALLOW_PRINT_);
                unsigned char haxString[512] = {0};
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
                _std::string Result((char*)haxString);
                return Result;
            }
            _std::string HexToString(uint64_t value,bool ClearBefore){
                Sauce::IO::Debug::Debugger_st Debugger("HexToString",_NAMESPACE_,_ALLOW_PRINT_);
                unsigned char haxString[512] = {0};
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
                _std::string Result((char*)haxString);
                return Result;
            }
            _std::string ToString(uint8_t value,bool ClearBefore){
                return ToString((int64_t)value,ClearBefore);
            }
            _std::string ToString(uint16_t value,bool ClearBefore){
                return ToString((int64_t)value,ClearBefore);
            }
            _std::string ToString(uint32_t value,bool ClearBefore){
                return ToString((int64_t)value,ClearBefore);
            }
            _std::string ToString(int8_t value,bool ClearBefore){
                return ToString((int64_t)value,ClearBefore);
            }
            _std::string ToString(int16_t value,bool ClearBefore){
                return ToString((int64_t)value,ClearBefore);
            }
            _std::string ToString(int32_t value,bool ClearBefore){
                return ToString((int64_t)value,ClearBefore);
            }
            _std::string ToString(uint64_t value,bool ClearBefore){
                return ToString((int64_t)value,ClearBefore);
            }
		    _std::string ToString(int64_t value,bool ClearBefore){
                Sauce::IO::Debug::Debugger_st Debugger("ToString",_NAMESPACE_,_ALLOW_PRINT_);
                unsigned char haxString[512]{0};
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
                _std::string Result((char*)haxString);
                return Result;
            }
            _std::string ToString(float value,uint16_t decimalPlaces){
                Sauce::IO::Debug::Debugger_st Debugger("ToString",_NAMESPACE_,_ALLOW_PRINT_);
                _std::string Result = ToString((int)value);
                if(value < 0){
                    value *= -1;
                }
                Result+='.';
                float newValue = (value - (int)value);
                for(uint16_t i=0;i<decimalPlaces;i++){
                    newValue *= 10;
                    Result+= (char)((int)newValue +48);
                    newValue -= (int)newValue;
                }
                return Result;
            }
            _std::string ToString(double value,uint16_t decimalPlaces){
                Sauce::IO::Debug::Debugger_st Debugger("ToString",_NAMESPACE_,_ALLOW_PRINT_);
                _std::string Result = ToString((int)value);
                if(value < 0){
                    value *= -1;
                }
                Result+='.';
                float newValue = (value - (int)value);
                for(uint16_t i=0;i<decimalPlaces;i++){
                    newValue *= 10;
                    Result+= (char)((int)newValue +48);
                    newValue -= (int)newValue;
                }
                return Result;
            }
            uint64_t ToUint64(_std::string value){
                Sauce::IO::Debug::Debugger_st Debugger("ToUint64",_NAMESPACE_,_ALLOW_PRINT_);
                uint64_t Result=0;
                for(size_t i=0;(i<30&&i<value.Size());i++){
                    size_t Mag=1;
                    for(size_t ii=0;ii<i;ii++){Mag*=10;}
                    char _char=value[value.Size()-(i+1)];
                    Result+=(_char-0x30)*Mag;
                }
                return Result;
            }
        };
    };
};