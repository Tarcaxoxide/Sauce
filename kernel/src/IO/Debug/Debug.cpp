#include<Sauce/IO/Debug/Debug.hpp>
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Global.hpp>

int64_t Indentation=0;

namespace Sauce{
	namespace IO{
		namespace Debug{
			Debugger_st::Debugger_st(const char* FileName,const char* FunctionName,const char* thisNameSpace,bool AllowPrint){
				Sauce::Global::Kernel->InterruptsOff();
				this->FunctionName=(char*)FunctionName;
				this->thisNameSpace=(char*)thisNameSpace;
				this->FileName=(char*)FileName;
				this->AllowPrint=AllowPrint;
				if(!AllowPrint)return;
				indent();
				Sauce::IO::Debug::COM1_Console.Write((char*)"(");
				Sauce::IO::Debug::COM1_Console.Write(this->FileName);
				Sauce::IO::Debug::COM1_Console.Write((char*)")");
				Sauce::IO::Debug::COM1_Console.Write((char*)">[");
				Sauce::IO::Debug::COM1_Console.Write(this->thisNameSpace);
				Sauce::IO::Debug::COM1_Console.Write((char*)"::");
				Sauce::IO::Debug::COM1_Console.Write(this->FunctionName);
				Sauce::IO::Debug::COM1_Console.Write((char*)"]\n");
				Indentation++;
				Sauce::Global::Kernel->InterruptsOn();
			}
			void Debugger_st::Print(const char* text){
				if(!AllowPrint)return;
				Sauce::Global::Kernel->InterruptsOff();
				indent();
				Sauce::IO::Debug::COM1_Console.Write((char*)"[");
				Sauce::IO::Debug::COM1_Console.Write(this->thisNameSpace);
				Sauce::IO::Debug::COM1_Console.Write((char*)"::");
				Sauce::IO::Debug::COM1_Console.Write(this->FunctionName);
				Sauce::IO::Debug::COM1_Console.Write((char*)"]");
				Sauce::IO::Debug::COM1_Console.Write((char*)"{");
				Sauce::IO::Debug::COM1_Console.Write((char*)text);
				Sauce::IO::Debug::COM1_Console.Write((char*)"}\n");
				Sauce::Global::Kernel->InterruptsOn();
			}
			void Debugger_st::indent(){
				std::string IndentString="";
				for(int64_t i=0;i<Indentation;i++){
					IndentString+=".";
				}
				Sauce::IO::Debug::COM1_Console.Write(IndentString.RawTyped());
			}
			Debugger_st::~Debugger_st(){
				if(!AllowPrint)return;
				Sauce::Global::Kernel->InterruptsOff();
				indent();
				Sauce::IO::Debug::COM1_Console.Write((char*)"(");
				Sauce::IO::Debug::COM1_Console.Write(this->FileName);
				Sauce::IO::Debug::COM1_Console.Write((char*)")");
				Sauce::IO::Debug::COM1_Console.Write((char*)"<[");
				Sauce::IO::Debug::COM1_Console.Write(this->thisNameSpace);
				Sauce::IO::Debug::COM1_Console.Write((char*)"::");
				Sauce::IO::Debug::COM1_Console.Write(this->FunctionName);
				Sauce::IO::Debug::COM1_Console.Write((char*)"]\n");
				Indentation--;
				Sauce::Global::Kernel->InterruptsOn();
			}
		};
	};
};