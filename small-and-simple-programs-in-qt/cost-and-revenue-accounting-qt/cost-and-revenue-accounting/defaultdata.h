#ifndef DEFAULTDATA_H
#define DEFAULTDATA_H

#include <QObject>
#include <QList>
#include <QMap>
#include "expense.h"
#include "profit.h"

// Класс с данными по умолчанию:
class DefaultData
{

// Публичные члены класса:
public:

    // Констуктор:
    DefaultData();

    // Получить список расходов по умолчанию:
    QList<Base> createDefaultCostsList();

    // Получить словарь расходов по умолчанию:
    QMap<QString, QList<Base>> createDefaultCostsMap();

    // Получить список доходов по умолчанию:
    QList<Base> createDefaultProfitsList();

    // Получить словарь доходов по умолчанию:
    QMap<QString, QList<Base>> createDefaultProfitsMap();

// Приватные члены класса:
private:

    // Список месяцев:
    QStringList monthsList;

};

#endif // DEFAULTDATA_H
