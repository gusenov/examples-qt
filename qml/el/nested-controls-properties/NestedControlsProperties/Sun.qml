import QtQuick 2.0

Rectangle {
    signal sunPressed(int х, int у)

    color: "yellow"
    radius: 1000

    MouseArea {
        anchors.fill: parent

        onPressed: {
            // console.log("onPressed")
            sunPressed(mouse.x, mouse.y)
        }

        onEntered: {

        }

        onExited: {

        }
    }
}
