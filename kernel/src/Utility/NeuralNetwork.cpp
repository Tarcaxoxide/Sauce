#include<Sauce/Utility/NeuralNetwork.hpp>
#include<Sauce/Math/Functions.hpp>

namespace Sauce{
    namespace Utility{
        namespace Neural{
            Layer_st::Layer_st(size_t Height){
                for(size_t i=0;i<Height;i++){
                    Neurons.AddLast(new Neuron_st{0,0,0});
                }
            }
            void Network_st::AddLayer(size_t Height){
                Layers.AddLast(new Layer_st(Height));
                if(Layers.Size() > 1){
                    Layers[Layers.Size()-2]->NextLayer=Layers[Layers.Size()-1];
                }
            }
        };
    };
};