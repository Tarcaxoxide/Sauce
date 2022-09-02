#include<Sauce/Utility/NeuralNetwork.hpp>
#include<Sauce/Math/Functions.hpp>

namespace Sauce{
    namespace Utility{
        namespace Neural{
            void Neuron_st::Insert(double insertedValue){
                for(size_t Ai=0;Ai<MyLayer->NextLayer->Neurons.Size();Ai++){
                    size_t ConnectionWeight = Sauce::Math::difference(Weight,MyLayer->NextLayer->Neurons[Ai]->Weight);
                    //ActivationFunction?
                }
            
            }
            Layer_st::Layer_st(size_t Height){
                for(size_t i=0;i<Height;i++){
                    Neurons.AddLast(new Neuron_st{0,0,0});
                    Neurons.Last()->MyLayer=this;
                    Neurons.Last()->Bias=((double)Sauce::Math::random_get(100)/(double)100.00);
                    Neurons.Last()->Weight=((double)Sauce::Math::random_get(100)/(double)100.00);
                    Neurons.Last()->Value=((double)Sauce::Math::random_get(100)/(double)100.00);
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