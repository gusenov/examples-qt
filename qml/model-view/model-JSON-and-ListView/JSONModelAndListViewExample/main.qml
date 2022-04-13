import QtQuick 2.12
import QtQuick.Window 2.12

// Импортируем JS-файл с данными JSОN-модели
// и указываем идентификатор для пространства имен
// CDs, чтобы получить доступ к переменной, которой эта
// модель присвоена:
import "qrc:/CDs.js" as CDs

Window {
    id: mainrect
    color: "gray"
    width: 200
    height: 360
    visible: true

    Component.onCompleted: {
        // console.log(Object.keys(CDs));
        // qml: [jsonModel]

        // console.log(CDs.jsonModel)
        // qml: [[object Object],[object Object],[object Object]]
    }

    // За отображение каждого элемента списка в отдельности всегда отвечает элемент делегата.
    // За основу для делегата берем элемент Component.

    // Component - это template по которому можно создавать объекты.
    // Компонент можно определить как отдельный .qml файл или inline используя Component {}.
    // Компонент определенный inline не будет работать пока не будет загружен через Loader.
    // Отличие от Item в том, что Item - это просто визуальный тип определенный в модуле QtQuick.
    // Item не унаследован от Component, но кастомный компонент может базироваться на Item,
    // если он является корневым элементом например, в .qml файле.

    Component {

        // Присваиваем ему идентификатор delegate.
        // Это нужно для того, чтобы мы могли сослаться на него из элемента представления.
        id: delegate

        // Внутри этого элемента мы в элементе Item определяем то,
        // как должен отображаться отдельный элемент данных.

        Item {
            width: mainrect.width
            height: 70

            // При помощи элемента Row отображаем
            // данные в виде строки, причем слева - растровое изображение обложки (элемент Image),
            // а справа - вся текстовая информация, расположенная в виде столбца при помощи элемента
            // Column.

            Row {
                anchors.verticalCenter: parent.verticalCenter

                // Элемент Image загружает файл, местоположение и имя которого содержится в свойстве
                // модели cover.
                Image {
                    width: 64
                    height: 64
                    source: modelData.cover
                    smooth: true
                }

                Column {

                    // Элементы Text отображают разными цветами и размерами свойства моделей
                    // artist, album и year. Заметьте, доступ к свойствам модели мы получаем посредством
                    // текущего элемента modelData.

                    Text {
                        color: "white"
                        text: modelData.artist
                        font.pointSize: 12
                    }

                    Text {
                        color: "lightblue"
                        text: modelData.album
                        font.pointSize: 10
                    }

                    Text {
                        color: "yellow"
                        text: modelData.year
                        font.pointSize: 8
                    }

                }
            }
        }
    }

    // За отображение данных в виде столбца или строки отвечает
    // элемент ListView:
    ListView {
        // Для того чтобы разрешить в представлении навигацию, выполняемую
        // при помощи клавиатуры, свойством focus осуществляем установку фокуса.
        focus: true

        // По умолчанию элемент ListView применяется без декорации. Добавить декорации можно
        // с помощью свойств header и footer, а также свойства highlight - для показа текущего
        // элемента.

        // В верхней декорации с помощью свойства header мы создаем градиентный заголовок
        // (элемент Gradient) и в его центре позиционируем надпись "CDs" (элемент техt).
        header: Rectangle {
            width: parent.width
            height: 30
            gradient: Gradient {
                GradientStop { position: 0; color: "gray" }
                GradientStop { position: 0.7; color: "black" }
            }
            Text {
                anchors.centerIn: parent;
                color: "gray";
                text: "CDs"
                font.bold: true;
                font.pointSize: 20
            }
        }

        // В нижней декорации (свойство footer) мы тоже задаем элемент прямоугольника с градиентом,
        // но без надписи.
        footer: Rectangle {
            width: parent.width
            height: 30
            gradient: Gradient {
                GradientStop { position: 0; color: "gray" }
                GradientStop { position: 0.7; color: "black" }
            }
        }

        // Для декорирования выделения элементов (свойство highlight) представления
        // списка мы ограничиваемся только установкой голубого цвета (свойство color).
        highlight: Rectangle {
            width: parent.width
            color: "darkblue"
        }

        // Представления позиционируются внутри других элементов точно так же, как и обычные
        // элементы (свойство anchors).Представление расположено внутри элемента
        // серого прямоугольника.
        anchors.fill: parent

        // Модель
        // содержится в JS-файле и присвоена переменной jsonМodel. Для того чтобы получить к ней
        // доступ, нам нужно использовать идентификатор пространства имен, поэтому мы присваиваем
        // CDs.jsonModel свойству model:
        model: CDs.jsonModel

        // Делегат представлен элементом
        // Component и имеет идентификатор delegate. Чтобы его задействовать, мы присваиваем
        // идентификатор делегата свойству delegate представления ListView:
        delegate: delegate
    }
}
