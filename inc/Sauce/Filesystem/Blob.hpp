#ifndef __Sauce_Filesystem_Blob
#define __Sauce_Filesystem_Blob
#include<Sauce/Filesystem/Header.hpp>
#include<std/list.hpp>
namespace Sauce{
	namespace Filesystem{
		namespace Blob{
			struct Blob_st{
				Sauce::Filesystem::Header::Header_st Header;
				std::list<Blob_st> Sub;
				Blob_st(const char* name,const char* ext,Sauce::Filesystem::Header::Classification_en classification){
					if(classification == Sauce::Filesystem::Header::Classification_en::Classification_File){
						Header.Name=(char*)name;
						Header.Ext=(char*)ext;
					}else if(classification == Sauce::Filesystem::Header::Classification_en::Classification_Directory){
						Header.Name=new char[11]{0};
						Header.Name=(char*)name;
						Header.Ext=(char*)ext;
					}
					Header.Classification=classification;
				}
				inline void Add(const char* name,const char* ext,Sauce::Filesystem::Header::Classification_en classification){
					Sub.AddLast(Blob_st(name,ext,classification));
				}
			};
		};
	};
};
#endif