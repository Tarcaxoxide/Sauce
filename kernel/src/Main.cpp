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

    if(Sauce::IO::Debug::COM1_Good)Sauce::IO::Debug::COM1_Console.Initialize(Sauce::IO::Debug::COM1);
    if(Sauce::IO::Debug::COM2_Good)Sauce::IO::Debug::COM2_Console.Initialize(Sauce::IO::Debug::COM2);
    if(Sauce::IO::Debug::COM3_Good)Sauce::IO::Debug::COM3_Console.Initialize(Sauce::IO::Debug::COM3);
    if(Sauce::IO::Debug::COM4_Good)Sauce::IO::Debug::COM4_Console.Initialize(Sauce::IO::Debug::COM4);
    if(Sauce::IO::Debug::COM5_Good)Sauce::IO::Debug::COM5_Console.Initialize(Sauce::IO::Debug::COM5);
    if(Sauce::IO::Debug::COM6_Good)Sauce::IO::Debug::COM6_Console.Initialize(Sauce::IO::Debug::COM6);
    if(Sauce::IO::Debug::COM7_Good)Sauce::IO::Debug::COM7_Console.Initialize(Sauce::IO::Debug::COM7);
    if(Sauce::IO::Debug::COM8_Good)Sauce::IO::Debug::COM8_Console.Initialize(Sauce::IO::Debug::COM8);
    

    Sauce::Kernel_cl Kernel(DFBL);
    Kernel.Stop(true);
    return DFBL->TestNumber;
}