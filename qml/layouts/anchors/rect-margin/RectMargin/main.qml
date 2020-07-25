import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 360
    height: 180
    title: qsTr("Отступы с четырех сторон")

    Rectangle {
        color: "red"
        anchors {
            // Ограничиваем правую границу красного прямоугольника серединой окна
            // (свойство right), в остальном его размеры соответствуют размерам основного окна.
            right: parent.horizontalCenter
            left: parent.left
            top: parent.top
            bottom: parent.bottom

            // При помощи свойств leftMargin, topMargin, rightMargin и bottomМargin задаем одинаковые
            // отступы, равные пяти пикселам.
            leftMargin: 5
            topMargin: 5
            rightMargin: 5
            bottomMargin: 5
        }
    }

    Rectangle {
        color: "green"
        anchors {
            // Ограничиваем левую границу серединой основного окна и со всех сторон
            // отступаем на 20 пикселов.
            left: parent.horizontalCenter
            right: parent.right
            top: parent.top
            bottom: parent.bottom
            leftMargin: 20
            topMargin: 20
            rightMargin: 20
            bottomMargin: 20
        }
    }
}
