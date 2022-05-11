#include<Sauce/Kernel.hpp>

extern "C" int64_t _start(DataStructure* DFBL){ // DFBL = Data From Boot Loader // I will not be using shortnames like this in userspace.
    Sauce::IO::Debug::COM1_Good=Sauce::IO::Debug::init_serial(Sauce::IO::Debug::COM1);
    Sauce::IO::Debug::COM2_Good=Sauce::IO::Debug::init_serial(Sauce::IO::Debug::COM2);
    Sauce::IO::Debug::COM3_Good=Sauce::IO::Debug::init_serial(Sauce::IO::Debug::COM3);
    Sauce::IO::Debug::COM4_Good=Sauce::IO::Debug::init_serial(Sauce::IO::Debug::COM4);
    Sauce::IO::Debug::COM5_Good=Sauce::IO::Debug::init_serial(Sauce::IO::Debug::COM5);
    Sauce::IO::Debug::COM6_Good=Sauce::IO::Debug::init_serial(Sauce::IO::Debug::COM6);
    Sauce::IO::Debug::COM7_Good=Sauce::IO::Debug::init_serial(Sauce::IO::Debug::COM7);
    Sauce::IO::Debug::COM8_Good=Sauce::IO::Debug::init_serial(Sauce::IO::Debug::COM8);

    uint16_t Port = Sauce::IO::Debug::LowestAvailablePort();
    if(Port == 0)return DFBL->TestNumber; // if initializing the serial ports failed than just exit.
    Sauce::IO::Debug::write_string_serial("[Initialized Serial Ports For Debugging]\n\0",Port);


    Sauce::Kernel_cl Kernel(DFBL,Port);
    Kernel.Stop(true);
    return DFBL->TestNumber;
}