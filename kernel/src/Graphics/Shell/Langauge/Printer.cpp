#include<Sauce/Graphics/Shell/Language/Printer.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
namespace Sauce{
	namespace Graphics{
		namespace Shell{
			namespace Language{
				std::string Print_str(Sauce::Memory::SmartPtr_cl<Sauce::Graphics::Shell::Language::Types::Value> value){
					Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Print_str",_NAMESPACE_,_ALLOW_PRINT_);
					return value->inspect();
				}
			};
		};
	};
};