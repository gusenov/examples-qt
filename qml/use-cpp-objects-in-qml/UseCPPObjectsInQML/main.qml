import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

// Включаем наш модуль
// com.myinc.Calculaition:
import com.myinc.Calculation 1.0


ApplicationWindow {
    title: "Factorial Calculation"
    width: 250
    height: 150
    visible: true

    // Создаем элемент Calculation с идентификатором calc:
    Calculation {
        id: calc
    }

    // В элементе вертикального размещения ColumnLayout
    // мы используем два элемента горизонтального
    // размещения RowLayout:

    ColumnLayout {
        anchors.fill: parent




        // Вызов метода factorial(),
        // который был определен в классе calculation как Q_INVOКAВLE.
        // Его вызов происходит в элементе Text (см. свойство text)
        // при изменениях значения счетчика.

        RowLayout { // 1. call of an invokaЬle method
            SpinBox {
                id: sbx
                value: 0
            }

            Text {
                // Доступ к измененному значению счетчика мы получаем при помощи
                // свойства value идентификатора sbx, а доступ
                // к элементу вычислений Calculation - при помощи идентификатора calc.
                text: "Result:" + calc.factorial(sbx.value)
            }
        }




        // Другой подход с использованием свойств.

        RowLayout { // 2. using of the properties
            SpinBox {
                value: 0
                // При каждом элементе счетчика в его свойстве обработки
                // события onValueChanged мы присваиваем свойству input элемента Calculation актуальное
                // значение.
                onValueChanged: calc.input = value

                // Подобное изменение повлечет за собой также и
                // изменение свойства result элемента Calculation,
                // поэтому отображаем это свойство в элементе Text (см. свойство text):
            }

            Text {
                text: "Result:" + calc.result
            }
        }




        // Третий подход, в котором мы будем
        // отлавливать изменения свойства result:

        Calculation {
            // Соединяем свойство input в элементе Calculation со свойством value
            // элемента счетчика SpinBox:
            input: sbx_.value

            // В свойстве onResultValueChanged мы отлавливаем изменения
            // вычисленных значений факториала и отображаем их в текстовом элементе при помощи
            // идентификатора txt (свойство text):
            onResultValueChanged: txt_.text = "Result:" + result
        }

        RowLayout {
            SpinBox {
                id: sbx_
                value: 0
            }

            Text {
                id: txt_
            }
        }




    }
}
