#pragma once

#include<Sauce/Types.hpp>
#include<Sauce/Memory/DynamicArray.hpp>

namespace Sauce{
    namespace Storage{
        namespace FileSystem{
			struct BIOS_Parameter_Block_st{
	            uint8_t The_first_three_bytes[3];
	            uint8_t OEM_identifier[8];
	            uint8_t Number_of_Bytes_per_sector[2];
	            uint8_t Number_of_sectors_per_cluster[1];
	            uint8_t Number_of_reserved_sectors[2];
	            uint8_t Number_of_File_Allocation_Tables[1];
	            uint8_t Number_of_root_directory_entries[2];
	            uint8_t Total_sectors[2];
	            uint8_t Media_descriptor_type[1];
	            uint8_t Number_of_sectors_per_FAT[2];
	            uint8_t Number_of_sectors_per_track[2];
	            uint8_t Number_of_heads[2];
	            uint8_t Number_of_hidden_sectors[4];
	            uint8_t Large_sector_count[4];
	        }__attribute__((packed));
	        struct F32_Extended_Boot_Record_st{
	            uint8_t Sectors_per_FAT[4]; // the size of the fat in sectors
	            uint8_t Flags[2];
	            uint8_t FAT_version_number[2];
	            uint8_t Cluster_number_of_the_root_directory[4];
	            uint8_t Sector_number_of_the_FSinfo_structure[2];
	            uint8_t Sector_number_of_the_backup_boot_sector[2];
	            uint8_t Reserved_FormattedZero[12];
	            uint8_t Drive_number[1];
	            uint8_t Flags_reserved[1];
	            uint8_t Signature[1];
	            uint8_t Volume_ID[4];
	            uint8_t Volume_label_string[11];
    	        uint8_t System_identifier_string[8];
	            uint8_t Boot_code[420];
	            uint8_t Bootable_partition_signature[2];
	        }__attribute__((packed));
	        struct FSInfo_st{
	            uint8_t Lead_signature[4];
	            uint8_t Reserved1[480];
	            uint8_t last_known_free_cluster_count[4];
	            uint8_t start_looking_for_available_clusters[4];
	            uint8_t Reserved2[12];
	            uint8_t Trail_signature[4];
	        }__attribute__((packed));
			struct FileSystem_F32_st{
				BIOS_Parameter_Block_st* BIOS_Parameter_Block=nullptr;
				F32_Extended_Boot_Record_st* F32_Extended_Boot_Record=nullptr;
				FSInfo_st* FSInfo=nullptr;
				struct Dist_st{
					size_t total_sectors;
					size_t fat_size;
					size_t root_dir_sectors;
					size_t first_data_sector;
					size_t first_fat_sector;
					size_t data_sectors;
					size_t total_clusters;
					size_t root_cluster;
				}Dist;
				FileSystem_F32_st(size_t portNumber);
				~FileSystem_F32_st();
			};
		};
	};
};
