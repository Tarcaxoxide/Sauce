#include<Sauce/IO/ACPI.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utility/Conversion.hpp>


namespace Sauce{
    namespace IO{
        namespace ACPI{
            void* FindTable(Sauce::IO::Debug::Debugger_st* pDebugger,SDTHeader* sdtHeader,char* signature){
                Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"FindTable");
                int entries = (sdtHeader->Length - sizeof(Sauce::IO::ACPI::SDTHeader)) / 8;
                for(int t=0;t<entries;t++){
                    Sauce::IO::ACPI::SDTHeader* nSDTHeader = (Sauce::IO::ACPI::SDTHeader*)*(uint64_t*)((uint64_t)sdtHeader + sizeof(Sauce::IO::ACPI::SDTHeader) + (t * 8));
                    for(int i=0;i<4;i++){
                        if(nSDTHeader->Signature[i] != signature[i]){
                            break;
                        }
                        if(i == 3){
                            return nSDTHeader;
                        }
                    }
                }
                return NULL;
            }
        };
    };
};