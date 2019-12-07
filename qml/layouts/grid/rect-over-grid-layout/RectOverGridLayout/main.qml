import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Layouts 1.3

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ColumnLayout {
        anchors.fill: parent

        GridLayout {
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredHeight: 1

            columns: 2

            // № 1
            Rectangle {
                color: "bisque"

                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            // № 2
            Rectangle {
                color: "black"

                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            // № 3
            Rectangle {
                color: "blue"

                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            // № 4
            Rectangle {
                color: "cadetblue"

                Layout.fillHeight: true
                Layout.fillWidth: true
            }
        }  // GridLayout

        Item {
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredHeight: 1

            GridLayout {
                columns: 2
                anchors.fill: parent

                Rectangle {
                    color: "blueviolet"

                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    Layout.bottomMargin: -5

                    id: rectBlueViolet
                }

                Rectangle {
                    color: "brown"

                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    Layout.bottomMargin: -5
                    id: primaryLineHolder

                    // Большую MouseArea-область нужно определить раньше меньшей.
                    MouseArea {
                        anchors.fill: parent
                        cursorShape: {
                            return primaryLineMouseArea.pressedButtons & Qt.LeftButton ? Qt.SizeHorCursor : Qt.ArrowCursor;
                        }
                    }

                    Rectangle {
                        color: "chartreuse"
                        id: primaryLine

                        height: parent.height
                        width: 5
                        x: 10

                        MouseArea {
                            id: primaryLineMouseArea

                            anchors.fill: parent

                            drag {
                                target:   primaryLine
                                axis:     Drag.XAxis
                                maximumX: primaryLineHolder.width - this.width
                                minimumX: 0
                                smoothed: true
                                threshold: 0
                            }

                            cursorShape: Qt.SizeHorCursor
                        }
                    }
                }


                Rectangle {
                    color: "burlywood"

                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }

                Rectangle {
                    color: "blanchedalmond"

                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    ColumnLayout {
                        width: parent.width
                        height: 40

                        RowLayout {
                            Rectangle {
                                color: "coral"

                                Layout.fillHeight: true
                                Layout.fillWidth: true
                            }

                            Rectangle {
                                color: "cornflowerblue"

                                Layout.fillHeight: true
                                Layout.fillWidth: true
                            }
                        }

                        RowLayout {
                            Rectangle {
                                color: "cyan"

                                Layout.fillHeight: true
                                Layout.fillWidth: true
                            }

                            Rectangle {
                                color: "crimson"

                                Layout.fillHeight: true
                                Layout.fillWidth: true
                            }
                        }
                    }

                    Rectangle {
                        color: "chocolate"

                        height: parent.height / 2
                        width: 5
                        x: primaryLine.x
                    }

                }

            }  // GridLayout

            Rectangle {
                color: "cornsilk"
                id: masterLine

                height: parent.height - 30
                width: 5
                x: 10

                MouseArea {
                    id: masterLineMouseArea

                    anchors.fill: parent

                    drag {
                        target:   masterLine
                        axis:     Drag.XAxis
                        maximumX: rectBlueViolet.width - this.width
                        minimumX: 0
                        smoothed: true
                        threshold: 0
                    }

                    cursorShape: Qt.SizeHorCursor
                }
            }

        }  // Item

    }  // ColumnLayout
}
