#include<Sauce/Kernel.hpp>


extern "C" int64_t _start(DataStructure* DFBL){ // DFBL = Data From Boot Loader
    Sauce::_Kernel Kernel(DFBL);

    Kernel.Term.PutString("Test\n\r");
    

    Kernel.Stop();
    return DFBL->TestNumber;
}