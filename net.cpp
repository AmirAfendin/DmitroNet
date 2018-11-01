#include "net.h"
#include <QtMath>

Net::Net(QObject *parent) : QObject(parent)
{

}

float Net::sigmoid(float x)
{
    return 1 / (1 + qExp(-x));
}
