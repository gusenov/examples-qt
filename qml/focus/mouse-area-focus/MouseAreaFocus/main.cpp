#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QLoggingCategory>
#include "myquickitem.h"
#include "myquickview.h"
#include "shortcutlistener.h"

static QObject *shortcutListenerInstance(QQmlEngine *, QJSEngine *engine)
{
    auto ptr = new ShortcutListener(engine);
    ptr->setObjectName("Singleton QML ShortcutListener");
    return ptr;
}

int main(int argc, char *argv[])
{
    QLoggingCategory::setFilterRules(""
//        "qt.quick.focus = true\n"  // To find out how an item got focus
    );

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<MyQuickItem>("myquickitem", 1, 0, "MyQuickItem");
    qmlRegisterType<MyQuickView>("myquickview", 1, 0, "MyQuickView");

    qmlRegisterSingletonType<ShortcutListener>("App", 1, 0, "ShortcutListener", shortcutListenerInstance);

    QQmlApplicationEngine engine;

    ShortcutListener shortcutListener(&engine);
    shortcutListener.setObjectName("App wide ShortcutListener");
    shortcutListener.listenTo(qApp);

    const QUrl url(QStringLiteral("qrc:/init.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
