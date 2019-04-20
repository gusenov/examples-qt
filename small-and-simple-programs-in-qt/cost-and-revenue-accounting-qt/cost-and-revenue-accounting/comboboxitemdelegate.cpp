#include "comboboxitemdelegate.h"
#include <QComboBox>
#include <QDebug>
#include <QEvent>
#include <QMouseEvent>
#include <QAbstractItemView>

// Конструктор:
ComboBoxItemDelegate::ComboBoxItemDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

// Метод создания выпадающего списка для выбора месяца:
QWidget *ComboBoxItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // Неиспользуемые параметры:
    Q_UNUSED(option);
    Q_UNUSED(index);

    // Создание и заполнение выпадающего списка:

    QComboBox *cb = new QComboBox(parent);

    cb->addItem("Январь");
    cb->addItem("Февраль");
    cb->addItem("Март");
    cb->addItem("Апрель");
    cb->addItem("Май");
    cb->addItem("Июнь");
    cb->addItem("Июль");
    cb->addItem("Август");
    cb->addItem("Сентябрь");
    cb->addItem("Октябрь");
    cb->addItem("Ноябрь");
    cb->addItem("Декабрь");

    return cb;
}

// Метод для установки текущего значения в выпадающем списке:
void ComboBoxItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    // Получаем выпадающий список:
    QComboBox *cb = qobject_cast<QComboBox *>(editor);
    Q_ASSERT(cb);  // убеждаемся, что он не пустой.

    // Получаем текущее значение для выпадающего списка:
    const QString currentText = index.data(Qt::DisplayRole).toString();

    // Находим его в выпадающем списке:
    const int cbIndex = cb->findText(currentText);

    // Если нашли:
    if (cbIndex >= 0)
       cb->setCurrentIndex(cbIndex);  // то выбираем.

    cb->showPopup();  // раскрываем выпадающий список.
}

// Метод для запоминания выбранного в выпадающем списке значения:
void ComboBoxItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    // Получаем выпадающий список:
    QComboBox *cb = qobject_cast<QComboBox *>(editor);
    Q_ASSERT(cb);  // убеждаемся, что он не пустой.

    // Сохраняем данные из выпадающиего списка в модели:
    model->setData(index, cb->currentText(), Qt::EditRole);
}

// Обработчик событий в выпадающем списке:
bool ComboBoxItemDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonRelease)
    {
        QMouseEvent* pME = static_cast<QMouseEvent*>(event);
        if(pME->button() == Qt::LeftButton)
        {
            QAbstractItemView* pView = qobject_cast<QAbstractItemView*>( const_cast<QWidget*>(option.widget) );
            if(pView != nullptr)
            {
//                qDebug() << pView;
            }
            return true;
        }
    }
    return QStyledItemDelegate::editorEvent(event, model, option, index);
}
