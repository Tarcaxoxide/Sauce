#include<Sauce/Fauxon/DataTypes/BaseDataType.hpp>
#include<stddef.h>
#include<stdint.h>
#include<_std/string.hpp>
namespace Sauce{
    namespace Fauxon{
        namespace DataTypes{
            namespace Kind_en{
                _std::string toString(Kind_en Kind){
                    _std::string Result="";
                    switch(Kind){
                        case Kind_en::__NULL:{Result="__NULL";}break;
                        case Kind_en::__TOKEN:{Result="__TOKEN";}break;
                    }
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
