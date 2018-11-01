#ifndef LAYER_H
#define LAYER_H

#include "neuron.h"

class Layer
{
public:
    Layer();

private:
    QVector<Neuron> m_neurons;
};

#endif // LAYER_H
