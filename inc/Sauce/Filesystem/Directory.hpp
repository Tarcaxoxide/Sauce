#ifndef __Sauce_Filesystem_Directory
#define __Sauce_Filesystem_Directory
#include<Sauce/Filesystem/Blob.hpp>
#include<std/string.hpp>
namespace Sauce{
	namespace Filesystem{
		namespace Directory{
			struct Directory_st:public Sauce::Filesystem::Blob::Blob_st{
				Directory_st(const char* name): Sauce::Filesystem::Blob::Blob_st(name,Sauce::Filesystem::Header::Classification::Classification_Directory){}
				std::list<Blob_st> Sub;
				inline void Add(const char* name,Sauce::Filesystem::Header::Classification classification){
					Sub.AddLast(Blob_st(name,classification));
				}
				inline void AddFile(const char* name){Add(name,Sauce::Filesystem::Header::Classification::Classification_File);}
				inline void AddDirectory(const char* name){Add(name,Sauce::Filesystem::Header::Classification::Classification_Directory);}
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