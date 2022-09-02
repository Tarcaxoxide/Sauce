#include<Sauce/Utility/NeuralNetwork.hpp>
#include<Sauce/Math/Functions.hpp>

namespace Sauce{
    namespace Utility{
        namespace Neural{
            Network_st::Network_st(size_t EntryNeuronCount,size_t MeshNeuronCount,size_t MeshDensity,size_t ExitNeuronCount){
                //populate the layers.
                for(size_t i=0;i<EntryNeuronCount;i++){
                    EntryNeurons.AddLast(new Neuron_st);
                }
                for(size_t i=0;i<MeshNeuronCount;i++){
                    MeshNeurons.AddLast(new Neuron_st);
                }
                for(size_t i=0;i<ExitNeuronCount;i++){
                    ExitNeurons.AddLast(new Neuron_st);
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
                        MeshNeurons[Ai]->Connections.AddLast(MeshNeurons[Sauce::Math::random_get(MeshNeuronCount)-1]);
                    }
                }
            }
        };
    };
};