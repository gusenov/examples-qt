import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("TextFieldUnderline")

    Rectangle {
        anchors.fill: parent
        color: "#191D21"
    }

    ColumnLayout {
        anchors.centerIn: parent

        MyTextField {
            id: myTextField1
            txt {
                color: "green"
            }
        }

        MyTextField {
            id: myTextField2
        }

        TextField {

            Rectangle {
                id: underline
                height: 1
                width: parent.width
                color: "#FFFFFF"
                y: parent.height + 3
                visible: parent.activeFocus
                opacity: 0.4
            }
        }
    }
}
