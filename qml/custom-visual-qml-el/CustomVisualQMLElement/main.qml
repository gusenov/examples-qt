import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.2

// Импортировать элемент Ellipse при помощи директивы import:
import com.myinc.Ellipse 1.0

Window {
    visible: true
    width: 200
    height: 100
    title: qsTr("PaintElement")

    // Добавить элемент Ellipse в элемент основного окна программы:
    Ellipse {
        // Чтобы наш элемент всегда заполнял область основного окна приложения,
        // мы используем фиксатор anchors.fill:
        anchors.fill: parent
        // При изменении размеров окна наш элемент будет автоматически
        // изменять свои размеры и заполнять всю его область.

        // При помощи реализованного свойства
        // color задаем эллипсу голубой цвет:
        color: "blue"
    }
}
