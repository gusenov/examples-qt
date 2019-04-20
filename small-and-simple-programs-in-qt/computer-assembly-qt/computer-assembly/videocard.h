#ifndef VIDEOCARD_H
#define VIDEOCARD_H

#include "computercomponent.h"


// Видеокарта:
class VideoCard : public ComputerComponent
{

// Публичные члены класса:
public:

    // Конструктор:
    VideoCard(DeviceType type, int id, QString name, int price, QString specifications, QList<int> compatibility);
};

#endif // VIDEOCARD_H
