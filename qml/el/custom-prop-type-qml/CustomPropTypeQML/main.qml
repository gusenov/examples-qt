import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import com.example 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MyItem {
        property string currentCoord

        id: myItem1
        anchors.fill: parent
        obj: MyClass {
            s: myItem1.currentCoord
        }

//        MouseArea {
//            anchors.fill: parent
//            onClicked: {
//                myItem1.currentCoord = mouseX + ", " + mouseY
//            }
//        }
    }

    Button {
        text: ""
        onClicked: {
        }
    }
}
