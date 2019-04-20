#include "motherboard.h"

// Конструктор:
Motherboard::Motherboard(DeviceType type, int id, QString name, int price, QString specifications, QList<int> compatibility):
    ComputerComponent (type, id, name, price, specifications, compatibility)
{

}
