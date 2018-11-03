#ifndef NET_H
#define NET_H

#include <QObject>
#include "layer.h"
#include "input.h"

class Net : public QObject
{
    Q_OBJECT
public:
    explicit Net(QVector<Input> inputs, QObject *parent = nullptr);

signals:

public slots:
    void dumpInfo();
    void calculate();
    float checkResult(int ideal, int epoch);

    int m_epochs = 5000;
    float m_learningRate = 0.05f;

private:
    void buildLayers();
    QVector<Layer> m_layers;
    QVector<Input> m_inputs;
};

#endif // NET_H
