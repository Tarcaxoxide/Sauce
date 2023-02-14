#include<Sauce/IO/ACPI.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utility/Conversion.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
namespace Sauce{
    namespace IO{
        namespace ACPI{
            void* FindTable(SDTHeader* sdtHeader,char* signature){
                Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"FindTable",_NAMESPACE_,_ALLOW_PRINT_);
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