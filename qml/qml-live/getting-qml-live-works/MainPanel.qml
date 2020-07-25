import QtQuick 2.0
import QtQuick.Layouts 1.0

Item {
    width: 640
    height: 480

    Grid {
        anchors.fill: parent
        columns: 3
        spacing: 10

        Repeater {
            model: [
                {"color": "blue" },
                {"color": "green" },
                {"color": "red" },
                {"color": "yellow" },
                {"color": "black" },
                {"color": "pink" },
                {"color": "gray" },
                {"color": "brown" },
                {"color": "orange" }
            ]

            delegate: Badge {
                color: modelData.color
            }
        }

    }

}
