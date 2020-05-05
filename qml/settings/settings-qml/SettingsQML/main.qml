import QtQuick 2.0
import QtQuick.Window 2.12
import Qt.labs.settings 1.1

Window {
    id: window

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Settings {
        id: settings
        property string state: "active"
    }

    Settings {
        id: settingsGeometry
        category: "Geometry"
        property alias width: window.width
        property alias height: window.height
    }

    Component.onDestruction: {
    }
}
