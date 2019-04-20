#ifndef RAM_H
#define RAM_H

#include "computercomponent.h"


// Оперативная память:
class RAM : public ComputerComponent
{

// Публичные члены класса:
public:

    // Конструктор:
    RAM(DeviceType type, int id, QString name, int price, QString specifications, QList<int> compatibility);
};

#endif // RAM_H
