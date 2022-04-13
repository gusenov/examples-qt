import QtQuick 2.12
import QtQuick.Window 2.12
import QtQml.Models 2.13
import QtQuick.Layouts 1.3

Window {
    visible: true
    width: 640
    height: 480

    ListModel {
        id: alphabetModel

        ListElement {
            name: "Vowels"
            letters: [
                ListElement { name: "A" },
                ListElement { name: "E" },
                ListElement { name: "I" },
                ListElement { name: "O" },
                ListElement { name: "U" }
            ]
        }

        ListElement {
            name: "Consonant"
            letters: [
                ListElement { name: "B" },
                ListElement { name: "C" },
                ListElement { name: "D" },
                ListElement { name: "F" }
            ]
        }
    }

    ColumnLayout {
        anchors.fill: parent

        Repeater {
            model: alphabetModel

            Rectangle {
                Layout.fillWidth: true

                height: 100
                border.width: 1
                color: "red"

                Text {
                    id: txt
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.right: parent.right
                    height: 50
                    text: model.name
                }

                RowLayout {
                    id: rowLyt
                    anchors.top: txt.bottom
                    anchors.left: parent.left
                    anchors.right: parent.right
                    height: 50

                    property var model2: model

                    Repeater {
                        model: rowLyt.model2.letters
                        Rectangle {
                            width: 100;
                            height: 40
                            border.width: 1
                            color: "yellow"
                            Text {
                                anchors.fill: parent
                                text: model.name
                            }
                        }
                    }  // Repeater

                }  // RowLayout

            }  // Rectangle
        }  // Repeater
    }  // ColumnLayout
}
