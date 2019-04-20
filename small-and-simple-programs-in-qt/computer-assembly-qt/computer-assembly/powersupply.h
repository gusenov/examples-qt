#ifndef POWERSUPPLY_H
#define POWERSUPPLY_H

#include "computercomponent.h"


// Блок питания:
class PowerSupply : public ComputerComponent
{

// Публичные члены класса:
public:

    // Конструктор:
    PowerSupply(DeviceType type, int id, QString name, int price, QString specifications, QList<int> compatibility);
};

#endif // POWERSUPPLY_H
