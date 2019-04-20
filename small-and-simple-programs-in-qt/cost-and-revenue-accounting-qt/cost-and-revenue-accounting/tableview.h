#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QTableView>
#include <QMouseEvent>


// Класс таблицы:
class TableView : public QTableView  // унаследован от класса QTableView.
{

// Публичные члены класса:
public:

    // Конструктор:
    TableView(QWidget *parent = nullptr);

    // Переопределение метода нажатия кнопки мыши:
    void mousePressEvent(QMouseEvent *event);
};

#endif // TABLEVIEW_H
