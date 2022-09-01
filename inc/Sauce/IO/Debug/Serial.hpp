#pragma once

#include<Sauce/Types.hpp>
#include<Sauce/IO/IO.hpp>

namespace Sauce{
    namespace IO{
        namespace Debug{
            static const uint16_t COM1=0x3F8;static bool COM1_Good=false;
            static const uint16_t COM2=0x2F8;static bool COM2_Good=false;
            static const uint16_t COM3=0x3E8;static bool COM3_Good=false;
            static const uint16_t COM4=0x2E8;static bool COM4_Good=false;
            static const uint16_t COM5=0x5F8;static bool COM5_Good=false;
            static const uint16_t COM6=0x4F8;static bool COM6_Good=false;
            static const uint16_t COM7=0x5E8;static bool COM7_Good=false;
            static const uint16_t COM8=0x4E8;static bool COM8_Good=false;
            bool init_serial(uint16_t PORT);
            int serial_received(uint16_t PORT);
            char read_serial(uint16_t PORT);
            int is_transmit_empty(uint16_t PORT);
            void write_serial(char a,uint16_t PORT);
            void write_string_serial(const char* a,uint16_t PORT);

            static inline uint16_t LowestAvailablePort(){
                static uint16_t Port=0;
                if(Port != 0)return Port;
                if(Sauce::IO::Debug::COM8_Good)Port=Sauce::IO::Debug::COM8;
                if(Sauce::IO::Debug::COM7_Good)Port=Sauce::IO::Debug::COM7;
                if(Sauce::IO::Debug::COM6_Good)Port=Sauce::IO::Debug::COM6;
                if(Sauce::IO::Debug::COM5_Good)Port=Sauce::IO::Debug::COM5;
                if(Sauce::IO::Debug::COM4_Good)Port=Sauce::IO::Debug::COM4;
                if(Sauce::IO::Debug::COM3_Good)Port=Sauce::IO::Debug::COM3;
                if(Sauce::IO::Debug::COM2_Good)Port=Sauce::IO::Debug::COM2;
                if(Sauce::IO::Debug::COM1_Good)Port=Sauce::IO::Debug::COM1;
                return Port;
            }
            static inline uint16_t HighestAvailablePort(){
                static uint16_t Port=0;
                if(Port != 0)return Port;
                if(Sauce::IO::Debug::COM1_Good)Port=Sauce::IO::Debug::COM1;
                if(Sauce::IO::Debug::COM2_Good)Port=Sauce::IO::Debug::COM2;
                if(Sauce::IO::Debug::COM3_Good)Port=Sauce::IO::Debug::COM3;
                if(Sauce::IO::Debug::COM4_Good)Port=Sauce::IO::Debug::COM4;
                if(Sauce::IO::Debug::COM5_Good)Port=Sauce::IO::Debug::COM5;
                if(Sauce::IO::Debug::COM6_Good)Port=Sauce::IO::Debug::COM6;
                if(Sauce::IO::Debug::COM7_Good)Port=Sauce::IO::Debug::COM7;
                if(Sauce::IO::Debug::COM8_Good)Port=Sauce::IO::Debug::COM8;
                return Port;
            }
        };
    };
};