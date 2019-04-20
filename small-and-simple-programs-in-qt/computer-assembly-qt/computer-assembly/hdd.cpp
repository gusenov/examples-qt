#include "hdd.h"

// Конструктор:
HDD::HDD(DeviceType type, int id, QString name, int price, QString specifications, QList<int> compatibility):
    ComputerComponent (type, id, name, price, specifications, compatibility)
{

}
