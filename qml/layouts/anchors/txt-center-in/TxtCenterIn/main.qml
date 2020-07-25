import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 360
    height: 360
    title: qsTr("Фиксация текстового элемента по центру")

    Text {
        text: "Centered"

        // Элемент Text вложен в элемент Window, и мы фиксируем элемент
        // Text относительно его родителя Window, что реализуется всего лишь одной строчкой
        // кода. В этой строчке происходит присвоение значения parent свойству anchors.centerIn
        // элемента Text.
        // anchors.centerIn: parent

        // Можно было бы отцентрировать элемент,
        // применяя также свойства verticalCenter и horizontalCenter:
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        // Фиксаторы ссылаемых элементов имеют прямое отражение!
        // Используется parent.horizontalCenter, а не parent.anchors.horizontalCenter.
    }
}
