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

void Net::checkResult()
{
    int resultValue = 0;
    for (const Input &input : m_inputs) {
        if (input.activation)
            resultValue += input.value;
    }

    if (resultValue % 2)
        checkMSE(0.0f);
    else
        checkMSE(1.0f);
}

float Net::checkMSE(float i)
{
    float a = m_layers.last().neurons.last().getActivation();
    float mse = qPow((i - a), 2.0f) / float(m_epochs);
    return mse;
}

void Net::calculate()
{
    QVector<float> inputActivations;

    for (const Input &input : m_inputs)
        inputActivations << input.activation;

    for (int i = 0; i < m_layers.count(); ++i) {
        if (i == 0) {
            for (Neuron &neuron : m_layers[i].neurons)
                neuron.activations = inputActivations;
        } else {
            for (Neuron &neuron : m_layers[i].neurons)
                neuron.activations = m_layers[i-1].getActivations();
        }
    }
}

void Net::train()
{
    float actual = m_layers.last().neurons.last().getActivation();
    float expected;

    int resultValue = 0;
    for (const Input &input : m_inputs) {
        if (input.activation)
            resultValue += input.value;
    }

    if (resultValue % 2)
        expected = 0.0f;
    else
        expected = 1.0f;

    float error = actual - expected;
    float gradient = actual * (1 - actual);
    float weights_delta = actual * gradient;

    float weight_1 = m_layers.last().neurons.last().weights.first();
    float weight_2 = m_layers.last().neurons.last().weights.last();

    float output_1 = m_layers[(m_layers.count() - 2)].neurons.first().getActivation();
    float output_2 = m_layers[(m_layers.count() - 2)].neurons.last().getActivation();

    weight_1 = weight_1 - output_1 * weights_delta * m_learningRate;
    weight_2 = weight_2 - output_2 * weights_delta * m_learningRate;

    m_layers.last().neurons.last().weights[0] = weight_1;
    m_layers.last().neurons.last().weights[1] = weight_2;

    for (int i = m_layers.count() - 2; i >= 0; --i) {
        for (int j = 0; j < m_layers[i].neurons.count(); ++j) {
            Neuron &neuron = m_layers[i].neurons[j];
        }
    }
}

void Net::buildLayers()
{
    m_layers.clear();

    for (int i = m_inputs.count() - 1; i > 0; --i)
        m_layers << Layer(i);
}
