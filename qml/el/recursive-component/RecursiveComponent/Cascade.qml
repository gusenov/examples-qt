import QtQuick 2.0

Item {
    Rectangle {
        id: rect

        // Читаем координаты из Loader-а.
        // parent - это Item.
        // А так как загружаем через Loader,
        // то parent.parent это будет Loader.
        x: parent.parent.xPos
        y: parent.parent.yPos

        width: 50
        height: 50
        color: "red"

        MouseArea {  // https://doc.qt.io/qt-5/qml-qtquick-mousearea.html
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton | Qt.MiddleButton
            onPressed: (mouse) => {  // https://doc.qt.io/qt-5/qml-qtquick-mouseevent.html
                if (mouse.button === Qt.LeftButton)
                    rect.x += 50
                else if (mouse.button === Qt.RightButton)
                    rect.x -= 50
               else if (mouse.button === Qt.MiddleButton)
                   rect.y += 50
            }
        }
    }

    Loader {
        id: loader
        source: {

            // console.log("rect.x = ", rect.x)
            // В первый раз вывод будет:
            // rect.x =  0
            // В данном случае rect отсылается к элементу Rectangle выше,
            // а не тому который будет подгружен.

            if (rect.x + 50 > 640 || rect.y + 50 > 480)
                return ""
            return "Cascade.qml"
        }

        property var xPos: rect.x + 50
        property var yPos: rect.y + 50
    }

    Component.onCompleted: {
        // console.log("parent = ", parent)

        // Если загружать этот файл через Loader, например: Loader { source: "Cascade.qml" }
        // то родителем будет QQuickLoader.
        // qml: parent =  QQuickLoader(0x7fddaaf6b7c0)

        // Если в main.qml объявить Window { ... Cascade { ... } ... }
        // то родителем будет Window.
        // qml: parent =  QQuickRootItem(0x7fbc98a8e940)
    }
}
