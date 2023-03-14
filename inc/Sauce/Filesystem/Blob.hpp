#ifndef __Sauce_Filesystem_Blob
#define __Sauce_Filesystem_Blob
#include<Sauce/Filesystem/Header.hpp>
#include<std/list.hpp>
#include<std/string.hpp>
#include<std/to_string.hpp>
namespace Sauce{
	namespace Filesystem{
		namespace Blob{
			struct Blob_st{
				Sauce::Filesystem::Header::Header_st Header;
				std::list<Blob_st> Sub;
				size_t CurrentByte{0};
				size_t CurrentSector{0};
				std::ustring CurrentSectorData;
				Blob_st(const char* name,const char* ext,Sauce::Filesystem::Header::Classification_en classification){
					if(classification == Sauce::Filesystem::Header::Classification_en::Classification_File){
						Header.Name=new char[sizeof(name)+1]{0};
						for(size_t i=0;i<sizeof(name);i++)Header.Name[i]=name[i];
						Header.Ext=(char*)ext;
					}else if(classification == Sauce::Filesystem::Header::Classification_en::Classification_Directory){
						Header.Name=new char[sizeof(name)+1]{0};
						for(size_t i=0;i<sizeof(name);i++)Header.Name[i]=name[i];
						Header.Ext=(char*)ext;
					}
					Header.Classification=classification;
				}
				std::string List();
				Blob_st& GetSub(size_t index);
				uint8_t& GetByte(size_t byte);
				void Add(const char* name,const char* ext,Sauce::Filesystem::Header::Classification_en classification);
			};
		};
	};
};
#endif