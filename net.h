#ifndef NET_H
#define NET_H

#include <QObject>
#include "layer.h"

class Net : public QObject
{
    Q_OBJECT
public:
    explicit Net(QObject *parent = nullptr);

signals:

public slots:

private:
    float sigmoid(float x);

    void buildLayers();
    QVector<Layer> m_layers;
};

#endif // NET_H
