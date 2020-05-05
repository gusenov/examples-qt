import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Above {
        id: above
        anchors.fill: parent

        sky {
            id: mySky
            color: "aqua"
            onSkyClicked: {
                mySky.color = "deepskyblue"
            }
        }

        sun.color: "red"
        sun.onColorChanged: {
            console.log("sun.onColorChanged")
        }
    }
}
