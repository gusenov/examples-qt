import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 360
    height: 360
    title: qsTr("Фиксация с перекрытием элемента")

    Rectangle {
        id: redrect
        color: "red"

        // Присваиваем размеры (свойства width и height) таким образом, чтобы он
        // не занимал полностью всю площадь окна.
        width: parent.width / 1.5
        height: parent.height / 1.5

        anchors.top: parent.top
        anchors.left: parent.left
    }

    Rectangle {
        // Чтобы видеть область перекрытия, второй прямоугольник
        // делаем полупрозрачным (свойство opacity) и присваиваем ему зеленый цвет.
        opacity: 0.5
        color: "green"

        // Связываем его вершину (свойство top) с вертикальным центром (свойство verticalCenter)
        // красного прямоугольника:
        anchors.top: redrect.verticalCenter

        // Его низ (свойство bottom) связываем с низом элемента родителя:
        anchors.bottom: parent.bottom

        // Левую границу (свойство left) связываем с горизонтальным центром (свойство
        // horizontalCenter) красного прямоугольника:
        anchors.left: redrect.horizontalCenter

        // А правую границу (свойство right) - с правой границей элемента родителя:
        anchors.right: parent.right
    }
}
