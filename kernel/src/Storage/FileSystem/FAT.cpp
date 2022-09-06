#include<Sauce/Storage/FileSystem/FAT.hpp>
#include<Sauce/Global/Global.hpp>
#include<Sauce/Storage/AHCI.hpp>

#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utility/Conversion.hpp>
#include<Sauce/Utility/Manipulations.hpp>

namespace Sauce{
	namespace Storage{
		namespace FileSystem{
			FAT32Driver_cl::FAT32Driver_cl(size_t AHCI_portNumber){
				BootSector=new FAT32_BootSector_st;
				size_t BootSector_CurrentAddress=0;
				for(size_t i=0;i<3;i++){BootSector->Jmp_Boot[i];}
				for(size_t i=0;i<8;i++){BootSector->OEM_Name[i];}
				for(size_t i=0;i<2;i++){BootSector->Bytes_Per_Sector[i];}
				for(size_t i=0;i<1;i++){BootSector->Sector_Per_Cluster[i];}
				for(size_t i=0;i<2;i++){BootSector->Reserved_Sector_Count[i];}
				for(size_t i=0;i<1;i++){BootSector->Number_Of_FATs[i];}
				for(size_t i=0;i<2;i++){BootSector->Root_Entry_Count[i];}
				for(size_t i=0;i<2;i++){BootSector->Total_Sector_Count16[i];}
				for(size_t i=0;i<1;i++){BootSector->Media_Type[i];}
				for(size_t i=0;i<2;i++){BootSector->Sectors_Per_FAT16[i];}
				for(size_t i=0;i<2;i++){BootSector->Sectors_Per_Track[i];}
				for(size_t i=0;i<2;i++){BootSector->Number_Of_Heads[i];}
				for(size_t i=0;i<4;i++){BootSector->Hidden_Sector_Count[i];}
				for(size_t i=0;i<4;i++){BootSector->Total_Sector_Count32[i];}
				for(size_t i=0;i<4;i++){BootSector->Sectors_Per_FAT32[i];}
				for(size_t i=0;i<2;i++){BootSector->Flags[i];}
				for(size_t i=0;i<2;i++){BootSector->FS_Version[i];}
				for(size_t i=0;i<4;i++){BootSector->Root_Cluster[i];}
				for(size_t i=0;i<2;i++){BootSector->FS_Info[i];}
				for(size_t i=0;i<2;i++){BootSector->Backup_Boot_Sector[i];}
				for(size_t i=0;i<12;i++){BootSector->Reserved[i];}
				for(size_t i=0;i<1;i++){BootSector->DrvNum[i];}
				for(size_t i=0;i<1;i++){BootSector->Reserved1[i];}
				for(size_t i=0;i<1;i++){BootSector->Boot_Signature[i];}
				for(size_t i=0;i<4;i++){BootSector->Volume_ID[i];}
				for(size_t i=0;i<11;i++){BootSector->Volume_Label[i];}
				for(size_t i=0;i<8;i++){BootSector->FS_Type[i];}
			}
			FAT32Driver_cl::~FAT32Driver_cl(){
				delete[] BootSector;
			}
		};
	};
};
