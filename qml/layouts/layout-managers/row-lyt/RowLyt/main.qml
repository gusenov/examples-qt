import QtQuick 2.12
import QtQuick.Window 2.12

// Включаем модуль QtQuick.Layouts для использования размещений:
import QtQuick.Layouts 1.3

Window {
    visible: true
    width: 320
    height: 240
    title: qsTr("RowLayout")

    RowLayout {
        // Заполняем всю область окна элемента размещения RowLayout присвоением anchords.fill
        // элемента предка (parent):
        anchors.fill: parent

        // Устанавливаем рамку (бордюр), равную 10 (свойство margins),
        // и фиксированное растояние между элементами (свойство spacing), тоже равное 10:
        anchors.margins: 10
        spacing: 10

        // Установим минимальные размеры элементов и разрешим первому и последнему элементам
        // вытягиваться на всю длину окна, а среднему элементу - заполнять пространство между
        // крайними элементами:

        Rectangle {
            // Встроенному
            // свойству размещения fillHeight первого и последнего элементов Rectangle мы
            // присваиваем значение true - что дает этим элементам возможность увеличиваться по высоте:
            Layout.fillHeight: true

            // Всем элементам Rectangle мы устанавливаем минимальные
            // размеры 64х64 при помощи свойств minimumWidth и minimumHeight:
            Layout.minimumWidth: 64;
            Layout.minimumHeight: 64;

            color: "red"
        }

        Rectangle {
            // В среднем элементе для возможности увеличения в ширину мы присваиваем свойству
            // fillWidth значение true:
            Layout.fillWidth: true

            Layout.minimumWidth: 64;
            Layout.minimumHeight: 64;
            color: "blue"
        }

        Rectangle {
            Layout.fillHeight: true
            Layout.minimumWidth: 64;
            Layout.minimumHeight: 64;
            color: "green"
        }
    }

    // Размещение в вертикальном порядке работает аналогично, просто замените имя элемента Row на Column.
}
