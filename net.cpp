#include "net.h"
#include <QDebug>

Net::Net(QVector<Input> inputs, QObject *parent)
    : QObject(parent)
{
    m_inputs = inputs;
    buildLayers();
}

void Net::dumpInfo()
{
    for (const Input &input : m_inputs) {
        qDebug() << "Input value:" << input.value
                 << "Input activation:" << input.activation
                 << "\n";
    }

    for (int i = 0; i < m_layers.count(); ++i) {
        qDebug() << "Layer №" << QString::number(i);
        for (int j = 0; j < m_layers[i].neurons.count(); ++j) {
            qDebug() << "Hiden №" << QString::number(j)
                     << "activations:" << m_layers[i].neurons[j].activations
                     << "weights:" << m_layers[i].neurons[j].weights
                     << "\n";
        }
    }

    qDebug() << "Right?: " << checkResult();

    qDebug() << "=========================================";
}

void Net::buildLayers()
{
    m_layers.clear();

    for (int i = 0; i < m_inputs.count() - 1; ++i)
        m_layers << Layer(i);
}
