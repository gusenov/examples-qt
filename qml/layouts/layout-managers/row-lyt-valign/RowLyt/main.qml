import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Layouts 1.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        spacing: 8

        RowLayout {
            spacing: 0
            anchors.left: parent.left
            anchors.right: parent.right

            Rectangle {
                color: "red"
                height: 10
                Layout.preferredWidth: 100
                Layout.alignment: Qt.AlignTop
            }

            Rectangle {
                color: "green"
                height: 100
                Layout.fillWidth: true
            }
        }

    }
}
