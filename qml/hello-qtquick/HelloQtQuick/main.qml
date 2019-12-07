// Директива import:

import QtQuick 2.13
import QtQuick.Window 2.13

/*
Ее назначение - включение программного кода,
который вы хотите использовать в программе.
Ее аналогом в С++ является директива include.
В нашем случае мы импортируем модули QtQuick и QtQuick.Window,
чтобы иметь возможность использовать их функции и элементы.

Рядом с именем модуля QtQuick определен также и номер.
А это значит, что будет использоваться именно та версия, которая соответствует этому номеру.
Функции и элементы из более ранних версий модулей будут нам недоступны.
Такой механизм гарантирует,
что поведение ваших QМLпрограмм не будет изменено даже с появлением более новых версий,
так как вы целенаправленно используете версию с указанным номером.
*/




/*
Для более объемных по коду функций JavaScript можно создать отдельные файлы
и импортировать их в QМL-файле элемента.
Стоящее в директиве import после ключевого слова as имя MyScripts является своеобразным идентификатором,
с помощью которого мы можем получить доступ ко всем функциям,определенным в файле.
Этот момент требует пояснения - представьте себе, что вы импортируете два файла с функциями,
в которых встречаются две функции с одинаковыми именами.
Идентификатор убережет вас от получившейся путаницы: вы можете представить его
с неким локальным пространством имен, который вы задаете для использования в каждом
отдельном QМL-файле сами.
*/
import "myfunctions.js" as MyScripts




/*
Пользовательский интерфейс описывается как дерево элементов с их свойствами.

Дерево элементов фвйла:

              Window
            /        \
 MouseArea             TextEdit
                                \
                                  Rectangle


Каждый QМL-файл должен содержать один корневой элемент:
Это элемент основного окна приложения.
Корневым элементом является элемент основного окна приложения Window.
*/
Window {

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MouseArea {

        // К элементу предка можно получить доступ
        // и без идентификатора - при помощи свойства-ссылки parent:
        anchors.fill: parent

        onClicked: {  //  свойства могут быть дополнены при помощи JavaScript:

            // Получить доступ к элементам можно при помощи их идентификатора id,
            // который должен быть уникален:
            console.log( qsTr( 'Clicked on background. Text: "' + textEdit.text + '"') )
        }
    }

    TextEdit {
        id: textEdit
        text: qsTr ( "Enter some text... ")
        verticalAlignment: Text.AlignVCenter
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        Rectangle {
            anchors.fill: parent
            anchors.margins: -10
            color: "transparent"
            border.width: 1
        }
    }

    Rectangle {
        // Для вычисления первым делом задействован JavaScript,
        // и только после этого вычисленное значение будет присвоено свойству width
        // элемента Rectangle:
        width: parent.width / 5
    }

    Rectangle {
        // Если выражение JavaScript содержит две или более строк, то оно помещается в фигурные скобки:
        width: {
            var w = parent.width / 5  // присваиваем вычисленное значение промежуточной переменной.
            console.log("Current width:" + w)  // отображаем ее значение на консоли.
            return w  // затем возвращаем его для присвоения свойству width.
        }
    }

    Rectangle {
        // Функции JavaScript можно интегрировать в сами элементы.
        // Реализуем в элементе функцию определения максимума и используем ее:
        function maximum(a, Ь)
        {
            return a > Ь ? a : Ь;
        }
        width: maximum(parent.width, 100)
    }

    Rectangle {
        width: MyScripts.maximum(parent.width, 100)
    }

}
