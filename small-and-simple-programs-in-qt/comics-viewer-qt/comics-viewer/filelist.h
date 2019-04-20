#ifndef FILELIST_H
#define FILELIST_H

#include <QDir>
#include <QString>
#include <QStringList>
#include <QFileInfoList>


// Класс позволяет работать со списком файлов из папки:
class FileList
{

// Публичные члены класса:
public:

    // Конструктор:
    FileList(const QString& dirPath);

    // Получить список файлов:
    QStringList getFileList();

    // Получить список изображений из папки:
    QStringList getImageList();

    // Проверить есть ли в папке текстовые файлы:
    bool hasAnyTxtFiles();

    // Получить первый текстовый файл:
    QString getFirstTxtFilePath();

// Приватные члены класса:
private:

    // Путь к папке:
    QString dirPath;

    // Объект описывающий папку:
    QDir dir;

};

#endif // FILELIST_H
