import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5

Window {
    visible: true

    /*
     0   1   2   3   4
    [1] [2] [3] [4] [5]
       1   2   3   4
    */
    width: 64 * rowLyt.children.length  +  (rowLyt.children.length - 1) * rowLyt.spacing

    height: 64
    title: qsTr("RowLayout")

    RowLayout {
        id: rowLyt

        Item {
            width: 64
            height: 64
            Button {
                anchors.fill: parent
                text: "1"
                visible: false
            }
        }

        Item {
            width: btn2.width
            height: btn2.height

            Button {
                id: btn2
                width: 64
                height: 64

                anchors.fill: parent
                text: "2"
            }
        }

        Item {
            width: 64
            height: 64
            Button {
                anchors.fill: parent
                text: "3"
            }
        }

        Item {
            width: children.length ? children[0].width : 0
            height: children.length ? children[0].height : 0
            Button {
                width: 64
                height: 64
                anchors.fill: parent
                text: "4"
                visible: false
            }
        }

        Item {
            width: 64
            height: 64
            Button {
                anchors.fill: parent
                text: "5"
            }
        }
    }
}
