#include "data.h"
#include <QFile>
#include <QJsonDocument>
#include <QVariantMap>

// Конструктор:
Data::Data(QString fileName)
{
    // Запоминаем имя файла в переменную класса:
    this->fileName = fileName;
}

// Получить содержимое JSON-файла в виде строки:
QString Data::getData()
{
    // Переменная для хранения результирующей строки:
    QString data;

    // Открытие файла путь к которому хранится в переменной fileName:
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        // qDebug() << "Файл не открыт!" << endl;
    }
    else
    {
        // qDebug() << "Файл открыт." << endl;

        // Чтение данных из файла в переменную data:
        data = file.readAll();
    }

    // Закрытие файла:
    file.close();

    // qDebug() << data << endl;
    return data;
}

// Распарсить строковое содержимое JSON-файла и получить его в виде объекта:
QJsonObject Data::parseJson()
{
    // Получаем строковое содержимое JSON-файла:
    QString val = getData();

    // Преобразование строки в JSON-документ:
    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());

    // Получение из JSON-документа объекта класса QJsonObject:
    jObject = doc.object();

    return jObject;
}

// Получить содержимое JSON-файла в виде словаря (т.е. данных в структуре ключ-значение):
QVariantMap Data::getMainMap()
{
    // Преобразование объекта класса QJsonObject в объект класса QVariantMap:
    return jObject.toVariantMap();
}
