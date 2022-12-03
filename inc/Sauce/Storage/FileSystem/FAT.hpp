#pragma once

#include<Sauce/Storage/AHCI.hpp>
#include<Sauce/Global.hpp>
#include<Sauce/Math/Types.hpp>

namespace Sauce{
    namespace Storage{
        namespace FileSystem{
            namespace FAT{
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
                    union{
                        uint8_t NUMBER_OF_SECTORS_PER_FAT_12[2]{0x00};
                        uint8_t NUMBER_OF_SECTORS_PER_FAT_16[2];
                    };
                    uint8_t NUMBER_OF_SECTORS_PER_TRACK[2]{0x00};
                    union{
                        uint8_t NUMBER_OF_HEADS[2]{0x00};
                        uint8_t NUMBER_OF_SIDES[2];
                    };
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
                    uint8_t FILE_SIZE[4]{0x00};
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
                    FAT32_FileSystemFileObject_st* Directories[16];
                    size_t LastEntryIndex;
                    DistilledInformation_st* Dist;
                    Sauce::Memory::List_cl<uint8_t> Data;
                    Sauce::string Name;
                    uint32_t ClusterNumberOfEntry(size_t EntryIndex);
                    uint32_t SectorNumberOfEntry(size_t EntryIndex);
                    uint32_t OffsetOfEntry(size_t EntryIndex);
                    uint32_t NextClusterOfEntry(size_t EntryIndex);
                    void ReadEntries();
                    Sauce::string NameOfEntry(size_t EntryIndex);
                    Sauce::string ListEntries(Sauce::string prefix);
                    FAT32_FileSystemFileObject_st(size_t ClusterNumber,DistilledInformation_st* Dist,Sauce::string Name);
                    ~FAT32_FileSystemFileObject_st();
                };

                struct FAT32Driver_st{
                    Extended_Boot_Record_FAT32_st Boot_Record;
                    FSINFO_Structure_st FSINFO_Structure;
                    DistilledInformation_st Dist;
                    FAT32_FileSystemFileObject_st* RootDirectory;
                    FAT32Driver_st(size_t Port,uint32_t PartitionOffset=0);
                };
                
            };
        };
    };
};