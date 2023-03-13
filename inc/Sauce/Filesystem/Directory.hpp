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
				inline std::string List(){
					std::string Result="[";
					for(size_t i=0;i<Sub.Size();i++){
						switch(Sub[i].Header.Classification){
							case Sauce::Filesystem::Header::Classification_en::Classification_Data:{Result+="Data:";}break;
							case Sauce::Filesystem::Header::Classification_en::Classification_File:{Result+="File:";}break;
							case Sauce::Filesystem::Header::Classification_en::Classification_Directory:{Result+="Directory:";}break;
							case Sauce::Filesystem::Header::Classification_en::Classification_Descriptor:{Result+="Descriptor:";}break;
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