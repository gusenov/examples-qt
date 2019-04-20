#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "parameter.h"


// Класс представляющий собой температурный режим:
class Temperature : public Parameter  // унаследован от Parameter.
{

// Публичные члены класса:
public:

    // Конструктор:
    Temperature(float min, float max);

    // Виртуальная функция, которая возвращает баллы:
    virtual float getScore();

    // Виртуальная функция, которая определяет умрёт ли народ или нужно считать баллы:
    virtual bool willDie();

// Приватные члены класса:
private:

    // Минимальное значение температуры:
    float _min;

    // Максимальное значение температуры:
    float _max;
};

#endif // TEMPERATURE_H
