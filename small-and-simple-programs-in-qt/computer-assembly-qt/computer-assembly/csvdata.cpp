#include "csvdata.h"
#include <QFile>

// Конструктор:
CsvData::CsvData(QString fileName)
{
    this->fileName = fileName;
}

// Метод который возвращает содержимое CSV-файла в форме списка строковых списков:
QList<QStringList> CsvData::parseCsv()
{
    // Результирующий список строк:
    QList<QStringList> resultList;

    // Открываемый файл:
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        return resultList;
    }

    // Чтение файла:
    while (!file.atEnd()) {
        QStringList cellsList;

        QByteArray row = file.readLine();  // очередная строка из файла.

        // Разбиваем строку на ячейки:
        QList<QByteArray> cells = row.split(';');

        QList<QByteArray>::iterator i;
        for (i = cells.begin(); i != cells.end(); ++i)
            cellsList.append(*i);

        resultList.append(cellsList);
    }

    // Закрытие файла:
    file.close();

    return resultList;
}
