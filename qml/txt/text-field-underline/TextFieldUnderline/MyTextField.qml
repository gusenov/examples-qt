import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Item {
    property alias txt: txt

    implicitHeight: txt.implicitHeight + 4
    implicitWidth: txt.implicitWidth

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        TextField {
            id: txt
            color: "red"
        }

        Rectangle {
            id: underline
            height: 1
            Layout.fillWidth: true
            color: "gray"
            Layout.topMargin: 3
            visible: txt.activeFocus
        }
    }
}
