#include "dachadata.h"
#include <QVariantMap>

// Конструктор:
DachaData::DachaData(QString fileName): Data(fileName) { }

// Получить список типов растений:

QStringList DachaData::getTypeItems()
{
    // Получаем JSON-данные в виде словаря:
    QVariantMap mainMap = jObject.toVariantMap();

    // Проходим по всем ключам и добавляем их в список типов растений:
    QStringList typeItems;
    for (QVariantMap::const_iterator iter = mainMap.begin(); iter != mainMap.end(); ++iter) {
        typeItems << iter.key();
    }

    // Здесь в списке типов будут: Овощи, Плодовые деревья, Ягоды и прочее.
    // Т.е. все ключи, которые находятся на первом уровне в JSON-файле.

    return typeItems;
}

// Получить словарь растений для заданного типа:
QVariantMap DachaData::getTypeMap(QString typeName)
{
    // Получаем JSON-данные в виде словаря:
    QVariantMap mainMap = getMainMap();

    // Получаем словарь конкретных растений принадлежащих заданному типу:
    QVariantMap typeMap = mainMap[typeName].toMap();

    // Например, для типа Овощи, здесь в словаре окажутся ключи:
    //  Томаты, Перцы, Баклажаны, Огурцы, Капуста, Картофель;
    // и соответствующие для них значения.

    return typeMap;
}

// Получить список растений принадлежащих заданному типу:
QStringList DachaData::getPlantItems(QString typeName)
{    
    // Получаем словарь конкретных растений принадлежащих заданному типу:
    QVariantMap dataMap = getTypeMap(typeName);

    // Проходим по всем ключам и добавляем их в список растений:
    QStringList plantItems;
    for (QVariantMap::const_iterator iter = dataMap.begin(); iter != dataMap.end(); ++iter) {
        plantItems << iter.key();
    }

    // Например, для типа Овощи, здесь в списке окажутся ключи:
    //  Томаты, Перцы, Баклажаны, Огурцы, Капуста, Картофель.

    return plantItems;
}

// Получить словарь деталей по заданному растению:
QVariantMap DachaData::getPlantMap(QString typeName, QString plantName)
{
    // Получить словарь растений для заданного типа typeName:
    QVariantMap typeMap = getTypeMap(typeName);

    // Получить словарь деталей по заданному растению plantName:
    QVariantMap plantMap = typeMap[plantName].toMap();

    // Например, для типа Овощи и растения Томаты здесь будет результатом:
    // { "Сроки": …, "Соседство": …, "Лучшие сорта": …}

    return plantMap;
}
