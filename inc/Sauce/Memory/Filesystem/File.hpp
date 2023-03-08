#ifndef __Sauce_Memory_Filesystem_File
#define __Sauce_Memory_Filesystem_File
#include<std/string.hpp>
namespace Sauce{
	namespace Memory{
		namespace Filesystem{
			namespace File{
				struct Header_st{
					uint32_t Attribute_Write:1; // is the file writable.
					uint32_t Attribute_Read:1; // can i read this? 
					uint32_t Attribute_Execute:1; // executable code?
					uint32_t Attribute_UserLand:1; // whether or not we even let the userland know about this.
					uint32_t Attribute_Admin:1; // admin/root only.
					uint32_t Attribute_Bitmap:1; // is the this actually an image?
					uint32_t Attribute_Text:1; // is the this actually plan text.
					uint32_t Attribute_Set:1; // has the this been loaded?
					uint32_t Attribute_Encrypted:12;//holds a selector for the encryption algorithm used, 0 if none.
					uint32_t SizeExtension:12; //Size*SizeExtension.
					uint32_t Size; //Size on disk.
				}__attribute__((packed));
				struct File_st{
					Header_st Header;
					std::string Name;
					std::ustring Contents;
					File_st(){
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