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
						Header.Ext=new char[sizeof(ext)+1]{0};
						for(size_t i=0;i<sizeof(ext);i++)Header.Ext[i]=ext[i];
					}else if(classification == Sauce::Filesystem::Header::Classification_en::Classification_Directory){
						Header.Name=new char[sizeof(name)+1]{0};
						for(size_t i=0;i<sizeof(name);i++)Header.Name[i]=name[i];
						ext=".";
						Header.Ext=new char[sizeof(ext)+1]{0};
						for(size_t i=0;i<sizeof(ext);i++)Header.Ext[i]=ext[i];
					}
					Header.Classification=classification;
				}
				void Add(const char* name,const char* ext,Sauce::Filesystem::Header::Classification_en classification);
				//Blob_st(const Blob_st& other){
				//	Header.Sectors=other.Header.Sectors;
				//	Header.BytesPerSector=other.Header.BytesPerSector;
				//	Header.PortNumber=other.Header.PortNumber;
				//	Header.Name=new char[sizeof(other.Header.Name)]{0};
				//	for(size_t i=0;i<sizeof(other.Header.Name);i++)Header.Name[i]=other.Header.Name[i];
				//	Header.Ext=new char[sizeof(other.Header.Ext)]{0};
				//	for(size_t i=0;i<sizeof(other.Header.Ext);i++)Header.Ext[i]=other.Header.Ext[i];
				//	for(size_t i=0;i<other.Sub.Size();i++)Sub.AddLast(Blob_st(other.Sub[i]));
				//}
				//~Blob_st(){
				//	delete Header.Name;
				//	delete Header.Ext;
				//}
				std::string List();
				Blob_st& GetSub(size_t index);
				uint8_t& GetByte(size_t byte);
			};
		};
	};
};
#endif