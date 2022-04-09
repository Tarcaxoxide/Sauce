#include<Sauce/Kernel.hpp>


extern "C" int64_t _start(DataStructure* DFBL){ // DFBL = Data From Boot Loader
    Sauce::_Kernel Kernel(DFBL);

    Sauce::IO::MouseData* NM;
    do{
        NM = Sauce::IO::ProcessMousePacket();
        if(NM->New)Sauce::_Kernel::Notify_Of_Mouse(NM);
    }while(true);

    Kernel.Stop(true);
    return DFBL->TestNumber;
    //test
}