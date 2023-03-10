#include<Sauce/Filesystem/File.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
	namespace Filesystem{
		namespace File{
			File_st::File_st(){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"File_st::File_st",_NAMESPACE_,_ALLOW_PRINT_);
				Header.Attributes.Write=1; //you can write to the file.
				Header.Attributes.Read=0; //you can't read it because there isn't anything there to read.
				Header.Attributes.Execute=0; //default non-executable (you don't want to execute your text files right XD right?)
				Header.Attributes.UserLand=0; //default userland is not allowed to see the file because it's not ready yet.
				Header.Attributes.Admin=0; //default not requiring admin access.
				Header.Attributes.Bitmap=0; //default not a bitmap image becase it's nothing.
				Header.Attributes.Text=0; //default not a text file because it's nothing
				Header.Attributes.Empty=1; //default is empty because nothing is very empty.
				Header.Attributes.Encrypted=0; //default not encrypted because i don't consider nothing at all to be encrypted.
				Header.Attributes.SizeExtension=0; //nothing has a size of a multiple of 0.
				Header.Attributes.Size=0; //nothing has 0 size.
			}
			File_st::File_st(const std::string& name){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"File_st::File_st(name)",_NAMESPACE_,_ALLOW_PRINT_);
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
			File_st::File_st(const File_st& other){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"File_st::File_st(other)",_NAMESPACE_,_ALLOW_PRINT_);
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
			}
			File_st::~File_st(){
				delete Header.Tags[0]; //delete the name tag.
				Header.Tags.Clear();
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
		};
	};
};