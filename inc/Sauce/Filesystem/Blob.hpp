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
				inline std::string List(){
					std::string Result="[";
					for(size_t i=0;i<Sub.Size();i++){
						switch(Sub[i].Header.Classification){
							case Sauce::Filesystem::Header::Classification_en::Classification_Data:{Result+="Data:";}break;
							case Sauce::Filesystem::Header::Classification_en::Classification_File:{Result+="File:";}break;
							case Sauce::Filesystem::Header::Classification_en::Classification_Directory:{Result+="Directory:";}break;
							case Sauce::Filesystem::Header::Classification_en::Classification_Descriptor:{Result+="Descriptor:";}break;
						}
						Result+="`";
						Result+=Sub[i].Header.Name;
						Result+="`:";
						Result+=std::to_string(i);
						
						if(i<Sub.Size()-1)Result+=",";
					}
					Result+="]";
					return Result;
				}
				inline void Add(const char* name,const char* ext,Sauce::Filesystem::Header::Classification_en classification){
					Sub.AddLast(Blob_st(name,ext,classification));
				}
			};
		};
	};
};
#endif