// Элементы для повторного использования должны быть помещены в отдельные файлы.
// Имя файла является именем элемента.

import QtQuick 2.0

// Элемент кнопки с текстом,
// которая при нажатии отправляет сигнал clicked.

// Элемент кнопки базируется на элементе BorderImage:
BorderImage {

    // За текст кнопки отвечает
    // внутренний элемент Text, поэтому, чтобы дать возможность его изменять извне, предоставляем
    // свойство-синоним:
    property alias text: txt.text

    // Декларируем сигнал clicked, который будет отправляться
    // при нажатии на нашу кнопку, поэтому он отправляется из обработчика onClicked
    // области мыши:
    signal clicked;

    source: "qrc:/mybutton.png"

    // Размер кнопки должен зависеть от ее текста, для этого соединяем свойства
    // размера текста с размерами элемента Borderimage и увеличиваем полями в 15 пикселов
    // с обеих сторон:
    width: txt.width + 15
    height: txt.height + 15
    border {left: 15; top: 12; right: 15; bottom: 121}

    Text {
        id: txt
        color: "white"
        anchors.centerIn: parent
    }

    MouseArea {
        anchors.fill: parent
        onClicked: parent.clicked();

        // При нажатии и отпускании мыши нам нужны разные визуальные представления
        // кнопки. Для того чтобы в зависимости от состояния кнопки загружать различные
        // изображения, используем обработчики onPressed и onReleased:
        onPressed: parent.source = "qrc:/mybuttonpressed.png"
        onReleased: parent.source = "qrc:/mybutton.png"
    }
}
