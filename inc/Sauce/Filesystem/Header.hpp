#ifndef __Sauce_Filesystem_Header
#define __Sauce_Filesystem_Header
#include<std/list.hpp>
namespace Sauce{
	namespace Filesystem{
		namespace Header{
			struct Header_st{
				uint64_t PermitRead:1;
				uint64_t PermitWrite:1;
				uint64_t PermitUserland:1;
				uint64_t Empty:1;
				uint64_t BlankAttributes:60;
				uint64_t Size;
				const char* Name;
				
				Header_st(){
					PermitRead=0;
					PermitWrite=1;
					PermitUserland=0;
					Empty=1;
					BlankAttributes=0;
					Size=0;
				}
			}__attribute__((packed));
		};
	};
};
#endif