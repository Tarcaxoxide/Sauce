#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace IO{
        namespace Debug{
            void Console_cl::Initialize(uint16_t DebugComPort){
                this->DebugComPort=DebugComPort;
                ready=true;
                switch(DebugComPort){
                    case COM1:{
                        Write((char*)"[COM1_Console Initialized]\n\0");
                    }break;
                    case COM2:{
                        COM1_Console.Write((char*)"[COM2_Console Initialized]\n\0");
                    }break;
                    case COM3:{
                        COM1_Console.Write((char*)"[COM3_Console Initialized]\n\0");
                    }break;
                    case COM4:{
                        COM1_Console.Write((char*)"[COM4_Console Initialized]\n\0");
                    }break;
                    case COM5:{
                        COM1_Console.Write((char*)"[COM5_Console Initialized]\n\0");
                    }break;
                    case COM6:{
                        COM1_Console.Write((char*)"[COM6_Console Initialized]\n\0");
                    }break;
                    case COM7:{
                        COM1_Console.Write((char*)"[COM7_Console Initialized]\n\0");
                    }break;
                    case COM8:{
                        COM1_Console.Write((char*)"[COM8_Console Initialized]\n\0");
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
        };
    };
};