#pragma once

#include<Sauce/Types.hpp>
#include<Sauce/Memory/DynamicArray.hpp>

namespace Sauce{
    namespace Utility{
        namespace Neural{
            struct Neuron_st{
                double Value,Bias,Weight;
            };
            struct Layer_st{
                Sauce::Memory::List_cl<Neuron_st*> Neurons;
                Layer_st* NextLayer=nullptr;
                Layer_st(size_t Height);
            };
            struct Network_st{
                Sauce::Memory::List_cl<Layer_st*> Layers;
                void AddLayer(size_t Height);
            };
        };
    };
};

