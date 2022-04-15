#include<Sauce/Kernel.hpp>


extern "C" int64_t _start(DataStructure* DFBL){ // DFBL = Data From Boot Loader // I will not be using shortnames like this in userspace.
    Sauce::Kernel_cl Kernel(DFBL);

    Sauce::IO::MouseData_st* NM; // Mouse data pointer, this was a new instance but that was causing problems with the position max/min 
                              // the onscreen mouse respected the boundries but the in code mouse did not.
                              // making this a pointer instead solved this issue.
    do{
        NM = Sauce::IO::ProcessMousePacket();
        if(NM->New)Sauce::Kernel_cl::Notify_Of_Mouse(NM);
    }while(true);

    Kernel.Stop(true);
    return DFBL->TestNumber;
}