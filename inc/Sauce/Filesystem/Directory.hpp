#ifndef __Sauce_Filesystem_Directory
#define __Sauce_Filesystem_Directory
#include<std/string.hpp>
#include<std/list.hpp>
#include<Sauce/Filesystem/File.hpp>
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
				Sauce::Filesystem::File::Header_st Header;
				std::string Name;
				std::list<Directory_st> SubDirectories;
				std::list<Sauce::Filesystem::File::File_st> Files;
				Directory_st(){
					Header.Attribute_Write=1;
					Header.Attribute_Read=0;
					Header.Attribute_Execute=0;
					Header.Attribute_UserLand=0;
					Header.Attribute_Admin=0;
					Header.Attribute_Bitmap=0;
					Header.Attribute_Text=0;
					Header.Attribute_Empty=1;
					Header.Attribute_Encrypted=0;
					Header.SizeExtension=0;
					Header.Size=0;
				}
			};
		};
	};
};
#endif