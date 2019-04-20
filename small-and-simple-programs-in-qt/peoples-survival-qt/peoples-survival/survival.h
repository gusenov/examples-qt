#ifndef SURVIVAL_H
#define SURVIVAL_H

#include <vector>
#include "parameter.h"


// Вычислитель выживаемости народа:
class Survival
{

// Публичные члены класса:
public:

    // Конструктор:
    Survival();

    // Добавить параметр:
    void addParameter(Parameter* p);

    // Подсчитать общие баллы:
    float getTotalScore();

    // Ответ на вопрос, выживет ли народ?
    bool willSurvive();

// Приватные члены класса:
private:

    // Вектор параметров:
    std::vector<Parameter*> _parameters;
};

#endif // SURVIVAL_H
