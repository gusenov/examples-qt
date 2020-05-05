import QtQuick 2.13
import QtQuick.Window 2.13

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MyControl {
        id: myControl1
    }

    Rectangle {
        width: 100
        height: 100
        x: 300
        y: 300
        color: "tomato"
    }
}
