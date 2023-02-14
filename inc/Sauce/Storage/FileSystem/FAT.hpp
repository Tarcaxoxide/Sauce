#include<_std/string.hpp>
#include<stddef.h>
#include<stdint.h>
#include<Sauce/Memory/List.hpp>
#pragma once
namespace Sauce{
    namespace Storage{
        namespace FileSystem{
            namespace FAT{
                //READ_ONLY=0x01 HIDDEN=0x02 SYSTEM=0x04 VOLUME_ID=0x08 DIRECTORY=0x10 ARCHIVE=0x20 LFN=READ_ONLY|HIDDEN|SYSTEM|VOLUME_ID
                const static uint8_t ENTRY_TYPE_READ_ONLY=0x01;
                const static uint8_t ENTRY_TYPE_HIDDEN=0x02;
                const static uint8_t ENTRY_TYPE_SYSTEM=0x04;
                const static uint8_t ENTRY_TYPE_VOLUME_ID=0x08;
                const static uint8_t ENTRY_TYPE_DIRECTORY=0x10;
                const static uint8_t ENTRY_TYPE_ARCHIVE=0x20;
                const static uint8_t ENTRY_TYPE_LFN=ENTRY_TYPE_READ_ONLY|ENTRY_TYPE_HIDDEN|ENTRY_TYPE_SYSTEM|ENTRY_TYPE_VOLUME_ID;
                struct Boot_Record_st{
                    uint8_t NOP[3]{0x00};
                    uint8_t OEM_IDENTIFIER[8]{0x00};
                    uint8_t NUMBER_OF_BYTES_PER_SECTOR[2]{0x00};
                    uint8_t NUMBER_OF_SECTORS_PER_CLUSTER[1]{0x00};
                    uint8_t NUMBER_OF_RESERVED_SECTORS[2]{0x00};
                    uint8_t NUMBER_OF_FATS[1]{0x00};
                    uint8_t NUMBER_OF_ROOT_DIRECTORY_ENTRIES[2]{0x00};
                    uint8_t TOTAL_SECTORS_IN_LOGICAL_VOLUME[2]{0x00};//if 0 then > 65535 sectors, check LARGE_SECTOR_COUNT
                    uint8_t MEDIA_DESCRIPTOR_TYPE[1]{0x00};
                    uint8_t NUMBER_OF_SECTORS_PER_FAT_12or16[2]{0x00};
                    uint8_t NUMBER_OF_SECTORS_PER_TRACK[2]{0x00};
                    uint8_t NUMBER_OF_HEADSorSIDES[2]{0x00};
                    uint8_t NUMBER_OF_HIDDEN_SECTORS[4]{0x00};
                    uint8_t LARGE_SECTOR_COUNT[4]{0x00};
                }__attribute__((packed));
                struct Extended_Boot_Record_FAT12_st : public Boot_Record_st{
                    uint8_t DRIVE_NUMBER[1]{0x00};
                    uint8_t WINDOWS_FLAGS[1]{0x00};
                    uint8_t SIGNATURE[1]{0x00}; //(must be 0x28 or 0x29)
                    uint8_t VOLUME_ID[4]{0x00};
                    uint8_t VOLUME_LABEL[11]{0x00}; // padded with spaces
                    uint8_t SYSTEM_IDENTIFIER[8]{0x00};
                    uint8_t BOOT_CODE[448]{0x00};
                    uint8_t BOOT_MAGIC[2]{0x00};
                }__attribute__((packed));
                struct Extended_Boot_Record_FAT16_st : public Boot_Record_st{
                    uint8_t DRIVE_NUMBER[1]{0x00};
                    uint8_t WINDOWS_FLAGS[1]{0x00};
                    uint8_t SIGNATURE[1]{0x00}; //(must be 0x28 or 0x29)
                    uint8_t VOLUME_ID[4]{0x00};
                    uint8_t VOLUME_LABEL[11]{0x00}; // padded with spaces
                    uint8_t SYSTEM_IDENTIFIER[8]{0x00};
                    uint8_t BOOT_CODE[448]{0x00};
                    uint8_t BOOT_MAGIC[2]{0x00};
                }__attribute__((packed));
                struct Extended_Boot_Record_FAT32_st : public Boot_Record_st{
                    uint8_t NUMBER_OF_SECTORS_PER_FAT_32[4]{0x00};
                    uint8_t FLAGS[2]{0x00};
                    uint8_t FAT_VERSION[2]{0x00}; // The high byte is the major version and the low byte is the minor version. FAT drivers should respect this field. 
                    uint8_t CLUSTER_NUMBER_OF_ROOT_DIRECTORY[4]{0x00};
                    uint8_t SECTOR_NUMBER_OF_THE_FSINFO_STRUCTURE[2]{0x00};
                    uint8_t SECTOR_NUMBER_OF_BACKUP_BOOT_SECTOR[2]{0x00};
                    uint8_t RESERVED0[12]{0x00};//When the volume is formated these bytes should be zero. 
                    uint8_t DRIVE_NUMBER[1]{0x00};
                    uint8_t WINDOWS_FLAGS[1]{0x00};
                    uint8_t SIGNATURE[1]{0x00};//(must be 0x28 or 0x29)
                    uint8_t VOLUME_ID[4]{0x00};
                    uint8_t VOLUME_LABEL[11]{0x00};// padded with spaces
                    uint8_t SYSTEM_IDENTIFIER[8]{0x00};
                    uint8_t BOOT_CODE[420]{0x00};
                    uint8_t BOOT_MAGIC[2]{0x00};
                }__attribute__((packed));
                struct FSINFO_Structure_st{
                    uint8_t LEAD_SIGNATURE[4]{0x00};//(0x41615252)
                    uint8_t RESERVED0[480]{0x00};// these bytes should never be used
                    uint8_t ANOTHER_SIGNATURE[4]{0x00};//(0x61417272)
                    uint8_t LAST_KNOWN_FREE_CLUSTER[4]{0x00};//If the value is 0xFFFFFFFF then the free count is unknown and must be computed.
                    uint8_t START_SEARCHING_FOR_AVAILABLE_CLUSTERS_HERE[4]{0x00};//If the value is 0xFFFFFFFF then there is no hint and the driver should start searching at 2
                    uint8_t RESERVED1[12]{0x00};
                    uint8_t TRAIL_SIGNATURE[4]{0x00};//(0xAA550000)
                }__attribute__((packed));
                struct DirectoryEntry_st{
                	uint8_t NAME[8]{0x00};
                	uint8_t EXT[3]{0x00};
                	uint8_t ATTRIB[1]{0x00};
                	uint8_t USER_ATTRIB[1]{0x00};
                	uint8_t UNDELETE[1]{0x00};
                    uint8_t CREATE_TIME[2]{0x00};
                    uint8_t CREATE_DATE[2]{0x00};
                    uint8_t ACCESS_DATE[2]{0x00};
                    uint8_t CLUSTER_HIGH[2]{0x00};
                    uint8_t MODIFIED_TIME[2]{0x00};
                    uint8_t MODIFIED_DATE[2]{0x00};
                    uint8_t CLUSTER_LOW[2]{0x00};
                    uint8_t FILE_SIZE[4]{0x00}; // this file size is in bytes (i think) test with a text file but (doesn't count termination? but seems to count newline)
                }__attribute__((packed));
                struct DistilledInformation_st{
                    size_t FatStart;
                    size_t FatSize;
                    size_t PartitionOffset;
                    size_t DataStart;
                    size_t SectorOfRootDirectoryEntry;
                    size_t SectorsPerCluster;
                    size_t BytesPerSector;
                    size_t Port;
                };
                struct FAT32_FileSystemFileObject_st{
                    Sauce::Memory::List_cl<DirectoryEntry_st> DirectoryEntries;
                    Sauce::Memory::List_cl<FAT32_FileSystemFileObject_st*> Directories;
                    Sauce::Memory::List_cl<FAT32_FileSystemFileObject_st*> Files;
                    char Name[9]{0x00};
                    size_t LastEntryIndex;
                    DirectoryEntry_st* ThisEntry;
                    FAT32_FileSystemFileObject_st* Previous;
                    DistilledInformation_st* Dist;
                    size_t ClusterNumber;
                    size_t EntryNumber;
                    Sauce::Memory::List_cl<uint8_t> Data;
                    uint32_t ClusterNumberOfEntry(size_t EntryIndex);
                    uint32_t SectorNumberOfEntry(size_t EntryIndex);
                    uint32_t OffsetOfEntry(size_t EntryIndex);
                    uint32_t NextClusterOfEntry(size_t EntryIndex);
                    void ReadEntries();
                    void ReadDirectory();
                    void ReadFile();
                    _std::string NameOfEntry(size_t EntryIndex);
                    _std::string ListEntries();
                    FAT32_FileSystemFileObject_st(size_t ClusterNumber,DistilledInformation_st* Dist,FAT32_FileSystemFileObject_st* Previous=nullptr,DirectoryEntry_st* ThisEntry=nullptr,size_t EntryNumber=0);
                    ~FAT32_FileSystemFileObject_st();
                };
                struct FAT32Driver_st{
                    Extended_Boot_Record_FAT32_st Boot_Record;
                    FSINFO_Structure_st FSINFO_Structure;
                    DistilledInformation_st Dist;
                    FAT32_FileSystemFileObject_st* RootDirectory;
                    FAT32Driver_st(size_t Port,uint32_t PartitionOffset=0);
                    FAT32_FileSystemFileObject_st* Find(_std::string Path);
                };  
            };
        };
    };
};
