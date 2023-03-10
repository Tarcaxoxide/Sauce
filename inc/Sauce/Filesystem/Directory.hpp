#ifndef __Sauce_Filesystem_Directory
#define __Sauce_Filesystem_Directory
#include<std/list.hpp>
#include<Sauce/Filesystem/File.hpp>
#include<std/string.hpp>
namespace Sauce{
	namespace Filesystem{
		namespace Directory{
			struct Directory_st{
				const char* Name;
				std::list<Sauce::Filesystem::Directory::Directory_st> Directories;
				std::list<Sauce::Filesystem::File::File_st> Files;
				inline void AddFile(const char* fileName){Files.AddLast(Sauce::Filesystem::File::File_st{fileName});}
				inline void AddDirectory(const char* directoryName){Directories.AddLast(Sauce::Filesystem::Directory::Directory_st{directoryName});}
				inline std::string ListFiles(){
					std::string Result="[";
					for(size_t i=0;i<Files.Size();i++){
						Result+=Files[i].Name;
						if(i<Files.Size()-1)Result+=",";
					}
					Result+="]";
					return Result;
				}
				inline std::string ListDirectories(){
					std::string Result="[";
					for(size_t i=0;i<Directories.Size();i++){
						Result+=Directories[i].Name;
						if(i<Directories.Size()-1)Result+=",";
					}
					Result+="]";
					return Result;
				}
				inline std::string List(){
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
};
#endif