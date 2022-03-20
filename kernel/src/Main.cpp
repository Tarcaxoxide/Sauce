#include<Sauce/Kernel.hpp>


extern "C" int64_t _start(DataStructure* DFBL){ // DFBL = Data From Boot Loader
    _Kernel Kernel(DFBL);

    Kernel.Term.PutString("Test\n\r");
    

    while(true){
        asm volatile("hlt");
    }
    return DFBL->TestNumber;
}