#include<Sauce/Filesystem/Directory.hpp>
namespace Sauce{
	namespace Filesystem{
		namespace Directory{
			std::string Directory_st::List(){
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