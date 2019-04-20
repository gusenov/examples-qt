#include "survival.h"

// Конструктор:
Survival::Survival()
{

}

// Добавить параметр:
void Survival::addParameter(Parameter* p)
{
    _parameters.push_back(p);
}

// Высчитать общие баллы:
float Survival::getTotalScore()
{
    // Итератор по параметрам:
    std::vector<Parameter*>::iterator it;

    float sum = 0;  // сумма баллов.

    for(it = _parameters.begin(); it != _parameters.end(); it++)
    {
        // Если параметр возвращает -1, то народ погиб
        // и дальше нет смысла считать:
        if ((*it)->willDie())
            return -1;
        else
            sum += (*it)->getScore();
    }

    return sum;  // возврат суммы баллов.
}

// Метод, который по пороговому значения решает, выжил ли народ:
bool Survival::willSurvive()
{
    return getTotalScore() >= 0.85f;
}
