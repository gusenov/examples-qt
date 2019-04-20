#include "ground.h"

// Конструктор:
Ground::Ground(GroundType groundType)
{
    _groundType = groundType;
}

// Получить вид местности:
GroundType Ground::getGroundType()
{
    return _groundType;
}

// Установить заданный вид местности:
void Ground::setGroundType(GroundType groundType)
{
    _groundType = groundType;
}

// Реализация виртуальной функции, которая возвращает баллы:
float Ground::getScore()
{
    // Если народ погибает, то количество баллов равно 0:
    if (willDie())
        return 0;

    switch (_groundType) {
    case DESERT: return 0;  // пустыня.
    case SWAMP: return 0.1f;  // болото.
    case MOUNTAINS: return 0.15f;  // горы.
    case FOREST:  return 0.20f;  // лес.
    case PLAIN: return 0.25f;  // равнина.
    }

    return 0;
}

// Реализация виртуальной функции, которая определяет умрёт ли народ или нужно считать баллы:
bool Ground::willDie()
{
    // В пустыне население всегда погибает:
    return _groundType == DESERT;
}
