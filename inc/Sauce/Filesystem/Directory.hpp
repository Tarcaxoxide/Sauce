#ifndef __Sauce_Filesystem_Directory
#define __Sauce_Filesystem_Directory
#include<std/list.hpp>
#include<Sauce/Filesystem/File.hpp>
#include<std/string.hpp>
namespace Sauce{
	namespace Filesystem{
		namespace Directory{
			struct Directory_st{
				const char* Name;/*there is some kind of weird behaviour here when using a std::string aka a Sauce::Memory::List_cl<char>, this should only be set once anyways.*/
				std::list<Sauce::Filesystem::Directory::Directory_st> Directories;
				std::list<Sauce::Filesystem::File::File_st> Files;
				void AddFile(const char* fileName);
				void AddDirectory(const char* directoryName);
				std::string ListFiles();
				std::string ListDirectories();
				std::string List();
			};
		};
	};
};
#endif