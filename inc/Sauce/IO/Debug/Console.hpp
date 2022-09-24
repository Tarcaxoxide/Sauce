#pragma once
#include<Sauce/IO/Debug/Serial.hpp>
#include "Sauce/IO/Debug/Settings.hpp"

namespace Sauce{
    namespace IO{
        namespace Debug{
            class Console_cl{
                uint16_t DebugComPort;
                bool ready=false;
                public:
                void Initialize(uint16_t DebugComPort);
                void Write(char* str);
            };

            extern Console_cl COM1_Console;
            extern Console_cl COM2_Console;
            extern Console_cl COM3_Console;
            extern Console_cl COM4_Console;
            extern Console_cl COM5_Console;
            extern Console_cl COM6_Console;
            extern Console_cl COM7_Console;
            extern Console_cl COM8_Console;

            enum StartOfPrint{
                Single=0,
                Start,
                Middle,
                End
            };

            //void Print_Call(char* msg,bool FunctionSpecific,StartOfPrint Done,bool Spam);
            //void Print_Detail(char* msg,bool FunctionSpecific,StartOfPrint Done,bool Spam);
            //void Print_Return(char* msg,bool FunctionSpecific,StartOfPrint Done,bool Spam);
            //inline void Print_Call(const char* msg,bool FunctionSpecific,StartOfPrint Done=StartOfPrint::Single){Print_Call((char*)msg,FunctionSpecific,Done,false);}
            //inline void Print_Detail(const char* msg,bool FunctionSpecific,StartOfPrint Done=StartOfPrint::Single){Print_Detail((char*)msg,FunctionSpecific,Done,false);}
            //inline void Print_Return(const char* msg,bool FunctionSpecific,StartOfPrint Done=StartOfPrint::Single){Print_Return((char*)msg,FunctionSpecific,Done,false);}
            //
            //inline void Print_Spammy_Call(const char* msg,bool FunctionSpecific,StartOfPrint Done=StartOfPrint::Single){Print_Call((char*)msg,FunctionSpecific,Done,true);}
            //inline void Print_Spammy_Detail(const char* msg,bool FunctionSpecific,StartOfPrint Done=StartOfPrint::Single){Print_Detail((char*)msg,FunctionSpecific,Done,true);}
            //inline void Print_Spammy_Return(const char* msg,bool FunctionSpecific,StartOfPrint Done=StartOfPrint::Single){Print_Return((char*)msg,FunctionSpecific,Done,true);}
        };
    };
};




//Sauce::IO::Debug::Print_("",Sauce::IO::Debug::KERNEL,true);



//Sauce::IO::Debug::StartOfPrint::