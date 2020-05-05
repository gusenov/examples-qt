import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

import "Library" as Library

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ColumnLayout {
        TextField {
            text: "QtQuick.Controls"
        }

        Library.TextField {
            id: txtF
        }
    }
}
