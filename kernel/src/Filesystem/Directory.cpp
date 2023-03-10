#include<Sauce/Filesystem/Directory.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
	namespace Filesystem{
		namespace Directory{
			Directory_st::Directory_st(){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Directory_st::Directory_st",_NAMESPACE_,_ALLOW_PRINT_);
				Header.Attributes.Write=1; //you can write to the directory.
				Header.Attributes.Read=0; //you can't read from a directory, it's not a file.
				Header.Attributes.Execute=0; //you can't execute a directory, it's not a file.
				Header.Attributes.UserLand=0; //default userland is not allowed to see the directory because it's not ready yet.
				Header.Attributes.Admin=0; //default not requiring admin access.
				Header.Attributes.Bitmap=0; //the directory isn't a bitmap image file.
				Header.Attributes.Text=0; //the directory isn't a text file.
				Header.Attributes.Empty=1; //default is empty because nothing is very empty.
				Header.Attributes.Encrypted=0; //default not encrypted because i don't consider nothing at all to be encrypted.
				Header.Attributes.SizeExtension=0; //nothing has a size of a multiple of 0.
				Header.Attributes.Size=0; //nothing has 0 size.
			}
			Directory_st::Directory_st(const std::string& name){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Directory_st::Directory_st(name)",_NAMESPACE_,_ALLOW_PRINT_);
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
				Header.Tags.Clear();
				Header.Tags.AddLast(new std::string(name.RawTyped()));
				Debugger.Print(Name());
			}
			Directory_st::Directory_st(const Directory_st& other){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Directory_st::Directory_st(other)",_NAMESPACE_,_ALLOW_PRINT_);
				Header.Attributes.Write=other.Header.Attributes.Write;
				Header.Attributes.Read=other.Header.Attributes.Read;
				Header.Attributes.Execute=other.Header.Attributes.Execute;
				Header.Attributes.UserLand=other.Header.Attributes.UserLand;
				Header.Attributes.Admin=other.Header.Attributes.Admin;
				Header.Attributes.Bitmap=other.Header.Attributes.Bitmap;
				Header.Attributes.Text=other.Header.Attributes.Text;
				Header.Attributes.Empty=other.Header.Attributes.Empty;
				Header.Attributes.Encrypted=other.Header.Attributes.Encrypted;
				Header.Attributes.SizeExtension=other.Header.Attributes.SizeExtension;
				Header.Attributes.Size=other.Header.Attributes.Size;
				Header.Tags.AddLast(new std::string(other.Header.Tags.First()->RawTyped()));//recreate the name tag because we delete it in the destructor.
				for(size_t i=1;i<other.Header.Tags.Size();i++){
					Header.Tags.AddLast(other.Header.Tags[i]);
				}
				for(size_t i=0;i<other.Files.Size();i++){
					Files.AddLast(other.Files[i]);
				}
				for(size_t i=0;i<other.Directories.Size();i++){
					Directories.AddLast(other.Directories[i]);
				}
			}
			Directory_st::~Directory_st(){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Directory_st::~Directory_st",_NAMESPACE_,_ALLOW_PRINT_);
				delete Header.Tags[0]; //delete the name tag.
				Header.Tags.Clear();
				Directories.Clear();
				Files.Clear();
				Header.Attributes.Write=0;
				Header.Attributes.Read=0;
				Header.Attributes.Execute=0;
				Header.Attributes.UserLand=0;
				Header.Attributes.Admin=1;
				Header.Attributes.Bitmap=0;
				Header.Attributes.Text=0;
				Header.Attributes.Empty=1;
				Header.Attributes.Encrypted=0;
				Header.Attributes.SizeExtension=0;
				Header.Attributes.Size=0;
			}
			std::string Directory_st::ListFiles(){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Directory_st::ListFiles",_NAMESPACE_,_ALLOW_PRINT_);
				if(Header.Attributes.Empty)return "[]";
				std::string Result="[";
				for(size_t i=0;i<Files.Size();i++){
					Result+=Files[i].Name();
					Debugger.Print(Files[i].Name());
					if(i<Files.Size()-1)Result+=",";
				}
				Result+="]";
				return Result;
			}
			std::string Directory_st::ListDirectories(){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Directory_st::ListDirectories",_NAMESPACE_,_ALLOW_PRINT_);
				if(Header.Attributes.Empty)return "[]";
				std::string Result="[";
				for(size_t i=0;i<Directories.Size();i++){
					Result+=Directories[i].Name();
					Debugger.Print(Directories[i].Name());
					if(i<Directories.Size()-1)Result+=",";
				}
				Result+="]";
				return Result;
			}
			std::string Directory_st::List(){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"Directory_st::ListDirectories",_NAMESPACE_,_ALLOW_PRINT_);
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