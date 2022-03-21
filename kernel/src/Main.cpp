#include<Sauce/Kernel.hpp>


extern "C" int64_t _start(DataStructure* DFBL){ // DFBL = Data From Boot Loader
    Sauce::_Kernel Kernel(DFBL);

    while(true){
        Sauce::IO::ProcessMousePacket();
        for(size_t I=0;I<10000;I++);
    }

    Kernel.Stop();
    return DFBL->TestNumber;
}