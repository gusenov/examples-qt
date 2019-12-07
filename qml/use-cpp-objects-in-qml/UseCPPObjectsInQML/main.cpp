#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Calculation.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    // Регистрируем при помощи функции qmlRegisterType<T>() наш класс Calculation.
    // В первом параметре этой функции мы
    // передаем строку, которая задает идентификатор модуля с его именем для включения
    // в QМL-программу.
    // Вторым параметром передаем номер версии,
    // третьим - номер уровня версии.
    // В последнем, четвертом, параметре мы передаем имя элемента.
    qmlRegisterType<Calculation>("com.myinc.Calculation", 1, 0, "Calculation");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
