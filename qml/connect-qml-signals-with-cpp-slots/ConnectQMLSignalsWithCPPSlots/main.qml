import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.13

// Окно с элементами QМL-кнопок Info и Quit:
Window {
    visible: true
    width: 150
    height: 150

    // Размещаем в элементе Column две кнопки (элементы Button) с надписями Info и Quit
    // в виде столбца в центре окна приложения (свойство anchors.centerIn):
    Column {
        anchors.centerIn: parent
        Button {
            signal infoClicked(string str)

            // Дпя получения доступа к кнопкам из С++
            // присваиваем их свойствам objectName уникальные строковые значения:
            objectName: "InfoButton"

            text: "Info"

            // Каждая из кнопок содержит сигнал, который мы впоследствии соединим с объектом С++. Сигнал
            // infoClicked() высылается при нажатии на кнопку (свойство onClicked) и высылает строку
            // "Information":
            onClicked: infoClicked ( "Information")
            // Все сигналы, объявленные в QML, автоматически доступны в С++.

        }
        Button {
            signal quitClicked()
            objectName: "QuitButton"
            text: "Quit"

            // Сигнал quitClicked() высылается без аргументов:
            onClicked: quitClicked()
        }
    }
}
