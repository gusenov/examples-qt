#include <QtWidgets>
#include "IntListModel.h"

int main( int argc, char** argv ) {
    QApplication арр( argc, argv );

    // При создании объекта модели мы в конструктор передаем список из
    // пяти чисел:
    IntListModel model(QList<int>() << 123 << 2341 << 32 << 5342 << 723);

    // Устанавливаем созданную модель в двух представлениях, вызывая метод
    // setModel():

    QListView list;
    list.setModel(&model);
    list.show();

    QTableView table;
    table.setModel(&model);
    table.show();

    return арр.exec();
}