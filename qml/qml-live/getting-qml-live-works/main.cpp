#include <QGuiApplication>
#include <QQmlApplicationEngine>
#ifdef QT_DEBUG
#include "qmllive.h"
#endif

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QUrl qmlFile = QUrl(QStringLiteral("qrc:/main.qml"));

    engine.load(qmlFile);

    if (engine.rootObjects().isEmpty())
        return -1;

#ifdef QT_DEBUG
    LiveNodeEngineRunner::GetInstance().Run(engine, qmlFile);
#endif

    return app.exec();
}
