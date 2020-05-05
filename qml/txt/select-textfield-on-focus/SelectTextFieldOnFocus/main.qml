import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.13

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ColumnLayout {

        GridLayout {
            columns: 3
            rows: 3

            columnSpacing: 10
            rowSpacing: 10

            MyTextField {
                id: cell11
                text: "367938"
            }

            MyTextField {
                id: cell12
                text: "-389389"
            }

            MyTextField {
                id:cell13
                text: "945415"
            }

            MyTextField {
                id: cell21
                text: "-499853"
            }

            MyTextField {
                id: cell22
                text: "481701"
            }

            MyTextField {
                id: cell23
                text: "-166502"
            }

            MyTextField {
                id: cell31
                text: "286881"
            }

            MyTextField {
                id: cell32
                text: "-570547"
            }

            MyTextField {
                id: cell33
                text: "259596"
            }
        }

        Button {
            text: "Ok"
            onClicked: {
                cell33.text = "33"
            }
        }

    }

}
