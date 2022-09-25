#pragma once

#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/NameSpaceIdentifiers.hpp>

namespace Sauce{
    namespace IO{
        namespace Debug{
            struct Debugger_st{
                Debugger_st* Previous{nullptr};
                Debugger_st* Next{nullptr};
                Debugger_st* PoN{nullptr};
                size_t indent=0;
                char* FunctionName;
                char* thisNameSpace;

                Debugger_st(Debugger_st* _Previous,const char* FunctionName,const char* thisNameSpace){
                    Previous=_Previous;
                    PoN=Previous->Next;
                    Previous->Next=this;
                    
                    this->FunctionName=(char*)FunctionName;
                    this->thisNameSpace=(char*)thisNameSpace;

                    indent=Previous->indent+1;

                    Indent();
                    Sauce::IO::Debug::COM1_Console.Write((char*)">[");
                    Sauce::IO::Debug::COM1_Console.Write(this->thisNameSpace);
                    Sauce::IO::Debug::COM1_Console.Write((char*)"::");
                    Sauce::IO::Debug::COM1_Console.Write(this->FunctionName);
                    Sauce::IO::Debug::COM1_Console.Write((char*)"]\n");
                }
                Debugger_st(const char* FunctionName,const char* thisNameSpace){
                    this->FunctionName=(char*)FunctionName;
                    this->thisNameSpace=(char*)thisNameSpace;
                    Indent();
                    Sauce::IO::Debug::COM1_Console.Write((char*)">[");
                    Sauce::IO::Debug::COM1_Console.Write(this->thisNameSpace);
                    Sauce::IO::Debug::COM1_Console.Write((char*)"::");
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
                    Sauce::IO::Debug::COM1_Console.Write(this->thisNameSpace);
                    Sauce::IO::Debug::COM1_Console.Write((char*)"::");
                    Sauce::IO::Debug::COM1_Console.Write(this->FunctionName);
                    Sauce::IO::Debug::COM1_Console.Write((char*)"]");
                    Sauce::IO::Debug::COM1_Console.Write((char*)"{");
                    Sauce::IO::Debug::COM1_Console.Write((char*)text);
                    Sauce::IO::Debug::COM1_Console.Write((char*)"}\n");
                }
                ~Debugger_st(){
                    Indent();
                    Sauce::IO::Debug::COM1_Console.Write((char*)"<[");
                    Sauce::IO::Debug::COM1_Console.Write(this->thisNameSpace);
                    Sauce::IO::Debug::COM1_Console.Write((char*)"::");
                    Sauce::IO::Debug::COM1_Console.Write(this->FunctionName);
                    Sauce::IO::Debug::COM1_Console.Write((char*)"]\n");
                    if(Previous == nullptr)return;
                    Previous->Next=PoN;
                }
            };
        };
    };
};