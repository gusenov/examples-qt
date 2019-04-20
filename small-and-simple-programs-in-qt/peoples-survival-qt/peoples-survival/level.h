#ifndef LEVEL_H
#define LEVEL_H

#include "parameter.h"


// Количество уровней развития:
const int LEVEL_TYPE_COUNT = 4;

// Перечисление уровней развития:
enum LevelType
{
    MINIMAL = 0,  // минимальный.
    EASY = 1,  // лёгкий.
    MIDDLE = 2,  // средний.
    HIGH = 3  // высокий.
};

// Класс представляющий собой уровень развития:
class Level : public Parameter  // унаследован от Parameter.
{
// Публичные члены класса:
public:

    // Конструктор, принмающий в качестве аргумента уровень развития:
    Level(LevelType levelType);

    // Виртуальная функция, которая возвращает баллы:
    virtual float getScore();

    // Виртуальная функция, которая определяет умрёт ли народ или нужно считать баллы:
    virtual bool willDie();

// Приватные члены класса:
private:

    // Внутренняя переменная хранящая уровень развития:
    LevelType _levelType;
};

#endif // LEVEL_H
