#ifndef CPU_H
#define CPU_H

#include "computercomponent.h"


// Процессор:
class CPU : public ComputerComponent
{

// Публичные члены класса:
public:

    // Конструктор:
    CPU(DeviceType type, int id, QString name, int price, QString specifications, QList<int> compatibility);
};

#endif // CPU_H
