#include<Sauce/Graphics/Shell/Language/Parser.hpp>

namespace Sauce{
    namespace Graphics{
        namespace Shell{
            namespace Language{
                std::string Parser_cl::Get(std::string VariableName){
                    for(size_t i=0;i<VariableTable.Size();i++){
                        if(VariableTable[i].Name == VariableName){
                            return VariableTable[i].Value;
                        }
                    }
                    if(ParentParser == nullptr)return "";
                    return ParentParser->Get(VariableName);
                }
                std::string Parser_cl::Set(std::string VariableName,std::string NewValue){
                    std::string OldValue="";
                    for(size_t i=0;i<VariableTable.Size();i++){
                        if(VariableTable[i].Name == VariableName){
                            OldValue=VariableTable[i].Value;
                            VariableTable[i].Value=NewValue;
                            return OldValue;
                        }
                    }
                    //Figure out the type, for now we are just going with string.
                    VariableTable.AddLast({VariableName,VariableElementType_en::VET_String,NewValue});
                    return OldValue;
                }
            };
        };
    };
};