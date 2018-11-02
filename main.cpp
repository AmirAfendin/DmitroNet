#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTime>
#include <QDebug>
#include "net.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    qsrand(QTime::currentTime().msec());
    QGuiApplication app(argc, argv);

    QVector<Input> inputs = {Input(1, 0.0f), Input(2, 0.0f),
                              Input(3, 0.0f), Input(4, 0.0f)};

    Net net(inputs);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
