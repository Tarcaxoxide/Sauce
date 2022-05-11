#include<Sauce/IO/Debug/Serial.hpp>

extern "C" void __stack_chk_fail(){
    uint16_t Port = Sauce::IO::Debug::LowestAvailablePort();
    if(Port == 0)return; // we can't write to port because there is none available.
    Sauce::IO::Debug::write_string_serial("[__stack_chk_fail]\n\0",Port);
}
extern "C" void _Unwind_Resume(){
    uint16_t Port = Sauce::IO::Debug::LowestAvailablePort();
    if(Port == 0)return; // we can't write to port because there is none available.
    Sauce::IO::Debug::write_string_serial("[_Unwind_Resume]\n\0",Port);
}
extern "C" void __gxx_personality_v0(){
    uint16_t Port = Sauce::IO::Debug::LowestAvailablePort();
    if(Port == 0)return; // we can't write to port because there is none available.
    Sauce::IO::Debug::write_string_serial("[__gxx_personality_v0]\n\0",Port);
}
extern "C" void __dso_handle(){
    uint16_t Port = Sauce::IO::Debug::LowestAvailablePort();
    if(Port == 0)return; // we can't write to port because there is none available.
    Sauce::IO::Debug::write_string_serial("[__dso_handle]\n\0",Port);
}
extern "C" void __cxa_atexit(){
    uint16_t Port = Sauce::IO::Debug::LowestAvailablePort();
    if(Port == 0)return; // we can't write to port because there is none available.
    Sauce::IO::Debug::write_string_serial("[__cxa_atexit]\0",Port);
}