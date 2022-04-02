#include<Sauce/Kernel.hpp>


extern "C" int64_t _start(DataStructure* DFBL){ // DFBL = Data From Boot Loader
    Sauce::_Kernel Kernel(DFBL);

    Sauce::IO::GlobalTerminal->PutString("\n\r");
    Sauce::IO::GlobalTerminal->PutString(Sauce::Convert::To_String::From_uint64((uint64_t)DFBL->rsdp));
    Sauce::IO::GlobalTerminal->PutString("\n\r");
    
    Sauce::IO::GlobalTerminal->PutChar(*(uint8_t*)DFBL->rsdp);
    Sauce::IO::GlobalTerminal->PutChar(*((uint8_t*)DFBL->rsdp+1));
    Sauce::IO::GlobalTerminal->PutChar(*((uint8_t*)DFBL->rsdp+2));
    Sauce::IO::GlobalTerminal->PutChar(*((uint8_t*)DFBL->rsdp+3));
    Sauce::IO::GlobalTerminal->PutChar(*((uint8_t*)DFBL->rsdp+4));
    Sauce::IO::GlobalTerminal->PutChar(*((uint8_t*)DFBL->rsdp+5));
    Sauce::IO::GlobalTerminal->PutChar(*((uint8_t*)DFBL->rsdp+6));
    Sauce::IO::GlobalTerminal->PutChar(*((uint8_t*)DFBL->rsdp+7));

    do{
        Sauce::IO::MouseData NM = Sauce::IO::ProcessMousePacket();
        if(NM.New)Sauce::_Kernel::Notify_Of_Mouse(NM);
    }while(true);

    Kernel.Stop();
    return DFBL->TestNumber;
    //test push
}