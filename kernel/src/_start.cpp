#include<Sauce/Kernel.hpp>
#include<Sauce/Math.hpp>
#include<Sauce/IO/Debug/Serial.hpp>
extern "C" int64_t _start(DataStructure* DFBL){
	Sauce::IO::Debug::COM1_Good=Sauce::IO::Debug::init_serial(Sauce::IO::Debug::COM1);
	Sauce::IO::Debug::COM2_Good=Sauce::IO::Debug::init_serial(Sauce::IO::Debug::COM2);
	Sauce::IO::Debug::COM3_Good=Sauce::IO::Debug::init_serial(Sauce::IO::Debug::COM3);
	Sauce::IO::Debug::COM4_Good=Sauce::IO::Debug::init_serial(Sauce::IO::Debug::COM4);
	Sauce::IO::Debug::COM5_Good=Sauce::IO::Debug::init_serial(Sauce::IO::Debug::COM5);
	Sauce::IO::Debug::COM6_Good=Sauce::IO::Debug::init_serial(Sauce::IO::Debug::COM6);
	Sauce::IO::Debug::COM7_Good=Sauce::IO::Debug::init_serial(Sauce::IO::Debug::COM7);
	Sauce::IO::Debug::COM8_Good=Sauce::IO::Debug::init_serial(Sauce::IO::Debug::COM8);

	DefaultSerialWrite("The kernel says hello!");

	Sauce::Core::Kernel_cl Kernel(DFBL);
	return DFBL->TestNumber;
}