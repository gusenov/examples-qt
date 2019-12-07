import QtQuick 2.13
import QtQuick.Window 2.13

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Row {
        anchors.centerIn: parent
        spacing: 10

        Item {
            width: 194
            height: 45

            Button {
                anchors.centerIn: parent

                // С помощью свойства
                // text мы присваиваем элементу кнопки начальный текст:
                text: "Please, Click me!"

                // При нажатии кнопки в свойстве
                // обработки сигнала onClicked присваиваем кнопке другой текст:
                onClicked: {
                    text = "Clicked!"
                }

            }
        }




        // Альтернативное решение для
        // кнопки Button.qml - замена сигнала clicked свойством:

        Item {
            width: 194
            height: 45
            Btn {
                anchors.centerIn: parent
                text: "Please, Click me!"

                // Свойство обработки события называется уже не onClicked, а
                // onClickedChanged, так как теперь генерируется событие изменения значения свойства:
                onClickedChanged: {
                    text = "Clicked!"
                }
            }
        }




    }

}
