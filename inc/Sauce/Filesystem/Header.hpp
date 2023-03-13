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
				std::list<size_t> Sectors;
				size_t PortNumber;
				Classification_en Classification;
				char* Ext;
				char* Name;
				Header_st(){
					Classification=Classification_en::Classification_Data;
					Sectors.Clear();
				}
			};
		};
	};
};
#endif
