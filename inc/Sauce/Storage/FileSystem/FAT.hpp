#pragma once
#include<stddef.h>
#include<stdint.h>
namespace Sauce{
    namespace Storage{
        namespace FileSystem{
            namespace FAT{
                struct BiosBootBlock_st{
                    uint8_t NOP_JMP[3];
                    uint8_t OEM_IDENTIFIER[8];
                    uint8_t NUMBER_OF_BYTES_PER_SECTOR[2];
                    uint8_t NUMBER_OF_SECTORS_PER_CLUSTER[1];
                    uint8_t NUMBER_OF_RESERVED_SECTORS[2];
                    uint8_t NUMBER_OF_FILE_ALLOCATION_TABLES[1];
                    uint8_t NUMBER_OF_ROOT_DIRECTORY_ENTRIES[2];
                    uint8_t TOTAL_SECTORS_IN_THE_LOGICAL_VOLUME[2]; // If this value is 0 check LARGE_SECTOR_COUNT
                    uint8_t MEDIA_TYPE[1];
                    uint8_t NUMBER_OF_SECTORS_PER_FAT_12_OR_16[2];
                    uint8_t NUMBER_OF_SECTORS_PER_TRACK[2];
                    uint8_t NUMBER_OF_HEADS_OR_SIDES[2];
                    uint8_t NUMBER_OF_HIDDEN_SECTORS[4];
                    uint8_t LARGE_SECTOR_COUNT[4];
                };

                class FAT32_cl{
                    BiosBootBlock_st BiosBootBlock;
                    public:
                    FAT32_cl(size_t Port);
                };
            };
        };
    };
};