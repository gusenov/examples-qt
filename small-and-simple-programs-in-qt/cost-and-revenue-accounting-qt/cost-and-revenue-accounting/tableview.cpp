#include "tableview.h"
#include "indexes.h"

// Конструктор:
TableView::TableView(QWidget *parent):
    QTableView(parent)
{

}

// Переопределение метода нажатия кнопки мыши:
void TableView::mousePressEvent(QMouseEvent *event)
{
    // Если нажата левая кнопка мыши:
    if (event->button() == Qt::LeftButton) {

        // Получаем индекс:
        QModelIndex index = indexAt(event->pos());
        int rowIndex = index.row();  // индекс строки.
        int colIndex = index.column();  // индекс столбца.

        // Если это выбор месяца:
        if (rowIndex == MONTH_ROW_INDEX && colIndex == MONTH_COL_INDEX)
            edit(index);  // то переходим в режим редактирования.

        // Иначе, если это ввод суммы:
        else if (rowIndex > MONTH_ROW_INDEX && colIndex == AMOUNT_VALUE_COL_INDEX
                 && rowIndex < index.model()->rowCount() - 1)
            edit(index);  // то переходим в режим редактирования.

    }

    // Вызов метода базового класса:
    QTableView::mousePressEvent(event);
}
