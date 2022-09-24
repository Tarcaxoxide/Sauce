#pragma once

#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace IO{
        namespace Debug{

            struct Debugger_st{
                Debugger_st* Previous{nullptr};
                Debugger_st* Next{nullptr};
                Debugger_st* PoN{nullptr};
                size_t indent=0;
                char* FunctionName;

                Debugger_st(Debugger_st* _Previous,const char* FunctionName){
                    Previous=_Previous;
                    PoN=Previous->Next;
                    Previous->Next=this;
                    
                    this->FunctionName=(char*)FunctionName;

                    indent=Previous->indent+1;

                    Indent();
                    Sauce::IO::Debug::COM1_Console.Write((char*)">[");
                    Sauce::IO::Debug::COM1_Console.Write(this->FunctionName);
                    Sauce::IO::Debug::COM1_Console.Write((char*)"]\n");
                }
                Debugger_st(const char* FunctionName){
                    this->FunctionName=(char*)FunctionName;
                    Indent();
                    Sauce::IO::Debug::COM1_Console.Write((char*)">[");
                    Sauce::IO::Debug::COM1_Console.Write(this->FunctionName);
                    Sauce::IO::Debug::COM1_Console.Write((char*)"]\n");
                }
                void Indent(){
                    //for(size_t i=0;i<indent;i++){
                    //    Sauce::IO::Debug::COM1_Console.Write((char*)" ");
                    //}
                }
                void Print(const char* text){Print((char*)text);}
                void Print(char* text){
                    Indent();
                    Sauce::IO::Debug::COM1_Console.Write((char*)"[");
                    Sauce::IO::Debug::COM1_Console.Write(this->FunctionName);
                    Sauce::IO::Debug::COM1_Console.Write((char*)"]");
                    Sauce::IO::Debug::COM1_Console.Write((char*)"{");
                    Sauce::IO::Debug::COM1_Console.Write((char*)text);
                    Sauce::IO::Debug::COM1_Console.Write((char*)"}\n");
                }
                ~Debugger_st(){
                    Indent();
                    Sauce::IO::Debug::COM1_Console.Write((char*)"<[");
                    Sauce::IO::Debug::COM1_Console.Write(this->FunctionName);
                    Sauce::IO::Debug::COM1_Console.Write((char*)"]\n");
                    if(Previous == nullptr)return;
                    Previous->Next=PoN;
                }
            };
        };
    };
};