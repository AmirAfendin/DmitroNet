#ifndef NET_H
#define NET_H

#include <QObject>
#include "layer.h"

class Net : public QObject
{
    Q_OBJECT
public:
    explicit Net(QVector<int> values, QObject *parent = nullptr);

signals:

public slots:
    void dumpInfo();
    void checkResult();
    float checkMSE(float ideal);
    void calculate();
    void train();

private:
    void buildLayers();
    QVector<Layer> m_layers;
    QVector<bool> m_inputs;
    QVector<int> m_values;
    int m_epochs = 5000;
    float m_learningRate = 0.05f;
};

#endif // NET_H
