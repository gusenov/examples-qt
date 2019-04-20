#include "people.h"

// Конструктор:
People::People(int numberOfPeople)
{
    _numberOfPeople = numberOfPeople;
}

// Реализация виртуальной функции, которая возвращает баллы:
float People::getScore()
{
    // Если народ погибает, то количество баллов равно 0:
    if (willDie())
        return 0;

    if (_numberOfPeople == 0)
        return 0;
    else if (_numberOfPeople <= 1000)
        return 0.1f;
    else if (_numberOfPeople <= 10000)
        return 0.15f;
    else if (_numberOfPeople <= 50000)
        return 0.20f;
    else
        return 0.25f;
}

// Реализация виртуальной функции, которая определяет умрёт ли народ или нужно считать баллы:
bool People::willDie()
{
    return _numberOfPeople == 0;
}
