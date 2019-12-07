#include "ellipse.h"
#include <QPainter>

// ----------------------------------------------------------------------
Ellipse::Ellipse(QQuickItem* pqi /*=О*/): QQuickPaintedItem(pqi),
    m_color (Qt::black)  // инициализируем значение атрибута
                         // цвета m_color черным цветом Qt::Ыасk.
{
}

// ----------------------------------------------------------------------
void Ellipse::paint(QPainter* ppainter)
{
    // Устанавливаем режим сглаживания вызовом метода setRenderHint():
    ppainter->setRenderHint(QPainter::Antialiasing, true);

    // Устанавливаем в объекте кисти QBrush
    // значение цвета заполнения в соответствии с его текущим значением, которое возвращает
    // метод colorValue():
    ppainter->setBrush(QBrush(colorValue()));

    // Для того чтобы не отображалась контурная линия, мы присваиваем
    // в методе setPen() нулевой объект пера Qt::NoPen.
    ppainter->setPen(Qt::NoPen);

    // Вызов метода отображения эллипса -
    // его размеры устанавливаются вызовом метода boundingRect(),
    // который управляется из QML свойствами х, у, width и height.
    ppainter->drawEllipse(boundingRect());
}




// Методы setColorValue() и colorValue() прикреплены к свойству color -
// они отвечают за установку и возвращение значения цвета, хранящегося в атрибуте m_color.

// ----------------------------------------------------------------------
QColor Ellipse::colorValue() const
{
    return m_color;
}

// ----------------------------------------------------------------------
void Ellipse::setColorValue(const QColor& col)
{
    m_color = col;
}
