#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "ellipse.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    // Наш класс С++ называется Ellipse, и для того чтобы сделать его доступным в QML, нам
    // необходимо зарегистрировать его в основной программе.
    // Для этого мы вызываем шаблонную глобальную функцию qmlRegister<T>()
    // и типизируем ее нашим классом Ellipse.
    // В первом параметре в эту функцию мы передаем имя для модуля,
    // что обеспечит возможность его включения в QМL-программу.
    // Вторым параметром следует номер
    // версии, третьим - номер уровня версии модуля, в который входит наш элемент.
    // А в последнем, четвертом, параметре мы передаем имя, под которым будет доступен наш элемент
    // в QМL-программе.
    qmlRegisterType<Ellipse>("com.myinc.Ellipse", 1, 0, "Ellipse");

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
