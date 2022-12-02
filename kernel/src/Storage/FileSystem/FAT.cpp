#include<Sauce/Storage/FileSystem/FAT.hpp>
#include<Sauce/Utility/Conversion.hpp>

namespace Sauce{
    namespace Storage{
        namespace FileSystem{
            namespace FAT{
                FAT32_FileSystemFileObject_st::FAT32_FileSystemFileObject_st (Sauce::Memory::List_cl<uint8_t> sector){
                    Sauce::IO::Debug::Debugger_st Debugger("FAT32_FileSystemFileObject_st::FAT32_FileSystemFileObject_st",_NAMESPACE_,_ALLOW_PRINT_);
                    size_t offset=0;
                    if(sector.Size() != 512){
                        Sauce::string str("Incorrect sized data, expecting 512 bytes but received ");
                        str+=Sauce::Utility::Conversion::ToString(sector.Size());
                        Debugger.Print(str.Raw());
                        return;
                    }
                    for(size_t i=0;i<16;i++){
                        DirectoryEntry_st DirectoryEntry;
                        //  uint8_t NAME[8];
                        for(size_t i=0;i<8;i++){DirectoryEntry.NAME[i]=sector[i+offset];}offset+=8;
                        //  uint8_t EXT[3];
                        for(size_t i=0;i<3;i++){DirectoryEntry.EXT[i]=sector[i+offset];}offset+=3;
                        //  uint8_t ATTRIB[1];
                        for(size_t i=0;i<1;i++){DirectoryEntry.ATTRIB[i]=sector[i+offset];}offset+=1;
                        //  uint8_t USER_ATTRIB[1];
                        for(size_t i=0;i<1;i++){DirectoryEntry.USER_ATTRIB[i]=sector[i+offset];}offset+=1;
                        //  uint8_t UNDELETE[1];
                        for(size_t i=0;i<1;i++){DirectoryEntry.UNDELETE[i]=sector[i+offset];}offset+=1;
                        //  uint8_t CREATE_TIME[2];
                        for(size_t i=0;i<2;i++){DirectoryEntry.CREATE_TIME[i]=sector[i+offset];}offset+=2;
                        //  uint8_t CREATE_DATE[2];
                        for(size_t i=0;i<2;i++){DirectoryEntry.CREATE_DATE[i]=sector[i+offset];}offset+=2;
                        //  uint8_t ACCESS_DATE[2];
                        for(size_t i=0;i<2;i++){DirectoryEntry.ACCESS_DATE[i]=sector[i+offset];}offset+=2;
                        //  uint8_t CLUSTER_HIGH[2];
                        for(size_t i=0;i<2;i++){DirectoryEntry.CLUSTER_HIGH[i]=sector[i+offset];}offset+=2;
                        //  uint8_t MODIFIED_TIME[2];
                        for(size_t i=0;i<2;i++){DirectoryEntry.MODIFIED_TIME[i]=sector[i+offset];}offset+=2;
                        //  uint8_t MODIFIED_DATE[2];
                        for(size_t i=0;i<2;i++){DirectoryEntry.MODIFIED_DATE[i]=sector[i+offset];}offset+=2;
                        //  uint8_t CLUSTER_LOW[2];
                        for(size_t i=0;i<2;i++){DirectoryEntry.CLUSTER_LOW[i]=sector[i+offset];}offset+=2;
                        //  uint8_t FILE_SIZE[4];
                        for(size_t i=0;i<4;i++){DirectoryEntry.FILE_SIZE[i]=sector[i+offset];}offset+=4;
                        DirectoryEntries[i]=DirectoryEntry;
                    }
                }

