import QtQuick 2.0
import QtQuick.XmlListModel 2.0

XmlListModel {
    // Элемент XmlListModel имеет свойство
    // source, а это значит, что ХМL-данные могут быть получены не только с локального носителя,
    // но и из Интернета. Любой элемент с этим свойством имеет такую способность.
    source: "qrc:///CDs.xml"

    // Чтобы иметь возможность получать данные, нужен механизм XPath. Он позволяет легко
    // запросить нужную нам информацию. Этот механизм можно представить как механизм
    // запросов к базе данных, которая представлена ХМL-файлом. Нас интересуют определенные
    // имена свойств, поэтому, чтобы получить их данные, мы создаем элементы XmlRole. В этих
    // элементах запрашивается любая часть данных. В свойстве name мы задаем имя, которое будет
    // представлять данные, а в свойстве query указываем тег и его тип. Свойство query идентифицирует
    // части данных в модели. В нашем случае все типы строковые. Все эти данные
    // берутся относительно пути тегов "/Cds/CD", заданного в свойстве query родительского элемента
    // XmlListModel.

    query: "/CDs/CD"

    XmlRole {
        name: "artist";
        query: "artist/string()"
    }

    XmlRole {
        name: "album";
        query: "album/string()"
    }

    XmlRole {
        name: "year";
        query: "year/string()"
    }

    XmlRole {
        name: "cover";
        query: "cover/string()"
    }
}
