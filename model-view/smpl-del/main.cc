#include "SimpleDelegate.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QStringListModel model;
    model.setStringList(QStringList() << "Item1" << "Item2" << "ItemЗ");

    QListView listView;
    listView.setModel(&model);

    // Вызов метода setItemDelegate() устанавливает
    // в представлении объект созданного нами делегата (класс SimpleDelegate):
    listView.setItemDelegate(new SimpleDelegate(&listView));

    // Для того чтобы представление реагировало на перемещения курсора мыши над ним,
    // необходимо в окне просмотра при помощи метода setAttribute() установить флаг
    // Qt::WA_Hover.
    listView.viewport()->setAttribute(Qt::WA_Hover);

    listView.show();

    app.exec();
}