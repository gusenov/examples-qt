import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 360
    height: 180
    title: qsTr("Относительный отступ")

    Rectangle {
        height: 10
        width: 10
        color: "red"
        anchors {
            // Можно сделать относительный отступ при
            // помощи свойств, имена которых оканчиваются словом Offset.
            // Отступ элемента на десять пикселов вниз:
            verticalCenterOffset: 10
            verticalCenter: parent.verticalCenter

            horizontalCenter: parent.horizontalCenter
        }
    }

    Rectangle {
        width: 10
        height: 10
        radius: width * 0.5
        color: "green"

        anchors {
            verticalCenter: parent.verticalCenter
            horizontalCenter: parent.horizontalCenter
        }
    }
}
