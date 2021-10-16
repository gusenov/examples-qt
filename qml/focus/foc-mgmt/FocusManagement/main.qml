import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14

Window {  // (QQuickWindow)
    readonly property int kSpace: 5

    id: win
    objectName: "win"
    visible: true
    width: 640
    height: 240
    title: qsTr("Hello World")

    onActiveFocusItemChanged: {
        title = "activeFocusItem = " + (activeFocusItem ? activeFocusItem.objectName : null)
        console.log("win.activeFocusItem = ", activeFocusItem)
    }

    Component.onCompleted: {
        // console.log("win = ", win)
        // qml: win =  QQuickWindowQmlImpl_QML_2(0x7ff3a34a7670, "win")
    }

    flags: Qt.WindowStaysOnTopHint
    // https://stackoverflow.com/questions/42273358/qml-on-windows-make-the-window-to-stay-on-top

    Rectangle {  // : Item
        id: rect1
        color: "aliceblue"
        anchors.fill: parent
    }

    TextField {  // : FocusScope : Item : (QQuickItem) : QtObject (QObject)
        id: textEdit1
        objectName: "textEdit1"
        text: activeFocus ? "activeFocus" : "TextField"
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: kSpace
        anchors.topMargin: kSpace

//        focus: true

        KeyNavigation.backtab: button1
    }

    TextField {
        id: textEdit2
        objectName: "textEdit2"
        text: activeFocus ? "activeFocus" : "TextField"
        anchors.left: textEdit1.right
        anchors.top: parent.top
        anchors.leftMargin: kSpace
        anchors.topMargin: kSpace

        KeyNavigation.tab: button1  // При нажатии на Tab фокус перейдет на кнопку.
    }

    Button {  // : AbstractButton : Control : Item (QQuickItem) : QtObject (QObject)
        id: button1
        objectName: "button1"
        text: activeFocus ? "activeFocus" : "Button"
        anchors.left: textEdit2.right
        anchors.top: parent.top
        anchors.leftMargin: kSpace
        anchors.topMargin: kSpace
        checkable: true

        // focus: true  // При старте фокус будет на кнопке, но не будет синей рамки.
        focusPolicy: Qt.WheelFocus  // При клике или ролике фокус будет на кнопке.
    }

    Button {
        id: button2
        objectName: "button2"
        text: activeFocus ? "activeFocus" : "Button"
        anchors.left: parent.left
        anchors.top: textEdit1.bottom
        anchors.leftMargin: kSpace
        anchors.topMargin: kSpace
        onClicked: {
//            button2.visible = false
            // If this property is set to false, the item will no longer receive mouse events, but will continue to receive key events and will retain the keyboard focus if it has been set.
            // In contrast, setting the enabled property to false stops both mouse and keyboard events, and also removes focus from the item.
            button2.enabled = false
            console.log("button2.activeFocus = ", button2.activeFocus)
        }
        onActiveFocusChanged: {
//            console.log("button2.activeFocus = ", button2.activeFocus)
        }
    }

    Rectangle {
        id: rect2
        objectName: "rect2"
        color: "antiquewhite"
        anchors.left: button2.right
        anchors.top: textEdit1.bottom
        anchors.leftMargin: kSpace
        anchors.topMargin: kSpace
        width: 512
        height: 64

//        focus: true  // При старте фокус будет на прямоугольнике.
        /*
            qt.quick.focus: QQuickWindowPrivate::setFocusInScope():
            qt.quick.focus:     scope: QQuickRootItem(0x7ff466838980)
            qt.quick.focus:     scopeSubFocusItem: QObject(0x0)
            qt.quick.focus:     item: QQuickRectangle(0x7ff464768420, name = "rect2")
            qt.quick.focus:     activeFocusItem: QObject(0x0)

            qt.quick.focus: QQuickWindowPrivate::setFocusInScope():
            qt.quick.focus:     scope: QObject(0x0)
            qt.quick.focus:     item: QQuickRootItem(0x7ff466838980)  // Это окно.
            qt.quick.focus:     activeFocusItem: QObject(0x0)

            qml: win.activeFocusItem =  QQuickRectangle(0x7ff464768420, "rect2")
        */

        Button {
            id: button3
            objectName: "button3"
            text: activeFocus ? "activeFocus" : "Button"
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.leftMargin: kSpace
            anchors.topMargin: kSpace
//            focus: true
            onClicked: {
                button3.enabled = false
                /*
                  Происходит потеря фокуса:

                    qt.quick.focus: QQuickWindowPrivate::clearFocusInScope():
                    qt.quick.focus:     scope: QQuickRootItem(0x7f887dc3f2a0)
                    qt.quick.focus:     item: Button_QMLTYPE_1(0x7f887f928200, name = "button3")
                    qt.quick.focus:     activeFocusItem: Button_QMLTYPE_1(0x7f887f928200, name = "button3")
                    qml: win.activeFocusItem =  QQuickRootItem(0x7f887dc3f2a0)
                */
            }
        }

    }
}

/*

--

Если никому не ставить focus: true, то при старте будет:

qt.quick.focus: QQuickWindowPrivate::setFocusInScope():
qt.quick.focus:     scope: QObject(0x0)
qt.quick.focus:     item: QQuickRootItem(0x7f9e03d34960)
qt.quick.focus:     activeFocusItem: QObject(0x0)

qml: win.activeFocusItem =  QQuickRootItem(0x7f9e03d34960)

--

При переключении на другое окно:

qt.quick.focus: QQuickWindowPrivate::clearFocusInScope():
qt.quick.focus:     scope: QObject(0x0)
qt.quick.focus:     item: QQuickRootItem(0x7ff77a67b330)
qt.quick.focus:     activeFocusItem: QQuickRectangle(0x7ff77a481640, name = "rect2")  // Если при старте у rect2.focus == true.

qml: win.activeFocusItem =  null

// При возвращении обратно в окно:

qt.quick.focus: QQuickWindowPrivate::setFocusInScope():
qt.quick.focus:     scope: QObject(0x0)
qt.quick.focus:     item: QQuickRootItem(0x7ff77a67b330)
qt.quick.focus:     activeFocusItem: QObject(0x0)

qml: win.activeFocusItem =  QQuickRectangle(0x7ff77a481640, "rect2")

--

*/
