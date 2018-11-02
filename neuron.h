#ifndef NEURON_H
#define NEURON_H

#include <QVector>

class Neuron
{
public:
    Neuron(){};
    Neuron(int weightsCount);

    float sigmoid(float x);
    QVector<float> weights;
    QVector<float> factors;
};

#endif // NEURON_H
