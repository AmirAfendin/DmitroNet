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

    Net net({1, 2, 3, 4});
    net.calculate();
    net.dumpInfo();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
