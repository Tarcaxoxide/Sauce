#ifndef __Sauce_Filesystem_Header
#define __Sauce_Filesystem_Header
#include<std/list.hpp>
namespace Sauce{
	namespace Filesystem{
		namespace Header{
			enum Classification_en:uint8_t{
				Classification_Data=0,
				Classification_File,
				Classification_Directory,
				Classification_Descriptor
			};
			struct Header_st{
				size_t StartingSector;
				size_t Size;
				size_t PortNumber;
				Classification_en Classification;
				char* Ext;
				char* Name;
				Header_st(){
					Classification=Classification_en::Classification_Data;
					Size=0;
				}
			}__attribute__((packed));
		};
	};
};
#endif
