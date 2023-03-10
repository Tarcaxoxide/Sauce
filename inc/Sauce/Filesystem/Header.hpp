#ifndef __Sauce_Filesystem_Header
#define __Sauce_Filesystem_Header
#include<std/string.hpp>
#include<std/list.hpp>
namespace Sauce{
	namespace Filesystem{
		namespace Header{
			struct Attributes_st{
				uint32_t Write:1; // is the file writable.
				uint32_t Read:1; // can i read this? 
				uint32_t Execute:1; // executable code?
				uint32_t UserLand:1; // whether or not we even let the userland know about this.
				uint32_t Admin:1; // admin/root only.
				uint32_t Bitmap:1; // is the this actually an image?
				uint32_t Text:1; // is the this actually plan text.
				uint32_t Empty:1; // has the this been loaded?
				uint32_t Encrypted:12;//holds a selector for the encryption algorithm used, 0 if none.
				uint32_t SizeExtension:12; //Size*SizeExtension.
				uint32_t Size; //Size on disk.
			}__attribute__((packed));
			struct Header_st{
				Attributes_st Attributes;
				std::list<std::string*> Tags;
			};
		};
	};
};
#endif