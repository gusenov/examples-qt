// Благодаря тому, что в QML интегрирован JavaScript,
// данные в формате JSON могут использоваться напрямую, то есть можно считать JSОN-данные
// в переменную и использовать ее в качестве модели данных. Модель для CD
// в JSON могла бы иметь следующий вид:
var jsonModel = [
    {
        artist: "Amaranthe",
        album: "Amaranthe",
        year: 2011,
        cover: "qrc:/covers/Amaranthe.webp",
    }, {
        artist: "Dark Princess",
        album: "Without You",
        year: 2005,
        cover: "qrc:/covers/WithoutYou.jpg",
    }, {
        artist: "Within Temptation",
        album: "The Unforgiving",
        year: 2011,
        cover: "qrc:/covers/TheUnforgiving.jpg",
    }
];
