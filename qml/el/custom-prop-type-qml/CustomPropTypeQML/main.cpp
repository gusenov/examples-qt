#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "myclass.h"
#include "otherclass.h"
#include "integer64.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<MyClass>("com.example", 1, 0, "MyClass");
    qmlRegisterType<OtherClass>("com.example", 1, 0, "OtherClass");
    qmlRegisterType<Integer64>("MyModules", 1, 0, "Integer64");


    // Без qRegisterMetaType ошибка: Cannot assign to property of unknown type "".
    // С qRegisterMetaType ошибка:   Cannot assign to property of unknown type "Integer64".
     qRegisterMetaType<Integer64>();
//    /Qt5.14.2/5.14.2/clang_64/lib/QtCore.framework/Headers/qmetatype.h:1882: error: static_assert failed due to requirement 'bool(QMetaTypeId2<Integer64>::Defined)' "Type is not registered, please use the Q_DECLARE_METATYPE macro to make it known to Qt's meta-object system"
//        Q_STATIC_ASSERT_X(QMetaTypeId2<T>::Defined, "Type is not registered, please use the Q_DECLARE_METATYPE macro to make it known to Qt's meta-object system");
     // Нужно добавлять Q_DECLARE_METATYPE.

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
