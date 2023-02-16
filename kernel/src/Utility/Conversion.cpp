#include<Sauce/Utility/Conversion.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
    namespace Utility{
        namespace Conversion{
            _std::string HexToString(uint8_t value,bool ClearBefore){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"HexToString",_NAMESPACE_,_ALLOW_PRINT_);
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
                Debugger.Print(Result);
                return Result;
            }
            _std::string HexToString(uint16_t value,bool ClearBefore){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"HexToString",_NAMESPACE_,_ALLOW_PRINT_);
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
                Debugger.Print(Result);
                return Result;
            }
            _std::string HexToString(uint32_t value,bool ClearBefore){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"HexToString",_NAMESPACE_,_ALLOW_PRINT_);
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
                Debugger.Print(Result);
                return Result;
            }
            _std::string HexToString(uint64_t value,bool ClearBefore){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"HexToString",_NAMESPACE_,_ALLOW_PRINT_);
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
                Debugger.Print(Result);
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
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"ToString",_NAMESPACE_,_ALLOW_PRINT_);
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
                Debugger.Print(Result);
                return Result;
            }
            _std::string ToString(float value,uint16_t decimalPlaces){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"ToString",_NAMESPACE_,_ALLOW_PRINT_);
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
                Debugger.Print(Result);
                return Result;
            }
            _std::string ToString(long double value,uint16_t decimalPlaces){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"ToString",_NAMESPACE_,_ALLOW_PRINT_);
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
                Debugger.Print(Result);
                return Result;
            }
            ///
            _std::string ToString(Sauce::uPoint8_st value){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"ToString",_NAMESPACE_,_ALLOW_PRINT_);
                _std::string Result="";
                Result+=ToString(value.X);
                Result+=".";
                Result+=ToString(value.Y);
                Result+=".";
                Result+=ToString(value.Z);
                Debugger.Print(Result);
                return Result;
            }
			_std::string ToString(Sauce::uPoint16_st value){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"ToString",_NAMESPACE_,_ALLOW_PRINT_);
                _std::string Result="";
                Result+=ToString(value.X);
                Result+=".";
                Result+=ToString(value.Y);
                Result+=".";
                Result+=ToString(value.Z);
                Debugger.Print(Result);
                return Result;
            }
			_std::string ToString(Sauce::uPoint32_st value){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"ToString",_NAMESPACE_,_ALLOW_PRINT_);
                _std::string Result="";
                Result+=ToString(value.X);
                Result+=".";
                Result+=ToString(value.Y);
                Result+=".";
                Result+=ToString(value.Z);
                Debugger.Print(Result);
                return Result;
            }
			_std::string ToString(Sauce::uPoint64_st value){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"ToString",_NAMESPACE_,_ALLOW_PRINT_);
                _std::string Result="";
                Result+=ToString(value.X);
                Result+=".";
                Result+=ToString(value.Y);
                Result+=".";
                Result+=ToString(value.Z);
                Debugger.Print(Result);
                return Result;
            }
			_std::string ToString(Sauce::Point8_st value){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"ToString",_NAMESPACE_,_ALLOW_PRINT_);
                _std::string Result="";
                Result+=ToString(value.X);
                Result+=".";
                Result+=ToString(value.Y);
                Result+=".";
                Result+=ToString(value.Z);
                Debugger.Print(Result);
                return Result;
            }
			_std::string ToString(Sauce::Point16_st value){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"ToString",_NAMESPACE_,_ALLOW_PRINT_);
                _std::string Result="";
                Result+=ToString(value.X);
                Result+=".";
                Result+=ToString(value.Y);
                Result+=".";
                Result+=ToString(value.Z);
                Debugger.Print(Result);
                return Result;
            }
			_std::string ToString(Sauce::Point32_st value){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"ToString",_NAMESPACE_,_ALLOW_PRINT_);
                _std::string Result="";
                Result+=ToString(value.X);
                Result+=".";
                Result+=ToString(value.Y);
                Result+=".";
                Result+=ToString(value.Z);
                Debugger.Print(Result);
                return Result;
            }
			_std::string ToString(Sauce::Point64_st value){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"ToString",_NAMESPACE_,_ALLOW_PRINT_);
                _std::string Result="";
                Result+=ToString(value.X);
                Result+=".";
                Result+=ToString(value.Y);
                Result+=".";
                Result+=ToString(value.Z);
                Debugger.Print(Result);
                return Result;
            }
            ///
            int64_t ToInt64(_std::string value){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"ToInt64",_NAMESPACE_,_ALLOW_PRINT_);
                uint64_t Result=0;
                bool negative=(value.First() == '-');
                if(value.First() == '-'||value.First() == '+')value.RemoveFirst();
                for(size_t i=0;(i<30&&i<value.Size());i++){
                    size_t Mag=1;
                    for(size_t ii=0;ii<i;ii++){Mag*=10;}
                    char _char=value[value.Size()-(i+1)];
                    Result+=(_char-0x30)*Mag;
                }
                if(negative)return -Result;
                Debugger.Print(ToString(Result));
                return Result;
            }
            uint64_t ToUint64(_std::string value){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"ToUint64",_NAMESPACE_,_ALLOW_PRINT_);
                uint64_t Result=0;
                if(value.First() == '-'||value.First() == '+')value.RemoveFirst();
                for(size_t i=0;(i<30&&i<value.Size());i++){
                    size_t Mag=1;
                    for(size_t ii=0;ii<i;ii++){Mag*=10;}
                    char _char=value[value.Size()-(i+1)];
                    Result+=(_char-0x30)*Mag;
                }
                Debugger.Print(ToString(Result));
                return Result;
            }
            long double ToDouble(_std::string value){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"ToDouble",_NAMESPACE_,_ALLOW_PRINT_);
                _std::string PreDot="";
                _std::string PostDot="";
                bool AfterDot=false;
                for(size_t i=0;i<value.Size();i++){
                    if(value[i] == '.'){AfterDot=true;continue;}
                    if(AfterDot){
                        PostDot+=value[i];
                    }else{
                        PreDot+=value[i];
                    }
                }
                long double PreDotNumber=(long double)ToInt64(PreDot);
                long double PostDotNumber=(long double)ToInt64(PostDot);
                for(size_t i=0;i<PostDot.Size();i++){
                    PostDotNumber/=10;
                }
                long double Result=PostDotNumber+PreDotNumber;
                Debugger.Print(ToString(Result));
                return Result;
            }
            Sauce::uPoint8_st TouPoint8(_std::string value){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"TouPoint8",_NAMESPACE_,_ALLOW_PRINT_);
                size_t dot_counter=0;
                uint8_t X=0,Y=0,Z=0;
                _std::string tmp="";
                for(size_t i=0;i<=value.Size();i++){
                    if(i == value.Size() || value[i] == '.'){
                        switch(dot_counter){
                            case 0:{
                                X = (uint8_t)ToUint64(tmp);
                                dot_counter++;
                                tmp="";
                            }break;
                            case 1:{
                                Y = (uint8_t)ToUint64(tmp);
                                dot_counter++;
                                tmp="";
                            }break;
                            case 2:{
                                Z = (uint8_t)ToUint64(tmp);
                                dot_counter++;
                                tmp="";
                            }break;
                            default:{return Sauce::uPoint8_st{X,Y,Z};}break;
                        }
                    }else{
                        tmp+=value[i];
                    }
                }
                Sauce::uPoint8_st Result{X,Y,Z};
                Debugger.Print(ToString(Result));
                return Result;
            }
			Sauce::uPoint16_st TouPoint16(_std::string value){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"TouPoint16",_NAMESPACE_,_ALLOW_PRINT_);
                size_t dot_counter=0;
                uint16_t X=0,Y=0,Z=0;
                _std::string tmp="";
                for(size_t i=0;i<=value.Size();i++){
                    if(i == value.Size() || value[i] == '.'){
                        switch(dot_counter){
                            case 0:{
                                X = (uint16_t)ToUint64(tmp);
                                dot_counter++;
                                tmp="";
                            }break;
                            case 1:{
                                Y = (uint16_t)ToUint64(tmp);
                                dot_counter++;
                                tmp="";
                            }break;
                            case 2:{
                                Z = (uint16_t)ToUint64(tmp);
                                dot_counter++;
                                tmp="";
                            }break;
                            default:{return Sauce::uPoint16_st{X,Y,Z};}break;
                        }
                    }else{
                        tmp+=value[i];
                    }
                }
                Sauce::uPoint16_st Result{X,Y,Z};
                Debugger.Print(ToString(Result));
                return Result;
            }
			Sauce::uPoint32_st TouPoint32(_std::string value){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"TouPoint32",_NAMESPACE_,_ALLOW_PRINT_);
                size_t dot_counter=0;
                uint32_t X=0,Y=0,Z=0;
                _std::string tmp="";
                for(size_t i=0;i<=value.Size();i++){
                    if(i == value.Size() || value[i] == '.'){
                        switch(dot_counter){
                            case 0:{
                                X = (uint32_t)ToUint64(tmp);
                                dot_counter++;
                                tmp="";
                            }break;
                            case 1:{
                                Y = (uint32_t)ToUint64(tmp);
                                dot_counter++;
                                tmp="";
                            }break;
                            case 2:{
                                Z = (uint32_t)ToUint64(tmp);
                                dot_counter++;
                                tmp="";
                            }break;
                            default:{return Sauce::uPoint32_st{X,Y,Z};}break;
                        }
                    }else{
                        tmp+=value[i];
                    }
                }
                Sauce::uPoint32_st Result{X,Y,Z};
                Debugger.Print(ToString(Result));
                return Result;
            }
			Sauce::uPoint64_st TouPoint64(_std::string value){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"TouPoint64",_NAMESPACE_,_ALLOW_PRINT_);
                size_t dot_counter=0;
                uint64_t X=0,Y=0,Z=0;
                _std::string tmp="";
                for(size_t i=0;i<=value.Size();i++){
                    if(i == value.Size() || value[i] == '.'){
                        switch(dot_counter){
                            case 0:{
                                X = (uint64_t)ToUint64(tmp);
                                dot_counter++;
                                tmp="";
                            }break;
                            case 1:{
                                Y = (uint64_t)ToUint64(tmp);
                                dot_counter++;
                                tmp="";
                            }break;
                            case 2:{
                                Z = (uint64_t)ToUint64(tmp);
                                dot_counter++;
                                tmp="";
                            }break;
                            default:{return Sauce::uPoint64_st{X,Y,Z};}break;
                        }
                    }else{
                        tmp+=value[i];
                    }
                }
                Sauce::uPoint64_st Result{X,Y,Z};
                Debugger.Print(ToString(Result));
                return Result;
            }
			Sauce::Point8_st ToPoint8(_std::string value){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"ToPoint8",_NAMESPACE_,_ALLOW_PRINT_);
                size_t dot_counter=0;
                int8_t X=0,Y=0,Z=0;
                _std::string tmp="";
                for(size_t i=0;i<=value.Size();i++){
                    if(i == value.Size() || value[i] == '.'){
                        switch(dot_counter){
                            case 0:{
                                X = (int8_t)ToInt64(tmp);
                                dot_counter++;
                                tmp="";
                            }break;
                            case 1:{
                                Y = (int8_t)ToInt64(tmp);
                                dot_counter++;
                                tmp="";
                            }break;
                            case 2:{
                                Z = (int8_t)ToInt64(tmp);
                                dot_counter++;
                                tmp="";
                            }break;
                            default:{return Sauce::Point8_st{X,Y,Z};}break;
                        }
                    }else {
                        tmp+=value[i];
                    }
                }
                Sauce::Point8_st Result{X,Y,Z};
                Debugger.Print(ToString(Result));
                return Result;
            }
			Sauce::Point16_st ToPoint16(_std::string value){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"ToPoint16",_NAMESPACE_,_ALLOW_PRINT_);
                size_t dot_counter=0;
                int16_t X=0,Y=0,Z=0;
                _std::string tmp="";
                for(size_t i=0;i<=value.Size();i++){
                    if(i == value.Size() || value[i] == '.'){
                        switch(dot_counter){
                            case 0:{
                                X = (int16_t)ToInt64(tmp);
                                dot_counter++;
                                tmp="";
                            }break;
                            case 1:{
                                Y = (int16_t)ToInt64(tmp);
                                dot_counter++;
                                tmp="";
                            }break;
                            case 2:{
                                Z = (int16_t)ToInt64(tmp);
                                dot_counter++;
                                tmp="";
                            }break;
                            default:{return Sauce::Point16_st{X,Y,Z};}break;
                        }
                    }else{
                        tmp+=value[i];
                    }
                }
                Sauce::Point16_st Result{X,Y,Z};
                Debugger.Print(ToString(Result));
                return Result;
            }
			Sauce::Point32_st ToPoint32(_std::string value){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"ToPoint32",_NAMESPACE_,_ALLOW_PRINT_);
                size_t dot_counter=0;
                int32_t X=0,Y=0,Z=0;
                _std::string tmp="";
                for(size_t i=0;i<=value.Size();i++){
                    if(i == value.Size() || value[i] == '.'){
                        switch(dot_counter){
                            case 0:{
                                X = (int32_t)ToInt64(tmp);
                                dot_counter++;
                                tmp="";
                            }break;
                            case 1:{
                                Y = (int32_t)ToInt64(tmp);
                                dot_counter++;
                                tmp="";
                            }break;
                            case 2:{
                                Z = (int32_t)ToInt64(tmp);
                                dot_counter++;
                                tmp="";
                            }break;
                            default:{return Sauce::Point32_st{X,Y,Z};}break;
                        }
                    }else{
                        tmp+=value[i];
                    }
                }
                Sauce::Point32_st Result{X,Y,Z};
                Debugger.Print(ToString(Result));
                return Result;
            }
			Sauce::Point64_st ToPoint64(_std::string value){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"ToPoint64",_NAMESPACE_,_ALLOW_PRINT_);
                size_t dot_counter=0;
                int64_t X=0,Y=0,Z=0;
                _std::string tmp="";
                for(size_t i=0;i<=value.Size();i++){
                    if(i == value.Size() || value[i] == '.'){
                        switch(dot_counter){
                            case 0:{
                                X = (int64_t)ToInt64(tmp);
                                dot_counter++;
                                tmp="";
                            }break;
                            case 1:{
                                Y = (int64_t)ToInt64(tmp);
                                dot_counter++;
                                tmp="";
                            }break;
                            case 2:{
                                Z = (int64_t)ToInt64(tmp);
                                dot_counter++;
                                tmp="";
                            }break;
                            default:{return Sauce::Point64_st{X,Y,Z};}break;
                        }
                    }else{
                        tmp+=value[i];
                    }
                }
                Sauce::Point64_st Result{X,Y,Z};
                Debugger.Print(ToString(Result));
                return Result;
            }
        };
    };
};