import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 200
    height: 200
    title: qsTr("Grid")

    Grid {
        rows: 2  // количество строк
        columns: 2  // столбцов таблицы

        anchors.centerIn: parent
        spacing: 10

        Rectangle {
            width: 64; height: 64; color: "red"
        }

        Rectangle {
            width: 64; height: 64;color: "blue"
        }

        Rectangle {
            width: 64; height: 64; color: "green"
        }

        Rectangle {
            width: 64; height: 64; color: "black"
        }
    }
}
