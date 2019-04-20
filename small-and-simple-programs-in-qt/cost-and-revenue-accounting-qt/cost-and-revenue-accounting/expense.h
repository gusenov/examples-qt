#ifndef EXPENSE_H
#define EXPENSE_H

#include "base.h"


// Расход:
class Expense : public Base
{

// Публичные члены класса:
public:

    // Конструктор:
    Expense(QString itemName, double amount);

};

#endif // EXPENSE_H
