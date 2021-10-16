import QtQuick 2.0
import com.example 1.0
import MyModules 1.0

Item {

    property MyClass obj

    property /* QObject* */ Integer64 i64MaxVal: Integer64 {
        value: "9223372036854775807"
    }

    Integer64 {
        id: int64MaxValue
        value: "9223372036854775807"
    }

    MyClass {
        id: myObject
//         a: 200  // Invalid property assignment: unsupported type "qulonglong"

//        o: OtherClass {  // Cannot assign to property of unknown type "".
//            id: otherObject
//        }

//        i: Integer64 {  // Cannot assign to property of unknown type "Integer64".
//            value: "9223372036854775807"
//        }

//        i: int64MaxValue  // Unable to assign Integer64 to Integer64

//        i: i64MaxVal  // Unable to assign Integer64 to Integer64
    }

    Rectangle {
        anchors.fill: parent
        color: "cornflowerblue"
    }

    Rectangle {
        id: myRect2
        anchors.centerIn: parent
        color: "firebrick"
        width: 2 * myObject.a  // работает
//        height: myObject.a  // работает

        MouseArea {
            anchors.fill: parent
            onClicked: {
                // myObject.i = int64MaxValue  // Error: Cannot assign QObject* to Integer64
                // myObject.i = i64MaxVal  // Error: Cannot assign QObject* to Integer64
            }
        }
    }

    Binding {
        target: myRect2
        property: "height"
        value: myObject.a
    }
}
