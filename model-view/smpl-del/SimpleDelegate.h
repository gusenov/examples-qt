//
// Created by Abbas Gussenov on 2020-02-11.
//

#ifndef SimpleDelegate_h
#define SimpleDelegate_h

#include <QtWidgets>

// Простой пример делегата, который выделяет элемент, как
// только пользователь проведет над ним курсор (указатель) мыши:
class SimpleDelegate : public QStyledItemDelegate {
public:
    SimpleDelegate(QObject* pobj = nullptr) : QStyledItemDelegate(pobj)
    {
    }

    void paint(QPainter* pPainter,  // указатель на объект класса
               const QStyleOptionViewItem& option,  // ссылка на структуру QStyleOptionViewItem, определенную в классе QStyle
               const QModelIndex& index) const  // модельный индекс
    {
        // Для перерисовки элемента каждый раз,
        // когда пользователь проведет над ним мышь, мы просто проверяем флаги состояния установленных
        // битов объекта структуры option, чтобы определить, находится ли мышь на элементе
        // или нет. Если биты флага QStyle::State_MouseOver установлены, это значит, что курсор
        // мыши находится над элементом, и в этом случае его фон рисуется при помощи линейного
        // градиента.
        if (option.state & QStyle::State_MouseOver) {
            QRect rect = option.rect;
            QLinearGradient gradient(0, 0, rect.width(), rect.height());
            gradient.setColorAt(0, Qt::white);
            gradient.setColorAt(0.5, Qt::blue);
            gradient.setColorAt(1, Qt::green);
            pPainter->setBrush(gradient);
            pPainter->drawRect(rect);
        }

        QStyledItemDelegate::paint(pPainter, option, index);
    }

    // Перегрузив метод
    // sizeHint(), мы можем управлять величиной области каждого элемента - в нашем примере
    // мы делегируем ширину по умолчанию из объекта класса QStyleOptionViewItem, а высоту
    // устанавливаем равной 55 пикселам.
    QSize sizeHint(const QStyleOptionViewItem& option,
                   const QModelIndex& /*index*/) const {
        return QSize(option.rect.width(), 55);
    }

    // Если бы мы захотели изменить стандартный способ редактирования, то нам пришлось бы
    // реализовать в унаследованном классе методы createEditor(), setEditorData() и
    // setModelData(). Метод createEditor() создает виджет для редактирования. Метод
    // setEditorData() устанавливает данные в виджете редактирования. Метод setModelData()
    // извлекает данные из виджета редактирования и передает их модели.
};

#endif /* SimpleDelegate_h */
