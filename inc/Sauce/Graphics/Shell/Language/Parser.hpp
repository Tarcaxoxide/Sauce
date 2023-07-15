#ifndef __Sauce_Graphics_Shell_Language_Parser
#define __Sauce_Graphics_Shell_Language_Parser
#include<std/string.hpp>
#include<std/list.hpp>
#include<stddef.h>
#include<stdint.h>
namespace Sauce{
    namespace Graphics{
        namespace Shell{
            namespace Language{
                enum VariableElementType_en{
                    VET_Numerical,
                    VET_Identifier,
                    VET_String
                };
                struct VariableElementTable_st{
                    std::string Name;
                    VariableElementType_en Type;
                    std::string Value;
                };
                class Parser_cl{
                    Parser_cl* ParentParser{nullptr};
                    std::list<VariableElementTable_st> VariableTable;
                    std::list<int64_t> Stack;
                    public:
                        Parser_cl(Parser_cl* OtherParser=nullptr):ParentParser(OtherParser){}
                        std::string Get(std::string VariableName);
                        std::string Set(std::string VariableName,std::string NewValue);
                };
            };
        };
    };
};
#endif