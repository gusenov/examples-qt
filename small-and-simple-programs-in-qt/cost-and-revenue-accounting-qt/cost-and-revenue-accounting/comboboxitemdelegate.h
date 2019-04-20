#ifndef COMBOBOXITEMDELEGATE_H
#define COMBOBOXITEMDELEGATE_H

#include <QStyledItemDelegate>

// Класс для выбора месяца в таблице:
class ComboBoxItemDelegate : public QStyledItemDelegate  // унаследован от класса QStyledItemDelegate.
{
    // Q_OBJECT - этот макрос обязателен для любого класса на Си++,
    // в котором планируется описать сигналы и/или слоты:
    Q_OBJECT

// Публичные члены класса:
public:

    // Конструктор:
    ComboBoxItemDelegate(QObject *parent = nullptr);

    // Перегрузка методов класса QStyledItemDelegate:

    // Метод создания выпадающего списка для выбора месяца:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    // Метод для установки текущего значения в выпадающем списке:
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;

    // Метод для запоминания выбранного в выпадающем списке значения:
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

    // Обработчик событий в выпадающем списке:
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);

};

#endif // COMBOBOXITEMDELEGATE_H
