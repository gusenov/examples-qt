import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Button")

    Button {
        id: myBtn
        // text: "Click Here!"

        width: 196
        height: 50

        background: Rectangle {
            color: "gold"

            Image {
                id: btnImg
                width: parent.width
                height: parent.height
                source: "qrc:/btn-png/btn-png/1.png"
            }
        }

        checkable: true

        onClicked: {
            console.log("myBtn.clicked()")

            console.log("myBtn.checked = " + myBtn.checked)
        }

        onToggled: {
            console.log("myBtn.toggled()")
            console.log("myBtn.checked = " + myBtn.checked)
        }

        MouseArea {
            id: btnMouseArea
            hoverEnabled: true
            anchors.fill: myBtn
            propagateComposedEvents: true

            onEntered: {
                btnImg.source = "qrc:/btn-png/btn-png/2.png"
            }

            onExited: {
                btnImg.source = "qrc:/btn-png/btn-png/1.png"
            }

            onPressed: {
                btnImg.source = "qrc:/btn-png/btn-png/3.png"

                // Если раскомментировать, то onClicked от btnMouseArea не будет вызываться.
                // Но onClicked от myBtn будет вызываться.
                // mouse.accepted = false
            }

            onClicked: {
                console.log("btnMouseArea.clicked()")

                btnImg.source = "qrc:/btn-png/btn-png/4.png"

                // Этот MouseArea перекрывавает как-то myBtn и его onClicked не вызывается.
                // Поэтому здесь стоит явный выпуск события clicked у myBtn,
                // чтобы вызвался его onClicked.
                myBtn.clicked()

                // Click не означает toggle.
                myBtn.toggle()

                // Вызов toggle() сам по себе не инициирует выпуск события toggled().
                myBtn.toggled()
            }
        }
    }
}
