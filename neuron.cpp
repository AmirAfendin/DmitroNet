#include "neuron.h"
#include <QDebug>
#include <QtMath>

Neuron::Neuron(int weightsCount)
{
    for (int i = 0; i < weightsCount; ++i) {
        weights << qrand() % (100 + 1) / 100.0f;
    }
}

float Neuron::sigmoid(float x)
{
    return 1 / (1 + qExp(-x));
}
