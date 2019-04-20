#ifndef APPMODEL_H
#define APPMODEL_H

#include "csvdata.h"
#include <QList>

#include "videocard.h"
#include "motherboard.h"
#include "hdd.h"
#include "cpu.h"
#include "powersupply.h"
#include "ram.h"


// Класс представляющий собой модель данных приложения:
class AppModel: CsvData  // унаследован от CsvData.
{

// Публичные члены класса:
public:

    // Конструктор:
    AppModel(QString fileName);


    // Получить список наименований видеокарт:
    QStringList getVideoCardStringList(void);

    // Получить список наименований материнских плат:
    QStringList getMotherboardStringList(void);

    // Получить список наименований жестких дисков:
    QStringList getHddStringList(void);

    // Получить список наименований процессоров:
    QStringList getCpuStringList(void);

    // Получить список наименований блоков питания:
    QStringList getPowerSupplyStringList(void);

    // Получить список наименований оперативной памяти:
    QStringList getRamStringList(void);


    // Получить характеристики по типу детали и порядку в списке:
    QString getSpecificationsByIndex(DeviceType type, int index);

    // Получить цену цену по типу детали и порядку в списке:
    int getPriceByIndex(DeviceType type, int index);

    // Получить информацию о совместимости для выбранного оборудования:
    QString getCompatibilityInfo(int videoCardNo, int motherboardNo, int hddNo, int cpuNo, int powerSupplyNo, int ramNo);

// Приватные члены класса:
private:

    // Метод для конвертации QList<ComputerComponent> в QStringList:
    static QStringList listToStringList(QList<ComputerComponent> list);


    // Список строк из CSV-файла:
    QList<QStringList> parsedData;


    // Список видеокарт:
    QList<VideoCard> videoCardList;

    // Список материнских плат:
    QList<Motherboard> motherboardList;

    // Список жёстких дисков:
    QList<HDD> hddList;

    // Список процессоров:
    QList<CPU> cpuList;

    // Список блоков питания:
    QList<PowerSupply> powerSupplyList;

    // Список модулей оперативной памяти:
    QList<RAM> ramList;

};

#endif // APPMODEL_H
