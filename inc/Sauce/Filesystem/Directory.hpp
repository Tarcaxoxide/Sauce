#ifndef __Sauce_Filesystem_Directory
#define __Sauce_Filesystem_Directory
#include<std/string.hpp>
#include<std/list.hpp>
#include<Sauce/Filesystem/File.hpp>
#include<Sauce/Filesystem/Header.hpp>
namespace Sauce{
	namespace Filesystem{
		namespace Directory{
			enum FilesystemOnDiskType_en{
				RAW_DATA=0,
				FAT12,
				FAT16,
				FAT28, // aka "FAT32"
				FAT32, // aka "ExFAT"
				VFAT
			};
			struct Directory_st{
				Sauce::Filesystem::Header::Header_st Header;
				std::string Name;
				std::list<Directory_st> Directories;
				std::list<Sauce::Filesystem::File::File_st> Files;
				Directory_st();
				Directory_st(const std::string& name);
				std::string ListFiles();
				std::string ListDirectories();
				std::string List();
				void AddDirectoryEntry(std::string directoryName);
				void AddFileEntry(std::string fileName);
			};
		};
	};
};
#endif