#ifndef CSVDATA_H
#define CSVDATA_H

#include <QString>


// Класс для работы с CSV-данными:
class CsvData
{

// Публичные члены класса:
public:

    // Конструктор:
    CsvData(QString fileName);

    // Метод который возвращает содержимое CSV-файла в форме списка строковых списков:
    QList<QStringList> parseCsv();

// Защищенные члены класса:
protected:

    // Путь к файлу:
    QString fileName;
};

#endif // CSVDATA_H
