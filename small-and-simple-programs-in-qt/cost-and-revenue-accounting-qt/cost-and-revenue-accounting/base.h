#ifndef BASE_H
#define BASE_H

#include <QString>

// Базовый класс для классов дохода и расхода:
class Base
{

// Публичные члены класса:
public:

    // Конструктор:
    Base(QString itemName, double amount);

    // Получить название статьи расходов или доходов:
    QString getItemName() const;

    // Получить сумму:
    double getAmount() const;

    // Установить сумму:
    void setAmount(double value);

// Приватные члены класса:
private:

    // Статья дохода или расхода:
    QString itemName;

    // Сумма денег по этой статье:
    double amount;
};

#endif // BASE_H
