#ifndef MOTHERBOARD_H
#define MOTHERBOARD_H

#include "computercomponent.h"


// Материнская плата:
class Motherboard : public ComputerComponent
{

// Публичные члены класса:
public:

    // Конструктор:
    Motherboard(DeviceType type, int id, QString name, int price, QString specifications, QList<int> compatibility);
};

#endif // MOTHERBOARD_H
