#include "vegetation.h"

// Конструктор:
Vegetation::Vegetation(Ground* ground, VegetationType vegetationType)
{
    _ground = ground;
    _vegetationType = vegetationType;
}

// Реализация виртуальной функции, которая возвращает баллы:
float Vegetation::getScore()
{
    // Если народ погибает, то количество баллов равно 0:
    if (willDie())
        return 0;

    switch (_ground->getGroundType()) {
    case DESERT: return 0;  // пустыня

    case SWAMP:  // болото
        switch (_vegetationType) {
        case CRANBERRY: return 0.15f;  // клюква
        case CLOUDBERRY: return 0.1f;  // морошка
        default: return 0;
        }

    case MOUNTAINS:  // горы
        switch (_vegetationType) {
        case FOOD_STUFFS: return 0.15f;  // продукты питания
        case POPPY: return 0.05f;  // мак
        case GRASS_AND_BUSHES: return 0.05f;  // трава и кусты
        default: return 0;
        }

    case FOREST:   // лес
        switch (_vegetationType) {
        case BERRIES: return 0.2f;  // ягоды
        case MUSHROOMS: return 0.2f;  // грибы
        case FOOD_STUFFS: return 0.35f;  // продукты питания
        default: return 0;
        }

    case PLAIN:  // равнина
        switch (_vegetationType) {
        case WHEAT: return 0.35f;  // пшеница
        case POTATO: return 0.35f;  // картошка
        case ROOT: return 0.15f;  // корнеплоды
        default: return 0;
        }
    }
}

// Реализация виртуальной функции, которая определяет умрёт ли народ или нужно считать баллы:
bool Vegetation::willDie()
{
    return _ground->willDie();
}
