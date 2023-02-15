#pragma once
#include<Sauce/Memory/List.hpp>
#include<_std/string.hpp>
const static char* _NAMESPACE_="::";
const static bool _ALLOW_PRINT_=false;
namespace _std{
    const static char* _NAMESPACE_="::_std";
    const static bool _ALLOW_PRINT_=false;
};
namespace Sauce{
    const static char* _NAMESPACE_="::Sauce";
    const static bool _ALLOW_PRINT_=false;
    namespace Fauxon{
        const static char* _NAMESPACE_="::Sauce::Fauxon";
        const static bool _ALLOW_PRINT_=true;
        namespace DataTypes{
            const static char* _NAMESPACE_="::Sauce::Fauxon::DataTypes";
            const static bool _ALLOW_PRINT_=true;
        };
    };
    namespace Graphics{
        const static char* _NAMESPACE_="::Sauce::Graphics";
        const static bool _ALLOW_PRINT_=true;
        namespace Basic{
            const static char* _NAMESPACE_="::Sauce::Graphics::Basic";
            const static bool _ALLOW_PRINT_=false;
        };
    };
    namespace Interrupts{
        const static char* _NAMESPACE_="::Sauce::Interrupts";
        const static bool _ALLOW_PRINT_=false;
        namespace PIT{
            const static char* _NAMESPACE_="::Sauce::Interrupts::PIT";
            const static bool _ALLOW_PRINT_=false;
        };
    };
    namespace IO{
        const static char* _NAMESPACE_="::Sauce::IO";
        const static bool _ALLOW_PRINT_=false;
        namespace ACPI{
            const static char* _NAMESPACE_="::Sauce::IO::ACPI";
            const static bool _ALLOW_PRINT_=false;
        };
    };
    namespace Math{
        const static char* _NAMESPACE_="::Sauce::Math";
        const static bool _ALLOW_PRINT_=false;
    };
    namespace Memory{
        const static char* _NAMESPACE_="::Sauce::Memory";
        const static bool _ALLOW_PRINT_=false;
        namespace Management{
            const static char* _NAMESPACE_="::Sauce::Management";
            const static bool _ALLOW_PRINT_=false;
        };
    };
    namespace Commands{
        const static char* _NAMESPACE_="::Sauce::Commands";
        const static bool _ALLOW_PRINT_=false;
    };
    namespace Storage{
        const static char* _NAMESPACE_="::Sauce::Storage";
        const static bool _ALLOW_PRINT_=false;
        namespace FileSystem{
            const static char* _NAMESPACE_="::Sauce::Storage::Filesystem";
            const static bool _ALLOW_PRINT_=false;
            namespace FAT{
                const static char* _NAMESPACE_="::Sauce::Storage::Filesystem::FAT";
                const static bool _ALLOW_PRINT_=false;
            };
            namespace VirtualFileSystem{
                const static char* _NAMESPACE_="::Sauce::Storage::Filesystem::VirtualFileSystem";
                const static bool _ALLOW_PRINT_=false;
            };
        };
    };
    namespace Utility{
        const static char* _NAMESPACE_="::Sauce::Utility";
        const static bool _ALLOW_PRINT_=false;
        namespace Conversion{
            const static char* _NAMESPACE_="::Sauce::Utility::Conversion";
            const static bool _ALLOW_PRINT_=false;
        };
        namespace Manipulate{
            const static char* _NAMESPACE_="::Sauce::Utility::Manipulate";
            const static bool _ALLOW_PRINT_=false;
        };
        namespace Neural{
            const static char* _NAMESPACE_="::Sauce::Utility::Neural";
            const static bool _ALLOW_PRINT_=false;
        };
    };
};