                FAT32Driver_st::FAT32Driver_st(size_t Port,uint32_t PartitionOffset){
                    Sauce::IO::Debug::Debugger_st Debugger("FAT32Driver_st::FAT32Driver_st",_NAMESPACE_,_ALLOW_PRINT_);
                    this->Port=Port;
                    size_t CurrentByte=0;
                    Sauce::string debugString;
                    debugString="Boot_Record.NOP: ";
                    for(size_t i=0;i<3;i++){
                        Boot_Record.NOP[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.NOP[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="Boot_Record.OEM_IDENTIFIER: ";
                    for(size_t i=0;i<8;i++){
                        Boot_Record.OEM_IDENTIFIER[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.OEM_IDENTIFIER[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="Boot_Record.NUMBER_OF_BYTES_PER_SECTOR: ";
                    Debugger.Print(debugString.Raw());
                    for(size_t i=0;i<2;i++){
                        Boot_Record.NUMBER_OF_BYTES_PER_SECTOR[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.NUMBER_OF_BYTES_PER_SECTOR[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="Boot_Record.NUMBER_OF_SECTORS_PER_CLUSTER: ";
                    for(size_t i=0;i<1;i++){
                        Boot_Record.NUMBER_OF_SECTORS_PER_CLUSTER[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.NUMBER_OF_SECTORS_PER_CLUSTER[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="Boot_Record.NUMBER_OF_RESERVED_SECTORS: ";
                    for(size_t i=0;i<2;i++){
                        Boot_Record.NUMBER_OF_RESERVED_SECTORS[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.NUMBER_OF_RESERVED_SECTORS[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="Boot_Record.NUMBER_OF_FATS: ";
                    for(size_t i=0;i<1;i++){
                        Boot_Record.NUMBER_OF_FATS[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.NUMBER_OF_FATS[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="Boot_Record.NUMBER_OF_FATS: ";
                    for(size_t i=0;i<2;i++){
                        Boot_Record.NUMBER_OF_ROOT_DIRECTORY_ENTRIES[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.NUMBER_OF_ROOT_DIRECTORY_ENTRIES[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="Boot_Record.TOTAL_SECTORS_IN_LOGICAL_VOLUME: ";
                    for(size_t i=0;i<2;i++){
                        Boot_Record.TOTAL_SECTORS_IN_LOGICAL_VOLUME[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.TOTAL_SECTORS_IN_LOGICAL_VOLUME[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="Boot_Record.MEDIA_DESCRIPTOR_TYPE: ";
                    for(size_t i=0;i<1;i++){
                        Boot_Record.MEDIA_DESCRIPTOR_TYPE[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.MEDIA_DESCRIPTOR_TYPE[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="Boot_Record.NUMBER_OF_SECTORS_PER_FAT_(12/16): ";
                    for(size_t i=0;i<2;i++){
                        Boot_Record.NUMBER_OF_SECTORS_PER_FAT_12[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.NUMBER_OF_SECTORS_PER_FAT_12[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="Boot_Record.NUMBER_OF_SECTORS_PER_TRACK: ";
                    for(size_t i=0;i<2;i++){
                        Boot_Record.NUMBER_OF_SECTORS_PER_TRACK[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.NUMBER_OF_SECTORS_PER_TRACK[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="Boot_Record.NUMBER_OF_(HEAD/SIDES): ";
                    for(size_t i=0;i<2;i++){
                        Boot_Record.NUMBER_OF_HEADS[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.NUMBER_OF_HEADS[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="Boot_Record.NUMBER_OF_HIDDEN_SECTORS: ";
                    for(size_t i=0;i<4;i++){
                        Boot_Record.NUMBER_OF_HIDDEN_SECTORS[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.NUMBER_OF_HIDDEN_SECTORS[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="Boot_Record.LARGE_SECTOR_COUNT: ";
                    for(size_t i=0;i<4;i++){
                        Boot_Record.LARGE_SECTOR_COUNT[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.LARGE_SECTOR_COUNT[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="Boot_Record.NUMBER_OF_SECTORS_PER_FAT_32: ";
                    for(size_t i=0;i<4;i++){
                        Boot_Record.NUMBER_OF_SECTORS_PER_FAT_32[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.NUMBER_OF_SECTORS_PER_FAT_32[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="Boot_Record.FLAGS: ";
                    for(size_t i=0;i<2;i++){
                        Boot_Record.FLAGS[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.FLAGS[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="Boot_Record.FAT_VERSION: ";
                    for(size_t i=0;i<2;i++){
                        Boot_Record.FAT_VERSION[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.FAT_VERSION[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="Boot_Record.CLUSTER_NUMBER_OF_ROOT_DIRECTORY: ";
                    for(size_t i=0;i<4;i++){
                        Boot_Record.CLUSTER_NUMBER_OF_ROOT_DIRECTORY[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.CLUSTER_NUMBER_OF_ROOT_DIRECTORY[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="Boot_Record.SECTOR_NUMBER_OF_THE_FSINFO_STRUCTURE: ";
                    for(size_t i=0;i<2;i++){
                        Boot_Record.SECTOR_NUMBER_OF_THE_FSINFO_STRUCTURE[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.SECTOR_NUMBER_OF_THE_FSINFO_STRUCTURE[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="Boot_Record.SECTOR_NUMBER_OF_BACKUP_BOOT_SECTOR: ";
                    for(size_t i=0;i<2;i++){
                        Boot_Record.SECTOR_NUMBER_OF_BACKUP_BOOT_SECTOR[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.SECTOR_NUMBER_OF_BACKUP_BOOT_SECTOR[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="Boot_Record.RESERVED0: ";
                    for(size_t i=0;i<12;i++){
                        Boot_Record.RESERVED0[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.RESERVED0[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="Boot_Record.DRIVE_NUMBER: ";
                    for(size_t i=0;i<1;i++){
                        Boot_Record.DRIVE_NUMBER[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.DRIVE_NUMBER[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="Boot_Record.WINDOWS_FLAGS: ";
                    for(size_t i=0;i<1;i++){
                        Boot_Record.WINDOWS_FLAGS[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.WINDOWS_FLAGS[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="Boot_Record.SIGNATURE: ";
                    for(size_t i=0;i<1;i++){
                        Boot_Record.SIGNATURE[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.SIGNATURE[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="Boot_Record.VOLUME_ID: ";
                    for(size_t i=0;i<4;i++){
                        Boot_Record.VOLUME_ID[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.VOLUME_ID[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="Boot_Record.VOLUME_LABEL: ";
                    for(size_t i=0;i<11;i++){
                        Boot_Record.VOLUME_LABEL[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.VOLUME_LABEL[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="Boot_Record.SYSTEM_IDENTIFIER: ";
                    for(size_t i=0;i<8;i++){
                        Boot_Record.SYSTEM_IDENTIFIER[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.SYSTEM_IDENTIFIER[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="Boot_Record.BOOT_CODE: ";
                    for(size_t i=0;i<420;i++){
                        Boot_Record.BOOT_CODE[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.BOOT_CODE[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="Boot_Record.BOOT_MAGIC: ";
                    for(size_t i=0;i<2;i++){
                        Boot_Record.BOOT_MAGIC[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(Boot_Record.BOOT_MAGIC[i]);
                    }
                    Debugger.Print(debugString.Raw());

                    CurrentByte=((uint16_t)*Boot_Record.SECTOR_NUMBER_OF_THE_FSINFO_STRUCTURE)*(*((uint16_t*)Boot_Record.NUMBER_OF_BYTES_PER_SECTOR));
                    debugString="FSINFO_Structure.LEAD_SIGNATURE: ";
                    for(size_t i=0;i<4;i++){
                        FSINFO_Structure.LEAD_SIGNATURE[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(FSINFO_Structure.LEAD_SIGNATURE[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="FSINFO_Structure.RESERVED0: ";
                    for(size_t i=0;i<480;i++){
                        FSINFO_Structure.RESERVED0[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(FSINFO_Structure.RESERVED0[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="FSINFO_Structure.ANOTHER_SIGNATURE: ";
                    for(size_t i=0;i<4;i++){
                        FSINFO_Structure.ANOTHER_SIGNATURE[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(FSINFO_Structure.ANOTHER_SIGNATURE[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="FSINFO_Structure.LAST_KNOWN_FREE_CLUSTER: ";
                    for(size_t i=0;i<4;i++){
                        FSINFO_Structure.LAST_KNOWN_FREE_CLUSTER[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(FSINFO_Structure.LAST_KNOWN_FREE_CLUSTER[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="FSINFO_Structure.START_SEARCHING_FOR_AVAILABLE_CLUSTERS_HERE: ";
                    for(size_t i=0;i<4;i++){
                        FSINFO_Structure.START_SEARCHING_FOR_AVAILABLE_CLUSTERS_HERE[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(FSINFO_Structure.START_SEARCHING_FOR_AVAILABLE_CLUSTERS_HERE[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="FSINFO_Structure.RESERVED1: ";
                    for(size_t i=0;i<12;i++){
                        FSINFO_Structure.RESERVED1[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(FSINFO_Structure.RESERVED1[i]);
                    }
                    Debugger.Print(debugString.Raw());
                    debugString="FSINFO_Structure.TRAIL_SIGNATURE: ";
                    for(size_t i=0;i<4;i++){
                        FSINFO_Structure.TRAIL_SIGNATURE[i]=Sauce::Global::AHCIDriver->Read(Port,CurrentByte++);
                        debugString+=Sauce::Utility::Conversion::HexToString(FSINFO_Structure.TRAIL_SIGNATURE[i]);
                    }
                    Debugger.Print(debugString.Raw());

                    //void AHCIDriver_cl::Read(size_t portNumber,size_t startingSector,size_t sectorCount,Sauce::Memory::List_cl<uint8_t> &Bufferr)
//                    Sauce::Memory::List_cl<uint8_t> Bufferr;
//
//                    uint32_t fatStart=PartitionOffset+(*((uint16_t*)Boot_Record.NUMBER_OF_RESERVED_SECTORS));
//                    
//
//                    Sauce::Global::AHCIDriver->Read(Port,SectorOfRootDirectoryEntry,1,Bufferr);
//                    FAT32_FileSystemFileObject_st RootDirectoryEntry(Bufferr);
                    
                }
            };
        };
    };
};