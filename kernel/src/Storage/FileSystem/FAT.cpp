#include<Sauce/Storage/FileSystem/FAT.hpp>
#include<Sauce/Global/Global.hpp>
#include<Sauce/Storage/AHCI.hpp>

#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utility/Conversion.hpp>

namespace Sauce{
	namespace Storage{
		namespace FileSystem{
			FileSystem_F32_cl::FileSystem_F32_cl(size_t portNumber){
				//initialize the structures and buffer.
				BootSector=new FAT32_BootSector_st;
				
				size_t FileSystemBufferAddress=0;
				for(size_t i=0;i<3;i++){BootSector->The_first_three_bytes[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
				for(size_t i=0;i<8;i++){BootSector->OEM_identifier[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
				for(size_t i=0;i<2;i++){BootSector->Number_of_Bytes_per_sector[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<1;i++){BootSector->Number_of_sectors_per_cluster[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<2;i++){BootSector->Number_of_reserved_sectors[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<1;i++){BootSector->Number_of_File_Allocation_Tables[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<2;i++){BootSector->Number_of_root_directory_entries[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<2;i++){BootSector->Total_sectors[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<1;i++){BootSector->Media_descriptor_type[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<2;i++){BootSector->Number_of_sectors_per_FAT[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<2;i++){BootSector->Number_of_sectors_per_track[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<2;i++){BootSector->Number_of_heads[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<4;i++){BootSector->Number_of_hidden_sectors[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<4;i++){BootSector->Large_sector_count[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
				for(size_t i=0;i<4;i++){BootSector->Sectors_per_FAT[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<2;i++){BootSector->Flags[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<2;i++){BootSector->FAT_version_number[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<4;i++){BootSector->Cluster_number_of_the_root_directory[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<2;i++){BootSector->Sector_number_of_the_FSinfo_structure[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<2;i++){BootSector->Sector_number_of_the_backup_boot_sector[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<12;i++){BootSector->Reserved_FormattedZero[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<1;i++){BootSector->Drive_number[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<1;i++){BootSector->Flags_reserved[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<1;i++){BootSector->Signature[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<4;i++){BootSector->Volume_ID[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<11;i++){BootSector->Volume_label_string[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
    	        for(size_t i=0;i<8;i++){BootSector->System_identifier_string[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<420;i++){BootSector->Boot_code[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<2;i++){BootSector->Bootable_partition_signature[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
				
				
			}
			FileSystem_F32_cl::~FileSystem_F32_cl(){
				delete[] BootSector;
			}

		};
	};
};
