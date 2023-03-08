#ifndef __Sauce_Memory_Filesystem_Directory
#define __Sauce_Memory_Filesystem_Directory
#include<std/string.hpp>
#include<std/list.hpp>
#include<Sauce/Memory/Filesystem/File.hpp>
namespace Sauce{
	namespace Memory{
		namespace Filesystem{
			namespace Directory{
				struct Directory_st{
					Sauce::Memory::Filesystem::File::Header_st Header;
					std::list<Directory_st> SubDirectories;
					std::list<Sauce::Memory::Filesystem::File::File_st> Files;
					Directory_st(){
						Header.Attribute_Write=1;
						Header.Attribute_Read=0;
						Header.Attribute_Execute=0;
						Header.Attribute_UserLand=0;
						Header.Attribute_Admin=0;
						Header.Attribute_Bitmap=0;
						Header.Attribute_Text=0;
						Header.Set=0;
						Header.Attribute_Encrypted=0;
						Header.SizeExtension=0;
						Header.Size=0;
					}
				};
			};
		};
	};
};
#endif