// Использование интерфейса модели
// QStandardItemModel для создания и отображения иерархии.
// Приведенный пример не является хорошим образцом манипуляции с данными, но дает
// представление о том, как выполнять заполнение данными модели QStandardItemМodel.

#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication арр(argc, argv);

    // Сначала необходимо создать объект класса QStandardItemМodel.
    // Создаем модель, представляющую собой таблицу из пяти строк и трех столбцов.
    QStandardItemModel model(5, 3);

    for (int nTopRow = 0; nTopRow < 5; ++nTopRow ) {
        // В цикле получаем текущий индекс с помощью метода
        // index() и задаем данные для элемента.

        QModelIndex index = model.index(nTopRow, 0);

        // Методом setData() установить данные для каждого элемента.
        // Впоследствии эти данные можно будет получать методом data().
        model.setData(index, "item" + QString::number(nTopRow + 1));

        // Каждая ячейка в таблице может иметь дочерние таблицы.
        // И думая об иерархиях, мы должны не забыть об иерархиях таблиц.

        // Затем вставляем по текущему индексу подтаблицу
        // с четырьмя строками и тремя столбцами при помощи методов insertRows() и
        // insertColumns().

        model.insertRows(0, 4, index);
        model.insertColumns(0, 3, index);

        // Во вложенных циклах вызовом метода setData() ячейки подтаблицы одна
        // за другой заполняются данными.
        for (int nRow = 0 ; nRow < 4; ++nRow) {
            for (int nCol = 0; nCol < 3; ++nCol ) {
                QString strPos = QString("%1,%2").arg(nRow).arg(nCol);
                model.setData(model.index(nRow, nCol, index), strPos);
            }
        }
    }

    QTreeView treeView;
    treeView.setModel(&model);
    treeView.show();

    return арр.exec();
}