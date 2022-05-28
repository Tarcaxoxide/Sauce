#include<Sauce/IO/ACPI.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utilities/Conversion.hpp>


namespace Sauce{
    namespace IO{
        namespace ACPI{
            void* FindTable(SDTHeader* sdtHeader,char* signature){
                if(Sauce::IO::Debug::FUNCTION_CALLS)Sauce::IO::Debug::COM1_Console.Write((char*)"[FindTable]\n\0");
                int entries = (sdtHeader->Length - sizeof(Sauce::IO::ACPI::SDTHeader)) / 8;
                for(int t=0;t<entries;t++){
                    Sauce::IO::ACPI::SDTHeader* nSDTHeader = (Sauce::IO::ACPI::SDTHeader*)*(uint64_t*)((uint64_t)sdtHeader + sizeof(Sauce::IO::ACPI::SDTHeader) + (t * 8));
                    for(int i=0;i<4;i++){
                        if(nSDTHeader->Signature[i] != signature[i]){
                            break;
                        }
                        if(i == 3){
                            if(Sauce::IO::Debug::FUNCTION_RETURNS){
                                Sauce::IO::Debug::COM1_Console.Write((char*)"\t<-(\0");
                                Sauce::IO::Debug::COM1_Console.Write(Sauce::Convert::HexToString((uint64_t)nSDTHeader));
                                Sauce::IO::Debug::COM1_Console.Write((char*)")\n\0");
                            }
                            return nSDTHeader;
                        }
                    }
                }
                if(Sauce::IO::Debug::FUNCTION_RETURNS)Sauce::IO::Debug::COM1_Console.Write((char*)"\t<-(NULL)\n\0");
                return NULL;
            }
        };
    };
};