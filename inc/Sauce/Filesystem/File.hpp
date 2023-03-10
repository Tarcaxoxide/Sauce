#ifndef __Sauce_Filesystem_File
#define __Sauce_Filesystem_File
#include<Sauce/Filesystem/Blob.hpp>
#include<std/string.hpp>
namespace Sauce{
	namespace Filesystem{
		namespace File{
			struct File_st:public Sauce::Filesystem::Blob::Blob_st{
				File_st(const char* name): Sauce::Filesystem::Blob::Blob_st(name,Sauce::Filesystem::Header::Classification::Classification_File){}
			};
		};
	};
};
#endif