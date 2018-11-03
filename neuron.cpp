#include "neuron.h"
#include <QDebug>
#include <QtMath>

Neuron::Neuron(int weightsCount)
{
    for (int i = 0; i < weightsCount; ++i) {
        weights << qrand() % (100 + 1) / 100.0f;
    }
}

float Neuron::getActivation()
{
    float sum = 0.0f;

    if (weights.count() != activations.count()) {
        qCritical() << "Weights and activation counts doesn't match";
        return -1;
    }

    for (int i = 0; i < weights.count(); ++i) {
        sum += weights.at(i) * activations.at(i);
    }

    return sigmoid(sum);
}

float Neuron::sigmoid(float x)
{
    return 1 / (1 + qExp(-x));
}
