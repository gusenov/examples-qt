#include "level.h"

// Конструктор:
Level::Level(LevelType levelType)
{
    _levelType = levelType;
}

// Реализация виртуальной функции, которая возвращает баллы:
float Level::getScore()
{
    // Если народ погибает, то количество баллов равно 0:
    if (willDie())
        return 0;

    switch (_levelType) {
    case MINIMAL: return 0.1f;  // минимальный.
    case EASY: return 0.15f;  // лёгкий.
    case MIDDLE:  return 0.20f;  // средний.
    case HIGH: return 0.25f;  // высокий.
    }

    return 0;
}

// Реализация виртуальной функции, которая определяет умрёт ли народ или нужно считать баллы:
bool Level::willDie()
{
    return false;
}
