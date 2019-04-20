#include "temperature.h"

// Конструктор:
Temperature::Temperature(float min, float max)
{
    _min = min;
    _max = max;
}

// Реализация виртуальной функции, которая возвращает баллы:
float Temperature::getScore()
{
    // Если народ погибает, то количество баллов равно 0:
    if (willDie())
        return 0;

    int i = 0;  // счётчик.

    // Количество температурных диапазонов:
    const int RANGES_COUNT = 5;

    // Определяем в какие диапазоны попадает температура:

    bool ranges[RANGES_COUNT] = { false, false, false, false, false };

    // [-39; -20]
    ranges[i++] = (_min >= -39 && _min <= -20) ||
                  (_max >= -39 && _max <= -20);

    // [-19; 0]
    ranges[i++] = (_min >= -19 && _min <= 0) ||
                  (_max >= -19 && _max <= 0);

    // [+1; +19]
    ranges[i++] = (_min >= +1 && _min <= +19) ||
                  (_max >= +1 && _max <= +19);

    // [+20; +30]
    ranges[i++] = (_min >= +20 && _min <= +30) ||
                  (_max >= +20 && _max <= +30);

    // Сумма баллов:
    float sum = 0.0f;

    // Количество попаданий в дипазоны температур:
    int hits = 0;

    // Рассчёт среднего балла:

    for (i = 0; i < RANGES_COUNT; ++i)
    {
        // Если температура попала в i-ый диапазон:
        if (ranges[i]) {
            ++hits;  // увеличиваем счётчик попаданий.
            switch (i) {  // прибавляем к сумме баллов соответствующий диапазону балл:
            case 0: sum += 0.1f; break;
            case 1: sum += 0.15f; break;
            case 2: sum += 0.20f; break;
            case 3: sum += 0.25f; break;
            }
        }
    }

    // Делим сумму баллов на количество попаданий температуры в диапазоны:
    return sum / hits;
}

// Реализация виртуальной функции, которая определяет умрёт ли народ или нужно считать баллы:
bool Temperature::willDie()
{
    return _min <= -40 || _max <= -40 ||
           _min >= +40 || _max >= +40;
}
