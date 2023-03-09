#include<Sauce/Filesystem/Directory.hpp>

namespace Sauce{
	namespace Filesystem{
		namespace Directory{
			Directory_st::Directory_st(){
				Header.Attributes.Write=1;
				Header.Attributes.Read=0;
				Header.Attributes.Execute=0;
				Header.Attributes.UserLand=0;
				Header.Attributes.Admin=0;
				Header.Attributes.Bitmap=0;
				Header.Attributes.Text=0;
				Header.Attributes.Empty=1;
				Header.Attributes.Encrypted=0;
				Header.Attributes.SizeExtension=0;
				Header.Attributes.Size=0;
			}
			Directory_st::Directory_st(const std::string& name){
				Header.Attributes.Write=1;
				Header.Attributes.Read=0;
				Header.Attributes.Execute=0;
				Header.Attributes.UserLand=0;
				Header.Attributes.Admin=0;
				Header.Attributes.Bitmap=0;
				Header.Attributes.Text=0;
				Header.Attributes.Empty=1;
				Header.Attributes.Encrypted=0;
				Header.Attributes.SizeExtension=0;
				Header.Attributes.Size=0;
				Header.Tags.AddLast(name);
				Name=name;
			}
			std::string Directory_st::ListFiles(){
				if(Header.Attributes.Empty)return "[]";
				std::string Result="[";
				for(size_t i=0;i<Files.Size();i++){
					Result+=Files[i].Name;
					if(i<Files.Size()-1)Result+=",";
				}
				Result+="]";
				return Result;
			}
			std::string Directory_st::ListDirectories(){
				if(Header.Attributes.Empty)return "[]";
				std::string Result="[";
				for(size_t i=0;i<Directories.Size();i++){
					Result+=Directories[i].Name;
					if(i<Directories.Size()-1)Result+=",";
				}
				Result+="]";
				return Result;
			}
			std::string Directory_st::List(){
				if(Header.Attributes.Empty)return "[]";
				std::string Result="[";
				Result+=ListDirectories();
				Result+=",";
				Result+=ListFiles();
				Result+="]";
				return Result;
			}
			void Directory_st::AddDirectoryEntry(std::string directoryName){
				Directories.AddLast(Directory_st(directoryName));
				Header.Attributes.Empty=0;
			}
			void Directory_st::AddFileEntry(std::string fileName){
				Files.AddLast(Sauce::Filesystem::File::File_st(fileName));
				Header.Attributes.Empty=0;
			}
		};
	};
};