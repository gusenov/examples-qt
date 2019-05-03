#ifndef COMPUTERCOMPONENT_H
#define COMPUTERCOMPONENT_H

#include <QString>
#include <QList>
#include "devicetypes.h"


// Комплектующая:
class ComputerComponent
{

// Публичные члены класса:
public:

    // Конструктор:
    ComputerComponent(
            DeviceType type,
            int id,
            QString name,
            int price,
            QString specifications,
            QList<int> compatibility
    );

    // Получить тип компонента:
    DeviceType getType() const;

    // Получить идентификатор:
    int getId() const;

    // Получить наименование:
    QString getName() const;

    // Получить цену:
    int getPrice() const;

    // Получить характеристики:
    QString getSpecifications() const;

    // Получить идентификаторы совместимых компонентов:
    QList<int> getCompatibility();

    // Проверить совместима ли деталь с другой деталью:
    int isCompatible(const ComputerComponent& component) const;

// Приватные члены класса:
private:

    // Тип детали:
    DeviceType type;

    // Идентификатор:
    int id;

    // Наименование:
    QString name;

    // Цена:
    int price;

    // Характеристики:
    QString specifications;

    // Список идентификаторов совместимых деталей:
    QList<int> compatibility;

};

#endif // COMPUTERCOMPONENT_H
