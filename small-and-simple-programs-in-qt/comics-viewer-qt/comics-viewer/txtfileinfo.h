#ifndef TXTFILEINFO_H
#define TXTFILEINFO_H

#include "fileinfo.h"


// Класс представляет собой текстовый файл описывающий комикс в формате:

// Автор: Райан Стегман
// Название: Девушка паук
// Серия: Июнь 2006
// Издатель: Marvel

class TxtFileInfo : public FileInfo
{
// Публичные члены класса:
public:

    // Констуктор:
    TxtFileInfo(QString pathToFile);
};

#endif // TXTFILEINFO_H
