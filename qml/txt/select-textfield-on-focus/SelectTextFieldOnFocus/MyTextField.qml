import QtQuick 2.12
import QtQuick.Controls 2.3

import "utils.js" as Utils

TextField {
    id: txtF
//    selectByMouse: true

    property var oldValue

    signal valueChanged(var value)

    validator : RegExpValidator { regExp : /[-]?([0-9]+([.|,][0-9]*)?|[.|,][0-9]+)/ }


    function selectAll() {
        if (displayText.startsWith("-")) {
            select(1, displayText.length)
        } else {
            select(0, displayText.length)
        }
    }

    onFocusChanged: {
//        Utils.log("{ text = " + displayText + "; onFocusChanged = " + focus + " }")
        if (focus) {
            oldValue = displayText

            // При фокусировке на текстовом поле все содержимое выделяется.
            selectAll()
        }
    }

    onEditingFinished: {
        Utils.log("{ text = " + displayText + "; onEditingFinished }")

        if (displayText === "" || displayText === "-") {
            text = "0"
        } else {
            text = displayText.replace(/,/g, '.')
        }

        if (oldValue !== text)
            valueChanged(text)
    }

    onValueChanged: {
        Utils.log("{ text = " + displayText + "; onValueChanged }")
    }

    Keys.onPressed: {
//        if (event.key === Qt.Key_Return) {
//            Utils.log("Keys.onPressed = Qt.Key_Return");
//        } else {
//            Utils.log("Keys.onPressed = " + event.key)
//        }

        var num;

        if (event.key === Qt.Key_Return) {
            txtF.focus = false
        } else if (event.key === Qt.Key_Escape) {
            txtF.text = oldValue
            txtF.focus = false

        } else if (event.key === Qt.Key_Tab) {
            if (txtF.text==="" || /^([+-]?[.,]?)$/.test(txtF.text)) {
                txtF.text = "0"
            } else {
                txtF.text = txtF.text.replace(/,/g, '.')
            }


        // Изменять значения можно с помощью стрелок на клавиатуре (ВВЕРХ или ВНИЗ).
        // Поля с цифровым значением меняются на 1, но если зажимаются SHIFT + UP/DOWN,
        // то меняется на 10 и если ALT + UP/DOWN, то меняются на 0.1.

        } else if (event.key === Qt.Key_Up) {
            num = parseFloat(text)
            if (!Utils.isNumber(num))
                num = 0
            if (event.modifiers & Qt.ShiftModifier) {
                num += 10
            } else if (event.modifiers & Qt.AltModifier) {
                num += 0.1
            } else {
                num += 1
            }
            text = num
        } else if (event.key === Qt.Key_Down) {
            num = parseFloat(text)
            if (!Utils.isNumber(num))
                num = 0
            if (event.modifiers & Qt.ShiftModifier) {
                num -= 10
            } else if (event.modifiers & Qt.AltModifier) {
                num -= 0.1
            } else {
                num -= 1
            }
            text = num
        }
    }
}
