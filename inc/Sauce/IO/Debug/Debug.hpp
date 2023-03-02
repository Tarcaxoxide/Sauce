#ifndef __Sauce_IO_Debug_Debugger
#define __Sauce_IO_Debug_Debugger
#include<Sauce/NameSpaceIdentifiers.hpp>
#include<std/string.hpp>
namespace Sauce{
	namespace IO{
		namespace Debug{
				struct Debugger_st{
					char* FunctionName;
					char* thisNameSpace;
					char* FileName;
					bool AllowPrint=false;
					Debugger_st(const char* FileName,const char* FunctionName,const char* thisNameSpace,bool AllowPrint);
					void Print(const char* text);
					inline void Print(std::string text){Print(text.RawTyped());}
					void indent();
					~Debugger_st();
				};
		};
	};
};
#endif