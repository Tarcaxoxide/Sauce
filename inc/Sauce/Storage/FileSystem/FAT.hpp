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
				uint8_t Sectors_Per_Cluster[1];
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
				uint8_t Drive_Number[1];
				uint8_t Reserved1[1];
				uint8_t Boot_Signature[1];
				uint8_t Volume_ID[4];
				uint8_t Volume_Label[11];
				uint8_t FS_Type[8];
			} __attribute__ ((packed));

			struct DirectoryEntry_st{
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

			} __attribute__ ((packed));

			struct FSObject{
				//IDK?
			};

			class FAT32Driver_cl{
				FAT32_BootSector_st* BootSector;
				size_t AHCI_portNumber;
				public:
				FAT32Driver_cl(size_t AHCI_portNumber);
				~FAT32Driver_cl();
				size_t ClusterToLBA(uint32_t cluster);
				void Traverse(char* path);
				Sauce::Memory::List_cl<uint32_t> GetClusterChain(uint32_t firstcluster, uint64_t* numclus);
				Sauce::Memory::List_cl<FSObject> ReadDir(uint32_t cluster);
			};
		};
	};
};
