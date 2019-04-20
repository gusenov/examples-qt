#ifndef HDD_H
#define HDD_H

#include "computercomponent.h"


// Жесткий диск:
class HDD : public ComputerComponent
{

// Публичные члены класса:
public:

    // Конструктор:
    HDD(DeviceType type, int id, QString name, int price, QString specifications, QList<int> compatibility);
};

#endif // HDD_H
