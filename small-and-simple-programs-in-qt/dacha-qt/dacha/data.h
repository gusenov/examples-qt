#ifndef DATA_H
#define DATA_H

#include <QString>
#include <QJsonObject>

// Класс для работы с JSON файлом:
class Data
{

// Публичные члены класса:
public:

    // Конструктор:
    Data(QString fileName);

    // Получить содержимое JSON-файла в виде строки:
    QString getData();

    // Распарсить строковое содержимое JSON-файла и получить его в виде объекта:
    QJsonObject parseJson();

    // Получить содержимое JSON-файла в виде словаря (т.е. данных в структуре ключ-значение):
    QVariantMap getMainMap();

// Защищенные члены класса:
protected:

    // Имя JSON-файла:
    QString fileName;

    // JSON-содержимое представленное объектом класса QJsonObject:
    QJsonObject jObject;

};

#endif // DATA_H
