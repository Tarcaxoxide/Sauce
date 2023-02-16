#pragma once
#include<Sauce/NameSpaceIdentifiers.hpp>
#include<_std/string.hpp>
namespace Sauce{
    namespace IO{
        namespace Debug{
                struct Debugger_st{
                    char* FunctionName;
                    char* thisNameSpace;
                    char* FileName;
                    bool AllowPrint=false;
                    Debugger_st(const char* FileName,const char* FunctionName,const char* thisNameSpace,bool AllowPrint);
                    void Print(const char* text);
                    inline void Print(_std::string text){Print(text.Raw());}
                    void indent();
                    ~Debugger_st();
                };
        };
    };
};