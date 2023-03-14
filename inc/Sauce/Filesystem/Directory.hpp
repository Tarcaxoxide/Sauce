#ifndef __Sauce_Filesystem_Directory
#define __Sauce_Filesystem_Directory
#include<Sauce/Filesystem/Blob.hpp>
#include<std/string.hpp>
namespace Sauce{
	namespace Filesystem{
		namespace Directory{
			struct Directory_st:public Sauce::Filesystem::Blob::Blob_st{
				Directory_st(const char* name): Sauce::Filesystem::Blob::Blob_st(name,nullptr,Sauce::Filesystem::Header::Classification_en::Classification_Directory){}
				inline void AddFile(const char* name,const char* ext){Add(name,ext,Sauce::Filesystem::Header::Classification_en::Classification_File);}
				inline void AddDirectory(const char* name){Add(name,nullptr,Sauce::Filesystem::Header::Classification_en::Classification_Directory);}
				Sauce::Filesystem::Blob::Blob_st& operator[](size_t index);
			};
		};
	};
};
#endif