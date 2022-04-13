import QtQuick 2.0

Item
{
    property var mainRec

    height: 50

    id: contactDelegate
    Rectangle
    {
        id: delRec
        height: 50
        width: mainRec.width // ширина делегата равна ширине mainRec
        border.width: 2 // толщина "ободка" для объекта
        border.color: "black" // цвет грани одного делегата

        Text
        {
            anchors.topMargin: 3
            anchors.fill: parent // поле текста занимает весь родительский прямоугольник
            text: "Contact " + name + "  Phone: " + phone // тут мы задаём текст, с переменными из модели
        }

        Rectangle
        {
            // этот прямоугольник отображает возрастную шкалу
            height: 12
            color: "lightblue" // цвет прямоугольника, задающего возраст на возрастной шкале
            anchors.left: parent.left // привязываем левую грань к родительскому прямоугольнику
            anchors.leftMargin: mainRec.width * 0.05 // задаём отступ от левой привязки
            width: (mainRec.width * 0.9) * age / 100 // здесь простая формула задаёт длину шкалы
            // будем считать максимальный возраст - 100 лет
            anchors.bottom: parent.bottom // привязываем нижнюю сторону прямоугольника
            anchors.bottomMargin: 5 // отступ для нижней привязки
            radius: 3
            Text
            {
                // ну и для наглядности внутри шкалы отобразим собственно возраст
                anchors.fill: parent
                text: "Age = " + age
                font.pixelSize: 11
            }
        }
    }
}
