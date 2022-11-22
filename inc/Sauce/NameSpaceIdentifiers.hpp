#pragma once


#define LoggingDisabled 1

const static char* _NAMESPACE_="::";
const static bool _ALLOW_PRINT_=true;
namespace Sauce{
    const static char* _NAMESPACE_="::Sauce";
    const static bool _ALLOW_PRINT_=true;
    namespace Graphics{
        const static char* _NAMESPACE_="::Sauce::Graphics";
        const static bool _ALLOW_PRINT_=true;
    };
    namespace Interrupts{
        const static char* _NAMESPACE_="::Sauce::Interrupts";
        const static bool _ALLOW_PRINT_=true;
        namespace PIT{
            const static char* _NAMESPACE_="::Sauce::Interrupts::PIT";
            const static bool _ALLOW_PRINT_=true;
        };
    };
    namespace IO{
        const static char* _NAMESPACE_="::Sauce::IO";
        const static bool _ALLOW_PRINT_=true;
        namespace ACPI{
            const static char* _NAMESPACE_="::Sauce::IO::ACPI";
            const static bool _ALLOW_PRINT_=true;
        };
    };
    namespace Math{
        const static char* _NAMESPACE_="::Sauce::Math";
        const static bool _ALLOW_PRINT_=true;
    };
    namespace Memory{
        const static char* _NAMESPACE_="::Sauce::Memory";
        const static bool _ALLOW_PRINT_=true;
    };
    namespace Commands{
        const static char* _NAMESPACE_="::Sauce::Commands";
        const static bool _ALLOW_PRINT_=true;
    };
    namespace Storage{
        const static char* _NAMESPACE_="::Sauce::Storage";
        const static bool _ALLOW_PRINT_=true;
        namespace FileSystem{
            const static char* _NAMESPACE_="::Sauce::Storage::Filesystem";
            const static bool _ALLOW_PRINT_=true;
            namespace VirtualFileSystem{
                const static char* _NAMESPACE_="::Sauce::Storage::Filesystem::VirtualFileSystem";
                const static bool _ALLOW_PRINT_=true;
            };
        };
    };
    namespace Utility{
        const static char* _NAMESPACE_="::Sauce::Utility";
        const static bool _ALLOW_PRINT_=true;
        namespace Neural{
            const static char* _NAMESPACE_="::Sauce::Utility::Neural";
            const static bool _ALLOW_PRINT_=true;
        };
    };
};