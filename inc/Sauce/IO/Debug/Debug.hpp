#pragma once

#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/NameSpaceIdentifiers.hpp>

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
                Debugger_st(const char* FunctionName,const char* thisNameSpace){
                    this->FunctionName=(char*)FunctionName;
                    this->thisNameSpace=(char*)thisNameSpace;
                    Check();
                    if(!AllowPrint)return;
                    Sauce::IO::Debug::COM1_Console.Write((char*)">[");
                    Sauce::IO::Debug::COM1_Console.Write(this->thisNameSpace);
                    Sauce::IO::Debug::COM1_Console.Write((char*)"::");
                    Sauce::IO::Debug::COM1_Console.Write(this->FunctionName);
                    Sauce::IO::Debug::COM1_Console.Write((char*)"]\n");
                }
                void Check(){
                    if(Sauce::Utility::strcmp((const char*)this->thisNameSpace,"::")){AllowPrint=_ALLOW_PRINT_;}
                    else if(Sauce::Utility::strcmp((const char*)this->thisNameSpace,"::Sauce")){AllowPrint=Sauce::_ALLOW_PRINT_;}
                    else if(Sauce::Utility::strcmp((const char*)this->thisNameSpace,"::Sauce::Graphics")){AllowPrint=Sauce::Graphics::_ALLOW_PRINT_;}
                    else if(Sauce::Utility::strcmp((const char*)this->thisNameSpace,"::Sauce::Interrupts")){AllowPrint=Sauce::Interrupts::_ALLOW_PRINT_;}
                    else if(Sauce::Utility::strcmp((const char*)this->thisNameSpace,"::Sauce::Interrupts::PIT")){AllowPrint=Sauce::Interrupts::PIT::_ALLOW_PRINT_;}
                    else if(Sauce::Utility::strcmp((const char*)this->thisNameSpace,"::Sauce::IO")){AllowPrint=Sauce::IO::_ALLOW_PRINT_;}
                    else if(Sauce::Utility::strcmp((const char*)this->thisNameSpace,"::Sauce::IO::ACPI")){AllowPrint=Sauce::IO::ACPI::_ALLOW_PRINT_;}
                    else if(Sauce::Utility::strcmp((const char*)this->thisNameSpace,"::Sauce::Math")){AllowPrint=Sauce::Math::_ALLOW_PRINT_;}
                    else if(Sauce::Utility::strcmp((const char*)this->thisNameSpace,"::Sauce::Memory")){AllowPrint=Sauce::Memory::_ALLOW_PRINT_;}
                    else if(Sauce::Utility::strcmp((const char*)this->thisNameSpace,"::Sauce::Utility")){AllowPrint=Sauce::Utility::_ALLOW_PRINT_;}
                    else if(Sauce::Utility::strcmp((const char*)this->thisNameSpace,"::Sauce::Utility::Neural")){AllowPrint=Sauce::Utility::Neural::_ALLOW_PRINT_;}
                }
                void Print(const char* text){Print((char*)text);}
                void Print(char* text){
                    Check();
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