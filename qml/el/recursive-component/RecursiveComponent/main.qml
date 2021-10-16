import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Cascade")

    Loader {
        source: "Cascade.qml"

        property var xPos: 0
        property var yPos: 0
    }
}
