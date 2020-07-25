import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 360
    height: 60
    title: qsTr("Контроль размеров среднего элемента")

    // Когда мы задаем вертикальные или горизонтальные расположения с помощью фиксаторов,
    // то можем контролировать размеры элементов, которые находятся между элементами.

    // 3 элемента прямоугольников: красного, желтого и зеленого цветов.
    // У двух крайних ширина задана постоянной, ширина же
    // среднего элемента высчитывается на основании левой и правой границ соседних элементов.

    Rectangle {
        id: redrect
        color: "red"
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width: 60
    }

    Rectangle {
        color: "yellow"
        anchors.top: parent.top
        anchors.bottom: parent.bottom

        // Связывание свойств желтого прямоугольника left и right со свойствами right
        // красного прямоугольника и left зеленого прямоугольника соответственно:
        anchors.left: redrect.right
        anchors.right: greenrect.left
        // Тем самым желтый
        // прямоугольник полностью заполняет пространство между этими прямоугольниками,
        // и изменение размеров окна приведет только к увеличению либо к уменьшению ширины
        // желтого прямоугольника.
    }

    Rectangle {
        id: greenrect
        color: "green"
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width: 100
    }
}
