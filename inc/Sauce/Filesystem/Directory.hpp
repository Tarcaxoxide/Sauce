#ifndef __Sauce_Filesystem_Directory
#define __Sauce_Filesystem_Directory
#include<Sauce/Filesystem/Blob.hpp>
#include<std/string.hpp>
namespace Sauce{
	namespace Filesystem{
		namespace Directory{
			struct Directory_st:public Sauce::Filesystem::Blob::Blob_st{
				Directory_st(const char* name): Sauce::Filesystem::Blob::Blob_st(name,Sauce::Filesystem::Header::Classification::Classification_Directory){}
				inline void AddFile(const char* name){Add(name,Sauce::Filesystem::Header::Classification::Classification_File);}
				inline void AddDirectory(const char* name){Add(name,Sauce::Filesystem::Header::Classification::Classification_Directory);}
			};
		};
	};
};
#endif