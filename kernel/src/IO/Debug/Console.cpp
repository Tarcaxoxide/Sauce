#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace IO{
        namespace Debug{
            void Console_cl::Initialize(uint16_t DebugComPort){
                this->DebugComPort=DebugComPort;
                ready=true;
                switch(DebugComPort){
                    case COM1:{
                        if(Sauce::IO::Debug::FUNCTION_CALLS)Write((char*)"[COM1_Console Initialized]\n\0");
                    }break;
                    case COM2:{
                        if(Sauce::IO::Debug::FUNCTION_CALLS)COM1_Console.Write((char*)"[COM2_Console Initialized]\n\0");
                    }break;
                    case COM3:{
                        if(Sauce::IO::Debug::FUNCTION_CALLS)COM1_Console.Write((char*)"[COM3_Console Initialized]\n\0");
                    }break;
                    case COM4:{
                        if(Sauce::IO::Debug::FUNCTION_CALLS)COM1_Console.Write((char*)"[COM4_Console Initialized]\n\0");
                    }break;
                    case COM5:{
                        if(Sauce::IO::Debug::FUNCTION_CALLS)COM1_Console.Write((char*)"[COM5_Console Initialized]\n\0");
                    }break;
                    case COM6:{
                        if(Sauce::IO::Debug::FUNCTION_CALLS)COM1_Console.Write((char*)"[COM6_Console Initialized]\n\0");
                    }break;
                    case COM7:{
                        if(Sauce::IO::Debug::FUNCTION_CALLS)COM1_Console.Write((char*)"[COM7_Console Initialized]\n\0");
                    }break;
                    case COM8:{
                        if(Sauce::IO::Debug::FUNCTION_CALLS)COM1_Console.Write((char*)"[COM8_Console Initialized]\n\0");
                    }break;
                }
            }

            void Console_cl::Write(char* str){
                if(!ready)return;
                Sauce::IO::Debug::write_string_serial(str,DebugComPort);
            }
            Console_cl COM1_Console;
            Console_cl COM2_Console;
            Console_cl COM3_Console;
            Console_cl COM4_Console;
            Console_cl COM5_Console;
            Console_cl COM6_Console;
            Console_cl COM7_Console;
            Console_cl COM8_Console;
            size_t NestLevel=0;

            void Print_Call(char* msg,bool FunctionSpecific,bool Done,bool Spam){
                if(Sauce::IO::Debug::FUNCTION_CALLS && FunctionSpecific && (Sauce::IO::Debug::SPAMMY || (!Spam))){
                    Sauce::IO::Debug::COM1_Console.Write((char*)"[\0");
                    Sauce::IO::Debug::COM1_Console.Write(msg);
                    if(Done)Sauce::IO::Debug::COM1_Console.Write((char*)"]\0");
                }
                if(Done)NestLevel++;
            }
            void Print_Detail(char* msg,bool FunctionSpecific,bool Done,bool Spam){
                if(Sauce::IO::Debug::FUNCTION_DETAILS && FunctionSpecific && (Sauce::IO::Debug::SPAMMY || (!Spam))){
                    Sauce::IO::Debug::COM1_Console.Write((char*)"{\0");
                    Sauce::IO::Debug::COM1_Console.Write(msg);
                    if(Done)Sauce::IO::Debug::COM1_Console.Write((char*)"}\0");
                }
            }
            void Print_Return(char* msg,bool FunctionSpecific,bool Done,bool Spam){
                if(Sauce::IO::Debug::FUNCTION_RETURNS && FunctionSpecific && (Sauce::IO::Debug::SPAMMY || (!Spam))){
                    Sauce::IO::Debug::COM1_Console.Write((char*)"(\0");
                    Sauce::IO::Debug::COM1_Console.Write(msg);
                    if(Done)Sauce::IO::Debug::COM1_Console.Write((char*)")\n\0");
                }
                if(Done)NestLevel--;
            }
        };
    };
};