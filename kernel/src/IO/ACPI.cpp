#include<Sauce/IO/ACPI.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utilities/Conversion.hpp>


namespace Sauce{
    namespace IO{
        namespace ACPI{
            void* FindTable(SDTHeader* sdtHeader,char* signature){
                Sauce::IO::Debug::Print_Call("FindTable",true);
                int entries = (sdtHeader->Length - sizeof(Sauce::IO::ACPI::SDTHeader)) / 8;
                for(int t=0;t<entries;t++){
                    Sauce::IO::ACPI::SDTHeader* nSDTHeader = (Sauce::IO::ACPI::SDTHeader*)*(uint64_t*)((uint64_t)sdtHeader + sizeof(Sauce::IO::ACPI::SDTHeader) + (t * 8));
                    for(int i=0;i<4;i++){
                        if(nSDTHeader->Signature[i] != signature[i]){
                            break;
                        }
                        if(i == 3){
                            Sauce::IO::Debug::Print_Return(Sauce::Convert::HexToString((uint64_t)nSDTHeader),true);
                            return nSDTHeader;
                        }
                    }
                }
                Sauce::IO::Debug::Print_Return("<NULL>",true);
                return NULL;
            }
        };
    };
};