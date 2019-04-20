#include <QDebug>
#include "filelist.h"

// Конструктор:
FileList::FileList(const QString& dirPath)
{
    this->dirPath = dirPath;
    dir.setSorting(QDir::LocaleAware);
    dir.setPath(this->dirPath);
}

// Получить список файлов:
QStringList FileList::getFileList()
{
    QStringList list;
    QFileInfoList fileInfoList = dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
    foreach (QFileInfo f, fileInfoList) {
        if (f.isFile()) {
            list.append(f.filePath());
        }
    }
    return list;
}

// Получить список изображений из папки:
QStringList FileList::getImageList()
{
    dir.setNameFilters(QStringList() << "*.jpg" << "*.png" << "*.gif");
    QStringList list = getFileList();
    dir.setNameFilters(QStringList());
    return list;
}

// Проверить есть ли в папке текстовые файлы:
bool FileList::hasAnyTxtFiles()
{
    dir.setNameFilters(QStringList() << "*.txt");
    QStringList list = getFileList();
    dir.setNameFilters(QStringList());
    return list.size() > 0;
}

// Получить первый текстовый файл:
QString FileList::getFirstTxtFilePath()
{
    dir.setNameFilters(QStringList() << "*.txt");
    QStringList list = getFileList();
    dir.setNameFilters(QStringList());
    return list.first();
}
