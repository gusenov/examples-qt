#include "base.h"

// Конструктор:
Base::Base(QString itemName, double amount)
{
    // Статья дохода или расхода:
    this->itemName = itemName;

    // Сумма денег по этой статье:
    this->amount = amount;
}

// Получить название статьи расходов или доходов:
QString Base::getItemName() const
{
    return itemName;
}

// Получить сумму:
double Base::getAmount() const
{
    return amount;
}

// Установить сумму:
void Base::setAmount(double value)
{
    amount = value;
}
