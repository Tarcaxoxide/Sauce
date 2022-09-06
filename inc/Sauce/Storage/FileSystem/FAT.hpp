#pragma once

#include<Sauce/Types.hpp>
#include<Sauce/Memory/DynamicArray.hpp>

namespace Sauce{
    namespace Storage{
        namespace FileSystem{
			struct FAT32_BootSector_st{
				uint8_t Jmp_Boot[3];
				uint8_t OEM_Name[8];
				uint8_t Bytes_Per_Sector[2];
				uint8_t Sector_Per_Cluster[1];
				uint8_t Reserved_Sector_Count[2];
				uint8_t Number_Of_FATs[1];
				uint8_t Root_Entry_Count[2];
				uint8_t Total_Sector_Count16[2];
				uint8_t Media_Type[1];
				uint8_t Sectors_Per_FAT16[2];
				uint8_t Sectors_Per_Track[2];
				uint8_t Number_Of_Heads[2];
				uint8_t Hidden_Sector_Count[4];
				uint8_t Total_Sector_Count32[4];
				uint8_t Sectors_Per_FAT32[4];
				uint8_t Flags[2];
				uint8_t FS_Version[2];
				uint8_t Root_Cluster[4];
				uint8_t FS_Info[2];
				uint8_t Backup_Boot_Sector[2];
				uint8_t Reserved[12];
				uint8_t DrvNum[1];
				uint8_t Reserved1[1];
				uint8_t Boot_Signature[1];
				uint8_t Volume_ID[4];
				uint8_t Volume_Label[11];
				uint8_t FS_Type[8];
			};

			class FAT32Driver_cl{
				FAT32_BootSector_st* BootSector;
				public:
				FAT32Driver_cl(size_t AHCI_portNumber);
				~FAT32Driver_cl();
			};
		};
	};
};
