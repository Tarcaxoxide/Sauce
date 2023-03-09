#ifndef __Sauce_Filesystem_File
#define __Sauce_Filesystem_File
#include<std/string.hpp>
#include<Sauce/Filesystem/Header.hpp>
namespace Sauce{
	namespace Filesystem{
		namespace File{
			struct File_st{
				Sauce::Filesystem::Header::Header_st Header;
				std::string Name;
				std::ustring Contents;
				File_st();
				File_st(const std::string& name);
			};
		};
	};
};
#endif