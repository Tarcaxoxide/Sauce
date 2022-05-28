#include<Sauce/Storage/AHCI.hpp>
#include<Sauce/IO/Debug/Console.hpp>

namespace Sauce{
    namespace Storage{
        AHCIDriver_cl::AHCIDriver_cl(Sauce::IO::PCIDeviceHeader_st* pciBaseAddress){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::STORAGE)Sauce::IO::Debug::COM1_Console.Write((char*)"[AHCIDriver_cl::AHCIDriver_cl]\n\0");
            this->pciBaseAddress=pciBaseAddress;
            
            if(Sauce::IO::Debug::FUNCTION_RETURNS && Sauce::IO::Debug::STORAGE)Sauce::IO::Debug::COM1_Console.Write((char*)"\t<-(\"this\")\n\0");
        }
        AHCIDriver_cl::~AHCIDriver_cl(){
            if(Sauce::IO::Debug::FUNCTION_CALLS && Sauce::IO::Debug::STORAGE)Sauce::IO::Debug::COM1_Console.Write((char*)"[AHCIDriver_cl::~AHCIDriver_cl]\n\0");
            if(Sauce::IO::Debug::FUNCTION_RETURNS && Sauce::IO::Debug::STORAGE)Sauce::IO::Debug::COM1_Console.Write((char*)"\t<-(void)\n\0");
        }
    };
};