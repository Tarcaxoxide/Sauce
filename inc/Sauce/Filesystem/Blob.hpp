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
			};
		};
	};
};
#endif