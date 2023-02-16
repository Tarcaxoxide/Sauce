#pragma once
#include<stddef.h>
#include<stdint.h>
#include<_std/string.hpp>
namespace Sauce{
    namespace Fauxon{
        namespace DataTypes{
            namespace Kind_en{
                enum Kind_en:uint64_t{
                    __NULL=0,
                    __TOKEN,
                    __STATEMENT
                };
                _std::string toString(Kind_en Kind);
            };
            struct BaseDataType_st{
                struct Header_st{
                    Kind_en::Kind_en Kind{Kind_en::__NULL};
                    uint64_t SubKind;
                }Header;
                BaseDataType_st(Kind_en::Kind_en Kind,uint64_t SubKind);
            };
        };
    };
};
