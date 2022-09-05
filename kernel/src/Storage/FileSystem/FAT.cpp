#include<Sauce/Storage/FileSystem/FAT.hpp>
#include<Sauce/Global/Global.hpp>
#include<Sauce/Storage/AHCI.hpp>

#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utility/Conversion.hpp>

namespace Sauce{
	namespace Storage{
		namespace FileSystem{
			FileSystem_F32_st::FileSystem_F32_st(size_t portNumber){
				//initialize the structures and buffer.
				BIOS_Parameter_Block=new BIOS_Parameter_Block_st;
				F32_Extended_Boot_Record=new F32_Extended_Boot_Record_st;
				FSInfo=new FSInfo_st;
				
				size_t FileSystemBufferAddress=0;
				for(size_t i=0;i<3;i++){BIOS_Parameter_Block->The_first_three_bytes[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
				for(size_t i=0;i<8;i++){BIOS_Parameter_Block->OEM_identifier[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
				for(size_t i=0;i<2;i++){BIOS_Parameter_Block->Number_of_Bytes_per_sector[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<1;i++){BIOS_Parameter_Block->Number_of_sectors_per_cluster[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<2;i++){BIOS_Parameter_Block->Number_of_reserved_sectors[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<1;i++){BIOS_Parameter_Block->Number_of_File_Allocation_Tables[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<2;i++){BIOS_Parameter_Block->Number_of_root_directory_entries[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<2;i++){BIOS_Parameter_Block->Total_sectors_in_the_logical_volume[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<1;i++){BIOS_Parameter_Block->media_descriptor_type[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<2;i++){BIOS_Parameter_Block->Number_of_sectors_per_FAT[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<2;i++){BIOS_Parameter_Block->Number_of_sectors_per_track[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<2;i++){BIOS_Parameter_Block->Number_of_heads[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<4;i++){BIOS_Parameter_Block->Number_of_hidden_sectors[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<4;i++){BIOS_Parameter_Block->Large_sector_count[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
				
				for(size_t i=0;i<4;i++){F32_Extended_Boot_Record->Sectors_per_FAT[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<2;i++){F32_Extended_Boot_Record->Flags[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<2;i++){F32_Extended_Boot_Record->FAT_version_number[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<4;i++){F32_Extended_Boot_Record->Cluster_number_of_the_root_directory[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<2;i++){F32_Extended_Boot_Record->Sector_number_of_the_FSinfo_structure[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<2;i++){F32_Extended_Boot_Record->Sector_number_of_the_backup_boot_sector[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<12;i++){F32_Extended_Boot_Record->Reserved_FormattedZero[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<1;i++){F32_Extended_Boot_Record->Drive_number[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<1;i++){F32_Extended_Boot_Record->Flags_reserved[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<1;i++){F32_Extended_Boot_Record->Signature[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<4;i++){F32_Extended_Boot_Record->Volume_ID[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<11;i++){F32_Extended_Boot_Record->Volume_label_string[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
    	        for(size_t i=0;i<8;i++){F32_Extended_Boot_Record->System_identifier_string[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<420;i++){F32_Extended_Boot_Record->Boot_code[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<2;i++){F32_Extended_Boot_Record->Bootable_partition_signature[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
				
				FileSystemBufferAddress=(((uint16_t)*F32_Extended_Boot_Record->Sector_number_of_the_FSinfo_structure)*512);
				
				for(size_t i=0;i<4;i++){FSInfo->Lead_signature[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<480;i++){FSInfo->Reserved1[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<4;i++){FSInfo->last_known_free_cluster_count[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<4;i++){FSInfo->start_looking_for_available_clusters[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<12;i++){FSInfo->Reserved2[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
	            for(size_t i=0;i<4;i++){FSInfo->Trail_signature[i]=Sauce::Global::AHCIDriver->Read(portNumber,FileSystemBufferAddress++);}
			}
			FileSystem_F32_st::~FileSystem_F32_st(){
				delete[] BIOS_Parameter_Block;
				delete[] F32_Extended_Boot_Record;
				delete[] FSInfo;
			}
		};
	};
};
