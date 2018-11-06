#include "net.h"
#include <QDebug>
#include <QtMath>

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
            qDebug() << "Neuron №" << QString::number(j)
                     << "activations:" << m_layers[i].neurons[j].activations
                     << "weights:" << m_layers[i].neurons[j].weights
                     << "\n";
        }
    }

//    qDebug() << "Right?: " << checkResult();

    qDebug() << "=========================================";
}

void Net::calculate()
{
    int resultValue = 0;
    for (const Input &input : m_inputs) {
        if (input.activation)
            resultValue += input.value;
    }

    if (resultValue % 2)
        checkResult(0.0f);
    else
        checkResult(1.0f);
}

float Net::checkResult(float i)
{
    float a = m_layers.last().neurons.last().getActivation();
    float mse = qPow((i - a), 2.0f) / float(m_epochs);
    return mse;
}

void Net::buildLayers()
{
    m_layers.clear();

    for (int i = m_inputs.count() - 1; i > 0; --i)
        m_layers << Layer(i);
}
