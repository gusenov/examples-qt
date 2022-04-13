import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.13
import QtQuick.Controls 2.13

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ColumnLayout {
        ListView {
            height: 100
            width: 100
            model: tstMdl  // главная модель
            delegate: ComboBox {
                width: 100
                height: 50
                model: lst  // внутренний QVariantList

                onCurrentIndexChanged: {
                    // console.log(model)  // [string1,string2]
                    // console.log(Object.keys(model))  // [0,1]

                    console.log("currentIndex = ", currentIndex)
                }

            }
        }
    }
}
