#include<Sauce/Storage/FileSystem/FAT.hpp>



namespace Sauce{
    namespace Storage{
        namespace FileSystem{
            namespace FAT{
                Extended_Boot_Record_FAT32_st READ_FAT32(size_t port){
                    Extended_Boot_Record_FAT32_st FAT32Record;
                    //uint8_t Read(size_t portNumber,size_t ByteToRead);
                    size_t CurrentByte=0;
                    //FAT32Record.NOP[3];
                        for(size_t i=0;i<3;i++)FAT32Record.NOP[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);
                    //FAT32Record.OEM_IDENTIFIER[8];
                        for(size_t i=0;i<8;i++)FAT32Record.OEM_IDENTIFIER[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);
                    //FAT32Record.NUMBER_OF_BYTES_PER_SECTOR[2];
                        for(size_t i=0;i<2;i++)FAT32Record.NUMBER_OF_BYTES_PER_SECTOR[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);
                    //FAT32Record.NUMBER_OF_SECTORS_PER_CLUSTER[1];
                        for(size_t i=0;i<1;i++)FAT32Record.NUMBER_OF_SECTORS_PER_CLUSTER[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);
                    //FAT32Record.NUMBER_OF_RESERVED_SECTORS[2];
                        for(size_t i=0;i<2;i++)FAT32Record.NUMBER_OF_RESERVED_SECTORS[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);
                    //FAT32Record.NUMBER_OF_FATS[1];
                        for(size_t i=0;i<1;i++)FAT32Record.NUMBER_OF_FATS[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);
                    //FAT32Record.NUMBER_OF_ROOT_DIRECTORY_ENTRIES[2];
                        for(size_t i=0;i<2;i++)FAT32Record.NUMBER_OF_ROOT_DIRECTORY_ENTRIES[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);
                    //FAT32Record.TOTAL_SECTORS_IN_LOGICAL_VOLUME[2];
                        for(size_t i=0;i<2;i++)FAT32Record.TOTAL_SECTORS_IN_LOGICAL_VOLUME[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);
                    //FAT32Record.MEDIA_DESCRIPTOR_TYPE[1];
                        for(size_t i=0;i<1;i++)FAT32Record.MEDIA_DESCRIPTOR_TYPE[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);
                    //FAT32Record.NUMBER_OF_SECTORS_PER_FAT_FAT12[2];
                        for(size_t i=0;i<2;i++)FAT32Record.NUMBER_OF_SECTORS_PER_FAT_FAT12[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);
                    //FAT32Record.NUMBER_OF_SECTORS_PER_TRACK[2];
                        for(size_t i=0;i<2;i++)FAT32Record.NUMBER_OF_SECTORS_PER_TRACK[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);
                    //FAT32Record.NUMBER_OF_HEADS[2];
                        for(size_t i=0;i<2;i++)FAT32Record.NUMBER_OF_HEADS[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);
                    //FAT32Record.NUMBER_OF_HIDDEN_SECTORS[4];
                        for(size_t i=0;i<4;i++)FAT32Record.NUMBER_OF_HIDDEN_SECTORS[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);
                    //FAT32Record.LARGE_SECTOR_COUNT[4];
                        for(size_t i=0;i<4;i++)FAT32Record.LARGE_SECTOR_COUNT[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);
                    //FAT32Record.NUMBER_OF_SECTORS_PER_FAT_32[4];
                        for(size_t i=0;i<4;i++)FAT32Record.NUMBER_OF_SECTORS_PER_FAT_32[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);
                    //FAT32Record.FLAGS[2];
                        for(size_t i=0;i<2;i++)FAT32Record.FLAGS[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);
                    //FAT32Record.FAT_VERSION[2];
                        for(size_t i=0;i<2;i++)FAT32Record.FAT_VERSION[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);
                    //FAT32Record.CLUSTER_NUMBER_OF_ROOT_DIRECTORY[4];
                        for(size_t i=0;i<4;i++)FAT32Record.CLUSTER_NUMBER_OF_ROOT_DIRECTORY[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);
                    //FAT32Record.SECTOR_NUMBER_OF_THE_FSINFO_STRUCTURE[2];
                        for(size_t i=0;i<2;i++)FAT32Record.SECTOR_NUMBER_OF_THE_FSINFO_STRUCTURE[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);
                    //FAT32Record.SECTOR_NUMBER_OF_BACKUP_BOOT_SECTOR[2];
                        for(size_t i=0;i<2;i++)FAT32Record.SECTOR_NUMBER_OF_BACKUP_BOOT_SECTOR[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);
                    //FAT32Record.RESERVED0[12];
                        for(size_t i=0;i<12;i++)FAT32Record.RESERVED0[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);
                    //FAT32Record.DRIVE_NUMBER[1];
                        for(size_t i=0;i<1;i++)FAT32Record.DRIVE_NUMBER[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);
                    //FAT32Record.WINDOWS_FLAGS[1];
                        for(size_t i=0;i<1;i++)FAT32Record.WINDOWS_FLAGS[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);
                    //FAT32Record.SIGNATURE[1];
                        for(size_t i=0;i<1;i++)FAT32Record.SIGNATURE[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);
                    //FAT32Record.VOLUME_ID[4];
                        for(size_t i=0;i<4;i++)FAT32Record.VOLUME_ID[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);
                    //FAT32Record.VOLUME_LABEL[11];
                        for(size_t i=0;i<11;i++)FAT32Record.VOLUME_LABEL[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);
                    //FAT32Record.SYSTEM_IDENTIFIER[8];
                        for(size_t i=0;i<8;i++)FAT32Record.SYSTEM_IDENTIFIER[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);
                    //FAT32Record.BOOT_CODE[420];
                        for(size_t i=0;i<420;i++)FAT32Record.BOOT_CODE[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);
                    //FAT32Record.BOOT_MAGIC[2];
                        for(size_t i=0;i<2;i++)FAT32Record.BOOT_MAGIC[i]=Sauce::Global::AHCIDriver->Read(port,CurrentByte++);

                    return FAT32Record;
                }
            };
        };
    };
};