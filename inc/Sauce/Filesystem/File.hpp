#ifndef __Sauce_Filesystem_File
#define __Sauce_Filesystem_File
#include<std/string.hpp>
#include<Sauce/Filesystem/Header.hpp>
namespace Sauce{
	namespace Filesystem{
		namespace File{
			struct File_st{
				Sauce::Filesystem::Header::Header_st Header;
				inline std::string Name(){/*the filename is just the first tag*/return *(Header.Tags.First());}
				std::ustring Contents;
				File_st();
				File_st(const std::string& name);
				File_st(const File_st& other);
				~File_st();
			};
		};
	};
};
#endif