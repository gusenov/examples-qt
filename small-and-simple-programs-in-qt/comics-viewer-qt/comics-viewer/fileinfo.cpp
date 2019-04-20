#include "fileinfo.h"

// Конструктор:
FileInfo::FileInfo(QString pathToFile):
    pathToFile(pathToFile)
{

}

// Получить путь к файлу:
QString FileInfo::getPathToFile()
{
    return pathToFile;
}

// Получить автора:
QString FileInfo::getAuthor()
{
    return author;
}

// Получить название:
QString FileInfo::getName()
{
    return name;
}

// Получить серию:
QString FileInfo::getSeries()
{
    return series;
}

// Получить издательство:
QString FileInfo::getPublisher()
{
    return publisher;
}
