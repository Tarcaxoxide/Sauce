#pragma once

#include<Sauce/Types.hpp>

namespace Sauce{
    namespace Storage{
        namespace FileSystem{
            struct BIOS_Parameter_Block_st{
            //[3]/*The first three bytes EB 3C 90 disassemble to JMP SHORT 3C NOP. (The 3C value may be different.) The reason for this is to jump over the disk format information (the BPB and EBPB). Since the first sector of the disk is loaded into ram at location 0x0000:0x7c00 and executed, without this jump, the processor would attempt to execute data that isn't code. Even for non-bootable volumes, code matching this pattern (or using the E9 jump opcode) is required to be present by both Windows and OS X. To fulfil this requirement, an infinite loop can be placed here with the bytes EB FE 90.*/
            uint8_t The_first_three_bytes[3];
            //[8]/*OEM identifier. The first 8 Bytes (3 - 10) is the version of DOS being used. The next eight Bytes 29 3A 63 7E 2D 49 48 and 43 read out the name of the version. The official FAT Specification from Microsoft says that this field is really meaningless and is ignored by MS FAT Drivers, however it does recommend the value "MSWIN4.1" as some 3rd party drivers supposedly check it and expect it to have that value. Older versions of dos also report MSDOS5.1, linux-formatted floppy will likely to carry "mkdosfs" here, and FreeDOS formatted disks have been observed to have "FRDOS5.1" here. If the string is less than 8 bytes, it is padded with spaces.*/
            uint8_t OEM_identifier[8];
            //[2]/*Number of Bytes per sector (remember, all numbers are in the little-endian format).*/
            uint8_t Number_of_Bytes_per_sector[2];
            //[1]/*Number of sectors per cluster.*/
            uint8_t Number_of_sectors_per_cluster[1];
            //[2]/*Number of reserved sectors. The boot record sectors are included in this value.*/
            uint8_t Number_of_reserved_sectors[2];
            //[1]/*Number of File Allocation Tables (FAT's) on the storage media. Often this value is 2.*/
            uint8_t Number_of_File_Allocation_Tables[1];
            //[2]/*Number of root directory entries (must be set so that the root directory occupies entire sectors).*/
            uint8_t Number_of_root_directory_entries[2];
            //[2]/*Total sectors in the logical volume. If this value is 0, it means there are more than 65535 sectors in the volume, and the actual count is stored in the Large Sector Count entry at 0x20.*/
            uint8_t Total_sectors_in_the_logical_volume[2];
            //[1]/*This Byte indicates the media descriptor type.*/
            uint8_t media_descriptor_type[1];
            //[2]/*Number of sectors per FAT. FAT12/FAT16 only.*/
            uint8_t Number_of_sectors_per_FAT[2];
            //[2]/*Number of sectors per track.*/
            uint8_t Number_of_sectors_per_track[2];
            //[2]/*Number of heads or sides on the storage media.*/
            uint8_t Number_of_heads[2];
            //[4]/*Number of hidden sectors. (i.e. the LBA of the beginning of the partition.)*/
            uint8_t Number_of_hidden_sectors[4];
            //[4]/*Large sector count. This field is set if there are more than 65535 sectors in the volume, resulting in a value which does not fit in the Number of Sectors entry at 0x13.*/
            uint8_t Large_sector_count[4];
        }__attribute__((packed));
        struct F32_Extended_Boot_Record_st{
            //[4]/*Sectors per FAT. The size of the FAT in sectors.*/
            uint8_t Sectors_per_FAT[4];
            //[2]/*Flags.*/
            uint8_t Flags[2];
            //[2]/*FAT version number. The high byte is the major version and the low byte is the minor version. FAT drivers should respect this field.*/
            uint8_t FAT_version_number[2];
            //[4]/*The cluster number of the root directory. Often this field is set to 2.*/
            uint8_t Cluster_number_of_the_root_directory[4];
            //[2]/*The sector number of the FSInfo structure.*/
            uint8_t Sector_number_of_the_FSinfo_structure[2];
            //[2]/*The sector number of the backup boot sector.*/
            uint8_t Sector_number_of_the_backup_boot_sector[2];
            //[12]/*Reserved. When the volume is formated these bytes should be zero.*/
            uint8_t Reserved_FormattedZero[12];
            //[1]/*Drive number. The values here are identical to the values returned by the BIOS interrupt 0x13. 0x00 for a floppy disk and 0x80 for hard disks.*/
            uint8_t Drive_number[1];
            //[1]/*Flags in Windows NT. Reserved otherwise.*/
            uint8_t Flags_reserved[1];
            //[1]/*Signature (must be 0x28 or 0x29).*/
            uint8_t Signature[1];
            //[4]/*Volume ID 'Serial' number. Used for tracking volumes between computers. You can ignore this if you want.*/
            uint8_t Volume_ID[4];
            //[11]/*Volume label string. This field is padded with spaces.*/
            uint8_t Volume_label_string[11];
            //[8]/*System identifier string. Always "FAT32   ". The spec says never to trust the contents of this string for any use.*/
            uint8_t System_identifier_string[8];
            //[420]/*Boot code.*/
            uint8_t Boot_code[420];
            //[2]/*Bootable partition signature 0xAA55.*/ 
            uint8_t Bootable_partition_signature[2];
        }__attribute__((packed));
        struct FSInfo_st{
            //[4]/*Lead signature (must be 0x41615252 to indicate a valid FSInfo structure)*/
            uint8_t Lead_signature[4];
            //[480]/*Reserved, these bytes should never be used*/
            uint8_t Reserved1[480];
            //[4]/*Contains the last known free cluster count on the volume. If the value is 0xFFFFFFFF, then the free count is unknown and must be computed. However, this value might be incorrect and should at least be range checked (<= volume cluster count)*/
            uint8_t last_known_free_cluster_count[4];
            //[4]/*Indicates the cluster number at which the filesystem driver should start looking for available clusters. If the value is 0xFFFFFFFF, then there is no hint and the driver should start searching at 2. Typically this value is set to the last allocated cluster number. As the previous field, this value should be range checked.*/
            uint8_t start_looking_for_available_clusters[4];
            //[12]/*Reserved*/
            uint8_t Reserved2[12];
            //[4]/*Trail signature (0xAA550000)*/
            uint8_t Trail_signature[4];
        }__attribute__((packed));
        };
    };
};