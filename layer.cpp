#include "layer.h"

Layer::Layer(int neuronCount)
{
    for (int i = 0; i < neuronCount; ++i) {
        neurons << Neuron(neuronCount+1);
    }
}

QVector<float> Layer::getActivations()
{
    QVector<float> activaons;

    for (Neuron &neuron : neurons) {
        activaons << neuron.getActivation();
    }

    return activaons;
}

