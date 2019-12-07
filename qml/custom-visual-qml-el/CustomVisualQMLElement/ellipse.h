#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QQuickPaintedItem>
class QPainter;

// Наш новый класс Ellipse будет унаследован от класса QQuickPaintedItem:
class Ellipse : public QQuickPaintedItem
{
    Q_OBJECT
private:

    // Для установки
    // цвета, заполняющего площадь эллипса, мы добавим свойство color при
    // помощи макроса Q_PROPERTY. Этому свойству мы предоставим возможности чтения и записи
    // значений (WRITE и READ): чтение обеспечит метод colorValue(), а запись - метод
    // setColorValue().
    Q_PROPERTY(QColor color WRITE setColorValue
               READ colorValue )

    QColor m_color;
public:
    Ellipse(QQuickItem* pqi = nullptr);

    // Метод paint() отвечает за рисование элемента и вызывается всякий раз,
    // когда его требуется перерисовать снова, - это может потребоваться, например,
    // при изменениях размеров элемента. Этот метод можно грубо сравнить с методом события рисования
    // QWidget::paintEvent() с той лишь разницей, что он получает не указатель на объект события QPaintEvent,
    // а указатель на сам объект рисования QPainter, так что создавать отдельный объект QPainter нам не придется.
    void paint(QPainter* ppainter);

    QColor colorValue() const;
    void setColorValue(const QColor&);

signals:

public slots:
};

#endif // ELLIPSE_H
