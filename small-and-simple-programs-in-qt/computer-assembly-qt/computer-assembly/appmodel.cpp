#include "appmodel.h"

// Конструктор:
AppModel::AppModel(QString fileName):
    CsvData (fileName)  // вызов родительского конструктора.
{
    // Парсим CSV-данные:
    parsedData = parseCsv();

    QList<QStringList>::iterator i;
    for (i = parsedData.begin(); i != parsedData.end(); ++i)
    {
        QStringList& row = *i;

        // Получаем тип компонента:
        DeviceType type = static_cast<DeviceType>(row[0].toUShort());

        int id = row[1].toInt();  // идентификатор.

        QString name = row[2];  // наименование.

        int price = row[3].toInt();  // цена.

        QString specifications = row[4];  // характеристики.

        // Получаем список совместимых компонентов:
        QList<int> compatibility;
        QStringList compatibilityIds = row[5].split(",");
        QList<QString>::iterator j;
        for (j = compatibilityIds.begin(); j != compatibilityIds.end(); ++j)
            compatibility.append((*j).toInt());

        // Создаем объект соответствующего компоненту типа и
        // добавляем его в соответствующий список:
        switch (type) {
        case DeviceType::VideoCard:
            videoCardList.append(VideoCard(type, id, name, price, specifications, compatibility));
            break;
        case DeviceType::Motherboard:
            motherboardList.append(Motherboard(type, id, name, price, specifications, compatibility));
            break;
        case DeviceType::HDD:
            hddList.append(HDD(type, id, name, price, specifications, compatibility));
            break;
        case DeviceType::CPU:
            cpuList.append(CPU(type, id, name, price, specifications, compatibility));
            break;
        case DeviceType::PowerSupply:
            powerSupplyList.append(PowerSupply(type, id, name, price, specifications, compatibility));
            break;
        case DeviceType::RAM:
            ramList.append(RAM(type, id, name, price, specifications, compatibility));
            break;
        }
    }

}


// Получить список наименований видеокарт:
QStringList AppModel::getVideoCardStringList(void)
{
    QStringList stringList;
    foreach (VideoCard item, videoCardList)
        stringList << item.getName();
    return stringList;
}

 // Получить список наименований материнских плат:
QStringList AppModel::getMotherboardStringList(void)
{
    QStringList stringList;
    foreach (Motherboard item, motherboardList)
        stringList << item.getName();
    return stringList;
}

// Получить список наименований жестких дисков:
QStringList AppModel::getHddStringList(void)
{
    QStringList stringList;
    foreach (HDD item, hddList)
        stringList << item.getName();
    return stringList;
}

// Получить список наименований процессоров:
QStringList AppModel::getCpuStringList(void)
{
    QStringList stringList;
    foreach (CPU item, cpuList)
        stringList << item.getName();
    return stringList;
}

// Получить список наименований блоков питания:
QStringList AppModel::getPowerSupplyStringList(void)
{
    QStringList stringList;
    foreach (PowerSupply item, powerSupplyList)
        stringList << item.getName();
    return stringList;
}

// Получить список наименований оперативной памяти:
QStringList AppModel::getRamStringList(void)
{
    QStringList stringList;
    foreach (RAM item, ramList)
        stringList << item.getName();
    return stringList;
}


// Получить характеристики по типу детали и порядку в списке:
QString AppModel::getSpecificationsByIndex(DeviceType type, int index)
{
    switch (type) {
    case DeviceType::VideoCard: {
        VideoCard videoCard = videoCardList.at(index);
        return videoCard.getSpecifications();
    } case DeviceType::Motherboard: {
        Motherboard motherboard = motherboardList.at(index);
        return motherboard.getSpecifications();
    } case DeviceType::HDD: {
        HDD hdd = hddList.at(index);
        return hdd.getSpecifications();
    } case DeviceType::CPU: {
        CPU cpu = cpuList.at(index);
        return cpu.getSpecifications();
    } case DeviceType::PowerSupply: {
        PowerSupply powerSupply = powerSupplyList.at(index);
        return powerSupply.getSpecifications();
    } case DeviceType::RAM: {
        RAM ram = ramList.at(index);
        return ram.getSpecifications();
    }
    }

    return "";
}

// Получить цену цену по типу детали и порядку в списке:
int AppModel::getPriceByIndex(DeviceType type, int index)
{
    switch (type) {
    case DeviceType::VideoCard: {
        VideoCard videoCard = videoCardList.at(index);
        return videoCard.getPrice();
    } case DeviceType::Motherboard: {
        Motherboard motherboard = motherboardList.at(index);
        return motherboard.getPrice();
    } case DeviceType::HDD: {
        HDD hdd = hddList.at(index);
        return hdd.getPrice();
    } case DeviceType::CPU: {
        CPU cpu = cpuList.at(index);
        return cpu.getPrice();
    } case DeviceType::PowerSupply: {
        PowerSupply powerSupply = powerSupplyList.at(index);
        return powerSupply.getPrice();
    } case DeviceType::RAM: {
        RAM ram = ramList.at(index);
        return ram.getPrice();
    }
    }

    return 0;
}

// Получить информацию о совместимости для выбранного оборудования:
QString AppModel::getCompatibilityInfo(QList<int> videoCardNoLst, int motherboardNo, QList<int> hddNo, int cpuNo, int powerSupplyNo, int ramNo)
{
    Q_UNUSED(hddNo);
    Q_UNUSED(powerSupplyNo);

    QString result = "";

    const Motherboard& motherboard = motherboardList.at(motherboardNo);

    // const HDD& hdd1 = hddList.at(hddNo[0]);
    // const HDD& hdd2 = hddList.at(hddNo[1]);

    const CPU& cpu = cpuList.at(cpuNo);
    // const PowerSupply& powerSupply = powerSupplyList.at(powerSupplyNo);
    const RAM& ram = ramList.at(ramNo);

    foreach (int videoCardNo, videoCardNoLst) {
        const VideoCard& videoCard = videoCardList.at(videoCardNo);
        const QString videoCardName = videoCard.getName();
        switch (videoCard.isCompatible(motherboard)) {
        case -1: result += QString("Видеокарта %1 не совместима с материнской платой!").arg(videoCardName); break;
        case 0:  result += QString("Нет информации о соместимости видеокарты %1 с материнской платой.").arg(videoCardName); break;
        case 1:  result += QString("Видеокарта %1 cовместима с материнской платой.").arg(videoCardName); break;
        }
        result += "\n";
    }

    switch (cpu.isCompatible(motherboard)) {
    case -1: result += "Процессор не совместим с материнской платой!"; break;
    case 0:  result += "Нет информации о соместимости процессора с материнской платой."; break;
    case 1:  result += "Процессор cовместим с материнской платой."; break;
    }
    result += "\n";

    switch (ram.isCompatible(motherboard)) {
    case -1: result += "Оперативная память не совместима с материнской платой!"; break;
    case 0:  result += "Нет информации о соместимости оперативной памяти с материнской платой."; break;
    case 1:  result += "Оперативная память cовместима с материнской платой."; break;
    }
    result += "\n";

    return result;
}
