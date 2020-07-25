import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 360
    height: 360
    title: qsTr("Заполнение всей области элемента")

    Rectangle {
        color: "lightgreen"
        anchors.fill: text
    }

    Text {
        id: text
        text: "Text"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter

        // Заполнить какую-нибудь область и тем самым
        // изменить не только позицию, но и размеры элемента.

        // Связать свойства фиксатора со значениями свойств нужного элемента:
        /*
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        */

        // Группированные свойства - это свойства, которые
        // тематически подходят друг к другу, поэтому объединяются в отдельную группу.
        // Можно думать о группах как о пространстве имен С++.
        // Таким образом, при помощи точки можно обратиться к каждому отдельно
        // взятому свойству группы элемента.
        // Компактная форма обращения к группированным свойствам:
        /*
        anchors {  // группа называется anchors.
            left: parent.left
            right: parent.right
            top: parent.top
            bottom: parent.bottom
        }
        */

        // В арсенале anchors имеется свойство fill, которое способно заменить эти четыре строчки
        // всего одной. После связывания этого свойства с идентификационным
        // номером нужного элемента оно будет заполнять его область целиком.
        anchors.fill: parent
    }
}
