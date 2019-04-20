#ifndef GROUND_H
#define GROUND_H

#include "parameter.h"


// Количество видов условий местности:
const int GROUND_TYPE_COUNT = 5;

// Перечисление видов условий местности:
enum GroundType
{
    DESERT = 0,  // пустыня.
    SWAMP = 1,  // болото.
    FOREST = 2,  // горы.
    MOUNTAINS = 3,  // лес.
    PLAIN = 4  // равнина.
};

// Класс представляющий собой условия местности:
class Ground : public Parameter  // унаследован от Parameter.
{
// Публичные члены класса:
public:

    // Конструктор принимающий в качестве аргумента вид местности:
    Ground(GroundType groundType);

    // Получить вид местности:
    GroundType getGroundType();

    // Установить заданный вид местности:
    void setGroundType(GroundType groundType);

    // Виртуальная функция, которая возвращает баллы:
    virtual float getScore();

    // Виртуальная функция, которая определяет умрёт ли народ или нужно считать баллы:
    virtual bool willDie();

// Приватные переменные класса:
private:

    // Внутренняя переменная хранящая вид местности:
    GroundType _groundType;
};

#endif // GROUND_H
