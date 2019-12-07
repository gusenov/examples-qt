#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "cppconnect.h"

int main(int argc, char *argv[])
{
    // Cоздаем объект с именем cc от класса CppConnection,
    // который предназначен дпя соединения с QМL-элементами:
    CppConnection cc;




    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    // Классы QQmlApplicationEngine и QQmlComponent дают эквивалентные возможности для показа
    // QМL-элементов и получения доступа к ним, как к объектам класса QObject.
    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url, &cc](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);




        {   // Соединяем QМL-сигналы со слотами С++:

            // Указатель на узловой элемент в виде объекта класса QObject:
            QObject* pobj = obj;

            // Получаем указатели на элементы двух кнопок: pcmdQuitButton
            // и pcmdInfoButton:

            QObject* pcmdQuitButton = pobj->findChild<QObject*>("QuitButton");

            if (pcmdQuitButton) {
                // Используем привычные методы QObject::connect()
                // и соединяем сигналы элементов кнопок со слотами объекта cc:
                QObject::connect(pcmdQuitButton, SIGNAL(quitClicked()),
                &cc, SLOT(slotQuit()));
            }

            QObject* pcmdInfoButton = pobj->findChild<QObject*>("InfoButton");
            if (pcmdInfoButton) {
                QObject::connect(pcmdInfoButton, SIGNAL(infoClicked(QString) ),
                &cc, SLOT(slotInfo(QString)));
            }
        }




    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
