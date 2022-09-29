#include<Sauce/Storage/ATA.hpp>

namespace Sauce{
    namespace Storage{
        ATADriver_cl::ATADriver_cl(uint16_t portBase,bool master){
            ATACommandData.Port.data=portBase;
            ATACommandData.Port.error=portBase+1;
            ATACommandData.Port.sectorCount=portBase+2;
            ATACommandData.Port.lbaLow=portBase+3;
            ATACommandData.Port.lbaMid=portBase+4;
            ATACommandData.Port.lbaHigh=portBase+5;
            ATACommandData.Port.device=portBase+6;
            ATACommandData.Port.command=portBase+7;
            ATACommandData.Port.control=portBase+0x206;
            ATACommandData.bytesPerSector=512;
            ATACommandData.master=master;
        }
        void ATADriver_cl::Identify(){}
        void ATADriver_cl::Read28(uint32_t sector){}
        void ATADriver_cl::Write28(uint32_t sector,uint8_t* data,int count){}
        void ATADriver_cl::Flush(){}
    };
};