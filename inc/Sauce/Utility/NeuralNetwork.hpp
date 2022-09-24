#pragma once

#include<Sauce/Types.hpp>
#include<Sauce/Memory/DynamicArray.hpp>
#include<Sauce/IO/Debug/Debug.hpp>

namespace Sauce{
    namespace Utility{
        namespace Neural{
            struct Neuron_st{
                Sauce::Memory::List_cl<Neuron_st*> Connections;
                double Value;
                void Poke(Sauce::IO::Debug::Debugger_st* pDebugger);
            };
            
            struct Network_st{
                Sauce::Memory::List_cl<Neuron_st*> EntryNeurons;
                Sauce::Memory::List_cl<Neuron_st*> MeshNeurons;
                Sauce::Memory::List_cl<Neuron_st*> ExitNeurons;
                Network_st(Sauce::IO::Debug::Debugger_st* pDebugger,size_t EntryNeuronCount,size_t MeshNeuronCount,size_t MeshDensity,size_t ExitNeuronCount);
            };
        };
    };
};

