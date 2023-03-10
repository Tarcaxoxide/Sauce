#include<Sauce/Filesystem/File.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
	namespace Filesystem{
		namespace File{
			File_st::File_st(){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"File_st::File_st",_NAMESPACE_,_ALLOW_PRINT_);
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
			File_st::File_st(const std::string& name){
				Sauce::IO::Debug::Debugger_st Debugger(__FILE__,"File_st::File_st",_NAMESPACE_,_ALLOW_PRINT_);
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
				Debugger.Print(Name);
			}
		};
	};
};