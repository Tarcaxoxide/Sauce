#ifndef __Sauce_Filesystem_File
#define __Sauce_Filesystem_File
#include<Sauce/Filesystem/Blob.hpp>
#include<std/string.hpp>
namespace Sauce{
	namespace Filesystem{
		namespace File{
			struct File_st:public Sauce::Filesystem::Blob::Blob_st{
				size_t CurrentByte=0;
				size_t CurrentSector=0;
				std::ustring CurrentSectorData;
				File_st(const char* name,const char* ext): Sauce::Filesystem::Blob::Blob_st(name,ext,Sauce::Filesystem::Header::Classification_en::Classification_File){}
				uint8_t ReadByte(size_t byte);
			};
		};
	};
};
#endif