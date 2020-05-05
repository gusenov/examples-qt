import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Layouts 1.3

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ColumnLayout {
        anchors.rightMargin:  1
        anchors.leftMargin:   1
        anchors.bottomMargin: 1
        anchors.topMargin:    1

        anchors.fill: parent
        spacing: 2

        GridLayout {
            columns: 2

            Rectangle {
                color: "yellow"
                Layout.fillWidth: true
                Layout.fillHeight: true
            }

            Rectangle {
                color: "whitesmoke"
                Layout.fillWidth: true
                height: 100
            }

            Rectangle {
                color: "yellowgreen"
                Layout.fillWidth: true
                height: 50
            }

            Rectangle {
                color: "wheat"
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
        }
    }
}
