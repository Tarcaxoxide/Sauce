#ifndef __Sauce_Filesystem_Blob
#define __Sauce_Filesystem_Blob
#include<Sauce/Filesystem/Header.hpp>
#include<std/list.hpp>
#include<std/string.hpp>
#include<std/to_string.hpp>
#include<Sauce/Memory/SmartPtr.hpp>
namespace Sauce{
	namespace Filesystem{
		namespace Blob{
			struct Blob_st{
				Sauce::Filesystem::Header::Header_st Header;
				std::list<Blob_st> Sub;
				size_t CurrentByte{0};
				size_t CurrentSector{0};
				std::ustring CurrentSectorData;
				Blob_st(Sauce::Memory::SmartPtr_cl<char,9> name,Sauce::Memory::SmartPtr_cl<char,4> ext,Sauce::Filesystem::Header::Classification_en classification):Header(name,ext){
					Header.Classification=classification;
				}
				void Add(Sauce::Memory::SmartPtr_cl<char,9> name,Sauce::Memory::SmartPtr_cl<char,4> ext,Sauce::Filesystem::Header::Classification_en classification);
				
				std::string List();
				Blob_st& GetSub(size_t index);
				uint8_t& GetByte(size_t byte);
			};
		};
	};
};
#endif