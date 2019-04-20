#include "txtfileinfo.h"
#include <QFile>
#include <QDebug>

TxtFileInfo::TxtFileInfo(QString pathToFile):
    FileInfo (pathToFile)
{
    // Открываемый файл:
    QFile file(pathToFile);
    if (!file.open(QIODevice::ReadOnly)) {
        return;
    }

    // Чтение файла:
    QTextStream in(&file);
    QString row;
    while (in.readLineInto(&row)) {

        // Разбиваем строку на ключ и значение:
        QStringList keyValue = row.split(':');

        if (keyValue.at(0).compare("Автор", Qt::CaseInsensitive) == 0) {
            author = keyValue.at(1).trimmed();

        } else if (keyValue.at(0).compare("Название", Qt::CaseInsensitive) == 0) {
            name = keyValue.at(1).trimmed();

        } else if (keyValue.at(0).compare("Серия", Qt::CaseInsensitive) == 0) {
            series = keyValue.at(1).trimmed();

        } else if (keyValue.at(0).compare("Издатель", Qt::CaseInsensitive) == 0) {
            publisher = keyValue.at(1).trimmed();
        }


    }

    // Закрытие файла:
    file.close();
}
