#pragma once

#include<stddef.h>
#include<stdint.h>

//namespace Sauce{
//    namespace IO{
//        namespace ACPI{
            typedef struct {
                unsigned char Signature[8];
                uint8_t Checksum;
                uint8_t OEM_ID[6];
                uint8_t Revision;
                uint32_t RSDT_Address;
                uint32_t Length;
                uint64_t XSDT_Address;
                uint8_t ExtendedChecksum;
                uint8_t Reserved[3];
            }RSDP2;
            typedef struct {
                unsigned char Signature[4];
                uint32_t Length;
                uint8_t Revision;
                uint8_t Checksum;
                uint8_t OEM_ID[6];
                uint8_t EOM_Table_ID[8];
                uint32_t OEM_Revision;
                uint32_t Creator_ID;
                uint32_t Creator_Revision;
            }SDTHeader;
            typedef struct {
                SDTHeader Header;
                uint64_t Reserved;
            }MCFGHeader;
//        };
//    };
//};