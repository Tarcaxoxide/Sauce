#ifndef __Sauce_Filesystem_Header
#define __Sauce_Filesystem_Header
#include<std/list.hpp>
#include<Sauce/Memory/SmartPtr.hpp>
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
				size_t BytesPerSector;
				size_t PortNumber;
				Classification_en Classification;
				Sauce::Memory::SmartPtr_cl<char,9> Name;
				Sauce::Memory::SmartPtr_cl<char,4> Ext;
				Header_st(Sauce::Memory::SmartPtr_cl<char,9> name,Sauce::Memory::SmartPtr_cl<char,4> ext):Name(name),Ext(ext){}
			};
		};
	};
};
#endif
