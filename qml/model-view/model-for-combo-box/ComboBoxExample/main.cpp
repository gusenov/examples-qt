#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "testmodel.h"

void createTestModel(QQmlApplicationEngine& engine)
{
    static TestModel tstMdl;
    QQmlContext *ctx = engine.rootContext();
    ctx->setContextProperty("tstMdl", &tstMdl);
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    createTestModel(engine);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
