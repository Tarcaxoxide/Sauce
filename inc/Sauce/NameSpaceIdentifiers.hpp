#ifndef __Sauce_NameSpaceIdentifiers
#define __Sauce_NameSpaceIdentifiers
#include<Sauce/Memory/List.hpp>
#include<std/string.hpp>
const static char* _NAMESPACE_="::";
const static bool _ALLOW_PRINT_=false;
namespace std{
	const static char* _NAMESPACE_="::std";
	const static bool _ALLOW_PRINT_=false;
};
namespace Sauce{
	const static char* _NAMESPACE_="::Sauce";
	const static bool _ALLOW_PRINT_=false;
	namespace Graphics{
		const static char* _NAMESPACE_="::Sauce::Graphics";
		const static bool _ALLOW_PRINT_=false;
		namespace Shell{
			const static char* _NAMESPACE_="::Sauce::Graphics::Shell";
			const static bool _ALLOW_PRINT_=true;
			namespace Lisp{
				const static char* _NAMESPACE_="::Sauce::Graphics::Shell:Lisp";
				const static bool _ALLOW_PRINT_=true;
			};
		};
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
		namespace PCI{
			const static char* _NAMESPACE_="::Sauce::IO::PCI";
			const static bool _ALLOW_PRINT_=false;
		};
		namespace RTC{
			const static char* _NAMESPACE_="::Sauce::IO::RTC";
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
			const static char* _NAMESPACE_="::Sauce::Memory::Management";
			const static bool _ALLOW_PRINT_=false;
		};
	};
	namespace Filesystem{
		const static char* _NAMESPACE_="::Sauce::Filesystem";
		const static bool _ALLOW_PRINT_=false;
		namespace File{
			const static char* _NAMESPACE_="::Sauce::Filesystem::File";
			const static bool _ALLOW_PRINT_=false;
		};
		namespace Directory{
			const static char* _NAMESPACE_="::Sauce::Filesystem::Directory";
			const static bool _ALLOW_PRINT_=false;
		};
	};
	namespace Storage{
		const static char* _NAMESPACE_="::Sauce::Storage";
		const static bool _ALLOW_PRINT_=false;
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
	};
};
#endif