#ifndef NEURON_H
#define NEURON_H

#include <QVector>

class Neuron
{
public:
    Neuron(int weightsCount);

private:
    QVector<float> m_weights;
};

#endif // NEURON_H
