#include <QtWidgets>

// Пример разделения модели виджета класса QListWidget
// с представлением класса QListView - другими словами, оба виджета смотрят на
// одну и ту же модель данных.

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    // Создается и
    // заполняется элементами данных виджет элементно-ориентированного класса QListWidget:

    QStringList lst;
    QListWidget lwg;
    QListWidgetItem* pitem = nullptr;

    lwg.setIconSize(QSize(48, 48));
    lst << "Linux" << "Windows" << "macOS" << "Android";
    foreach(QString str, lst) {
        pitem = new QListWidgetItem(str, &lwg);
        pitem->setIcon(QPixmap(str + ".png"));
    }
    lwg.setWindowTitle("ListWidget");
    lwg.show();

    // Создание представления списка QListView:

    QListView listView;

    // Для того чтобы иметь возможность показать модель виджета (класса QListWidget), мы вызываем
    // из него метод model() и передаем возвращенный им указатель в метод setModel()
    // объекта listView. Кроме того, разделяем модель выделения при помощи методов
    // selectionМodel() И setSelectionМodel().

    listView.setModel(lwg.model());
    listView.setSelectionModel(lwg.selectionModel());

    listView.setWindowTitle("ListView");
    listView.show();

    return app.exec();
}