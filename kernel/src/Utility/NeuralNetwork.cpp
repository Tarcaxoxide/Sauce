#include<Sauce/Utility/NeuralNetwork.hpp>
#include<Sauce/Math/Functions.hpp>
//debugging
#include<Sauce/IO/Debug/Console.hpp>
#include<Sauce/Utility/Conversion.hpp>

namespace Sauce{
    namespace Utility{
        namespace Neural{
            void Neuron_st::Poke(Sauce::IO::Debug::Debugger_st* pDebugger){
                Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Neuron_st::Poke",_NAMESPACE_);
                if(Connections.Size())Connections[Sauce::Math::random_get(&Debugger,Connections.Size())]->Poke(&Debugger);
            }
            Network_st::Network_st(Sauce::IO::Debug::Debugger_st* pDebugger,size_t EntryNeuronCount,size_t MeshNeuronCount,size_t MeshDensity,size_t ExitNeuronCount){
                Sauce::IO::Debug::Debugger_st Debugger(pDebugger,"Network_st::Network_st",_NAMESPACE_);
                //populate the layers.
                size_t debugId=0;
                for(size_t i=0;i<EntryNeuronCount;i++){
                    EntryNeurons.AddLast(new Neuron_st);
                    EntryNeurons.Last()->Value=debugId++;
                }
                for(size_t i=0;i<MeshNeuronCount;i++){
                    MeshNeurons.AddLast(new Neuron_st);
                    MeshNeurons.Last()->Value=debugId++;
                }
                for(size_t i=0;i<ExitNeuronCount;i++){
                    ExitNeurons.AddLast(new Neuron_st);
                    ExitNeurons.Last()->Value=debugId++;
                }
                //create the entrence/exit node connections.
                for(size_t Ai=0;Ai<EntryNeuronCount;Ai++){
                    for(size_t Bi=0;Bi<MeshNeuronCount;Bi++){
                        EntryNeurons[Ai]->Connections.AddLast(MeshNeurons[Bi]);
                    }
                }
                for(size_t Ai=0;Ai<ExitNeuronCount;Ai++){
                    for(size_t Bi=0;Bi<MeshNeuronCount;Bi++){
                        MeshNeurons[Bi]->Connections.AddLast(ExitNeurons[Ai]);
                    }
                }
                //create the mesh inside the mesh layer.
                for(size_t Ai=0;Ai<MeshNeuronCount;Ai++){
                    for(size_t Bi=0;Bi<MeshDensity;Bi++){
                        MeshNeurons[Ai]->Connections.AddLast(MeshNeurons[Sauce::Math::random_get(&Debugger,MeshNeuronCount)]);
                    }
                }
            }
        };
    };
};