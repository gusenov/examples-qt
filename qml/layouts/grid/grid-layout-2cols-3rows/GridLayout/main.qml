import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Layouts 1.3

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    color: "blueviolet"

    GridLayout {
        columns: 2

        // Промежуток между столбцами:
        columnSpacing: 10  // default value is 5

        // Промежуток между строками:
        rowSpacing: 15     // default value is 5

        anchors.fill: parent

        Rectangle {

            // Если здесь указать
            // anchors.fill: parent
            // то это прямоугольник займет все окно.

            Layout.fillWidth: true
            Layout.fillHeight: true

            color: "aliceblue"

            Text {
                text: "№ 1";
                font.bold: true;

            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.bottomMargin: -15

            color: "antiquewhite"

            Text {
                text: "№ 2";
                font.underline: true
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true

            color: "aqua"

            Text {
                text: "№ 3";
                font.pixelSize: 20
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true

            color: "aquamarine"

            Text {
                text: "№ 4";
                font.strikeout: true
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.topMargin: -15

            color: "azure"

            Text {
                text: "№ 5";
                font.bold: true;
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.leftMargin: -10

            color: "beige"

            Text {
                text: "№ 6";
                font.bold: true;
            }
        }
    }

}
