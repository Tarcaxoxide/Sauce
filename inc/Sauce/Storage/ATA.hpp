#pragma once

#include<Sauce/Types.hpp>

namespace Sauce{
    namespace Storage{
        struct ATACommandData_st{
            struct Port_st{
                uint8_t data;
                uint8_t error;
                uint8_t sectorCount;
                uint8_t lbaLow;
                uint8_t lbaMid;
                uint8_t lbaHigh;
                uint8_t device;
                uint8_t command;
                uint8_t control;
            }Port;
            bool master;
            uint16_t bytesPerSector;
        };

        class ATADriver_cl{
            protected:
                ATACommandData_st ATACommandData;
            public:
                ATADriver_cl(uint16_t portBase,bool master);
                void Identify();
                void Read28(uint32_t sector);
                void Write28(uint32_t sector,uint8_t* data,int count);
                void Flush();
        };
    };
};