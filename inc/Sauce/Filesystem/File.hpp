#ifndef __Sauce_Filesystem_File
#define __Sauce_Filesystem_File
#include<Sauce/Filesystem/Header.hpp>
#include<std/string.hpp>
namespace Sauce{
	namespace Filesystem{
		namespace File{
			struct File_st{
				Sauce::Filesystem::Header::Header_st Header;
				File_st(const char* name){
					Header.Name=name;
				}
			};
		};
	};
};
#endif