#include "neuron.h"
#include <QDebug>

Neuron::Neuron(int weightsCount)
{
    for (int i = 0; i < weightsCount; ++i) {
        m_weights << qrand() % (100 + 1) / 100.0f;
    }

    qDebug() << m_weights;
}
