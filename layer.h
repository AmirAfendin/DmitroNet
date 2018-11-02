#ifndef LAYER_H
#define LAYER_H

#include "neuron.h"

class Layer
{
public:
    Layer(){};
    Layer(int neuronCount);

    QVector<Neuron> neurons;
};

#endif // LAYER_H
