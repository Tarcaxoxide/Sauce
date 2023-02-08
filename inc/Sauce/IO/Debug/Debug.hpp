#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/NameSpaceIdentifiers.hpp>
#pragma once
namespace Sauce{
	namespace Utility{
        bool strcmp(const char* strA,const char* strB);
    };
};
namespace Sauce{
    namespace IO{
        namespace Debug{
                struct Debugger_st{
                    size_t indent=0;
                    char* FunctionName;
                    char* thisNameSpace;
                    bool AllowPrint=false;
                    Debugger_st(const char* FunctionName,const char* thisNameSpace,bool AllowPrint){
                        this->FunctionName=(char*)FunctionName;
                        this->thisNameSpace=(char*)thisNameSpace;
                        this->AllowPrint=AllowPrint;
                        if(!AllowPrint)return;
                        Sauce::IO::Debug::COM1_Console.Write((char*)">[");
                        Sauce::IO::Debug::COM1_Console.Write(this->thisNameSpace);
                        Sauce::IO::Debug::COM1_Console.Write((char*)"::");
                        Sauce::IO::Debug::COM1_Console.Write(this->FunctionName);
                        Sauce::IO::Debug::COM1_Console.Write((char*)"]\n");
                    }
                    void Print(const char* text){
                        if(AllowPrint)Sauce::IO::Debug::COM1_Console.Write((char*)"[");
                        if(AllowPrint)Sauce::IO::Debug::COM1_Console.Write(this->thisNameSpace);
                        if(AllowPrint)Sauce::IO::Debug::COM1_Console.Write((char*)"::");
                        if(AllowPrint)Sauce::IO::Debug::COM1_Console.Write(this->FunctionName);
                        if(AllowPrint)Sauce::IO::Debug::COM1_Console.Write((char*)"]");
                        if(AllowPrint)Sauce::IO::Debug::COM1_Console.Write((char*)"{");
                        if(AllowPrint)Sauce::IO::Debug::COM1_Console.Write((char*)text);
                        if(AllowPrint)Sauce::IO::Debug::COM1_Console.Write((char*)"}\n");
                    }
                    ~Debugger_st(){
                        if(!AllowPrint)return;
                        Sauce::IO::Debug::COM1_Console.Write((char*)"<[");
                        Sauce::IO::Debug::COM1_Console.Write(this->thisNameSpace);
                        Sauce::IO::Debug::COM1_Console.Write((char*)"::");
                        Sauce::IO::Debug::COM1_Console.Write(this->FunctionName);
                        Sauce::IO::Debug::COM1_Console.Write((char*)"]\n");
                    }
                };
        };
    };
};