#include<Sauce/Storage/FileSystem/FAT.hpp>
#include<Sauce/Utility/Conversion.hpp>

namespace Sauce{
    namespace Storage{
        namespace FileSystem{
            namespace FAT{
                FAT32Driver_st::FAT32Driver_st(size_t Port){
                    this->Port=Port;
                    size_t CurrentByte=0;
                    for(size_t i=0;i<3;i++)Boot_Record.NOP[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<8;i++)Boot_Record.OEM_IDENTIFIER[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<2;i++)Boot_Record.NUMBER_OF_BYTES_PER_SECTOR[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<1;i++)Boot_Record.NUMBER_OF_SECTORS_PER_CLUSTER[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<2;i++)Boot_Record.NUMBER_OF_RESERVED_SECTORS[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<1;i++)Boot_Record.NUMBER_OF_FATS[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<2;i++)Boot_Record.NUMBER_OF_ROOT_DIRECTORY_ENTRIES[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<2;i++)Boot_Record.TOTAL_SECTORS_IN_LOGICAL_VOLUME[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<1;i++)Boot_Record.MEDIA_DESCRIPTOR_TYPE[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<2;i++)Boot_Record.NUMBER_OF_SECTORS_PER_FAT_12[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<2;i++)Boot_Record.NUMBER_OF_SECTORS_PER_TRACK[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<2;i++)Boot_Record.NUMBER_OF_HEADS[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<4;i++)Boot_Record.NUMBER_OF_HIDDEN_SECTORS[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<4;i++)Boot_Record.LARGE_SECTOR_COUNT[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<4;i++)Boot_Record.NUMBER_OF_SECTORS_PER_FAT_32[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<2;i++)Boot_Record.FLAGS[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<2;i++)Boot_Record.FAT_VERSION[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<4;i++)Boot_Record.CLUSTER_NUMBER_OF_ROOT_DIRECTORY[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<2;i++)Boot_Record.SECTOR_NUMBER_OF_THE_FSINFO_STRUCTURE[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<2;i++)Boot_Record.SECTOR_NUMBER_OF_BACKUP_BOOT_SECTOR[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<12;i++)Boot_Record.RESERVED0[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<1;i++)Boot_Record.DRIVE_NUMBER[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<1;i++)Boot_Record.WINDOWS_FLAGS[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<1;i++)Boot_Record.SIGNATURE[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<4;i++)Boot_Record.VOLUME_ID[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<11;i++)Boot_Record.VOLUME_LABEL[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<8;i++)Boot_Record.SYSTEM_IDENTIFIER[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<420;i++)Boot_Record.BOOT_CODE[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<2;i++)Boot_Record.BOOT_MAGIC[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);

                    CurrentByte=((uint16_t)*Boot_Record.SECTOR_NUMBER_OF_THE_FSINFO_STRUCTURE)*(*((uint16_t*)Boot_Record.NUMBER_OF_BYTES_PER_SECTOR));
                    for(size_t i=0;i<4;i++)FSINFO_Structure.LEAD_SIGNATURE[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<480;i++)FSINFO_Structure.RESERVED0[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<4;i++)FSINFO_Structure.ANOTHER_SIGNATURE[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<4;i++)FSINFO_Structure.LAST_KNOWN_FREE_CLUSTER[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<4;i++)FSINFO_Structure.START_SEARCHING_FOR_AVAILABLE_CLUSTERS_HERE[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<12;i++)FSINFO_Structure.RESERVED1[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    for(size_t i=0;i<12;i++)FSINFO_Structure.TRAIL_SIGNATURE[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                    
                    dist.total_sectors=(*(uint16_t*)Boot_Record.TOTAL_SECTORS_IN_LOGICAL_VOLUME)+(*(uint32_t*)Boot_Record.LARGE_SECTOR_COUNT);
                    dist.fat_size=(*(uint16_t*)Boot_Record.NUMBER_OF_SECTORS_PER_FAT_12)+(*(uint32_t*)Boot_Record.NUMBER_OF_SECTORS_PER_FAT_32);
                    dist.first_fat_sector=(*(uint16_t*)Boot_Record.NUMBER_OF_RESERVED_SECTORS);
                    dist.NumberOfSectors=((*(uint16_t*)Boot_Record.NUMBER_OF_ROOT_DIRECTORY_ENTRIES) *32)+((*(uint16_t*)Boot_Record.NUMBER_OF_BYTES_PER_SECTOR)-1)/(*(uint16_t*)Boot_Record.NUMBER_OF_BYTES_PER_SECTOR);
                    dist.data_sectors=dist.total_sectors-((*(uint16_t*)Boot_Record.NUMBER_OF_RESERVED_SECTORS)+((*(uint8_t*)Boot_Record.NUMBER_OF_FATS)*dist.fat_size))+dist.NumberOfSectors;
                    dist.total_clusters=dist.data_sectors/(*(uint8_t*)Boot_Record.NUMBER_OF_SECTORS_PER_CLUSTER);

                    dist.RootDirectory.NumberOfSectors=dist.NumberOfSectors;
                    dist.RootDirectory.FirstDataSector=(*(uint16_t*)Boot_Record.NUMBER_OF_RESERVED_SECTORS)+((*(uint8_t*)Boot_Record.NUMBER_OF_FATS)*dist.fat_size)+dist.RootDirectory.NumberOfSectors;
                    dist.RootDirectory.ClusterNumber=(*(uint32_t*)Boot_Record.CLUSTER_NUMBER_OF_ROOT_DIRECTORY);
                    dist.RootDirectory.FirstSector = ((dist.RootDirectory.ClusterNumber - 2) * (*(uint8_t*)Boot_Record.NUMBER_OF_SECTORS_PER_CLUSTER)) + dist.RootDirectory.FirstDataSector;
                    dist.RootDirectory.NumberOfEntries=(*(uint16_t*)Boot_Record.NUMBER_OF_ROOT_DIRECTORY_ENTRIES);
                }
                Sauce::string FAT32Driver_st::info_str(){
                    Sauce::string Result;
                    Result+="Boot_Record.NOP: ";
                    for(size_t i=0;i<3;i++)Result+=Sauce::Utility::Conversion::HexToString(Boot_Record.NOP[i]);
                    Result+="\n\r";
                    Result+="Boot_Record.OEM_IDENTIFIER: ";
                    for(size_t i=0;i<8;i++)Result+=Sauce::Utility::Conversion::HexToString(Boot_Record.OEM_IDENTIFIER[i]);
                    Result+="\n\r";
                    Result+="Boot_Record.NUMBER_OF_BYTES_PER_SECTOR: ";
                    Result+=Sauce::Utility::Conversion::ToString(*((uint16_t*)Boot_Record.NUMBER_OF_BYTES_PER_SECTOR));
                    Result+="\n\r";
                    Result+="Boot_Record.NUMBER_OF_SECTORS_PER_CLUSTER: ";
                    Result+=Sauce::Utility::Conversion::ToString(*((uint8_t*)Boot_Record.NUMBER_OF_SECTORS_PER_CLUSTER));
                    Result+="\n\r";
                    Result+="Boot_Record.NUMBER_OF_RESERVED_SECTORS: ";
                    Result+=Sauce::Utility::Conversion::ToString(*((uint16_t*)Boot_Record.NUMBER_OF_RESERVED_SECTORS));
                    Result+="\n\r";
                    Result+="Boot_Record.NUMBER_OF_FATS: ";
                    Result+=Sauce::Utility::Conversion::ToString(*((uint8_t*)Boot_Record.NUMBER_OF_FATS));
                    Result+="\n\r";
                    Result+="Boot_Record.NUMBER_OF_ROOT_DIRECTORY_ENTRIES: ";
                    Result+=Sauce::Utility::Conversion::ToString(*((uint16_t*)Boot_Record.NUMBER_OF_ROOT_DIRECTORY_ENTRIES) );
                    Result+="\n\r";
                    Result+="Boot_Record.TOTAL_SECTORS_IN_LOGICAL_VOLUME: ";
                    Result+=Sauce::Utility::Conversion::ToString(*((uint16_t*)Boot_Record.TOTAL_SECTORS_IN_LOGICAL_VOLUME));
                    Result+="\n\r";
                    Result+="Boot_Record.MEDIA_DESCRIPTOR_TYPE: ";
                    Result+=Sauce::Utility::Conversion::HexToString(*((uint8_t*)Boot_Record.MEDIA_DESCRIPTOR_TYPE));
                    Result+="\n\r";
                    Result+="Boot_Record.NUMBER_OF_SECTORS_PER_FAT_(12/16): ";
                    Result+=Sauce::Utility::Conversion::ToString(*((uint16_t*)Boot_Record.NUMBER_OF_SECTORS_PER_FAT_12));
                    Result+="\n\r";
                    Result+="Boot_Record.NUMBER_OF_SECTORS_PER_TRACK: ";
                    Result+=Sauce::Utility::Conversion::ToString(*((uint16_t*)Boot_Record.NUMBER_OF_SECTORS_PER_TRACK));
                    Result+="\n\r";
                    Result+="Boot_Record.NUMBER_OF_HEADS: ";
                    Result+=Sauce::Utility::Conversion::ToString(*((uint16_t*)Boot_Record.NUMBER_OF_HEADS));
                    Result+="\n\r";
                    Result+="Boot_Record.NUMBER_OF_HIDDEN_SECTORS: ";
                    Result+=Sauce::Utility::Conversion::ToString(*((uint32_t*)Boot_Record.NUMBER_OF_HIDDEN_SECTORS));
                    Result+="\n\r";
                    Result+="Boot_Record.LARGE_SECTOR_COUNT: ";
                    Result+=Sauce::Utility::Conversion::ToString(*((uint32_t*)Boot_Record.LARGE_SECTOR_COUNT));
                    Result+="\n\r";
                    Result+="Boot_Record.NUMBER_OF_SECTORS_PER_FAT_32: ";
                    Result+=Sauce::Utility::Conversion::ToString(*((uint32_t*)Boot_Record.NUMBER_OF_SECTORS_PER_FAT_32));
                    Result+="\n\r";
                    Result+="Boot_Record.FLAGS: ";
                    Result+=Sauce::Utility::Conversion::HexToString(*((uint16_t*)Boot_Record.FLAGS));
                    Result+="\n\r";
                    Result+="Boot_Record.FAT_VERSION: ";
                    Result+=Sauce::Utility::Conversion::HexToString(*((uint16_t*)Boot_Record.FAT_VERSION));
                    Result+="\n\r";
                    Result+="Boot_Record.CLUSTER_NUMBER_OF_ROOT_DIRECTORY: ";
                    Result+=Sauce::Utility::Conversion::ToString(*((uint32_t*)Boot_Record.CLUSTER_NUMBER_OF_ROOT_DIRECTORY));
                    Result+="\n\r";
                    Result+="Boot_Record.SECTOR_NUMBER_OF_THE_FSINFO_STRUCTURE: ";
                    Result+=Sauce::Utility::Conversion::ToString(*((uint16_t*)Boot_Record.SECTOR_NUMBER_OF_THE_FSINFO_STRUCTURE));
                    Result+="\n\r";
                    Result+="Boot_Record.SECTOR_NUMBER_OF_BACKUP_BOOT_SECTOR: ";
                    Result+=(Sauce::Utility::Conversion::ToString(*((uint16_t*)Boot_Record.SECTOR_NUMBER_OF_BACKUP_BOOT_SECTOR)));
                    Result+="\n\r";
                    Result+="Boot_Record.DRIVE_NUMBER: ";
                    Result+=Sauce::Utility::Conversion::HexToString(*((uint8_t*)Boot_Record.DRIVE_NUMBER));
                    Result+="\n\r";
                    Result+="Boot_Record.WINDOWS_FLAGS: ";
                    Result+=Sauce::Utility::Conversion::HexToString(*((uint8_t*)Boot_Record.WINDOWS_FLAGS));
                    Result+="\n\r";
                    Result+="Boot_Record.SIGNATURE: ";
                    Result+=Sauce::Utility::Conversion::HexToString(*((uint8_t*)Boot_Record.SIGNATURE));
                    Result+="\n\r";
                    Result+="Boot_Record.VOLUME_ID: ";
                    Result+=Sauce::Utility::Conversion::HexToString(*((uint8_t*)Boot_Record.VOLUME_ID));
                    Result+="\n\r";
                    Result+="Boot_Record.VOLUME_LABEL: ";
                    for(size_t i=0;i<11;i++)Result+=((char)Boot_Record.VOLUME_LABEL[i]);
                    Result+="\n\r";
                    Result+="Boot_Record.SYSTEM_IDENTIFIER: ";
                    Result+=Sauce::Utility::Conversion::HexToString(*((uint64_t*)Boot_Record.SYSTEM_IDENTIFIER));
                    Result+="\n\r";
                    Result+="Boot_Record.BOOT_MAGIC: ";
                    Result+=Sauce::Utility::Conversion::HexToString(*((uint16_t*)Boot_Record.BOOT_MAGIC));
                    Result+="\n\r";

                    Result+="test";

                    return Result;
                }
            };
        };
    };
};