#include "widget.h"

#include <QQuickWidget>
#include <QVBoxLayout>
#include <QStringListModel>
#include <QQmlContext>
#include <QMessageBox>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    QQuickWidget* pv = new QQuickWidget;
    // NOTE: Класс QQuickWidget содержит также и объект класса QQmlEngine, который предоставляет
    // среду для QМL-компонентов и является сердцевиной для исполнения QМL-кода. Доступ
    // к нему можно получить вызовом метода engine() .

    pv->setSource(QUrl("qrc:/main.qml"));
    QVBoxLayout* pvbx = new QVBoxLayout;
    pvbx->addWidget(pv);
    setLayout(pvbx);

    // Чтобы получить
    // доступ к объекту этого класса, нужно из объекта класса QQuickWidget вызвать метод
    // rootContext(), который возвращает указатель на корневой контекст:
    QQmlContext* pcon = pv->rootContext();
    // Используя этот указатель, вы можете в дерево контекста ввести новые объекты классов,
    // унаследованных от класса QObject.

    QStringList lst;
    for (int i = 0; i < 100; ++i) {
        lst << "Item" + QString::number(i);
    }
    QStringListModel* pmodel = new QStringListModel(this);
    pmodel->setStringList(lst);

    // Публикация объектов в контексте осуществляется с помощью метода
    // setContextProperty(). Этот метод принимает два аргумента. Первый аргумент - это имя,
    // под которым объект будет доступен в QML, второй аргумент - это адрес на сам объект.
    // Если вы проделаете эту операцию, то свойства класса QObject станут свойствами QML, а
    // слоты и методы, декларированные с помощью макроса Q_INVOКAВLE, станут методами,
    // которые могут вызываться из вашего нового QМL-элемента.

    pcon->setContextProperty("myModel", pmodel);
    pcon->setContextProperty("myText", "It's my text!");
    pcon->setContextProperty("myColor", QColor(Qt::yellow));
    pcon->setContextProperty("myWidget", this);
}

MyWidget::~MyWidget()
{

}

void MyWidget::slotDisplayDialog()
{
    QMessageBox::information(nullptr, "Message", "It's my message");
}
