import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 360
    height: 160
    title: qsTr("Row")

    Row {
        // Фиксируем сам элемент размещения с центром окна (свойство centerIn):
        anchors.centerIn: parent

        // Задаем расстояние между элементами, равное 1О пикселам:
        spacing: 10

        // Внутри элемента
        // горизонтального размещения Row определяем три элемента прямоугольников красного,
        // голубого и зеленого цветов с размерами 64х64 пиксела:

        Rectangle {
            width: 64; height: 64; color: "red"
        }

        Rectangle {
            width: 64; height: 64; color: "blue"
        }

        Rectangle {
            width: 64; height: 64; color: "green"
        }
    }
}
