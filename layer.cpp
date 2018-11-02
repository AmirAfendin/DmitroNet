#include "layer.h"

Layer::Layer(int neuronCount)
{
    for (int i = 0; i < neuronCount; ++i) {
        neurons << Neuron(neuronCount+1);
    }
}
