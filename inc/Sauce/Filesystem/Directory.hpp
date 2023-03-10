#ifndef __Sauce_Filesystem_Directory
#define __Sauce_Filesystem_Directory
#include<std/list.hpp>
#include<Sauce/Filesystem/File.hpp>
#include<Sauce/Filesystem/Header.hpp>
#include<std/string.hpp>
namespace Sauce{
	namespace Filesystem{
		namespace Directory{
			struct Directory_st{
				Sauce::Filesystem::Header::Header_st Header;
				Directory_st(const char* name){
					Header.Name=name;
				}
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