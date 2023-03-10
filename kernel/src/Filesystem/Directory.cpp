#include<Sauce/Filesystem/Directory.hpp>
#include<Sauce/IO/Debug/Debug.hpp>
namespace Sauce{
	namespace Filesystem{
		namespace Directory{
			void Directory_st::AddFile(const char* fileName){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Directory_st::AddFile",_NAMESPACE_,_ALLOW_PRINT_);
				Files.AddLast(Sauce::Filesystem::File::File_st(fileName));
				Header.Empty=0;
			}
			void Directory_st::AddDirectory(const char* directoryName){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Directory_st::AddDirectory",_NAMESPACE_,_ALLOW_PRINT_);
				Directories.AddLast(Sauce::Filesystem::Directory::Directory_st(directoryName));
				Header.Empty=0;
			}
			std::string Directory_st::ListFiles(){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Directory_st::ListFiles",_NAMESPACE_,_ALLOW_PRINT_);
				std::string Result="[";
				for(size_t i=0;i<Files.Size();i++){
					Result+=Files[i].Header.Name;
					if(i<Files.Size()-1)Result+=",";
				}
				Result+="]";
				return Result;
			}
			std::string Directory_st::ListDirectories(){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Directory_st::ListDirectories",_NAMESPACE_,_ALLOW_PRINT_);
				std::string Result="[";
				for(size_t i=0;i<Directories.Size();i++){
					Result+=Directories[i].Header.Name;
					if(i<Directories.Size()-1)Result+=",";
				}
				Result+="]";
				return Result;
			}
			std::string Directory_st::List(){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Directory_st::List",_NAMESPACE_,_ALLOW_PRINT_);
				std::string Result="[";
				Result+=ListDirectories();
				Result+=",";
				Result+=ListFiles();
				Result+="]";
				return Result;
			}
		};
	};
};