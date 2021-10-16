import QtQuick 2.0

Loader {
    id: initLoader
    objectName: "Root Loader in init.qml"

    Timer {
        repeat: false
        running: true
        onTriggered: {
            console.log("Timer onTriggered")
            initLoader.source = "qrc:/main.qml"
        }
    }
}
