#ifndef PEOPLE_H
#define PEOPLE_H

#include "parameter.h"


// Класс представляющий собой численность населения:
class People : public Parameter  // унаследован от Parameter.
{

// Публичные члены класса:
public:
    People(int numberOfPeople);

    // Виртуальная функция, которая возвращает баллы:
    virtual float getScore();

    // Виртуальная функция, которая определяет умрёт ли народ или нужно считать баллы:
    virtual bool willDie();

// Приватные члены класса:
private:

    // Количество людей:
    int _numberOfPeople;
};

#endif // PEOPLE_H
