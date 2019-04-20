#include "defaultdata.h"

// Констуктор:
DefaultData::DefaultData()
{
    monthsList << "Январь"
               << "Февраль"
               << "Март"
               << "Апрель"
               << "Май"
               << "Июнь"
               << "Июль"
               << "Август"
               << "Сентябрь"
               << "Октябрь"
               << "Ноябрь"
               << "Декабрь";
}

// Получить список расходов по умолчанию:
QList<Base> DefaultData::createDefaultCostsList()
{
    QList<Base> result;

    Expense clothes("Одежда и аксессуары", 0);
    Expense supermarkets("Супермаркеты", 0);
    Expense restaurants("Рестораны и кафе", 0);
    Expense entertainment("Отдых и развлечения", 0);
    Expense transfers("Переводы", 0);
    Expense pharmacy("Аптека", 0);
    Expense other("Прочие расходы", 0);

    result.append(clothes);
    result.append(supermarkets);
    result.append(restaurants);
    result.append(entertainment);
    result.append(transfers);
    result.append(pharmacy);
    result.append(other);

    return result;
}

// Получить словарь расходов по умолчанию:
QMap<QString, QList<Base>> DefaultData::createDefaultCostsMap()
{
    QMap<QString, QList<Base>> result;

    QList<Base> costsList = createDefaultCostsList();

    for (QStringList::iterator it = monthsList.begin(); it != monthsList.end(); ++it)
    {
        result.insert(*it, costsList);
    }

    return result;
}

// Получить список доходов по умолчанию:
QList<Base> DefaultData::createDefaultProfitsList()
{
    QList<Base> result;

    Profit deposit("Зачисления", 0);
    Profit transfer("Перевод на карту", 0);
    Profit cash("Внесение наличных", 0);
    Profit cancel("Возврат, отмена операций", 0);

    result.append(deposit);
    result.append(transfer);
    result.append(cash);
    result.append(cancel);

    return result;
}

// Получить словарь доходов по умолчанию:
QMap<QString, QList<Base>> DefaultData::createDefaultProfitsMap()
{
    QMap<QString, QList<Base>> result;

    QList<Base> profitsList = createDefaultProfitsList();

    for (QStringList::iterator it = monthsList.begin(); it != monthsList.end(); ++it)
    {
        result.insert(*it, profitsList);
    }

    return result;
}
