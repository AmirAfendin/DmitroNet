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

private:
    void buildLayers();
    QVector<Layer> m_layers;
    QVector<Input> m_inputs;
};

#endif // NET_H
