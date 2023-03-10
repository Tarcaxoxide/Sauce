#ifndef __Sauce_Filesystem_Header
#define __Sauce_Filesystem_Header
#include<std/list.hpp>
namespace Sauce{
	namespace Filesystem{
		namespace Header{
			enum Classification:uint8_t{
				Classification_Data=0,
				Classification_File,
				Classification_Directory,
				Classification_Descriptor
			};
			struct Header_st{
				uint64_t PermitRead:1;
				uint64_t PermitWrite:1;
				uint64_t PermitUserland:1;
				uint64_t Empty:1;
				uint64_t Classification:2;
				uint64_t BlankAttributes:58;
				uint64_t Size;
				const char* Name;
				Header_st(){
					PermitRead=0;
					PermitWrite=1;
					PermitUserland=0;
					Empty=1;
					Classification=Classification::Classification_Data;
					BlankAttributes=0;
					Size=0;
				}
			}__attribute__((packed));
		};
	};
};
#endif
