#pragma once

#include<Sauce/Storage/AHCI.hpp>
#include<Sauce/Global.hpp>

namespace Sauce{
    namespace Storage{
        namespace FileSystem{
            namespace FAT{
                struct Boot_Record_st{
                    uint8_t NOP[3];
                    uint8_t OEM_IDENTIFIER[8];
                    uint8_t NUMBER_OF_BYTES_PER_SECTOR[2];
                    uint8_t NUMBER_OF_SECTORS_PER_CLUSTER[1];
                    uint8_t NUMBER_OF_RESERVED_SECTORS[2];
                    uint8_t NUMBER_OF_FATS[1];
                    uint8_t NUMBER_OF_ROOT_DIRECTORY_ENTRIES[2];
                    uint8_t TOTAL_SECTORS_IN_LOGICAL_VOLUME[2];//if 0 then > 65535 sectors, check LARGE_SECTOR_COUNT
                    uint8_t MEDIA_DESCRIPTOR_TYPE[1];
                    union{
                        uint8_t NUMBER_OF_SECTORS_PER_FAT_12[2];
                        uint8_t NUMBER_OF_SECTORS_PER_FAT_16[2];
                    };
                    uint8_t NUMBER_OF_SECTORS_PER_TRACK[2];
                    union{
                        uint8_t NUMBER_OF_HEADS[2];
                        uint8_t NUMBER_OF_SIDES[2];
                    };
                    uint8_t NUMBER_OF_HIDDEN_SECTORS[4];
                    uint8_t LARGE_SECTOR_COUNT[4];
                }__attribute__((packed));
                struct Extended_Boot_Record_FAT12_st : public Boot_Record_st{
                    uint8_t DRIVE_NUMBER[1];
                    uint8_t WINDOWS_FLAGS[1];
                    uint8_t SIGNATURE[1]; //(must be 0x28 or 0x29)
                    uint8_t VOLUME_ID[4];
                    uint8_t VOLUME_LABEL[11]; // padded with spaces
                    uint8_t SYSTEM_IDENTIFIER[8];
                    uint8_t BOOT_CODE[448];
                    uint8_t BOOT_MAGIC[2];
                }__attribute__((packed));
                struct Extended_Boot_Record_FAT16_st : public Boot_Record_st{
                    uint8_t DRIVE_NUMBER[1];
                    uint8_t WINDOWS_FLAGS[1];
                    uint8_t SIGNATURE[1]; //(must be 0x28 or 0x29)
                    uint8_t VOLUME_ID[4];
                    uint8_t VOLUME_LABEL[11]; // padded with spaces
                    uint8_t SYSTEM_IDENTIFIER[8];
                    uint8_t BOOT_CODE[448];
                    uint8_t BOOT_MAGIC[2];
                }__attribute__((packed));
                struct Extended_Boot_Record_FAT32_st : public Boot_Record_st{
                    uint8_t NUMBER_OF_SECTORS_PER_FAT_32[4];
                    uint8_t FLAGS[2];
                    uint8_t FAT_VERSION[2]; // The high byte is the major version and the low byte is the minor version. FAT drivers should respect this field. 
                    uint8_t CLUSTER_NUMBER_OF_ROOT_DIRECTORY[4];
                    uint8_t SECTOR_NUMBER_OF_THE_FSINFO_STRUCTURE[2];
                    uint8_t SECTOR_NUMBER_OF_BACKUP_BOOT_SECTOR[2];
                    uint8_t RESERVED0[12];//When the volume is formated these bytes should be zero. 
                    uint8_t DRIVE_NUMBER[1];
                    uint8_t WINDOWS_FLAGS[1];
                    uint8_t SIGNATURE[1];//(must be 0x28 or 0x29)
                    uint8_t VOLUME_ID[4];
                    uint8_t VOLUME_LABEL[11];// padded with spaces
                    uint8_t SYSTEM_IDENTIFIER[8];
                    uint8_t BOOT_CODE[420];
                    uint8_t BOOT_MAGIC[2];
                }__attribute__((packed));
                struct FSINFO_Structure_st{
                    uint8_t LEAD_SIGNATURE[4];//(0x41615252)
                    uint8_t RESERVED0[480];// these bytes should never be used
                    uint8_t ANOTHER_SIGNATURE[4];//(0x61417272)
                    uint8_t LAST_KNOWN_FREE_CLUSTER[4];//If the value is 0xFFFFFFFF then the free count is unknown and must be computed.
                    uint8_t START_SEARCHING_FOR_AVAILABLE_CLUSTERS_HERE[4];//If the value is 0xFFFFFFFF then there is no hint and the driver should start searching at 2
                    uint8_t RESERVED1[12];
                    uint8_t TRAIL_SIGNATURE[4];//(0xAA550000)
                }__attribute__((packed));
                struct DirectoryEntry_st{
                	uint8_t name[8];
                	uint8_t ext[3];
                	uint8_t attrib[1];
                	uint8_t userattrib[1];
                	uint8_t undelete[1];
                	//uint16_t createtime;
                    uint8_t createtime[2];
                	//uint16_t createdate;
                    uint8_t createdate[2];
                	//uint16_t accessdate;
                    uint8_t accessdate[2];
                	//uint16_t clusterhigh;
                    uint8_t clusterhigh[2];
                	//uint16_t modifiedtime;
                    uint8_t modifiedtime[2];
                	//uint16_t modifieddate;
                    uint8_t modifieddate[2];
                	//uint16_t clusterlow;
                    uint8_t clusterlow[2];
                	//uint32_t filesize;
                    uint8_t filesize[4];
                }__attribute__((packed));

                struct FAT32Driver_st{
                    Extended_Boot_Record_FAT32_st Boot_Record;
                    FSINFO_Structure_st FSINFO_Structure;
                    size_t Port;
                    FAT32Driver_st(size_t Port);
                    Sauce::string info_str();
                        
                };
                
            };
        };
    };
};