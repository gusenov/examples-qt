#ifndef DACHADATA_H
#define DACHADATA_H

#include "data.h"


// Класс для работы с конкретной JSON-структурой
// описывающей растения:
class DachaData : public Data  // класс унаследован от класса Data.
{

// Публичные члены класса:
public:

    // Конструктор:
    DachaData(QString fileName);


    // Получить список типов растений:
    QStringList getTypeItems();

    // Получить словарь растений для заданного типа:
    QVariantMap getTypeMap(QString typeName);


    // Получить список растений принадлежащих заданному типу:
    QStringList getPlantItems(QString typeName);

    // Получить словарь деталей по заданному растению:
    QVariantMap getPlantMap(QString typeName, QString plantName);

};

#endif // DACHADATA_H
