#include<Sauce/Kernel.hpp>


extern "C" int64_t _start(DataStructure* DFBL){ // DFBL = Data From Boot Loader
    Sauce::_Kernel Kernel(DFBL);

    Sauce::IO::GlobalTerminal->PutString("\n\r");
    Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::HexToString((uint64_t)DFBL->rsdp));
    Sauce::IO::GlobalTerminal->PutString("\n\r");
    
    Sauce::IO::GlobalTerminal->PutChar(*(uint8_t*)DFBL->rsdp);
    Sauce::IO::GlobalTerminal->PutChar(*((uint8_t*)DFBL->rsdp+1));
    Sauce::IO::GlobalTerminal->PutChar(*((uint8_t*)DFBL->rsdp+2));
    Sauce::IO::GlobalTerminal->PutChar(*((uint8_t*)DFBL->rsdp+3));
    Sauce::IO::GlobalTerminal->PutChar(*((uint8_t*)DFBL->rsdp+4));
    Sauce::IO::GlobalTerminal->PutChar(*((uint8_t*)DFBL->rsdp+5));
    Sauce::IO::GlobalTerminal->PutChar(*((uint8_t*)DFBL->rsdp+6));
    Sauce::IO::GlobalTerminal->PutChar(*((uint8_t*)DFBL->rsdp+7));

    Sauce::IO::MouseData* NM;
    do{
        NM = Sauce::IO::ProcessMousePacket();
        if(NM->New)Sauce::_Kernel::Notify_Of_Mouse(NM);
    }while(true);

    Kernel.Stop(true);
    return DFBL->TestNumber;
    //test
}