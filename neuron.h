#ifndef NEURON_H
#define NEURON_H

#include <QVector>

class Neuron
{
public:
    Neuron(){};
    Neuron(int weightsCount);

    float getActivation();
    float sigmoid(float x);
    QVector<float> weights;
    QVector<float> activations;
};

#endif // NEURON_H
