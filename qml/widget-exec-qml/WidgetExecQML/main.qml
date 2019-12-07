import QtQuick 2.0

// QМL-программа, которая просто отображает центрированный текст (элемент Text)
// и содержит функцию изменения размера шрифта setFontSize():

Rectangle {
    color: "lightgreen"
    width: 100
    height: 100
    Text {


        // В элементе Tехt использовали свойство
        // objectName и присвоили ему строковое значение "text":
        objectName: "text"
        // Базовый QМL-элемент Item реализован в С++ классом QQuickitem,
        // который унаследован от QObject точно так же, как и класс QWidget.
        // Свойство objectName принадлежит классу
        // QObject, и, значит, если получить доступ к объекту класса QQuickitem,
        // то с ним можно работать как с обычным объектом QObject.
        // Для этого мы и присвоили свойству objectName строку,
        // с помощью которой сможем найти текстовый элемент.


        anchors.centerIn: parent
        text: "Hello QМL"

        // JаvаSсriрt функция, которая принимает в качестве аргумента целочисленный размер шрифта,
        // устанавливает его и возвращает строку с информацией о предыдущем размере шрифта:
        function setFontSize(newSize)
        {
            font.pixelSize = newSize
            return font.family + " Size=" + newSize
        }
    }
}
