import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.13

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Form")

    // Поля:
    Item {
        anchors.fill: parent

        // Подсвечивает контейнер полей:
        Rectangle {
            anchors.fill: parent
            color: "powderblue"
        }

        GridLayout {
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right

            columns: 2
            rows: 1
            rowSpacing: 4
            columnSpacing: 4

            Item {
                Layout.fillWidth: true

                Layout.minimumWidth: 108
                Layout.minimumHeight: 24

                Rectangle {
                    anchors.fill: parent
                    color: "springgreen"
                }

                Label {
                    anchors.fill: parent
                    text: "Name"
                    opacity: 0.5
                }
            }

            Item {
                Layout.fillWidth: true

                Layout.minimumWidth: 108
                Layout.minimumHeight: 24

                Rectangle {
                    anchors.fill: parent
                    color: "sienna"
                }

                TextField {
                    anchors.fill: parent
                    text: "Rec 1"
                    opacity: 0.5
                }
            }

            Item {
                Layout.minimumWidth: 108
                Layout.minimumHeight: 24

                Rectangle {
                    anchors.fill: parent
                    color: "salmon"
                }

                Label {
                    anchors.fill: parent
                    text: "Value"
                    opacity: 0.5
                }
            }

            Item {
                Layout.minimumWidth: 108
                Layout.minimumHeight: 24

                Rectangle {
                    anchors.fill: parent
                    color: "royalblue"
                }

                TextField {
                    anchors.fill: parent
                    text: "0"
                    opacity: 0.5
                }
            }

        }  // GridLayout
    }  // Item
}
