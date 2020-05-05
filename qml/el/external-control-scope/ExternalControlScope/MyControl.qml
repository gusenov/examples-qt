import QtQuick 2.0

Rectangle {
    id: rect1
    color: "violet"
    width: 100
    height: 100

    Rectangle {
        id: rect2
        color: "turquoise"
        width: 100
        height: 100
        x: rect1.width
        y: rect1.height
    }
}
