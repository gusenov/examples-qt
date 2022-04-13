import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Scroll")

    Rectangle {
        anchors.fill: parent
        color: "palevioletred"
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 10

        Item {
            Layout.fillWidth: true
            Layout.preferredHeight: btnCreate.height

            Rectangle {
                anchors.fill: parent
                color: "palegoldenrod"
            }

            RowLayout {
                anchors.fill: parent

                Button {
                    id: btnCreate
                    text: "Create"
                    onClicked: {
                        myModel.insertRows(myModel.rowCount(), 1)
                    }
                }

                Button {
                    text: "Remove"
                    onClicked: {
                        myModel.removeRows(
                            myModel.rowCount(),  // first index of the new item (row)
                            1                    // count
                        )
                    }
                }

                Button {
                    text: "Info"
                    onClicked: {
                        // console.log(Object.keys(myModel))

                        let idx = myModel.index(0 /*row*/, 0 /*column*/)
                        console.log(myModel.data(idx, 0))  // Qt::DisplayRole that according to the docs is 0
                    }
                }
            }
        }

        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true

            Rectangle {
                anchors.fill: parent
                color: "palegreen"
            }

            ScrollView {
                anchors.fill: parent

                ListView {
                    width: parent.width
                    delegate: ContactDelegate {
                        mainRec: parent
                    }
                    model: myModel // тут мы указываем имя нашей модели, которую подключили в Qt
                    spacing: 10 // отступ
                }
            }
        }

    }
}
