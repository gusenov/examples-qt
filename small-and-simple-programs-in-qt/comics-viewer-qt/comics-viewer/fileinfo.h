#ifndef FILEINFO_H
#define FILEINFO_H

#include <QString>


// Класс представляет собой файл с информацией о комиксе:
class FileInfo
{

// Публичные члены класса:
public:

    // Конструктор:
    FileInfo(QString pathToFile);

    // Получить путь к файлу:
    QString getPathToFile();


    // Получить автора:
    QString getAuthor();

    // Получить название:
    QString getName();

    // Получить серию:
    QString getSeries();

    // Получить издательство:
    QString getPublisher();


// Защищенные члены:
protected:

    // Путь к файлу:
    QString pathToFile;


    // Автор:
    QString author = "";

    // Название:
    QString name = "";

    // Серия:
    QString series = "";

    // Издательство:
    QString publisher = "";
};

#endif // FILEINFO_H
