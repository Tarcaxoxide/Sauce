#ifndef __Sauce_Filesystem_Blob
#define __Sauce_Filesystem_Blob
#include<Sauce/Filesystem/Header.hpp>
#include<std/list.hpp>
namespace Sauce{
	namespace Filesystem{
		namespace Blob{
			struct Blob_st{
				Sauce::Filesystem::Header::Header_st Header;
				Blob_st(const char* name,Sauce::Filesystem::Header::Classification classification){
					Header.Name=name;
					Header.Classification=classification;
				}
				std::list<Blob_st> Sub;
				inline void Add(const char* name,Sauce::Filesystem::Header::Classification classification){
					Sub.AddLast(Blob_st(name,classification));
				}
				inline std::string List(){
					std::string Result="[";
					for(size_t i=0;i<Sub.Size();i++){
						switch(Sub[i].Header.Classification){
							case Sauce::Filesystem::Header::Classification::Classification_Unset:{Result+="Unset:";}break;
							case Sauce::Filesystem::Header::Classification::Classification_File:{Result+="File:";}break;
							case Sauce::Filesystem::Header::Classification::Classification_Directory:{Result+="Directory:";}break;
							case Sauce::Filesystem::Header::Classification::Classification_Descriptor:{Result+="Descriptor:";}break;
						}
						Result+=Sub[i].Header.Name;
						if(i<Sub.Size()-1)Result+=",";
					}
					Result+="]";
					return Result;
				}
			};
		};
	};
};
#endif