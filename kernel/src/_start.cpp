#include<Sauce/Kernel.hpp>
#include<Sauce/Math.hpp>
extern "C" int64_t _start(DataStructure* DFBL){
	
	Sauce::Core::Kernel_cl Kernel(DFBL);
	return DFBL->TestNumber;
}