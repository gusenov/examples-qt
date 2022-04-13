#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "phonemodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;




    PhoneModel model;  // создаём один объект нашей модели.
    model.addContact(Contact("Mr. User 1", "123-45-67", 29));  // добавляем первый контакт.
    model.addContact(Contact("Ms. User 2", "890-12-34", 92));  // добавляем второй контакт.
    QQmlContext *ctxt = engine.rootContext(); // получаем контекст QML
    ctxt->setContextProperty("myModel", &model); // и передаём в него нашу модель с именем myModel




    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
