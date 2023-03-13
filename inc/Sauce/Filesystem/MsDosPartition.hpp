#ifndef __Sauce_Filesystem_MsDosPartition
#define __Sauce_Filesystem_MsDosPartition
#include<stddef.h>
#include<stdint.h>
namespace Sauce{
	namespace Filesystem{
		namespace MsDosPartition{
			struct PartitionTableEntry_st{
				uint8_t BootableFlag;//1
				uint8_t StartHead;//2
				uint8_t StartSector: 6;
				uint16_t StartCylinder:10;//4
				uint8_t PartitionId;//5
				uint8_t EndHead;//5
				uint8_t EndSector: 6;
				uint16_t EndCylinder:10;//7
				uint32_t LbaStart;//11
				uint32_t LbaLength;//15
			}__attribute__((packed));
			struct MasterBootRecord_st{
				uint8_t Bootloader[440];
				uint32_t Signature;
				uint16_t unused;
				PartitionTableEntry_st PrimaryPartitionTableEntries[4];
				uint16_t MagicNumber;
			}__attribute__((packed));
			class MsDosPartition_cl{
				protected:
				MasterBootRecord_st MasterBootRecord;
				size_t PortNumber;
				public:
				MsDosPartition_cl(size_t portNumber);
			};
		};
	};
};
#endif