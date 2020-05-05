import QtQuick 2.0

Rectangle {
    signal skyClicked(var mouse)

    color: "blue"

    MouseArea {
        anchors.fill: parent

        onClicked: {
            // console.log("onClicked")
            skyClicked(mouse)
        }
    }
}
