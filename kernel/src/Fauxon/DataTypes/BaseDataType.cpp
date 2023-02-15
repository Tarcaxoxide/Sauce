#include<Sauce/Fauxon/DataTypes/BaseDataType.hpp>
#include<stddef.h>
#include<stdint.h>
#include<_std/string.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
namespace Sauce{
    namespace Fauxon{
        namespace DataTypes{
            namespace Kind_en{
                _std::string toString(Kind_en Kind){
                    Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Kind_en::toString",_NAMESPACE_,_ALLOW_PRINT_);
                    _std::string Result="";
                    switch(Kind){
                        case Kind_en::__NULL:{Result="__NULL";}break;
                        case Kind_en::__TOKEN:{Result="__TOKEN";}break;
                    }
                    Debugger.Print(Result);
                    return Result;
                }
            };
            
            struct Header_st{
                Kind_en::Kind_en Kind{Kind_en::__NULL};
                uint64_t SubKind;
            }Header;
            BaseDataType_st::BaseDataType_st(Kind_en::Kind_en Kind,uint64_t SubKind){
                Header.Kind=Kind;
                Header.SubKind=SubKind;
            }
            
        };
    };
};
