import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import myquickview 1.0
import App 1.0

Item {
    objectName: "Root Item in main.qml"

    MyQuickView {
        id: myQuickView
        objectName: "MyQuickView item"

        width: 640
        height: 480

        source: "quick-it-hld.qml"

        Component.onCompleted: {
            myQuickView.visible = true
        }

        Rectangle {
            anchors.fill: parent
            color: "aliceblue"
        }

        MyPanel {
            color: "antiquewhite"
            width: 256
            height: 256
            anchors.top: parent.top
            anchors.topMargin: 8
            anchors.left: parent.left
            anchors.leftMargin: 8

            ListView {
                id: contactsListView
                width: 180; height: 200
                clip: true
                flickableDirection: Flickable.VerticalFlick
                boundsBehavior: Flickable.StopAtBounds
                ScrollBar.vertical: ScrollBar {}
                model: ListModel {
                    ListElement {
                        name: "Bill Smith"
                        number: "555 3264"
                    }
                    ListElement {
                        name: "John Brown"
                        number: "555 8426"
                    }
                    ListElement {
                        name: "Sam Wise"
                        number: "555 0473"
                    }
                }
                delegate: ItemDelegate {
                    id: del
                    text: name + ": " + number
                    highlighted: ListView.isCurrentItem
                    onClicked: {
                        contactsListView.currentIndex = index
                    }

                }
            }
        }

        MyPanel {
            color: "aquamarine"
            width: 256
            height: 256
            anchors.top: parent.top
            anchors.topMargin: 8
            anchors.right: parent.right
            anchors.rightMargin: 8
        }

        MyPanel {
            id: myBottomPanel
            objectName: "My Bottom Panel"

            color: "aqua"
            height: 128
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 8
            anchors.left: parent.left
            anchors.leftMargin: 8
            anchors.right: parent.right
            anchors.rightMargin: 8

            Rectangle {
                id: myCircle
                objectName: "My Circle"

                width: 64
                height: 64
                color: "beige"
                border.color: "blueviolet"
                border.width: 8
                radius: width * 0.5
                anchors.top: parent.top
                anchors.topMargin: 8
                anchors.left: parent.left
                anchors.leftMargin: 8

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: {
                        parent.border.color = "brown"
                    }
                    onExited: {
                        parent.border.color = "blueviolet"
                    }
                    acceptedButtons: Qt.LeftButton | Qt.RightButton
                    onClicked: {
                        if (mouse.button & Qt.RightButton) {
                            parent.border.color = "chartreuse"
                        } else {
                            // myBottomPanel.focus = true
                            // Если поставить фокус на myBottomPanel и
                            // ShortcutListener будет слушать только myCircle,
                            // то события не будут отлавливаться
                            // потому что фокус стоит на родительском элементе,
                            // а слушается дочерний элемент.

                            myCircle.focus = true
                            // ShortcutListener может слушать myCircle или myBottomPanel
                            // события все равно будут отлавливаться.
                            // Будет распространение от myCircle и далее к родительским элементам.

                            // myCircle.forceActiveFocus()
                        }
                    }
                }

                Keys.onPressed: {
                    // event.accepted = true
                    // Остановить распространение события.
                }

                Component.onCompleted: {
                    //ShortcutListener.listenTo(myCircle)
                }
            }

            Component.onCompleted: {
                ShortcutListener.listenTo(myBottomPanel)
            }
        }

    }

}
