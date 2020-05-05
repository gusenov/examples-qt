import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.13

Window {
    visible: true

    // Это размеры рабочей области окна (border и заголовок окна не учитываются):
    width: 268
    height: 180

    title: qsTr("Create New Record")

    /*
    Rectangle {
        // Rectangle займет все окно, но слева, справа, сверху и снизу будет 1 отступ.
        width: parent.width - 2
        height: parent.height - 2
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        color: "yellowgreen"
    }
    */


    // Подсвечивает область на которой будут располагаться компоненты.
    Rectangle {
        anchors.topMargin: 16
        anchors.leftMargin: 24
        anchors.rightMargin: 24
        anchors.bottomMargin: 16

        // Отступы (выше) делаются от заданных координат фиксации.
        // Если их не задать (ниже), то элемент не отобразится.
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        color: "yellow"
    }


    ColumnLayout {

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        anchors.topMargin: 16
        anchors.leftMargin: 24
        anchors.rightMargin: 24

        anchors.bottom: parent.bottom
        anchors.bottomMargin: 16
        // NOTE: Если зафиксироваться на bottom, то ColumnLayout всегда будет растягиваться
        // и не будет эффекта valign="top". Это при учете того, что размеры всех элементов заданы
        // фиксированно. Чтобы этого избежать нужно задать fillHeight адаптируемой области.

        spacing: 0  // по умолчанию = 5.
        // Пространство МЕЖДУ элементами входящими в этот ColumnLayout.

        // Заголовок:
        Item {
            // width: 220
            Layout.fillWidth: true

            height: 24

            // Подсвечивает контейнер заголовка:
            Rectangle {
                anchors.fill: parent
                color: "wheat"
            }

            Label {

                color: "#FFFFFF"
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                anchors.right: parent.right

                anchors.topMargin: 4
                anchors.bottomMargin: 4

                font.family: "PT Sans"
                font.weight: Font.Bold
                font.pointSize: 12

                text: "Create New Record"
            }
        }




        // Поля:
        Item {
            // width: 220
            // height: 52

            // Область для полей будет адаптироваться под размер окна:
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.minimumHeight: 52

            Layout.topMargin: 16

            // Подсвечивает контейнер полей:
            Rectangle {
                anchors.fill: parent
                color: "violet"
            }

            GridLayout {
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.right: parent.right

                columns: 2
                rowSpacing: 4
                columnSpacing: 4

                Rectangle {
                    // Если не задавать Layout.minimumHeight и Layout.minimumWidth
                    // в каждой ячейке, то Rectangle не будет видно.
                    Layout.minimumHeight: 24
                    Layout.minimumWidth: 108
                    Layout.fillWidth: true

                    color: "springgreen"

                    Label {
                        opacity: 0.5
                        text: "Name"
                        anchors.fill: parent
                    }
                }


                Rectangle {
                    Layout.minimumHeight: 24
                    Layout.minimumWidth: 108
                    Layout.fillWidth: true

                    color: "sienna"

                    TextField {
                        opacity: 0.5
                        text: "Rec 1"
                        anchors.fill: parent
                    }
                }

                Rectangle {
                    Layout.minimumHeight: 24
                    Layout.minimumWidth: 108
                    Layout.fillWidth: true

                    color: "salmon"

                    Label {
                        opacity: 0.5
                        text: "Value"
                        anchors.fill: parent
                    }
                }

                Rectangle {
                    Layout.minimumHeight: 24
                    Layout.minimumWidth: 108
                    Layout.fillWidth: true

                    color: "royalblue"

                    TextField {
                        opacity: 0.5
                        text: "0"
                        anchors.fill: parent
                    }
                }

            }  // GridLayout
        }  // Item




        // Кнопки:
        Item {
            width: 135
            height: 32

            Layout.topMargin: 24
            Layout.alignment: Qt.AlignRight

            // Подсвечивает контейнер кнопок:
            Rectangle {
                anchors.fill: parent
                color: "turquoise"
            }

            RowLayout {
                spacing: 4  // по умолчанию = 5.

                Item {
                    width: 66
                    height: 24

                    // Подсвечивает контейнер Cancel:
                    Rectangle {
                        anchors.fill: parent
                        color: "tomato"
                    }

                    Label {
                        text: "Cancel"

                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        anchors.left: parent.left
                        anchors.right: parent.right

                        anchors.topMargin: 4
                        anchors.bottomMargin: 4
                        anchors.leftMargin: 16
                        anchors.rightMargin: 16

                        font.family: "PT Sans"
                        font.pointSize: 12
                    }
                }

                Item {
                    width: 65
                    height: 24

                    // Подсвечивает контейнер Create:
                    Rectangle {
                        anchors.fill: parent
                        color: "thistle"
                        radius: 4
                        border.color: "#30b2f2"
                    }

                    Label {
                        text: "Create"

                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        anchors.left: parent.left
                        anchors.right: parent.right

                        anchors.topMargin: 4
                        anchors.bottomMargin: 4
                        anchors.leftMargin: 16
                        anchors.rightMargin: 16

                        font.family: "PT Sans"
                        font.pointSize: 12
                    }
                }
            }
        }

    }  // ColumnLayout
}
