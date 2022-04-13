import QtQuick 2.0

// Модель списка для коллекции компакт-дисков.
// Модель реализована в отдельном файле CDs.qml. Если же разместить ее в одном и
// том же файле вместе с представлением, то для того чтобы иметь возможность к ней обратиться,
// необходимо при помощи свойства id снабдить ее идентификатором.

ListModel {
    // Модель списка представлена элементом ListModel и содержит последовательности элементов
    // в следующем виде:

    ListElement {
        // Каждый ее подэлемент ListElement содержит одно или более свойств для данных. Элемент
        // ListElement не содержит ни одного предопределенного свойства, и все они задаются пользователем.

        artist: "Amaranthe"                 // исполнитель
        album: "Amaranthe"                  // альбом
        year: 2011                          // год
        cover: "qrc:/covers/Amaranthe.jpg"  // обложка - путь к файлу растрового изображения обложки CD
    }

    ListElement {
        artist: "Dark Princess"
        album: "Without You"
        year: 2005
        cover: "qrc:/covers/WithoutYou. jpg"
    }

    ListElement {
        artist: "Within Temptation"
        album: "The Unforgiving"
        year: 2011
        cover: "qrc:/covers/TheUnforgiving.jpg"
    }

    // Несмотря на то, что мы прописываем все данные вручную, элемент
    // ListModel - это динамический список элементов. Элементы этого списка могут быть добавлены,
    // вставлены, удалены и перемещены при помощи интегрированных в элемент
    // ListModel методов:
    //  - append(),
    //  - insert(),
    //  - remove()
    //  - и move().
    // Например, код для удаления текущего элемента может выглядеть так:
    // CDs.remove(view.currentindex)
}
