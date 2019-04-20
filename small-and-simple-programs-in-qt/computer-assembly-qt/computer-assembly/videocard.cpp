#include "videocard.h"

// Конструктор:
VideoCard::VideoCard(DeviceType type, int id, QString name, int price, QString specifications, QList<int> compatibility):
    ComputerComponent (type, id, name, price, specifications, compatibility)
{

}
