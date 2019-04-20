#ifndef DEVICETYPES_H
#define DEVICETYPES_H

// Тип компонента:
enum struct DeviceType : unsigned short int {
    VideoCard = 1,    // видеокарта
    Motherboard = 2,  // материнская плата
    HDD = 5,          // жесткий диск
    CPU = 4,          // процессор
    PowerSupply = 6,  // блок питания
    RAM = 3           // оперативная память
};

#endif // DEVICETYPES_H
