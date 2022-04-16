#include<Sauce/Kernel.hpp>


extern "C" int64_t _start(DataStructure* DFBL){ // DFBL = Data From Boot Loader // I will not be using shortnames like this in userspace.
    Sauce::Kernel_cl Kernel(DFBL);
    

    Kernel.Stop(true);
    return DFBL->TestNumber;
}