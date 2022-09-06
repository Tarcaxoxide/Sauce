#pragma once

#include<Sauce/Types.hpp>
#include<Sauce/Memory/DynamicArray.hpp>

namespace Sauce{
    namespace Storage{
        namespace FileSystem{
			struct FAT32_BootSector_st{
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
			struct DirectoryEntry{
				char name[8];
				char ext[3];
				uint8_t attrib;
				uint8_t userattrib;
				char undelete;
				uint16_t createtime;
				uint16_t createdate;
				uint16_t accessdate;
				uint16_t clusterhigh;
				uint16_t modifiedtime;
				uint16_t modifieddate;
				uint16_t clusterlow;
				uint32_t filesize;
			}__attribute__((packed));

			class FileSystem_F32_cl{
				FAT32_BootSector_st* BootSector=nullptr;
				public:
				FileSystem_F32_cl(size_t portNumber);
				~FileSystem_F32_cl();
			};
		};
	};
};
