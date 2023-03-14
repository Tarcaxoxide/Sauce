#ifndef __Sauce_Filesystem_FAT32
#define __Sauce_Filesystem_FAT32
#include<Sauce/Filesystem/MsDosPartition.hpp>
#include<std/list.hpp>
#include<Sauce/Filesystem/File.hpp>
#include<Sauce/Filesystem/Directory.hpp>
namespace Sauce{
	namespace Filesystem{
		namespace FAT32{
			struct BiosParameterBlock_st{
				uint8_t Jump[3];
				uint8_t SoftName[8];
				uint16_t BytesPerSector;
				uint8_t SectorsPerCluster;
				uint16_t ReservedSectors;
				uint8_t FatCopies;
				uint16_t RootDirectoryEntries;// always 0, not used by fat32
				uint16_t TotalSectors;
				uint8_t MediaType;
				uint16_t FatSectorCount;// always 0, not used by fat32
				uint16_t SectorsPerTrack;
				uint16_t HeadCount;
				uint32_t HiddenSectors;
				uint32_t TotalSectorCount;
				uint32_t TableSize;
				uint16_t ExtFlags;
				uint8_t FatVersion[2];
				uint32_t RootCluster;
				uint16_t FatInfo;
				uint16_t BackupSector;
				uint8_t ReservedA[12];
				uint8_t DriveNumber;
				uint8_t ReservedB;
				uint8_t BootSignature;
				uint32_t VolumeId;
				uint8_t VolumeLabel[11];
				uint8_t FatTypeLabel[8];
			}__attribute__((packed));
			struct DirectoryEntry_st{
				uint8_t Name[8];
				uint8_t Extension[3];
				uint8_t Attributes;
				uint8_t ReservedA;
				uint8_t CreationTimeTenth;
				uint16_t CreationTime;
				uint16_t CreationDate;
				uint16_t AccessTime;
				uint16_t FirstClusterHigh;
				uint16_t WriteTime;
				uint16_t WriteDate;
				uint16_t FirstClusterLow;
				uint32_t Size;
			}__attribute__((packed));

			class FAT32_cl: public Sauce::Filesystem::MsDosPartition::MsDosPartition_cl {
				Sauce::Filesystem::MsDosPartition::PartitionTableEntry_st* PartitionTableEntry;
				size_t PartitionNumber;
				BiosParameterBlock_st BiosParameterBlock;
				std::list<Sauce::Filesystem::Directory::Directory_st> Directories;
				public:
				FAT32_cl(size_t portNumber,size_t partitionNumber);
				Sauce::Filesystem::Directory::Directory_st ReadDirectory(size_t Offset,const char* directoryName);
			};
		};
	};
};
#endif


