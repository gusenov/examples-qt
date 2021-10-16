import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.13
import com.example.MyClass 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Force re-evaluation of a property binding")

    MyClass {
        id: myObj

        visible: false
    }

    Switch {
        id: mySwitch

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        text: qsTr("Visible")

        checked: true

        /*
        onCheckedChanged: {
            // console.log(checked)

            myObj.setVisible(checked)
        }
        */

        Binding {
            target: myObj
            property: "visible"
            value: mySwitch.checked
        }
    }

    Slider {
        id: mySlider

        anchors.top: mySwitch.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        from: 0
        value: 0
        to: parent.width - 1
    }

    Text {
        id: myTxt

        anchors.top: mySlider.bottom
        anchors.left: mySlider.left
        anchors.right: mySlider.right

        text: mySlider.value
        horizontalAlignment: Text.AlignHCenter
    }

    Rectangle {
        id: myRect

        width: 32
        height: 32
        color: "red"
        anchors.top: myTxt.bottom

        // HACK
        property int updateCounter

        x: myTxt.text

        // visible: myObj.visible  // OK

        // visible: myObj.isVisible()  // !

        // visible: myObj.dummy(myObj.visible)  // OK

        // HACK
        // visible: myRect.updateCounter, myObj.isVisible()  // Do not use comma expressions. (M30)
        visible: {
            myRect.updateCounter
            return myObj.isVisible()
        }

        Connections {
            target: myObj
            onVisibleChanged: (isVisible) => {
                // myRect.visible = myObj.isVisible()

                // HACK
                ++myRect.updateCounter
            }
        }
    }

}
