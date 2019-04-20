#ifndef VEGETATION_H
#define VEGETATION_H

#include "ground.h"


// Перечисление видов растительности:
enum VegetationType
{
    NONE,  // нет растительности
    CRANBERRY,  // клюква
    CLOUDBERRY,  // морошка
    FOOD_STUFFS,  // продукты питания
    POPPY,  // мак
    GRASS_AND_BUSHES,  // трава и кусты
    BERRIES,  // ягоды
    MUSHROOMS,  // грибы
    WHEAT,  // пшеница
    POTATO,  // картошка
    ROOT  // корнеплоды
};

// Класс представляющий собой типа растительности:
class Vegetation : public Parameter  // унаследован от Parameter.
{

// Публичные члены класса:
public:

    // Конструктор:
    Vegetation(Ground* ground, VegetationType vegetationType);

    // Виртуальная функция, которая возвращает баллы:
    virtual float getScore();

    // Виртуальная функция, которая определяет умрёт ли народ или нужно считать баллы:
    virtual bool willDie();

// Приватные члены класса:
private:

    // Условия местности:
    Ground* _ground;

    // Вид растительности:
    VegetationType _vegetationType;
};

#endif // VEGETATION_H
