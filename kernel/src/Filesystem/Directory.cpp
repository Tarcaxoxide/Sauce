#include<Sauce/Filesystem/Directory.hpp>
namespace Sauce{
	namespace Filesystem{
		namespace Directory{
			void Directory_st::AddFile(const char* fileName){
				Files.AddLast(Sauce::Filesystem::File::File_st{fileName});
			}
			void Directory_st::AddDirectory(const char* directoryName){
				Directories.AddLast(Sauce::Filesystem::Directory::Directory_st{directoryName});
			}
			std::string Directory_st::ListFiles(){
				std::string Result="[";
				for(size_t i=0;i<Files.Size();i++){
					Result+=Files[i].Name;
					if(i<Files.Size()-1)Result+=",";
				}
				Result+="]";
				return Result;
			}
			std::string Directory_st::ListDirectories(){
				std::string Result="[";
				for(size_t i=0;i<Directories.Size();i++){
					Result+=Directories[i].Name;
					if(i<Directories.Size()-1)Result+=",";
				}
				Result+="]";
				return Result;
			}
			std::string Directory_st::List(){
				std::string Result="[";
				Result+=ListDirectories();
				Result+=",";
				Result+=ListFiles();
				Result+="]";
				return Result;
			}
		};
	};
};